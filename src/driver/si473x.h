#ifndef SI473X_H
#define SI473X_H

#include <stdint.h>

#define SI4735_CMD_POWER_UP 0x01
#define SI4735_CMD_GET_REV 0x10
#define SI4735_CMD_POWER_DOWN 0x11
#define SI4735_CMD_SET_PROPERTY 0x12
#define SI4735_CMD_GET_PROPERTY 0x13
#define SI4735_CMD_GET_INT_STATUS 0x14
#define SI4735_CMD_PATCH_ARGS 0x15
#define SI4735_CMD_PATCH_DATA 0x16
#define SI4735_CMD_FM_TUNE_FREQ 0x20
#define SI4735_CMD_FM_SEEK_START 0x21
#define SI4735_CMD_FM_TUNE_STATUS 0x22
#define SI4735_CMD_FM_RSQ_STATUS 0x23
#define SI4735_CMD_FM_RDS_STATUS 0x24
#define SI4735_CMD_FM_AGC_STATUS 0x27
#define SI4735_CMD_FM_AGC_OVERRIDE 0x28
#define SI4735_CMD_TX_TUNE_FREQ 0x30
#define SI4735_CMD_TX_TUNE_POWER 0x31
#define SI4735_CMD_TX_TUNE_MEASURE 0x32
#define SI4735_CMD_TX_TUNE_STATUS 0x33
#define SI4735_CMD_TX_ASQ_STATUS 0x34
#define SI4735_CMD_TX_RDS_BUF 0x35
#define SI4735_CMD_TX_RDS_PS 0x36
#define SI4735_CMD_AM_TUNE_FREQ 0x40
#define SI4735_CMD_AM_SEEK_START 0x41
#define SI4735_CMD_AM_TUNE_STATUS 0x42
#define SI4735_CMD_AM_RSQ_STATUS 0x43
#define SI4735_CMD_AM_AGC_STATUS 0x47
#define SI4735_CMD_AM_AGC_OVERRIDE 0x48
#define SI4735_CMD_WB_TUNE_FREQ 0x50
#define SI4735_CMD_WB_TUNE_STATUS 0x52
#define SI4735_CMD_WB_RSQ_STATUS 0x53
#define SI4735_CMD_WB_SAME_STATUS 0x54
#define SI4735_CMD_WB_ASQ_STATUS 0x55
#define SI4735_CMD_WB_AGC_STATUS 0x57
#define SI4735_CMD_WB_AGC_OVERRIDE 0x58
#define SI4735_CMD_AUX_ASRC_START 0x61
#define SI4735_CMD_AUX_ASQ_STATUS 0x65
#define SI4735_CMD_GPIO_CTL 0x80
#define SI4735_CMD_GPIO_SET 0x81

