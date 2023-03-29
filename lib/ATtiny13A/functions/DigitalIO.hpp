#ifndef ATtiny_digitalIO_H
#define ATtiny_digitalIO_H 1
#include <avr/io.h>
namespace attiny {

    enum PinModes {
        Input,
        Output,
        InputPullup
    };

    enum Pins {
        Pin0 = PORTB0, Pin1 = PORTB1, Pin2 = PORTB2,
        Pin3 = PORTB3, Pin4 = PORTB4, Pin5 = PORTB5,
    };

    enum DigitalLevel {
        Low = false,
        High = true,
    };

    template<int mode = InputPullup> inline void pinMode(const Pins pin){ 
        DDRB &= ~_BV(pin);
        PORTB |= _BV(pin);
    }

    template<> inline void pinMode<Input>(const Pins pin) {
        DDRB &= ~_BV(pin);
    }

    template<> inline void pinMode<Output>(const Pins pin) {
        DDRB |= _BV(pin);
    }

    template<DigitalLevel level> inline void digitalWrite(const uint8_t pin);

    template<> inline void digitalWrite<Low>(const uint8_t pin) {
        PORTB &= ~_BV(pin);
    }

    template<> inline void digitalWrite<High>(const uint8_t pin) {
        PORTB |= _BV(pin);
    }

    inline void digitalFlip(const uint8_t pin) {
        PORTB ^= _BV(pin);
    }

    void digitalWrite(const uint8_t pin, const bool level) {
        level ? PORTB |= _BV(pin) : PORTB &= ~_BV(pin);
    }

    inline bool digitalRead(const uint8_t pin) {
        return PINB & _BV(pin);
    }

    enum ShiftModes {
        MostSignificantBitFirst,
        LeastSignificantBitFirst,
    };

    template<int modes> void shiftOut(const Pins pin, const Pins clock, uint8_t value) noexcept;
    template<> void shiftOut<MostSignificantBitFirst>(const Pins pin, const Pins clock, uint8_t value) noexcept {
        for (uint8_t i = 0; i < 8; ++i)  {
            digitalWrite(pin, (value & 128));
            value <<= 1;           
                
            PORTB ^= _BV(clock);
            PORTB ^= _BV(clock);		
        }
    }

    template<> void shiftOut<LeastSignificantBitFirst>(const Pins pin, const Pins clock, uint8_t value) noexcept {
        for (uint8_t i = 0; i < 8; i++)  {
            digitalWrite(pin, value & 1);
            value >>= 1;
            
            PORTB ^= _BV(clock);
            PORTB ^= _BV(clock);			
        }
    }

    template<int modes> uint8_t shiftIn(const Pins pin, const uint8_t clock) noexcept;
    template<> uint8_t shiftIn<MostSignificantBitFirst>(const Pins pin, const uint8_t clock) noexcept {
        uint8_t value = 0, i = 7;
        while (i--) {
            value = (value << 1) | digitalRead(pin);

            PORTB ^= _BV(clock);
            PORTB ^= _BV(clock);			
        }
        
        return value;
    }

    template<> uint8_t shiftIn<LeastSignificantBitFirst>(const Pins pin, const uint8_t clock) noexcept {
        uint8_t value = 0, i = 0;
        while (i < 8) {
            value |= digitalRead(pin) << i;

            PORTB ^= _BV(clock);
            PORTB ^= _BV(clock);			
            ++i;
        }
        
        return value;
    }

}


#endif