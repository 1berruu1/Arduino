#include <Arduino.h>
#include "SenzorAer.h"

#define LED_PIN LED_BUILTIN // Pin for the built-in LED


void setup() {
    Serial.begin(9600);
}

void loop() {

    Array60 readingsA0 = readSensor(A0);
    for(int i=0; i< 60;i++){
        Serial.println(readingsA0.arr[i]);
    }

    delay(1000);
}