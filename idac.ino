#include <Arduino.h>
#include <SPI.h>
#include "idac.h"

IDAC IDAC;  

void setup() {
    // Try this first:
    Serial.begin(115200UL);
    
    while (!Serial) {
        delay(100);
        if (millis() > 5000) break;
    }
    Serial.println("Portenta H7 initialized");

    // SPI Setup
    SPI.begin();
}

void loop() {
    Serial.println("connected");
    /* TEST ************************************************
    IDAC.chip_select(1, 0);
    delay(1000);
    IDAC.write_register(0x06, 0x0F);
    delay(1000);
    IDAC.chip_select(0, 1);
    delay(1000);
    */
    delay(3000);
    IDAC.chip_select(1, 0);
    IDAC.select_buck_boost(0x000F); // Select all four buck-boost converters
    delay(1000);

    IDAC.config_buck_boost(0x0000); // Full-tracking mode (current output only), enable +/- rails
    delay(1000);

    IDAC.select_dac_reg(0x01F0); // Select all 4 channels, disable SDO (daisy-chain), disable watchdog timer (default setting)
    delay(1000);

    IDAC.config_dac_reg(0x1005); // Enable DAC output, 0-20 mA
    delay(1000);
    
    IDAC.program_dac(0x0CCD); // 1 mA output (3277, current = 20mA * (CODE / (2^16)))
    delay(1000);

    // SPI.end();
}
