#include <Romi32U4.h>
#include "ultrasonic.h"

void Ultrasonic::init(void){
    pinMode(trig_pin, OUTPUT); //specifies the function of trig_pin
    pinMode(echo_pin, INPUT);  //specifies the function of echo_pin
}

float Ultrasonic::readData(void){
    
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  float distance = (pulseIn(echo_pin, HIGH) / 58);  //converts the pulse length to cm
  
  return distance;   // returns distance in cm
}

//print out the measurement from the ultrasonic
void Ultrasonic::printData(void){
    Serial.println(readData());
}
