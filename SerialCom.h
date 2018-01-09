/*
 * SerialCom.h
 *
 *  Created on: 4 Nov 2017
 *      Author: Adam Milward
 */

#include "Arduino.h"
#include "Config.h"

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

class SerialCom {
public:
    SerialCom();

    enum Mode {NORMAL, VERBOSE};
    Mode mode = NORMAL;

    //static SoftwareSerial BT;

    bool isNum(String*);
    bool actionSerial(String*, int);


    void out(unsigned int);
    void outWd(unsigned int);
    void out(int);
    void outWd(int);
    void out(float);
    void outWd(float);
    void out(byte);
    void outWd(byte);
    void out(String);
    void outWd(String);

private:


};

#endif /* SERIALCOM_H_ */
