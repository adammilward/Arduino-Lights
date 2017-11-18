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

    enum Mode {NORMAL, DEBUG_};
    Mode mode = DEBUG_;

    static SoftwareSerial BT;
    void outLn(String);
    void outWd(String);
    void outLn(char);
    void outWd(char);
    void out(String);
    void out(String, String);
    void out(String, int);
    void out(String, String, String);
    void debug(String);
    bool actionSerial(String);

};

#endif /* SERIALCOM_H_ */
