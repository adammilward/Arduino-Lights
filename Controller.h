/*
 * RemoteReceive.h
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */
#include "Arduino.h"
#include "LightCtr.h"

#ifndef REMOTERECEIVE_H_
#define REMOTERECEIVE_H_

class Controller {
public:
    Controller();

    const unsigned long int IR_HOLD = 0xFFFFFFFF;
    LightCtr LightRemote;
    void receive(unsigned long value);

private:
    enum Mode {LIGHTS, MP3};
    Mode mode;
    unsigned long int storedValue;
    void decode(unsigned long);

};
#endif /* REMOTERECEIVE_H_ */
