#line 1 "/Users/tonylin/Desktop/idac/idac.ino"
#include <Arduino.h>
#include <SPI.h>

#line 4 "/Users/tonylin/Desktop/idac/idac.ino"
void setup();
#line 18 "/Users/tonylin/Desktop/idac/idac.ino"
void loop();
#line 4 "/Users/tonylin/Desktop/idac/idac.ino"
void setup() {
    // Try this first:
    Serial.begin(115200UL);

    // If above doesn't work, comment it and uncomment this:
    // Serial.begin(115200UL);
    
    while (!Serial) {
        delay(100);
        if (millis() > 5000) break;
    }
    Serial.println("Portenta H7 initialized");
}

void loop() {
    delay(1000);
}
