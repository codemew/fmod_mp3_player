/////////////////////////////////////////////////////////////////////////////
///
/// @copyright
///     Copyright [2021] <Mindteck>
///
/// @brief
///    This is the Header file of rdtsbc file.
///
/// @authors Qt Creator Wizard, Remi Lahiri, Nikhilesh and Binay Mondal.
///
//////////////////////////////////////////////////////////////////////////////
#ifndef LINUX_CODE_SOURCE_COMMON_COMMON_RDTSBC_H_
#define LINUX_CODE_SOURCE_COMMON_COMMON_RDTSBC_H_

//#include "qstring.h"
#ifndef DESKTOP_MPM
#include <../libtempus/tempus-sbc.h>
#else
#define SBC_NO_ERROR 0
#define SBC_ERROR -1
#define SBC_ERROR_CPLD_INIT -2
#define SBC_ERROR_INIT -3
#define SBC_ERROR_NOT_STABLE -100
#define SBC_ERROR_PARAMETER -101
#define SBC_ERROR_SMBUS -102
#define SBC_ERROR_POWER -103
#define SBC_ERROR_SMBUS_NOACK -104
#define SBC_ERROR_DRIVER -105
#define SBC_ERROR_I2C_NOACK -106
#define SBC_ERROR_SMBUS_MUTEX -107
#define SBC_ERROR_I2C -108

/* === Audio Control bits === */
#define SBC_AUD_SPEAKER 0x00000001
#define SBC_AUD_VOIP 0x00000004

typedef struct tSbcBatteryTag {  // units
  int uTemp;                     // 0.1 K
  int uVoltage;                  // mV
  int uRelativeCharge;           // %
  int uAbsoluteCharge;           // %
  int uRemainingCapacity;        // mAh
  int uFullCapacity;             // mAh
  int uDesignCapacity;           // mAh
  int iCurrent;                  // mA
  int iAverageCurrent;           // mA
} tSbcBattery;

typedef enum tSbcLedMode { SBC_LED_OFF, SBC_LED_ON, SBC_LED_BLINK } tSbcLedMode;

#define SBC_CASE_TEMP 0x00000080
#define SYS_CAPNO 0x00040000
#define SYS_ECG 0x00080000  // Dummy for desktop build
#define SYS_SPO2 0x00100000
#define SYS_IBP1 0x00400000
#define SYS_ITEMP1 0x01000000
#define SBC_GPS 0x00000020
#define SBC_USB_EXTERNAL 0x00000800
#endif

// Local Error Codes
#define MT_ERROR_LOAD_MODEM -1000
#define MT_ERROR_UNLOAD_MODEM -1001
#define MT_ERROR_MODEM_SCRATCH -1002

#define SBC_LED_POWER_GREEN 0x00000001
#define SBC_LED_POWER_AMBER 0x00000002
#define SBC_LED_SPARE2 0x00000004
#define SBC_LED_SPARE3 0x00000008
#define SBC_LED_SPARE4 0x00000010
#define SBC_LED_SPARE5 0x00000020
#define SBC_LED_SPARE6 0x00000040
#define SBC_LED_SPARE7 0x00000080
#define SBC_LED_ANTENNA_0 0x00000100
#define SBC_LED_ANTENNA_1 0x00000200
#define SBC_LED_ANTENNA_2 0x00000400
#define SBC_LED_ANTENNA_3 0x00000800

// *******************Wrapper for sbc init API*****************************
inline int sbcInit() {
#ifndef DESKTOP_MPM
  return iSbcInit();
#else
  return 0;
#endif
}
// *******************Wrapper for sbc get device power
// API*****************************
inline int sbcGetDevicePower(int *pDeviceBits) {
#ifndef DESKTOP_MPM
  return iSbcGetDevicePower(pDeviceBits);
#else
  Q_UNUSED(pDeviceBits);
  return 0;
#endif
}
// *******************Wrapper for sbc switch device power
// API*****************************
inline int sbcSwitchDevicePower(int iOn, int iDeviceBits) {
#ifndef DESKTOP_MPM
  return iSbcSwitchDevicePower(iOn, iDeviceBits);
#else
  Q_UNUSED(iOn);
  Q_UNUSED(iDeviceBits);
  return 0;
#endif
}
// *******************Wrapper for sbc set leds API*****************************
inline void sbcSetLeds(int iLeadMask, int iLedMode) {
#ifndef DESKTOP_MPM
  iSbcSetLeds(iLeadMask, (tSbcLedMode)iLedMode);
#else
  Q_UNUSED(iLeadMask);
  Q_UNUSED(iLedMode);
#endif
}

// *******************Wrapper for Switch System Off
// API*****************************
inline void sbcSwitchSystemOff() {
#ifndef DESKTOP_MPM
  iSbcSwitchSystemOff();
#endif
}

// *******************Wrapper for sbc get leds API*****************************
inline void sbcGetLeds(int *iLeadMask, int iLedMode) {
#ifndef DESKTOP_MPM
  iSbcGetLeds(iLeadMask, (tSbcLedMode)iLedMode);
#else
  Q_UNUSED(iLeadMask);
  Q_UNUSED(iLedMode);
#endif
}

