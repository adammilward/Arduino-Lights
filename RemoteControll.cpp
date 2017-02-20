/*
 * RemoteControll.cpp
 *
 *  Created on: 21 Jan 2017
 *      Author: Adam Milward
 */

#include "RemoteControll.h"
#include "Arduino.h"
#include "Light.h"
//#include "stdio.h"

int RemoteControll::remConInt;
Light RemoteControll::Red(10, 0.125088);
Light RemoteControll::Green(9, 0.125);
Light RemoteControll::Blue(6, 0.2);


RemoteControll::Pointer RemoteControll::actions[2] = {
        &RemoteControll::plus,
        &RemoteControll::minus,
};


typedef void (*PTR)();

PTR minusPTR = &RemoteControll::minus;

PTR lightsRemote[2] = {
		&RemoteControll::plus,
		&RemoteControll::minus
};


RemoteControll::RemoteControll() {


}

void RemoteControll::plus(){
    Red.shift(+1);
	Blue.shift(+1);
	Green.shift(+1);
	Serial.println("Pve ");
}

void RemoteControll::minus(){
	Red.shift(-1);
	Blue.shift(-1);
	Green.shift(-1);
	Serial.println("Nve ");
}


void RemoteControll::receive(unsigned long value){
    unsigned long const MP_HOLD    = 0xFFFFFF; // Hold
    unsigned long const MP_OFF     = 0xFFA25D; // off button
    unsigned long const MP_MODE    = 0xFF629D; //
    unsigned long const MP_MUTE    = 0xFFE21D; //
    unsigned long const MP_PLAY    = 0xFF22DD; //
    unsigned long const MP_BACK    = 0xFF02FD; //
    unsigned long const MP_FF      = 0xFFC23D; //
    unsigned long const MP_EQ      = 0xFFE01F; //
    unsigned long const MP_NVE     = 0xFFA857; //
    unsigned long const MP_PVE     = 0xFF906F; //
    unsigned long const MP_0       = 0xFF6897; //
    unsigned long const MP_RR      = 0xFF9867; //
    unsigned long const MP_USD     = 0xFFB04F; //
    unsigned long const MP_1       = 0xFF30CF; //
    unsigned long const MP_2       = 0xFF18E7; //
    unsigned long const MP_3       = 0xFF7A85; //
    unsigned long const MP_4       = 0xFF10EF; //
    unsigned long const MP_5       = 0xFF38C7; //
    unsigned long const MP_6       = 0xFF5AA5; //
    unsigned long const MP_7       = 0xFF42BD; //
    unsigned long const MP_8       = 0xFF4AB5; //
    unsigned long const MP_9       = 0xFF52AD; //

	switch (value) {
		case MP_HOLD : break;
		case MP_OFF  : Serial.println("Off "); break;
		case MP_MODE : Serial.println("Mode"); break;
		case MP_MUTE : Serial.println("Mute"); break;
		case MP_PLAY : Serial.println("Plat"); break;
		case MP_BACK : Serial.println("Back"); break;
		case MP_FF   : Serial.println("FF  "); break;
		case MP_EQ   : Serial.println("EQ  "); break;
		case MP_NVE  : (*actions[0])(); break;
		case MP_PVE  : (*actions[1])(); break;
		case MP_0    : Serial.println("0   "); break;
		case MP_RR   : Serial.println("RR  "); break;
		case MP_USD  : Serial.println("USD "); break;
		case MP_1    : Serial.println("1   "); break;
		case MP_2    : Serial.println("2   "); break;
		case MP_3    : Serial.println("3   "); break;
		case MP_4    : Serial.println("4   "); break;
		case MP_5    : Serial.println("5   "); break;
		case MP_6    : Serial.println("6   "); break;
		case MP_7    : Serial.println("7   "); break;
		case MP_8    : Serial.println("8   "); break;
		case MP_9    : Serial.println("9   "); break;
		default 	 : Serial.println(value, HEX); break;   // display it on serial monitor in hexadecimal
    }

}
