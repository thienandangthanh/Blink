#ifndef Blink_h
#define Blink_h

#include "Arduino.h"
class Blink {
public:
	Blink(byte LEDpin, long onTime, long offtime);
	void update();

private:
	byte LEDpin;
	long onTime;
	long offTime;
	boolean LEDstate;
	unsigned long previousMillis;
	unsigned long currentMillis = millis();
};

#endif