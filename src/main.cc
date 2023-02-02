#include <attiny.hpp>
#include <tinystd.hpp>

/* this file is just a test file*/

using namespace attiny;
using namespace tinystd;
int main() {
    pinMode<Output>(Pin0);

    while (1) {
        digitalFlip(Pin0);
        _delay_ms(100);
    }    
}
