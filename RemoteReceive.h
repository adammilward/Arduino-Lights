/*
 * RemoteReceive.h
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */

#ifndef REMOTERECEIVE_H_
#define REMOTERECEIVE_H_

class RemoteReceive {
public:
    RemoteReceive();

    static void receive(unsigned long value);

    typedef void (*Pointer)();

    static Pointer actions[2];

private:
    enum Mode {Lights, MP3};
    Mode mode;

};

#endif /* REMOTERECEIVE_H_ */
