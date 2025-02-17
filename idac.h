#ifndef IDAC_H
#define IDAC_H

#include <Arduino.h>
#include <SPI.h>

#define ENABLE_PIN  LEDB
#define CHIP_SELECT_OUTPUT  LEDG


// DAC8775 Register Map
namespace DAC8775_REG {
    const uint16_t RESET = 0x01;
    const uint16_t RESET_CONFIG = 0x02;
    const uint16_t SELECT_DAC = 0x03;
    const uint16_t CONFIG_DAC = 0x04;
    const uint16_t DAC_DATA = 0x05;
    const uint16_t SELECT_BUCK_BOOST = 0x06;
    const uint16_t CONFIG_BUCK_BOOST = 0x07;
    const uint16_t CALIBRATE_EN = 0x016;
    const uint16_t CALIBRATE_GAIN = 0x09;
    const uint16_t CALIBRATE_OFFSET = 0x0A;
    const uint16_t STATUS = 0x0B;
    const uint16_t STATUS_MASK = 0x0C;
    const uint16_t ALARM_ACTION = 0x0D;
    const uint16_t ALARM_CODE = 0x0E;
    const uint16_t WATCHDOG = 0x10;
    const uint16_t DEVICE_ID = 0x11;
}

class IDAC {
    private:

        
    public:
        void write_register(uint16_t reg, uint16_t value);
        void select_buck_boost(uint16_t bb_reg);    // 16 bits, bit 4=d, 3=c, 2=b, 1=a
        void config_buck_boost(uint16_t bb_reg); // [11:10] = CCLP, [9:6] = PCLMP, [5:2] = NCLMP, [1:0] = PNSEL
        void select_dac_reg(uint16_t dac_reg); // 12=CLSLD, 11=CLSLC, 10=CLSLB, 9=CLSLA, 8=CHD, 7=CHC,6=CHB, 5=CHA, 4=DSDO, 3=CREN, [2:1]=WPD, 0=WEN
        void config_dac_reg(uint16_t dac_reg); // [15:14]=SCLIM, 13=HTEN, 12=OTEN, [11:8]=SRCLK_RATE, [7:5]=SR_STEP, 4=SREN, [3:0]=RANGE
        void program_dac(uint16_t data); // [15:0] dac data
        void chip_select(uint8_t enable, uint8_t select); // flags for enable chip and select chip
    };

#endif