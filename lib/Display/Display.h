#pragma
#include <Wire.h>
#include <Adafruit_SH110X.h>

#include "DisplayData.h"

class Display {
    public:
        void begin();
        void update();
        void render(const DisplayData& data);
        
    private:
    Adafruit_SH1106G oled = Adafruit_SH1106G(128, 64, &Wire, -1);
};