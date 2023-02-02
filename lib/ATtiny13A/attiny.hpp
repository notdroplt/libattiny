#ifndef ATtiny13_libc
#define ATtiny13_libc 1

#include <avr/io.h>
#include <util/delay.h>
#define HIGH true
#define LOW false

// Arduino types
using boolean = bool; // is this Java 
using byte = uint8_t;
using word = uint16_t;

#include "functions/AnalogIO.hpp"
#include "functions/BitsBytes.hpp"
#include "functions/Characters.hpp"
#include "functions/DigitalIO.hpp"
#include "functions/Math.hpp"
#include "functions/SoftwareSerial.hpp"

#define interrupts() asm volatile("sei")
#define noInterrrupts() asm volatile("cli")

#define delay(time) _delay_ms(time)
#define delay_microsseconds(time) _delay_us(time)

#endif
