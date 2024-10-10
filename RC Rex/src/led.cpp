#include "led.hpp"
#include <FastLED.h>

CRGB leds[NUMBER_OF_LEDS];

void led_setup() {
    FastLED.addLeds<NEOPIXEL, LED_RGB_PIN>(leds, NUMBER_OF_LEDS);
    Serial.println("led ok");
}

void set_led_color(int8_t led_index, uint8_t red, uint8_t green, uint8_t blue) {
    leds[led_index] = CRGB(red, green, blue);
    FastLED.show();
}

void clear_leds() {
    FastLED.clear(true);
}

