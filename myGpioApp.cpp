#include "myGpio.h"
#include <iostream>
#include <unistd.h>

int main() {
// Instantiate output GPIO pin p9.12
MYGPIO gpioOut(60); // Assuming p9.12 maps to gpio60
gpioOut.setDirection(1); // Set direction to output

// Instantiate input GPIO pin p8.16
MYGPIO gpioIn(16); // Assuming p8.16 maps to gpio16
gpioIn.setDirection(0); // Set direction to input

// Set p9.12 high for 3 seconds, then low
gpioOut.setValue(1);
cout << "GPIO p9.12 is high, value: " << gpioOut.getValue() << endl;
sleep(3);
gpioOut.setValue(0);
cout << "GPIO p9.12 is low, value: " << gpioOut.getValue() << endl;

// Read p8.16 and print its value
cout << "GPIO p8.16 value: " << gpioIn.getValue() << endl;

return 0;
}

