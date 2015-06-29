#include "header.h"

int main(int argc, char* argv[]){
	/*
	if(daemon(0,0) == -1)
		err(1, NULL);
	*/
	time_t currentTime = 0;
	time_t targetTime = 1439190000;
	
	localtime(&currentTime);

	struct tm * timeinfo;
	
	hd44780 lcd(14, 15, 24, 25, 8, 7);
   	lcd.init(20, 4);
	lcd.clear();
	
	lcd.move(0,1);
	lcd.write("LCD Countdown ver. 0.1.0");
    sleep(1);
    lcd.clear();
    lcd.move(0,0);
	lcd.write("Coffee countdown");
    lcd.move(0,1);
    lcd.write("Coffee bar opens in:");
    
	while (true){
        moveAndClearLine(0,1,lcd);
		lcd.write("");
        
		usleep(650);
	}	
	return 0;
}
