/*
 * SerialCom.h
 *
 *  Created on: 4 Nov 2017
 *      Author: Adam Milward
 */

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "Config.h"

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

class SerialCom {
public:
    SerialCom();

    enum Mode {NORMAL, VERBOSE};
    Mode mode = NORMAL;

    String name = "initialised";

    static SoftwareSerial BT;

    void out(String);
    void outWd(String);
    void debug(String);
    void debugWd(String);
    bool actionSerial(String*, int);
};

#endif /* SERIALCOM_H_ */