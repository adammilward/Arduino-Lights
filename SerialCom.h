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

    bool isNum(String*);
    void out(String);
    void outWd(String);
    bool actionSerial(String*, int);

private:


};

#endif /* SERIALCOM_H_ */
