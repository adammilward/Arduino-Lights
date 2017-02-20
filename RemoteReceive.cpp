/*
 * RemoteReceive.cpp
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */

#include "RemoteReceive.h"
#include "Arduino.h"



RemoteReceive::RemoteReceive() {
    mode = Lights;
}

void RemoteReceive::receive(unsigned long value){
    Serial.println(value, HEX);

}
