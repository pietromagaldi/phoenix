#include <motors.hpp>
#include <rc.hpp>

void control_setup(){
    Serial.begin(115200);
    pinMode(PIN_CANAL1, INPUT); 
    pinMode(PIN_CANAL2, INPUT); 
}

void run_remote_control(){

    Serial.println("Remote control selected");
    
    // recebe sinal do pino
    int16_t canal1 = pulseIn(PIN_CANAL1, HIGH, 30000); 
    int16_t canal2 = pulseIn(PIN_CANAL2, HIGH, 30000); 
    
    if (canal1 == 0 || canal2 == 0){ 
        motor_control(LEFT, 0); 
        motor_control(RIGHT, 0); 
        Serial.println("Desconectado"); 
    return; 
    } 
    
    // filtragem de sinais
    if(canal1<REFERENCIA+DEADZONE && canal1>REFERENCIA-DEADZONE){ 
        canal1 = REFERENCIA; 
    } 
    
    if(canal2<REFERENCIA+DEADZONE && canal2>REFERENCIA-DEADZONE){ 
        canal2 = REFERENCIA; 
    } 
    
    // mapeia o intervalo [-255, 255] pra [1000, 2000]
    canal1 = map(canal1, 1000, 2000, -255, 255); 
    canal2 = map(canal2, 1000, 2000, -255, 255); 
    
    // mixagem
    int16_t motor_left = canal1 - canal2; 
    int16_t motor_right = canal1 + canal2; 
    
    motor_control(LEFT, motor_left); 
    motor_control(RIGHT, motor_right); 
    
    Serial.print(motor_left); 
    Serial.print("\t"); 
    Serial.println(motor_right); 
}