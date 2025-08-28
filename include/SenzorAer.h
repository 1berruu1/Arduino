//
// Created by crist on 26/08/2025.
//

#ifndef ARDUINO_SENZORAER_H
#define ARDUINO_SENZORAER_H

class SenzorAer{
public:
    int pinNr;

public:
//    float readSensor(int pinNr);

};
/* Struct for returning the whole array for the readSensor function
 *
 */

struct Array60{
    float arr[61];
};

// Read sensor function that will read from the analog pins which takes the pin as an argument

Array60 readSensor(int pinNr);

// Blink led function using the on board led as an indicator that it works

void finishLED(int nrBlinks);

#endif //ARDUINO_SENZORAER_H
