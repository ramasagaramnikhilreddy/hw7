
/*
* This application controls GPIO pins on a BeagleBone board.
* It sets up an output pin (p9.12) and an input pin (p8.16) using the MYGPIO class.
* The program sets the output pin (p9.12) high for 3 seconds, then sets it low and prints its value.
* It also reads the value of the input pin (p8.16) and prints it.
*
* Command-line arguments: None
* Example invocation: ./myGpioApp
*/

#include "myGpio.h"
#include <iostream>
#include <unistd.h>

int main() {
MYGPIO gpioOut(60);
gpioOut.setDirection(1);

MYGPIO gpioIn(16);
gpioIn.setDirection(0);

gpioOut.setValue(1);
std::cout << "GPIO p9.12 is high, value: " << gpioOut.getValue() << std::endl;
sleep(3);
gpioOut.setValue(0);
std::cout << "GPIO p9.12 is low, value: " << gpioOut.getValue() << std::endl;

std::cout << "GPIO p8.16 value: " << gpioIn.getValue() << std::endl;

return 0;
}