#define SI4735_FLG_CTSIEN 0x80
// Renamed to GPO2IEN from GPO2OEN in datasheet to avoid conflict with real
// GPO2OEN below. Also makes more sense this way: GPO2IEN -> enable GPO2 as INT
// GPO2OEN -> enable GPO2 generically, as an output
#define SI4735_FLG_GPO2IEN 0x40
#define SI4735_FLG_PATCH 0x20
#define SI4735_FLG_XOSCEN 0x10
#define SI4735_FLG_FREEZE 0x02
#define SI4735_FLG_FAST 0x01
#define SI4735_FLG_SEEKUP 0x08
#define SI4735_FLG_WRAP 0x04
#define SI4735_FLG_CANCEL 0x02
#define SI4735_FLG_INTACK 0x01
#define SI4735_FLG_STATUSONLY 0x04
#define SI4735_FLG_MTFIFO 0x02
#define SI4735_FLG_GPO3OEN 0x08
#define SI4735_FLG_GPO2OEN 0x04
#define SI4735_FLG_GPO1OEN 0x02
#define SI4735_FLG_GPO3LEVEL 0x08
#define SI4735_FLG_GPO2LEVEL 0x04
#define SI4735_FLG_GPO1LEVEL 0x02
#define SI4735_FLG_BLETHA_0 0x00
#define SI4735_FLG_BLETHA_12 0x40
#define SI4735_FLG_BLETHA_35 0x80
#define SI4735_FLG_BLETHA_U (SI4735_FLG_BLETHA_12 | SI4735_FLG_BLETHA_35)
#define SI4735_FLG_BLETHB_0 SI4735_FLG_BLETHA_0
#define SI4735_FLG_BLETHB_12 0x10
#define SI4735_FLG_BLETHB_35 0x20
#define SI4735_FLG_BLETHB_U (SI4735_FLG_BLETHB_12 | SI4735_FLG_BLETHB_35)
#define SI4735_FLG_BLETHC_0 SI4735_FLG_BLETHA_0
#define SI4735_FLG_BLETHC_12 0x04
#define SI4735_FLG_BLETHC_35 0x08
#define SI4735_FLG_BLETHC_U (SI4735_FLG_BLETHC_12 | SI4735_FLG_BLETHC_35)
#define SI4735_FLG_BLETHD_0 SI4735_FLG_BLETHA_0
#define SI4735_FLG_BLETHD_12 0x01
#define SI4735_FLG_BLETHD_35 0x02
#define SI4735_FLG_BLETHD_U (SI4735_FLG_BLETHD_12 | SI4735_FLG_BLETHD_35)
#define SI4735_FLG_RDSEN 0x01
#define SI4735_FLG_DEEMPH_NONE 0x00
#define SI4735_FLG_DEEMPH_50 0x01
#define SI4735_FLG_DEEMPH_75 0x02
#define SI4735_FLG_RSQREP 0x08
#define SI4735_FLG_RDSREP 0x04
#define SI4735_FLG_STCREP 0x01
#define SI4735_FLG_ERRIEN 0x40
#define SI4735_FLG_RSQIEN 0x08
#define SI4735_FLG_RDSIEN 0x04
#define SI4735_FLG_STCIEN 0x01
#define SI4735_FLG_RDSNEWBLOCKB 0x20
#define SI4735_FLG_RDSNEWBLOCKA 0x10
#define SI4735_FLG_RDSSYNCFOUND 0x04
#define SI4735_FLG_RDSSYNCLOST 0x02
#define SI4735_FLG_RDSRECV 0x01
#define SI4735_FLG_GRPLOST 0x04
#define SI4735_FLG_RDSSYNC 0x01
#define SI4735_FLG_AMPLFLT 0x01
#define SI4735_FLG_AMCHFLT_6KHZ 0x00
#define SI4735_FLG_AMCHFLT_4KHZ 0x01
#define SI4735_FLG_AMCHFLT_3KHZ 0x02
#define SI4735_FLG_AMCHFLT_2KHZ 0x03
#define SI4735_FLG_AMCHFLT_1KHZ 0x04
#define SI4735_FLG_AMCHFLT_1KHZ8 0x05
#define SI4735_FLG_AMCHFLT_2KHZ5 0x06

// Define Si4735 Function modes
#define SI4735_FUNC_FM 0x00
#define SI4735_FUNC_AM 0x01
#define SI4735_FUNC_VER 0x0F

// Define Si4735 Output modes
#define SI4735_OUT_RDS 0x00 // RDS only
#define SI4735_OUT_ANALOG 0x05
#define SI4735_OUT_DIGITAL1 0x0B // DCLK, LOUT/DFS, ROUT/DIO
#define SI4735_OUT_DIGITAL2 0xB0 // DCLK, DFS, DIO
#define SI4735_OUT_BOTH (SI4735_OUT_ANALOG | SI4735_OUT_DIGITAL2)

