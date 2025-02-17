#include "idac.h"
#include <SPI.h>
#include <Arduino.h>

SPISettings mySettings(25000000, MSBFIRST, SPI_MODE1); // Settings of SPI @ 25 MHz, MSB first, mode 1)

void IDAC :: chip_select(uint8_t enable, uint8_t select) {  // set enable low to disable both DACs
    if (enable) {
        digitalWrite(ENABLE_PIN, LOW);        // Active low CS on DAC
    }
    else {
        digitalWrite(ENABLE_PIN, HIGH);
    }

    if (select) {// select = 0 for DAC 1, select = 1 for DAC 2
        digitalWrite(CHIP_SELECT_OUTPUT, LOW);  
    }
    else {
        digitalWrite(CHIP_SELECT_OUTPUT, HIGH);
    }
}

void IDAC :: write_register(uint16_t reg, uint16_t value) {
    SPI.beginTransaction(mySettings);

    // use for debug, can comment out
    Serial.println("beginning transactiion");
    delay(1000); 

    // First byte: register address with R/W bit = 0
    SPI.transfer(reg & 0x7F);

    Serial.print("transferring to register 0x");
    Serial.println(reg & 0x7F, HEX);  // Print in hexadecimal format

    // Transfer 16-bit data value
    SPI.transfer16(value);

    Serial.print("transferring value 0x");
    Serial.println(value, HEX);  // Print in hexadecimal format

    SPI.endTransaction();
}
