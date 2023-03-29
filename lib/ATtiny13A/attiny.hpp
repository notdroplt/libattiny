#ifndef ATtiny13_libc
#define ATtiny13_libc 1

#include <avr/io.h>
#include <util/delay.h>
#define HIGH true
#define LOW false

/*!< boolean type*/
using boolean = bool; 

/*!< byte type*/
using byte = uint8_t;

/*!< word type*/
using word = uint16_t;

#include "functions/AnalogIO.hpp"
#include "functions/BitsBytes.hpp"
#include "functions/Characters.hpp"
#include "functions/DigitalIO.hpp"
#include "functions/Math.hpp"
#include "functions/SoftwareSerial.hpp"

/*!< enable interrupts */
#define interrupts() asm volatile("sei")

/*!< disable interrupts */
#define noInterrrupts() asm volatile("cli")

/*!< pause the mcu for `time` millisseconds */
#define delay(time) _delay_ms(time)

/*!< pause the mcu for `time` microsseconds */
#define delay_microsseconds(time) _delay_us(time)

#endif
