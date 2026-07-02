#include "Display.h"
#include <Arduino.h>

void Display::begin()
{
    Serial.println("Display module initialized");
}

void Display::update()
{
    // Display update logic will be added later.
}

void Display::render()
{
    Serial.println("Display render called");
}