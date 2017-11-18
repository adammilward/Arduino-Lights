/*
 * AnaloguePin.cpp
 *
 *  Created on: 29 Jul 2017
 *      Author: Adam Milward
 */

#include "VoltMeter.h"
#include "Arduino.h"
#include "AnaloguePin.h"

AnaloguePin::AnaloguePin() {
    pinNo = -1;
    factor = 0;
}

void AnaloguePin::set(int inPin, float conversionFactor, String inName) {
    pinNo = inPin;
    factor = conversionFactor;
    name = inName;
}

float AnaloguePin::read() {
    return analogRead(pinNo)*factor;
}


