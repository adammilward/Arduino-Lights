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
    unsigned long int storedValue = 0;  // for sending when hold is pressed
    void decode(unsigned long, int);

};
#endif /* REMOTERECEIVE_H_ */
