/*
 * VoltMeter.cpp
 *
 *  Created on: 18 Nov 2017
 *      Author: Adam Milward
 */

#include "VoltMeter.h"

VoltMeter::VoltMeter() {
    aPin0.set(A0, CONFIG::A0_FACTOR);
    aPin1.set(A1, CONFIG::A1_FACTOR);
    aPin2.set(A2, CONFIG::A2_FACTOR);
    aPin3.set(A3, CONFIG::A3_FACTOR);
    aPin4.set(A4, CONFIG::A4_FACTOR);

}

float VoltMeter::getVoltage(int pinNumber) {
    return allPinsPtr[pinNumber]->read();
}

