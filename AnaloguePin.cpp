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

void AnaloguePin::set(byte inPin, float conversionFactor) {
    pinNo = inPin;
    factor = conversionFactor;
}

float AnaloguePin::read() {
    return analogRead(pinNo)*factor;
}


