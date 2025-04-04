
#!/bin/bash

config-pin p9.12 gpio
config-pin p8.16 gpio

g++ -o myGpioApp myGpioApp.cpp myGpio.cpp

chmod +x myGpioApp

