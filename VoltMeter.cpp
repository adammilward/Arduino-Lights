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
    return (configMode) ?
            analogRead(pinNumber):
            analogRead(pinNumber)*convFactor[pinNumber] ;
}

