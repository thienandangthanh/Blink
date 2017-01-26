#include "Arduino.h"
#include "Blink.h"

//<<constructor>>
Blink::Blink(byte _LEDpin, long _onTime, long _offTime)
{
	LEDpin = _LEDpin;
	pinMode(LEDpin, OUTPUT);
	onTime = _onTime;
	offTime = _offTime;
	LEDstate = LOW;
	previousMillis = 0;
}
Blink::Blink(byte _LEDpin)
{
	LEDpin = _LEDpin;
	pinMode(LEDpin, OUTPUT);
	LEDstate = LOW;
	previousMillis = 0;
}
//<<destructor>>
//no thing to destruct
void Blink::update()
{
	unsigned long currentMillis = millis();
	if ((LEDstate == HIGH) && (currentMillis - previousMillis >= onTime))
	{
		LEDstate = LOW;  // Turn it off
		previousMillis = currentMillis;  // Remember the time
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
	else if ((LEDstate == LOW) && (currentMillis - previousMillis >= offTime))
	{
		LEDstate = HIGH;  // turn it on
		previousMillis = currentMillis;   // Remember the time
		digitalWrite(LEDpin, LEDstate);   // Update the actual LED
	}
}
void Blink::update(long _onTime, long _offTime)
{
	onTime = _onTime;
	offTime = _offTime;
	unsigned long currentMillis = millis();
	if ((LEDstate == HIGH) && (currentMillis - previousMillis >= onTime))
	{
		LEDstate = LOW;  // Turn it off
		previousMillis = currentMillis;  // Remember the time
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
	else if ((LEDstate == LOW) && (currentMillis - previousMillis >= offTime))
	{
		LEDstate = HIGH;  // turn it on
		previousMillis = currentMillis;   // Remember the time
		digitalWrite(LEDpin, LEDstate);   // Update the actual LED
	}
}
void Blink::on()
{
	LEDstate = HIGH;
	digitalWrite(LEDpin, LEDstate);  // Update the actual LED
}
void Blink::on(long _onTime)
{
	onTime = _onTime;
	unsigned long currentMillis = millis();
	if ((LEDstate == LOW) && (currentMillis - previousMillis <= onTime))
	{
		LEDstate = HIGH;  // Turn it on
		previousMillis = currentMillis;  // Remember the time
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
	else
	{
		LEDstate = LOW;
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
}
void Blink::off()
{
	LEDstate = LOW;
	digitalWrite(LEDpin, LEDstate);  // Update the actual LED
}
void Blink::off(long _offTime)
{
	offTime = _offTime;
	unsigned long currentMillis = millis();
	if ((LEDstate == LOW) && (currentMillis - previousMillis <= offTime))
	{
		LEDstate = LOW;  // Turn it off
		previousMillis = currentMillis;  // Remember the time
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
	else
	{
		LEDstate = HIGH;
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
}