// Define Si47xx Status flag masks (bits the chip fed us)
#define SI4735_STATUS_CTS 0x80
#define SI4735_STATUS_ERR 0x40
#define SI4735_STATUS_RSQINT 0x08
#define SI4735_STATUS_RDSINT 0x04
#define SI4735_STATUS_ASQINT 0x02
#define SI4735_STATUS_STCINT 0x01
#define SI4735_STATUS_BLTF 0x80
#define SI4735_STATUS_AFCRL 0x02
#define SI4735_STATUS_VALID 0x01
#define SI4735_STATUS_BLENDINT 0x80
#define SI4735_STATUS_MULTHINT 0x20
#define SI4735_STATUS_MULTLINT 0x10
#define SI4735_STATUS_SNRHINT 0x08
#define SI4735_STATUS_SNRLINT 0x04
#define SI4735_STATUS_RSSIHINT 0x02
#define SI4735_STATUS_RSSILINT 0x01
#define SI4735_STATUS_SMUTE 0x08
#define SI4735_STATUS_PILOT 0x80
#define SI4735_STATUS_OVERMOD 0x04
#define SI4735_STATUS_IALH 0x02
#define SI4735_STATUS_IALL 0x01

// Define Si47xx Property codes
#define SI4735_PROP_GPO_IEN word(0x0001)
#define SI4735_PROP_DIGITAL_INPUT_FORMAT 0x0101
#define SI4735_PROP_DIGITAL_OUTPUT_FORMAT 0x0102
#define SI4735_PROP_DIGITAL_INPUT_SAMPLE_RATE 0x0103
#define SI4735_PROP_DIGITAL_OUTPUT_SAMPLE_RATE 0x0104
#define SI4735_PROP_REFCLK_FREQ 0x0201
#define SI4735_PROP_REFCLK_PRESCALE 0x0202
#define SI4735_PROP_FM_DEEMPHASIS 0x1100
#define SI4735_PROP_FM_CHANNEL_FILTER 0x1102
#define SI4735_PROP_FM_BLEND_STEREO_THRESHOLD 0x1105
#define SI4735_PROP_FM_BLEND_MONO_THRESHOLD 0x1106
#define SI4735_PROP_FM_ANTENNA_INPUT 0x1107
#define SI4735_PROP_FM_MAX_TUNE_ERROR 0x1108
#define SI4735_PROP_FM_RSQ_INT_SOURCE 0x1200
#define SI4735_PROP_FM_RSQ_SNR_HI_THRESHOLD 0x1201
#define SI4735_PROP_FM_RSQ_SNR_LO_THRESHOLD 0x1202
#define SI4735_PROP_FM_RSQ_RSSI_HI_THRESHOLD 0x1203
#define SI4735_PROP_FM_RSQ_RSSI_LO_THRESHOLD 0x1204
#define SI4735_PROP_FM_RSQ_MULTIPATH_HI_THRESHOLD 0x1205
#define SI4735_PROP_FM_RSQ_MULTIPATH_LO_THRESHOLD 0x1206
#define SI4735_PROP_FM_RSQ_BLEND_THRESHOLD 0x1207
#define SI4735_PROP_FM_SOFT_MUTE_RATE 0x1300
#define SI4735_PROP_FM_SOFT_MUTE_SLOPE 0x1301
#define SI4735_PROP_FM_SOFT_MUTE_MAX_ATTENUATION 0x1302
#define SI4735_PROP_FM_SOFT_MUTE_SNR_THRESHOLD 0x1303
#define SI4735_PROP_FM_SOFT_MUTE_RELEASE_RATE 0x1304
#define SI4735_PROP_FM_SOFT_MUTE_ATTACK_RATE 0x1305
#define SI4735_PROP_FM_SEEK_BAND_BOTTOM 0x1400
#define SI4735_PROP_FM_SEEK_BAND_TOP 0x1401
#define SI4735_PROP_FM_SEEK_FREQ_SPACING 0x1402
#define SI4735_PROP_FM_SEEK_TUNE_SNR_THRESHOLD 0x1403
#define SI4735_PROP_FM_SEEK_TUNE_RSSI_THRESHOLD 0x1404
#define SI4735_PROP_FM_RDS_INT_SOURCE 0x1500
#define SI4735_PROP_FM_RDS_INT_FIFO_COUNT 0x1501
#define SI4735_PROP_FM_RDS_CONFIG 0x1502
#define SI4735_PROP_FM_RDS_CONFIDENCE 0x1503
#define SI4735_PROP_FM_AGC_ATTACK_RATE 0x1700
#define SI4735_PROP_FM_AGC_RELEASE_RATE 0x1701
#define SI4735_PROP_FM_BLEND_RSSI_STEREO_THRESHOLD 0x1800
#define SI4735_PROP_FM_BLEND_RSSI_MONO_THRESHOLD 0x1801
#define SI4735_PROP_FM_BLEND_RSSI_ATTACK_RATE 0x1802
#define SI4735_PROP_FM_BLEND_RSSI_RELEASE_RATE 0x1803
#define SI4735_PROP_FM_BLEND_SNR_STEREO_THRESHOLD 0x1804
#define SI4735_PROP_FM_BLEND_SNR_MONO_THRESHOLD 0x1805
#define SI4735_PROP_FM_BLEND_SNR_ATTACK_RATE 0x1806
#define SI4735_PROP_FM_BLEND_SNR_RELEASE_RATE 0x1807
#define SI4735_PROP_FM_BLEND_MULTIPATH_STEREO_THRESHOLD 0x1808
#define SI4735_PROP_FM_BLEND_MULTIPATH_MONO_THRESHOLD 0x1809
#define SI4735_PROP_FM_BLEND_MULTIPATH_ATTACK_RATE 0x180A
#define SI4735_PROP_FM_BLEND_MULTIPATH_RELEASE_RATE 0x180B
#define SI4735_PROP_FM_BLEND_MAX_STEREO_SEPARATION 0x180C
#define SI4735_PROP_FM_NB_DETECT_THRESHOLD 0x1900
#define SI4735_PROP_FM_NB_INTERVAL 0x1901
#define SI4735_PROP_FM_NB_RATE 0x1902
#define SI4735_PROP_FM_NB_IIR_FILTER 0x1903
#define SI4735_PROP_FM_NB_DELAY 0x1904
#define SI4735_PROP_FM_HICUT_SNR_HIGH_THRESHOLD 0x1A00
#define SI4735_PROP_FM_HICUT_SNR_LOW_THRESHOLD 0x1A01
#define SI4735_PROP_FM_HICUT_ATTACK_RATE 0x1A02
#define SI4735_PROP_FM_HICUT_RELEASE_RATE 0x1A03
#define SI4735_PROP_FM_HICUT_MULTIPATH_TRIGGER_THRESHOLD 0x1A04
#define SI4735_PROP_FM_HICUT_MULTIPATH_END_THRESHOLD 0x1A05
#define SI4735_PROP_FM_HICUT_CUTOFF_FREQUENCY 0x1A06
#define SI4735_PROP_TX_COMPONENT_ENABLE 0x2100
#define SI4735_PROP_TX_AUDIO_DEVIATION 0x2101
#define SI4735_PROP_TX_PILOT_DEVIATION 0x2102
#define SI4735_PROP_TX_RDS_DEVIATION 0x2103
#define SI4735_PROP_TX_LINE_INPUT_LEVEL 0x2104
#define SI4735_PROP_TX_LINE_INPUT_MUTE 0x2105
#define SI4735_PROP_TX_PREEMPHASIS 0x2106
#define SI4735_PROP_TX_PILOT_FREQUENCY 0x2107
#define SI4735_PROP_TX_ACOMP_ENABLE 0x2200
#define SI4735_PROP_TX_ACOMP_THRESHOLD 0x2201
#define SI4735_PROP_TX_ACOMP_ATTACK_TIME 0x2202
#define SI4735_PROP_TX_ACOMP_RELEASE_TIME 0x2203
#define SI4735_PROP_TX_ACOMP_GAIN 0x2204
#define SI4735_PROP_TX_LIMITER_RELEASE_TIME 0x2205
#define SI4735_PROP_TX_ASQ_INTERRUPT_SOURCE 0x2300
#define SI4735_PROP_TX_ASQ_LEVEL_LOW 0x2301
#define SI4735_PROP_TX_ASQ_DURATION_LOW 0x2302
#define SI4735_PROP_TX_ASQ_LEVEL_HIGH 0x2303
#define SI4735_PROP_TX_ASQ_DURATION_HIGH 0x2304
#define SI4735_PROP_TX_RDS_INTERRUPT_SOURCE 0x2C00
#define SI4735_PROP_TX_RDS_PI 0x2C01
#define SI4735_PROP_TX_RDS_PS_MIX 0x2C02
#define SI4735_PROP_TX_RDS_PS_MISC 0x2C03
#define SI4735_PROP_TX_RDS_PS_REPEAT_COUNT 0x2C04
#define SI4735_PROP_TX_RDS_PS_MESSAGE_COUNT 0x2C05
#define SI4735_PROP_TX_RDS_PS_AF 0x2C06
#define SI4735_PROP_TX_RDS_FIFO_SIZE 0x2C07
#define SI4735_PROP_AM_DEEMPHASIS 0x3100
#define SI4735_PROP_AM_CHANNEL_FILTER 0x3102
#define SI4735_PROP_AM_AUTOMATIC_VOLUME_CONTROL_MAX_GAIN 0x3103
#define SI4735_PROP_AM_MODE_AFC_SW_PULL_IN_RANGE 0x3104
#define SI4735_PROP_AM_MODE_AFC_SW_LOCK_IN_RANGE 0x3105
#define SI4735_PROP_AM_RSQ_INTERRUPTS 0x3200
#define SI4735_PROP_AM_RSQ_SNR_HIGH_THRESHOLD 0x3201
#define SI4735_PROP_AM_RSQ_SNR_LOW_THRESHOLD 0x3202
#define SI4735_PROP_AM_RSQ_RSSI_HIGH_THRESHOLD 0x3203
#define SI4735_PROP_AM_RSQ_RSSI_LOW_THRESHOLD 0x3204
#define SI4735_PROP_AM_SOFT_MUTE_RATE 0x3300
#define SI4735_PROP_AM_SOFT_MUTE_SLOPE 0x3301
#define SI4735_PROP_AM_SOFT_MUTE_MAX_ATTENUATION 0x3302
#define SI4735_PROP_AM_SOFT_MUTE_SNR_THRESHOLD 0x3303
#define SI4735_PROP_AM_SOFT_MUTE_RELEASE_RATE 0x3304
#define SI4735_PROP_AM_SOFT_MUTE_ATTACK_RATE 0x3305
#define SI4735_PROP_AM_SEEK_BAND_BOTTOM 0x3400
#define SI4735_PROP_AM_SEEK_BAND_TOP 0x3401
#define SI4735_PROP_AM_SEEK_FREQ_SPACING 0x3402
#define SI4735_PROP_AM_SEEK_TUNE_SNR_THRESHOLD 0x3403
#define SI4735_PROP_AM_SEEK_TUNE_RSSI_THRESHOLD 0x3404
#define SI4735_PROP_AM_AGC_ATTACK_RATE 0x3702
#define SI4735_PROP_AM_AGC_RELEASE_RATE 0x3703
#define SI4735_PROP_AM_FRONTEND_AGC_CONTROL 0x3705
#define SI4735_PROP_AM_NB_DETECT_THRESHOLD 0x3900
#define SI4735_PROP_AM_NB_INTERVAL 0x3901
#define SI4735_PROP_AM_NB_RATE 0x3902
#define SI4735_PROP_AM_NB_IIR_FILTER 0x3903
#define SI4735_PROP_AM_NB_DELAY 0x3904
#define SI4735_PROP_RX_VOLUME 0x4000
#define SI4735_PROP_RX_HARD_MUTE 0x4001
#define SI4735_PROP_WB_MAX_TUNE_ERROR 0x5108
#define SI4735_PROP_WB_RSQ_INT_SOURCE 0x5200
#define SI4735_PROP_WB_RSQ_SNR_HI_THRESHOLD 0x5201
#define SI4735_PROP_WB_RSQ_SNR_LO_THRESHOLD 0x5202
#define SI4735_PROP_WB_RSQ_RSSI_HI_THRESHOLD 0x5203
#define SI4735_PROP_WB_RSQ_RSSI_LO_THRESHOLD 0x5204
#define SI4735_PROP_WB_VALID_SNR_THRESHOLD 0x5403
#define SI4735_PROP_WB_VALID_RSSI_THRESHOLD 0x5404
#define SI4735_PROP_WB_SAME_INTERRUPT_SOURCE 0x5500
#define SI4735_PROP_WB_ASQ_INTERRUPT_SOURCE 0x5600
#define SI4735_PROP_AUX_ASQ_INTERRUPT_SOURCE 0x6600
#define SI4735_PROP_DEBUG_CONTROL 0xFF00

