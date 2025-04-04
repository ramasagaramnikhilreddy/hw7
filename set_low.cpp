#include <iostream>
#include <fstream>

int main() {
std::ofstream gpioPin("/sys/class/gpio/gpio60/value");
gpioPin << "0"; // Set GPIO pin low
gpioPin.close();
return 0;
}
