
#!/bin/bash

config-pin p9.12 gpio
config-pin p8.16 gpio

g++ -o problem4-myGpioApp problem4-myGpioApp.cpp problem4-myGpio.cpp

chmod +x problem4-myGpioApp

