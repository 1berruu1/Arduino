#include <Arduino.h>
#include "SenzorAer.h"

void setup() {

    pinMode(LED_BUILTIN,OUTPUT);

    Serial.begin(9600);

    Array60 readingsA0;
//    Array60 readingsA1;
//    Array60 readingsA2;

    for (int i = 0; i < 60; i++) {
        readingsA0.arr[i] = analogRead(A0);
//        readingsA1.arr[i] = analogRead(A1);
        delay(1000);
    }

    for (int i = 0; i < 60; i++) {
        Serial.print(readingsA0.arr[i]);
        Serial.print(",");
    }

    Serial.println();
//
//    for (int i = 0; i < 60; i++) {
//        Serial.print(readingsA1.arr[i]);
//        Serial.print(",");
//    }

//    Serial.println();
//
//    for (int i = 0; i < 60; i++) {
//        Serial.print(readingsA2.arr[i]);
//        Serial.print(",");
//    }


    finishLED(3);
}




void loop() {



}