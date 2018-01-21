/*
 * VoltMeter.cpp
 *
 *  Created on: 18 Nov 2017
 *      Author: Adam Milward
 */

#include "VoltMeter.h"

VoltMeter::VoltMeter() {}

void VoltMeter::toggleConfigMode() {
    configMode = (configMode == OFF) ? ON : OFF;
}

float VoltMeter::getVoltage(int pinNumber) {
    delay(10);
    analogRead(pinNumber);
    delay(10);
    return (configMode) ?
            analogRead(pinNumber):
            analogRead(pinNumber)*convFactor[pinNumber] ;
}

void VoltMeter::setPin(int pin, float newValue) {
    float analogValue = 0;
    analogRead(pin);
    delay(10);
    int i = 3;
    while (i--) {
        analogValue += analogRead(pin);
        delay(10);
    }
    analogValue /= 3;
    convFactor[pin] = newValue/analogValue;
}
