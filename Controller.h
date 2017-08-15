/*
 * RemoteReceive.h
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */
#include "Arduino.h"
#include "LightCtr.h"
#include "SoftwareSerial.h"

#ifndef REMOTERECEIVE_H_
#define REMOTERECEIVE_H_

class Controller {
public:
    Controller();
    const unsigned long int IR_HOLD = 0xFFFFFFFF;
    LightCtr LightRemote;
    void irReceive(unsigned long value);
    void serialReceive(String data);
    static SoftwareSerial BTs;

private:
    enum Mode {LIGHTS, MP3};
    Mode mode;
    unsigned long int storedValue = 0;  // for sending when hold is pressed
    void decode(unsigned long, int);

};
#endif /* REMOTERECEIVE_H_ */
