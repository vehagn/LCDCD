#include "header.h"

int main(int argc, char* argv[]){
	/*
	if(daemon(0,0) == -1)
		err(1, NULL);
	*/
	time_t targetTime = 1339190000;//1439190000;
    int timeLeft = 0;
    int i;
    int j;
	
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
    
	do{       
        timeLeft = printTimeLeft(lcd, targetTime);
		sleep(1);
	} while(timeLeft);
    
    lcd.write(1,1,"The coffee bar is: ");
    lcd.write(1,2,"      !OPEN!       ");
    
	for (i=0;i<360000;i++){
    if (i%2){
        lcd.move( 0, 0);
        for (j=0;j<20;j++){lcd.write(hd44780::CCHAR0);}
        lcd.write( 0, 1,hd44780::CCHAR0); lcd.write(19, 1,hd44780::CCHAR0);
        lcd.write( 0, 2,hd44780::CCHAR0); lcd.write(19, 2,hd44780::CCHAR0);
        lcd.move( 0, 3);
        for (j=0;j<20;j++){lcd.write(hd44780::CCHAR0);}
    }
    else{
        lcd.write( 0, 0,"                    ");
        lcd.write( 0, 1," ");
        lcd.write(19, 1," ");
        lcd.write( 0, 0,"                    ");
    }  
    usleep(50000);
    }
}
