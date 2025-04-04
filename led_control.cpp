#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
system("echo 60 > /sys/class/gpio/export");
system("echo 16 > /sys/class/gpio/export");
system("echo out > /sys/class/gpio/gpio60/direction");
system("echo in > /sys/class/gpio/gpio16/direction");

std::ifstream buttonState("/sys/class/gpio/gpio16/value");
std::ofstream ledControl("/sys/class/gpio/gpio60/value");

int state = 0;

while (true) {
buttonState >> state;
if (state == 1) {
ledControl << "1";
} else {
ledControl << "0";
}
usleep(100000);
}

buttonState.close();
ledControl.close();
return 0;
}
