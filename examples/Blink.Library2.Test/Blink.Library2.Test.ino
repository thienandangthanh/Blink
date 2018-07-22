//Blink.Library2.Test.ino
#include <Blink.h>
Blink led13(13, 100, 100);
Blink led12(12);
Blink led11(11);
Blink led10(10);
void setup() {
	// put your setup code here, to run once
}

void loop() {
	// put your main code here, to run repeatedly
	led13.update();
	led12.on();
	led12.off();
	led11.on(1000);
	led11.off(500);
	led10.update(1000, 500);
}
