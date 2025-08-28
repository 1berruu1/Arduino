#include <Arduino.h>
#include "SenzorAer.h"

void setup() {

    pinMode(LED_BUILTIN,OUTPUT);

    Serial.begin(9600);
    Array60 readingsA0 = readSensor(A0);
    for(int i=0; i< 60;i++){
        Serial.println("Sensor reading: ");
        Serial.println(i);
        Serial.println(readingsA0.arr[i]);
    }
    Serial.println("Done printing");

    finishLED(3);
}



void loop() {



}