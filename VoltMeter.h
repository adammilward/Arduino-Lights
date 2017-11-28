/*
 * VoltMeter.h
 *
 *  Created on: 18 Nov 2017
 *      Author: Adam Milward
 */

#include "Arduino.h"
#include "AnaloguePin.h"
#include "Config.h"
#include "SerialCom.h"

#ifndef VOLTMETER_H_
#define VOLTMETER_H_

class VoltMeter {
public:
    VoltMeter();

    AnaloguePin aPin0;
    AnaloguePin aPin1;
    AnaloguePin aPin2;
    AnaloguePin aPin3;
    AnaloguePin aPin4;
    AnaloguePin* allPinsPtr[5] = {&aPin0, &aPin1, &aPin2, &aPin3, &aPin4};

    String getVoltage(int pinNumber);
};

#endif /* VOLTMETER_H_ */
