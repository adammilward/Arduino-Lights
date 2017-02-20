/*
 * RemoteControll.h
 *
 *  Created on: 21 Jan 2017
 *      Author: Adam Milward
 */

#include "Light.h"
#include "Arduino.h"


#ifndef REMOTECONTROLL_H_
#define REMOTECONTROLL_H_




class RemoteControll {
public:
	RemoteControll();
	static void receive(unsigned long value);

	static void doSomething();

	static int remConInt;

	static Light Red;
	static Light Blue;
	static Light Green;




	static void plus();
	static void minus();

	typedef void (*Pointer)();

	static Pointer actions[2];

private:
};

#endif /* REMOTECONTROLL_H_ */
