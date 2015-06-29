/* Standard C++ headers */
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <err.h>


/* Rpi-hw headers */
#include <rpi-hw.hpp>
#include <rpi-hw/utils.hpp>
#include <rpi-hw/time.hpp>
#include <rpi-hw/gpio.hpp>
#include <rpi-hw/display/hd44780.hpp>

using namespace std;
using namespace rpihw::iface;
using namespace rpihw::display;
using namespace rpihw::utils;

//Functions
void moveAndClearLine(int, int, hd44780&);
char getch();
//void getLine(char[], hd44780&);
void printfl(string, hd44780&);
char* str2char(string);

void printTime(hd44780&);
int printTimeLeft(hd44780&, time_t);