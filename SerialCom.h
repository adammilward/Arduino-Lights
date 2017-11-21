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
    Mode mode = VERBOSE;

    String name = "initialised";

    static SoftwareSerial BT;
    void outLn(String);
    void outLn(float);
    void outLn(int);
    void outWd(String);
    void outWd(float);
    void outWd(int);

    void out(String);
    void out(String, String);
    void out(String, int);
    void out(String, float);
    void out(String, int, String, float);

    void debug(String);
    bool actionSerial(String);
    void setName(String);
    void sayName();

};

#endif /* SERIALCOM_H_ */
