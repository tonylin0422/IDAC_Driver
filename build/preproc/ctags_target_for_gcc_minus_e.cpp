# 1 "/Users/tonylin/Desktop/idac/idac.ino"
# 2 "/Users/tonylin/Desktop/idac/idac.ino" 2
# 3 "/Users/tonylin/Desktop/idac/idac.ino" 2

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