typedef union {
  struct {
    // status ("RESP0")
    uint8_t STCINT : 1;
    uint8_t DUMMY1 : 1;
    uint8_t RDSINT : 1;
    uint8_t RSQINT : 1;
    uint8_t DUMMY2 : 2;
    uint8_t ERR : 1;
    uint8_t CTS : 1;
    // RESP1
    uint8_t RSSIILINT : 1; //!<  RSSI Detect Low.
    uint8_t RSSIHINT : 1;  //!<  RSSI Detect High.
    uint8_t SNRLINT : 1;   //!<  SNR Detect Low.
    uint8_t SNRHINT : 1;   //!<  SNR Detect High.
    uint8_t MULTLINT : 1;  //!<  Multipath Detect Low
    uint8_t MULTHINT : 1;  //!<  Multipath Detect High
    uint8_t DUMMY3 : 1;
    uint8_t BLENDINT : 1; //!<  Blend Detect Interrupt.
    // RESP2
    uint8_t VALID : 1; //!<  Valid Channel.
    uint8_t AFCRL : 1; //!<  AFC Rail Indicator.
    uint8_t DUMMY4 : 1;
    uint8_t
        SMUTE : 1; //!<  Soft Mute Indicator. Indicates soft mute is engaged.
    uint8_t DUMMY5 : 4;
    // RESP3
    uint8_t STBLEND : 7; //!<  Indicates amount of stereo blend in% (100 = full
                         //!<  stereo, 0 = full mono).
    uint8_t PILOT : 1;   //!<  Indicates stereo pilot presence.
    // RESP4 to RESP7
    uint8_t RSSI; //!<  RESP4 - Contains the current receive signal strength
                  //!<  (0–127 dBμV).
    uint8_t SNR;  //!<  RESP5 - Contains the current SNR metric (0–127 dB).
    uint8_t MULT; //!<  RESP6 - Contains the current multipath metric. (0 = no
                  //!<  multipath; 100 = full multipath)
    uint8_t FREQOFF; //!<  RESP7 - Signed frequency offset (kHz).
  } resp;
  uint8_t raw[8];
} RSQStatus;

