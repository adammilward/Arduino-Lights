/*
 * Config.h
 *
 *  Created on: 11 Mar 2017
 *      Author: Adam Milward
 */

#ifndef CONFIG_H_
#define CONFIG_H_
class CONFIG {
public:
    static const int DELAY_MIN = 1;
    static const int DELAY_MAX = 256;
    /* Chineese Uno */
    static const int RED_PIN = 10;
    static const int GREEN_PIN = 9;
    static const int BLUE_PIN = 6;
    static const int IREC_PIN = 12;

    /* Mega
    static const int RED_PIN = 10;
    static const int GREEN_PIN = 9;
    static const int BLUE_PIN = 6;
    static const int IREC_PIN = 12;
     */
};
#endif /* CONFIG_H_ */
