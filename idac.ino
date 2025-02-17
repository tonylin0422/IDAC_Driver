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
}