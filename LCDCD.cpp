#include "header.h"

int main(int argc, char* argv[]){
	/*
	if(daemon(0,0) == -1)
		err(1, NULL);
	*/
	time_t targetTime = 1439190000;
	
	hd44780 lcd(14, 15, 24, 25, 8, 7);
   	lcd.init(20, 4);
    lcd.setAutoscroll(hd44780::NO_SCROLL);
    
	lcd.clear();
    rpihw::gpio &io = rpihw::gpio::get();
	io.setup(23, rpihw::OUTPUT);
	io.write(23, rpihw::HIGH); 
	
	lcd.move(0,1);
	lcd.write("LCD Countdown ver. 0.1.0");
    sleep(5);
    lcd.clear();
    lcd.move(0,0);
	lcd.write("Coffee countdown");
    lcd.move(0,0);
    lcd.write("Coffee bar opens in:");
    
	while (true){
        moveAndClearLine(0,1,lcd);
		lcd.write("");
        printTimeLeft(lcd, targetTime);
		sleep(1);
	}	
	return 0;
}
