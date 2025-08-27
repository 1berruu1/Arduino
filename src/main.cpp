#include <Arduino.h>
#include "SenzorAer.h"

#define LED_PIN LED_BUILTIN // Pin for the built-in LED


void setup() {
    Serial.begin(9600);
}

void loop() {


    readSensor(A0);
    readSensor(A1);
    readSensor(A2);
    readSensor(A3);




    delay(1000);
}