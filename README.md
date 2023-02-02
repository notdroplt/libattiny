# attinylib

A header only library focused in compiler-time optimizations, trying to implement most of both [Arduino core](https://github.com/arduino/ArduinoCore-avr) and a freestanding libc++ enviroment
  
the library is being developed and tested in the [ATtiny13A](https://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny13A-Data-Sheet-DS40002307A.pdf)

### [`lib/functions`](./lib/functions/): Arduino-core implementation, under the namespace `attiny::`
### [`lib/types`](./lib/types/): freestanding libc++ implementation, under the namespace `tinystd::`

this code is licensed under the [MIT LICENSE](LICENSE)