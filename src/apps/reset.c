#include "reset.h"
#include "../driver/eeprom.h"
#include "../driver/st7565.h"
#include "../driver/system.h"
#include "../helper/measurements.h"
#include "../ui/helper.h"
#include "../radio.h"
#include "ARMCM0.h"
#include <string.h>

static const uint16_t BYTES_TOTAL = 0x2000;
static const Band freqPresets[] = {
    (Band){(FRange){181000, 200000}, "160m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){350000, 380000}, "80m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){700000, 720000}, "40m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){1010000, 1015000}, "30m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){1400000, 1435000}, "20m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){1748000, 1790000}, "16m B-cast", STEP_5_0kHz, MOD_AM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){1806800, 1816800}, "17m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){1890000, 1902000}, "15m B-cast", STEP_5_0kHz, MOD_AM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){2100000, 2144990}, "15m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){2145000, 2185000}, "13m B-cast", STEP_5_0kHz, MOD_AM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){2489000, 2499000}, "12m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){2567000, 2610000}, "11m B-cast", STEP_5_0kHz, MOD_AM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){2697500, 2799990}, "CB", STEP_5_0kHz, MOD_FM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){2800000, 2970000}, "10m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){5000000, 5400000}, "6m HAM", STEP_1_0kHz, MOD_USB, BK4819_FILTER_BW_NARROWER},
    (Band){(FRange){11800000, 13500000}, "Air Band", STEP_100_0kHz, MOD_AM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){14400000, 14800000}, "2m HAM", STEP_25_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
    (Band){(FRange){15175000, 15599990}, "Railway", STEP_25_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
    (Band){(FRange){15600000, 16327500}, "Sea", STEP_25_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
    (Band){(FRange){24300000, 27000000}, "Satcom", STEP_5_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
    (Band){(FRange){30001250, 30051250}, "River1", STEP_12_5kHz, MOD_FM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){33601250, 33651250}, "River2", STEP_12_5kHz, MOD_FM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){43307500, 43477500}, "LPD", STEP_25_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
    (Band){(FRange){44600625, 44620000}, "PMR", STEP_6_25kHz, MOD_FM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){46256250, 46272500}, "FRS/GMR462", STEP_12_5kHz, MOD_FM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){46756250, 46771250}, "FRS/GMR467", STEP_12_5kHz, MOD_FM, BK4819_FILTER_BW_NARROW},
    (Band){(FRange){86400000, 86900000}, "LoRa WAN", STEP_100_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
    (Band){(FRange){124000000, 130000000}, "23cm HAM", STEP_25_0kHz, MOD_FM, BK4819_FILTER_BW_WIDE},
};

static uint16_t bytesErased = 0;
static uint8_t buf[8];

void RESET_Init() {
  bytesErased = 0;
  memset(buf, 0xFF, sizeof(buf));
}

void RESET_Update() {
  EEPROM_WriteBuffer(bytesErased, buf, 8);
  bytesErased += 8;
  if (bytesErased >= BYTES_TOTAL) {
        for(uint8_t i=0;i<28;++i) {
            Preset p ={.band = freqPresets[i]};
            RADIO_SavePreset(i, &p);
        }
    NVIC_SystemReset();
  }
  gRedrawScreen = true;
}

void RESET_Render() {
  char String[16];
  UI_ClearScreen();
  sprintf(String, "%u%", bytesErased * 100 / BYTES_TOTAL);
  UI_PrintStringSmall(String, 0, 0, 2);

  memset(gFrameBuffer[3], 0b00111100,
         ConvertDomain(bytesErased, 0, 8196, 0, LCD_WIDTH));
}

bool RESET_key(KEY_Code_t k, bool p, bool h) {
  return false;
}
