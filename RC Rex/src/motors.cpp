#include "motors.hpp"
//KFC ESTEVE AQUI
void motor_setup() {
    analogWriteFrequency(50000);
    pinMode(RIGHT_MOTOR_1, OUTPUT);
    pinMode(RIGHT_MOTOR_2, OUTPUT);
    pinMode(LEFT_MOTOR_1, OUTPUT);
    pinMode(LEFT_MOTOR_2, OUTPUT);
}

void motor_control(Side_t side, int16_t speed) {
    if (speed > MAX_PWR){
       speed = MAX_PWR;
    }
    else if (speed < -MAX_PWR){
       speed = -MAX_PWR;
    }
    switch (side){
        case RIGHT:
            if (speed > 0) {
                analogWrite(RIGHT_MOTOR_2, 255-speed);
                analogWrite(RIGHT_MOTOR_1, 255);
            }
            else if (speed == 0) {
                analogWrite(RIGHT_MOTOR_1, 0);
                analogWrite(RIGHT_MOTOR_2, 0);
            } else {
                analogWrite(RIGHT_MOTOR_2, 255);
                analogWrite(RIGHT_MOTOR_1, 255+speed);
            }
            break;

        case LEFT:
            if (speed > 0) {
                analogWrite(LEFT_MOTOR_2, 255-speed);
                analogWrite(LEFT_MOTOR_1, 255);
            } else if (speed == 0){
                analogWrite(LEFT_MOTOR_2, 0);
                analogWrite(LEFT_MOTOR_1, 0);
            }
            else {
                analogWrite(LEFT_MOTOR_2, 255);
                analogWrite(LEFT_MOTOR_1, 255+speed);
            }
            break;

        default:
            break;
    }
}