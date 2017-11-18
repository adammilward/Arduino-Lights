/*
 * VoltMeter.cpp
 *
 *  Created on: 18 Nov 2017
 *      Author: Adam Milward
 */

#include "VoltMeter.h"

VoltMeter::VoltMeter() {
    aPin0.set(A0, CONFIG::A0_FACTOR, "Solar Panels");
    aPin1.set(A1, CONFIG::A1_FACTOR, "Consumer Unit");
    aPin2.set(A2, CONFIG::A2_FACTOR, "Leisure Battery");
    aPin3.set(A3, CONFIG::A3_FACTOR, "Van Battey");
    aPin4.set(A4, CONFIG::A4_FACTOR, "Spare");

}

String VoltMeter::getName(int pinNumber) {
    return allPinsPtr[pinNumber]->name;

}

String VoltMeter::getVoltage(int pinNumber) {
    return String(allPinsPtr[pinNumber]->read());
}

