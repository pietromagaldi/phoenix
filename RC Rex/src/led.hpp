#pragma once
#include <FastLED.h>

#define LED_RGB_PIN 8
#define NUMBER_OF_LEDS 1

#define RED             255, 0, 0
#define DARK_ORANGE     254, 23, 0  
#define LIGHT_ORANGE    255, 48, 0
#define YELLOW          255, 115, 0
#define LIME_GREEN      163, 251, 0
#define GREEN           0, 230,   0
#define EMERALD         0, 250, 40
#define CIAN            0, 255, 255
#define LIGHT_BLUE      159, 197, 232
#define BLUE            0,   0, 255
#define PURPLE          137,   0, 255
#define LIGHT_PURPLE    182,   154, 255
#define PINK_BOT            240,   47, 103
#define LIGHT_PINK      255,   163, 218
#define SCARLET         152, 0, 0
#define WHITE           200, 200, 200

#define LED_RGB 0

void led_setup();
void set_led_color(int8_t led_index, uint8_t red, uint8_t green, uint8_t blue);
void clear_leds();

uint8_t last_color_led();