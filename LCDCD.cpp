#include "header.h"

int main(int argc, char* argv[]){
	/*
	if(daemon(0,0) == -1)
		err(1, NULL);
	*/
	time_t targetTime = 1439190000;
	
    //Setup LCD screen
	hd44780 lcd(14, 15, 24, 25, 8, 7);
   	lcd.init(20, 4);
    lcd.setAutoscroll(hd44780::NO_SCROLL);
    lcd.clear(); 
    
    //Define custom symbols
    uint8_t black[8]        = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    lcd.defChar( hd44780::CCHAR0, black );
    
    //Turn on backlighting
    rpihw::gpio &io = rpihw::gpio::get();
	io.setup(23, rpihw::OUTPUT);
	io.write(23, rpihw::HIGH); 
	
    //Static text
    lcd.write("Coffee bar opens in:");
    moveAndClearLine(0,1,lcd);
	lcd.write(" Days  Hrs  Min  Sec");
    
	while (true){       
        printTimeLeft(lcd, targetTime);
		usleep(2000);
	}	
	return 0;
}
