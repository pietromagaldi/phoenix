#include <Arduino.h>
#include "motors.hpp"
#include "rc.hpp"
#include "led.hpp"

void setup() {
  analogWriteFrequency(50000); 
  Serial.begin(115200);
  motor_setup();
  control_setup();
  led_setup();
}

void loop() {
  set_led_color(LED_RGB, PINK_BOT);
  run_remote_control();
}
