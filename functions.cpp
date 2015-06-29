#include "header.h"

void moveAndClearLine(int i, int j, hd44780 &lcd){
	lcd.move(i,j);
	lcd.write("                    ");
	lcd.move(i,j);
}
char getch(){
        struct termios old_tio, new_tio;
        char buf = 0;
        
        tcgetattr(STDIN_FILENO,&old_tio);
        new_tio=old_tio;
        new_tio.c_lflag &= ~(ICANON|ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

        if (read(0, &buf, 1) < 0)
                perror ("read()");

        tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
        return (buf);     
	
}
/*
void getLine(char buf[], hd44780 &lcd){
	char c;
	int i = 0;
	lcd.setCursor(hd44780::CURSOR_BLINKING);
	uint8_t startx = lcd.getXCursor();
	uint8_t starty = lcd.getYCursor();	
	uint8_t xpos;
	do{
		xpos = lcd.getXCursor();
		c = getch();
		if ((int)c == 127){
			if (i > 0){
				write(1, "\b \b", 3);
				i--;
			}
			xpos = (xpos <= startx)?(startx):(xpos-1);
			lcd.move(xpos,starty);
			lcd.write(' ');
			lcd.move(xpos,starty);
		}else{
			buf[(i++)%128] = c;
			lcd.write(c);
			write(1, &c, 1);
		}
	}while (c != '\n');
	buf[i%128] = '\0';
	lcd.setCursor(hd44780::NO_CURSOR);
}
*/
void printfl(string str, hd44780 &lcd){
	printf("%s\n", str.c_str());
	lcd.write(str);
}

char* str2char(string s){
	char *c=new char[s.size()+1];
	c[s.size()]=0;
	memcpy(c,s.c_str(),s.size());

	return c;
}

void printTime(hd44780 &lcd){
	time_t now;
	struct tm timeinfo;
	char buf [64];
	
	time(&now);
	timeinfo = *localtime(&now);
	strftime(buf,64,"%a %d %b %H:%M:%S \nWeek %V Year %G",&timeinfo);
	
	lcd.clear();
	lcd.move(0,1);
	printfl("Timestamp:", lcd);
	lcd.move(0,2);
	printfl(buf, lcd);	
}

void printTimeLeft(hd44780 &lcd, time_t targetTime){
	time_t now;
	struct tm timeinfo;
	char buf [64];
	
	time(&now);
    difftime(targetTime, now);
	timeinfo = *localtime(&now);
	strftime(buf,64,"%a %d %b %H:%M:%S \nWeek %V Year %G",&timeinfo);
	
	lcd.clear();
	lcd.move(0,1);
	printfl("Timestamp:", lcd);
	lcd.move(0,2);
	printfl(buf, lcd);	
}