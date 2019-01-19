#include <Arduino.h>
#include "Led.cpp"
const uint8_t PIN_I_LED = 7;
const uint8_t PIN_HEART_LED = 5;
const uint8_t PIN_U_LED = 2;

void setup() {

    Led *lampLed = new Led(PIN_I_LED, 0);
    Led *lampLed = new Led(PIN_HEART_LED, 0);
    Led *lampLed = new Led(PIN_U_LED, 0);

}

void loop() {

}