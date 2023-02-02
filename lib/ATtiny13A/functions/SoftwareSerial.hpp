#include <attiny.hpp>

namespace attiny
{
    bool get_parity(uint8_t v, bool p = false) {
        for (byte i = 0; i < 8; ++i)
        {
            p ^= v & 1;
            v >>= 1;
        }
        return p;
    }

    bool get_parity(uint8_t * v, uint16_t size) {
        bool p = false;
        for (; size; v++, size--)
        {
            p = get_parity(*v, p);
        }
        return p;
    }

    template <int Size>
    class SoftwareSerial final
    {
    private:
        const uint8_t _pin_tx: 3;
        const uint8_t _pin_rx: 3;
                
        char buffer[Size];

    
    public:
        SoftwareSerial(T /* args */);
    };
    
} // namespace attiny