typedef union {
  struct {
    uint8_t INTACK : 1; //!<  If set, clears the seek/tune complete interrupt
                        //!<  status indicator.
    uint8_t CANCEL : 1; //!<  If set, aborts a seek currently in progress.
    uint8_t RESERVED2 : 6;
  } arg;
  uint8_t raw;
} TuneStatus;

typedef union {
  struct {
    // Status
    uint8_t STCINT : 1; //!<  Seek/Tune Complete Interrupt; 1 = Tune complete
                        //!<  has been triggered.
    uint8_t DUMMY1 : 1;
    uint8_t RDSINT : 1; //!<  Radio Data System (RDS) Interrup; 0 = interrupt
                        //!<  has not been triggered.
    uint8_t RSQINT : 1; //!<  Received Signal Quality Interrupt; 0 = interrupt
                        //!<  has not been triggered.
    uint8_t DUMMY2 : 2;
    uint8_t ERR : 1; //!<  Error. 0 = No error 1 = Error
    uint8_t CTS : 1; //!<  Clear to Send.
    // RESP1
    uint8_t VALID : 1; //!<  Valid Channel
    uint8_t AFCRL : 1; //!<  AFC Rail Indicator
    uint8_t DUMMY3 : 5;
    uint8_t BLTF : 1; //!<  Reports if a seek hit the band limit
    // RESP2
    uint8_t READFREQH; //!<  Read Frequency High byte.
    // RESP3
    uint8_t READFREQL; //!<  Read Frequency Low byte.
    // RESP4
    uint8_t RSSI; //!<  Received Signal Strength Indicator (dBμV)
    // RESP5
    uint8_t
        SNR; //!<  This byte contains the SNR metric when tune is complete (dB).
    // RESP6
    uint8_t
        MULT; //!<  If FM, contains the multipath metric when tune is complete;
              //!<  IF AM READANTCAPH (tuning capacitor value high byte)
    // RESP7
    uint8_t READANTCAP; //!<  If FM, contains the current antenna tuning
                        //!<  capacitor value; IF AM READANTCAPL (tuning
                        //!<  capacitor value low byte)
  } resp;
  uint8_t raw[8]; //!<  Check it
} ResponseStatus;

