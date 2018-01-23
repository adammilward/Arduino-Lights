/*
 * VoltMeter.h
 *
 *  Created on: 18 Nov 2017
 *      Author: Adam Milward
 */

#include "Config.h"

#ifndef VOLTMETER_H_
#define VOLTMETER_H_

class VoltMeter {
public:
    VoltMeter();

    enum ConfigMode {OFF = 0, ON = 1};
    ConfigMode configMode = OFF;

    static const byte numberOfPins = 5;
    float convFactor[numberOfPins] = {
        CONFIG::A0_FACTOR,
        CONFIG::A1_FACTOR,
        CONFIG::A2_FACTOR,
        CONFIG::A3_FACTOR,
        CONFIG::A4_FACTOR
    };

    void toggleConfigMode();
    float getVoltage(int pinNumber);
    void setPin(int, float);
    void saveCalibration();
    void retrieveCalibration();
    float getCalibration(int);
};


#endif /* VOLTMETER_H_ */