// *******************Wrapper for sbc get keypad*****************************
inline int sbcGetKeypad(int *pwKeyMask) {
#ifndef DESKTOP_MPM
  return iSbcGetKeypad(pwKeyMask);
#else
  Q_UNUSED(pwKeyMask);
  return 0;
#endif
}

// *******************Wrapper for sbc battery
// current****************************
inline int sbcGetBatteryStatus(int *pwStatus, int *pwVoltage,
                               int *pwRelativeCharge, int *piCurrent,
                               tSbcBattery *psBattery, char *szManufacturer) {
#ifndef DESKTOP_MPM
  return iSbcGetBatteryStatus(pwStatus, pwVoltage, pwRelativeCharge, piCurrent,
                              psBattery, szManufacturer);
#else
  Q_UNUSED(pwStatus);
  Q_UNUSED(pwVoltage);
  Q_UNUSED(pwRelativeCharge);
  Q_UNUSED(piCurrent);
  Q_UNUSED(psBattery);
  Q_UNUSED(szManufacturer);
  return 0;
#endif
}
// *******************Wrapper for sbc battery
// voltage****************************
inline int sbcGetBatteryVoltage(int *pwVoltage) {
#ifndef DESKTOP_MPM
  return iSbcGetBatteryVoltage(pwVoltage);
#else
  Q_UNUSED(pwVoltage);
  return 0;
#endif
}

// *******************Wrapper for sbc battery charge****************************
inline int sbcGetBatteryCharge(int *pwRelativeCharge) {
#ifndef DESKTOP_MPM
  return iSbcGetBatteryCharge(pwRelativeCharge);
#else
  Q_UNUSED(pwRelativeCharge);
  return 0;
#endif
}

// *******************Wrapper for sbc battery
// current****************************
inline int sbcGetBatteryCurrent(int *piCurrent) {
#ifndef DESKTOP_MPM
  return iSbcGetBatteryCurrent(piCurrent);
#else
  Q_UNUSED(piCurrent);
  return 0;
#endif
}

// *******************Wrapper for sbc battery
// current****************************
inline int sbcSetAudioControl(int boOn, int dwAudioControlBits) {
#ifndef DESKTOP_MPM
  return iSbcSetAudioControl(boOn, dwAudioControlBits);
#else
  Q_UNUSED(boOn);
  Q_UNUSED(dwAudioControlBits);
  return 0;
#endif
}

// *******************Wrapper for sbc audio
// routing******************************
inline int sbcSetAudioRouting(int boOn, int dwAudioMuxBits) {
#ifndef DESKTOP_MPM
  return iSbcSetAudioRouting(boOn, dwAudioMuxBits);
#else
  Q_UNUSED(boOn);
  Q_UNUSED(dwAudioMuxBits);
  return 0;
#endif
}

// *******************Wrapper for sbc get
// temperature****************************
inline int sbcGetTemperature(int *piCaseTemp) {
#ifndef DESKTOP_MPM
  return iSbcGetTemperature(piCaseTemp);
#else
  // Q_UNUSED(piCaseTemp);
  *piCaseTemp = 0;
  return 0;
#endif
}

// *******************Wrapper for sbc get processor
// temperature******************
inline int sbcGetProcessorTemp(int *iTemp) {
#ifndef DESKTOP_MPM
  //Q_UNUSED(iTemp);
  return iSbcGetProcessorTemp(iTemp);
#else
  //Q_UNUSED(iTemp);
  return 0;
#endif
}

// *******************Wrapper for sbc get charger
// inhibit************************
inline int sbcGetChargeInhibit(int *pboInhibit) {
#ifndef DESKTOP_MPM
  return iSbcGetChargeInhibit(pboInhibit);
#else
  Q_UNUSED(pboInhibit);
  return 0;
#endif
}

// *******************Wrapper for sbc set charger
// inhibit************************
inline int sbcSetChargeInhibit(int boInhibit) {
#ifndef DESKTOP_MPM
  return iSbcSetChargeInhibit(boInhibit);
#else
  Q_UNUSED(boInhibit);
  return 0;
#endif
}

// *******************Wrapper for sbc set watchdog
// API8**************************
inline int sbcSetWatchdog(int dwDelay) {
#ifndef DESKTOP_MPM
  return iSbcSetWatchdog(dwDelay);
#else
  Q_UNUSED(dwDelay);
  return 0;
#endif
}

// *******************Wrapper for sbc set beep level
// API*****************************
inline int sbcSetBeepLevel(int iLevel) {
#ifndef DESKTOP_MPM
  return iSbcSetBeepLevel(iLevel);
#else
  Q_UNUSED(iLevel);
  return 0;
#endif
}

// *******************Wrapper for sbc set Backlight level
// API*****************************
inline int SbcSetBacklight(int iLevel) {
#ifndef DESKTOP_MPM
  return iSbcSetBacklight(iLevel);
#else
  Q_UNUSED(iLevel);
  return 0;
#endif
}

// *******************Wrapper for GPS reset API*****************************
inline int sbcSetGpsReset(int boReset) {
#ifndef DESKTOP_MPM
  return iSbcSetGpsReset(boReset);
#else
  Q_UNUSED(boReset);
  return 0;
#endif
}

#endif  // LINUX_CODE_SOURCE_COMMON_COMMON_RDTSBC_H_
