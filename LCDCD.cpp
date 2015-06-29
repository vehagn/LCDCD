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
	
    lcd.write("Coffee bar opens in:");
    moveAndClearLine(0,2,lcd);
	lcd.write("Days Hours  Min  Sec");
    
	while (true){       
        printTimeLeft(lcd, targetTime);
		sleep(1);
	}	
	return 0;
}
