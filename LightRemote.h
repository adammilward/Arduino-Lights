/*
 * LightsRemote.h
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */



#ifndef LIGHTREMOTE_H_
#define LIGHTREMOTE_H_



class LightRemote{

private:
	static void decode(unsigned long value);

public:
	enum lightMode {     // declare the enum for setting LED brightness
		WHITE, RED, GREEN, BLUE, FADE
	};

	LightRemote(); // Constructor
	static void timer();
	static void receive(unsigned long value);
	static void print();
};
#endif /* LIGHTREMOTE_H_ */