// Command responses
// Names that begin with FIELD are argument masks.  Others are argument
// constants.
enum {
  // FM_TUNE_STATUS, AM_TUNE_STATUS, WB_TUNE_STATUS
  FIELD_TUNE_STATUS_RESP1_SEEK_LIMIT =
      0b10000000,                            // Seek hit search limit - not WB
  FIELD_TUNE_STATUS_RESP1_AFC_RAILED = 0b10, // AFC railed
  FIELD_TUNE_STATUS_RESP1_SEEKABLE =
      0b01, // Station could currently be found by seek,
  FIELD_TUNE_STATUS_RESP1_VALID = 0b01, // that is, the station is valid
  // FM_RSQ_STATUS, AM_RSQ_STATUS, WB_RSQ_STATUS
  /* See RSQ interrupts above for RESP1. */
  FIELD_RSQ_STATUS_RESP2_SOFT_MUTE = 0b1000,  // Soft mute active - not WB
  FIELD_RSQ_STATUS_RESP2_AFC_RAILED = 0b0010, // AFC railed
  FIELD_RSQ_STATUS_RESP2_SEEKABLE =
      0b0001, // Station could currently be found by seek,
  FIELD_RSQ_STATUS_RESP2_VALID = 0b0001,      // that is, the station is valid
  FIELD_RSQ_STATUS_RESP3_STEREO = 0b10000000, // Stereo pilot found - FM only
  FIELD_RSQ_STATUS_RESP3_STEREO_BLEND =
      0b01111111, // Stereo blend in % (100 = full stereo, 0 = full mono) - FM
                  // only
  // FM_RDS_STATUS
  /* See RDS interrupts above for RESP1. */
  FIELD_RDS_STATUS_RESP2_FIFO_OVERFLOW = 0b00000100, // FIFO overflowed
  FIELD_RDS_STATUS_RESP2_SYNC = 0b00000001, // RDS currently synchronized
  FIELD_RDS_STATUS_RESP12_BLOCK_A = 0b11000000,
  FIELD_RDS_STATUS_RESP12_BLOCK_B = 0b00110000,
  FIELD_RDS_STATUS_RESP12_BLOCK_C = 0b00001100,
  FIELD_RDS_STATUS_RESP12_BLOCK_D = 0b00000011,
  RDS_STATUS_RESP12_BLOCK_A_NO_ERRORS = 0U << 6,     // Block had no errors
  RDS_STATUS_RESP12_BLOCK_A_2_BIT_ERRORS = 1U << 6,  // Block had 1-2 bit errors
  RDS_STATUS_RESP12_BLOCK_A_5_BIT_ERRORS = 2U << 6,  // Block had 3-5 bit errors
  RDS_STATUS_RESP12_BLOCK_A_UNCORRECTABLE = 3U << 6, // Block was uncorrectable
  RDS_STATUS_RESP12_BLOCK_B_NO_ERRORS = 0U << 4,
  RDS_STATUS_RESP12_BLOCK_B_2_BIT_ERRORS = 1U << 4,
  RDS_STATUS_RESP12_BLOCK_B_5_BIT_ERRORS = 2U << 4,
  RDS_STATUS_RESP12_BLOCK_B_UNCORRECTABLE = 3U << 4,
  RDS_STATUS_RESP12_BLOCK_C_NO_ERRORS = 0U << 2,
  RDS_STATUS_RESP12_BLOCK_C_2_BIT_ERRORS = 1U << 2,
  RDS_STATUS_RESP12_BLOCK_C_5_BIT_ERRORS = 2U << 2,
  RDS_STATUS_RESP12_BLOCK_C_UNCORRECTABLE = 3U << 2,
  RDS_STATUS_RESP12_BLOCK_D_NO_ERRORS = 0U << 0,
  RDS_STATUS_RESP12_BLOCK_D_2_BIT_ERRORS = 1U << 0,
  RDS_STATUS_RESP12_BLOCK_D_5_BIT_ERRORS = 2U << 0,
  RDS_STATUS_RESP12_BLOCK_D_UNCORRECTABLE = 3U << 0,
  // WB_SAME_STATUS - TODO

