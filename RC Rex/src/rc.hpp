#include <Arduino.h>

#define PIN_CANAL1 40 // rodinha 
#define PIN_CANAL2 47 // gatilho 
#define REFERENCIA 1500
#define DEADZONE 20

void control_setup();
void run_remote_control();