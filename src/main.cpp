#include <Arduino.h>
#include <Version.h>

void setup() {
    Serial.begin(115200);

    Serial.println();
    Serial.println("==============================");
    Serial.println(Version::Name);
    Serial.println("Version: ");
    Serial.println(Version::String);
    Serial.println("==============================");
}

void loop(){
    static uint32_t counter = 0;

    Serial.print("Loop: ");
    Serial.println(counter++);

    delay(1000);
}