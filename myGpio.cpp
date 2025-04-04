#include "myGpio.h"
#include <unistd.h>

MYGPIO::MYGPIO(int number) {
this->number = number;
this->name = "gpio" + to_string(number);
this->path = "/sys/class/gpio/";

// Export GPIO
write(path, "export", to_string(number));
}

void MYGPIO::write(string path, string filename, string value) {
stream.open(path + filename);
if (stream.is_open()) {
stream << value;
stream.close();
}
}

void MYGPIO::write(string path, string filename, int value) {
write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename) {
string value;
ifstream stream(path + filename);
if (stream.is_open()) {
stream >> value;
stream.close();
}
return value;
}

int MYGPIO::getNumber() {
return number;
}

void MYGPIO::setDirection(int dir) {
string direction = (dir == 1) ? "out" : "in";
write(path + "gpio" + to_string(number) + "/", "direction", direction);
}

string MYGPIO::getDirection() {
return read(path + "gpio" + to_string(number) + "/", "direction");
}

void MYGPIO::setValue(int val) {
write(path + "gpio" + to_string(number) + "/", "value", val);
}

int MYGPIO::getValue() {
return stoi(read(path + "gpio" + to_string(number) + "/", "value"));
}

void MYGPIO::toggleOutput() {
int currentVal = getValue();
setValue(currentVal == 1 ? 0 : 1);
}

void MYGPIO::toggleOutputNumberOfTimes(int n, int delay) {
for (int i = 0; i < n; i++) {
toggleOutput();
usleep(delay);
}
}

MYGPIO::~MYGPIO() {
write(path, "unexport", to_string(number));
}
