#include <Arduino.h>
#include "motors.hpp"
#include "rc.hpp"

void setup() {
  analogWriteFrequency(50000); 
  Serial.begin(115200);
  motor_setup();
  control_setup();  
}

void loop() {
  run_remote_control();
}
