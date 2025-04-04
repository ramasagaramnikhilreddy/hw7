#include <iostream>
#include <fstream>

int main() {
std::ofstream gpioPin("/sys/class/gpio/gpio60/value");
gpioPin << "1"; // Set GPIO pin high
gpioPin.close();
return 0;
}
