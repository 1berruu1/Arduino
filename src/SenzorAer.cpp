#include <SenzorAer.h>
#include <Arduino.h>

/*
    * Function to read analog values from four sensors connected to A0, A1, A2, and A3 pins.
    * The function runs for 60 seconds, checking if any sensor has a value greater than 0.
    * If a sensor value is greater than 0, it reads the values from all four.
 */


//TODO validari si error handling


Array60 readSensor(int pinNr) {
    unsigned long startTime = millis();
    Array60 allReadings;
//    float allReadings[61] = {};
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
            break;
        }
    }
    allReadings.arr[60] = totalReadings/60;
    return allReadings;
    }
