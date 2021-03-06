#include "header.h"

int main(int argc, char* argv[]){
	
    if(daemon(0,0) == -1)
        err(1, NULL);
	  
    // targetTime in UNIX time
    time_t targetTime = 1443420000; //28th September 2015 8:00 a.m.
    int timeLeft = 0;
    int i, j;
	
    //Setup LCD screen
    hd44780 lcd(14, 15, 24, 25, 8, 7);
    lcd.init(20, 4);
    lcd.setAutoscroll(hd44780::NO_SCROLL);
    lcd.clear(); 
    
    //Define custom symbols
    uint8_t black[8] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    lcd.defChar(hd44780::CCHAR0, black);
	
    //Static text
    lcd.write("New apartment in:   ");
    moveAndClearLine(0,1,lcd);
    lcd.write(" Days  Hrs  Min  Sec");
    
    do{       
        timeLeft = printTimeLeft(lcd, targetTime);
	usleep(2e5);
    } while(timeLeft);

    //Celebrate that the countdown is finished
    lcd.clear();
    lcd.write(1,1,"      I have       ");
    lcd.write(1,2,"     !!MOVED!!     ");
    
    for (i=0;i<360000;i++){
	if (i%2){
            lcd.move( 0, 0);
            for (j=0;j<20;j++){lcd.write(hd44780::CCHAR0);}
            lcd.move( 0, 3);
            for (j=0;j<20;j++){lcd.write(hd44780::CCHAR0);}
            lcd.write( 0, 1,hd44780::CCHAR0); lcd.write(19, 1,hd44780::CCHAR0);
            lcd.write( 0, 2,hd44780::CCHAR0); lcd.write(19, 2,hd44780::CCHAR0);     
        }else{
            lcd.write( 0, 0,"                    ");
            lcd.write( 0, 3,"                    ");
            lcd.write( 0, 1," "); lcd.write(19, 1," ");
            lcd.write( 0, 2," "); lcd.write(19, 2," ");
        }
        usleep(1e5);
    }
}
