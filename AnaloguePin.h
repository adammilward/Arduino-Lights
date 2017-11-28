/*
 * AnaloguePin.h
 *
 *  Created on: 29 Jul 2017
 *      Author: Adam Milward
 */

#ifndef ANALOGUEPIN_H_
#define ANALOGUEPIN_H_



class AnaloguePin {
public:
    AnaloguePin();
    int pinNo;
    float factor;
    float read();
    void set(int, float);
    // sets the conversion factor an pin number

private:

};

#endif /* ANALOGUEPIN_H_ */