  // AUX_ASQ_STATUS, WB_ASQ_STATUS
  /* See ASQ interrupts above for RESP1. */
  FIELD_AUX_ASQ_STATUS_RESP2_OVERLOAD =
      0b1, // Audio input is currently overloading ADC
  FIELD_WB_ASQ_STATUS_RESP2_ALERT = 0b1, // Alert tone is present
  // FM_AGC_STATUS, AM_AGC_STATUS, WB_AGC_STATUS
  FIELD_AGC_STATUS_RESP1_DISABLE_AGC = 0b1, // True if AGC disabled
};

typedef enum {
  SI4732_FM,
  SI4732_AM,
  SI4732_LSB,
  SI4732_USB,
  SI4732_CW,
} SI4732_MODE;

typedef enum {
  SI4735_BW_6_kHz,
  SI4735_BW_4_kHz,
  SI4735_BW_3_kHz,
  SI4735_BW_2_kHz,
  SI4735_BW_1_kHz,
  SI4735_BW_1_8_kHz,
  SI4735_BW_2_5_kHz,
} SI4735_FilterBW;

void SI4732_PowerUp();
void SI4732_PowerDown();
void SI4732_SetFreq(uint16_t freq);
void SI4732_ReadRDS(uint8_t buf[13]);
void SI4732_SwitchMode(SI4732_MODE mode);
void RSQ_GET();
void SI4732_SetAutomaticGainControl(uint8_t AGCDIS, uint8_t AGCIDX);
void SI4732_Seek(bool up, bool wrap);
void SI4735_SeekStationProgress(void (*showFunc)(uint16_t f),
                                bool (*stopSeking)(), uint8_t up_down);
uint16_t SI4732_getFrequency(bool *valid);
void SI4735_SetBandwidth(SI4735_FilterBW AMCHFLT, bool AMPLFLT);
void SI4735_SetSeekFmLimits(uint16_t bottom, uint16_t top);
void SI4735_SetSeekAmLimits(uint16_t bottom, uint16_t top);
void SI4735_SetSeekFmSpacing(uint16_t spacing);
void SI4735_SetSeekAmSpacing(uint16_t spacing);
void SI4735_SetSeekFmRssiThreshold(uint16_t value);
void SI4735_SetSeekAmRssiThreshold(uint16_t value);
void SI4735_GetTuneStatus(uint8_t INTACK, uint8_t CANCEL);

extern SI4732_MODE si4732mode;
extern RSQStatus rsqStatus;
extern uint16_t siCurrentFreq;
extern ResponseStatus siCurrentStatus;

#endif /* end of include guard: SI473X_H */
