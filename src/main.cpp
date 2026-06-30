#include <Arduino.h>

void setup() {
    Serial.begin(115200);

    Serial.println();
    Serial.println("==============================");
    Serial.println(" AquariumController");
    Serial.println(" PlatformIO test");
    Serial.println("==============================");
}

void loop(){
    static uint32_t counter = 0;

    Serial.print("Loop: ");
    Serial.println(counter++);

    delay(1000);
}