#line 1 "/Users/tonylin/Desktop/idac/idac.h"
#ifndef IDAC_H
#define IDAC_H

// Define Registers 
#define RESET 0x01
#define RESET_CONFIG 0x02
#define SELECT_DAC 0x03
#define CONFIG_DAC 0x04
#define DAC_DATA 0x05
#define SELECT_BUCK_BOOST 0x06
#define CONFIG_BUCK_BOOST 0x07
#define CALIBRATE_EN 0x08
#define CALIBRATE_GAIN 0x09
#define CALIBRATE_OFFSET 0x0A
#define STATUS 0x0B
#define STATUS_MASK 0x0C
#define ALARM_ACTION 0x0D
#define ALARM_CODE 0x0E
#define WATCHDOG 0x10
#define DEVICE_ID 0x11

class idac {
    private:
    public:

};

#endif