#ifndef IDAC_H
#define IDAC_H

#include <Arduino.h>
#include <SPI.h>

#define ENABLE_PIN  LEDB
#define CHIP_SELECT_OUTPUT  LEDG


// DAC8775 Register Map
#define RESET 0x01
#define RESET_CONFIG 0x02
#define SELECT_DAC 0x03
#define CONFIG_DAC 0x04
#define DAC_DATA 0x05
#define SELECT_BUCK_BOOST 0x06
#define CONFIG_BUCK_BOOST 0x07
#define CALIBRATE_EN 0x016
#define CALIBRATE_GAIN 0x09
#define CALIBRATE_OFFSET 0x0A
#define STATUS 0x0B
#define STATUS_MASK 0x0C
#define ALARM_ACTION 0x0D
#define ALARM_CODE 0x0E
#define WATCHDOG 0x10
#define DEVICE_ID 0x11


class IDAC {
    private:

        
    public:
        void write_register(uint16_t reg, uint16_t value);
        void select_buck_boost(uint16_t bb_val);    // 16 bits, bit 3=d, 2=c, 1=b, 0=a
        void config_buck_boost(uint16_t bb_config_val); // [11:10] = CCLP, [9:6] = PCLMP, [5:2] = NCLMP, [1:0] = PNSEL
        void select_dac_reg(uint16_t dac_sel); // 12=CLSLD, 11=CLSLC, 10=CLSLB, 9=CLSLA, 8=CHD, 7=CHC,6=CHB, 5=CHA, 4=DSDO, 3=CREN, [2:1]=WPD, 0=WEN
        void config_dac_reg(uint16_t dac_config); // [15:14]=SCLIM, 13=HTEN, 12=OTEN, [11:8]=SRCLK_RATE, [7:5]=SR_STEP, 4=SREN, [3:0]=RANGE
        void program_dac(uint16_t data); // [15:0] dac data
        void chip_select(uint8_t enable, uint8_t select); // flags for enable chip and select chip
    };

#endif