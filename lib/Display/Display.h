#pragma
#include <Adafruit_SH110X.h>

class Display {
    public:
        void begin();
        void update();
        void render();
        
    private:
    Adafruit_SH1106G oled = Adafruit_SH1106G(128, 64, &Wire, -1);
};