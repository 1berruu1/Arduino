#include "SenzorAer.h"
#include <Arduino.h>

/*
    * Function to read analog values from four sensors connected to A0, A1, A2, and A3 pins.
    * The function runs for 60 seconds, checking if any sensor has a value greater than 0.
    * If a sensor value is greater than 0, it reads the values from all four.
 */

//TODO validari si error handling

// Trebuie un senzor pentru a vedea ce valori trebuie bagate pentru error handling
// functia analogRead returneaza un int asa ca in functie de ce valori returneaza senzorul se face error handling

Array60 readSensor(int pinNr) {
    unsigned long startTime = millis();
    Array60 allReadings;
    float totalReadings = 0;
    byte arrayIndex = 0;
    while (millis() - startTime < 60000) {
        float AnalogRead = analogRead(pinNr);
        if (AnalogRead != 0){
            allReadings.arr[arrayIndex] = AnalogRead;
            totalReadings += allReadings.arr[arrayIndex];
            arrayIndex++;
            delay(1000);
        }
        else{
            Serial.print((int) "Erroare senzor: ", pinNr);
            delay(1000);
            break;
        }
    }
    float averageValue = totalReadings/60;
    allReadings.arr[arrayIndex] = averageValue;
    Serial.println("Average: ");
    Serial.println(allReadings.arr[60]);
    Serial.println("=======");
    return allReadings;
    }


void finishLED(int nr){
    for(int i=0; i < nr; i++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
    }
}
