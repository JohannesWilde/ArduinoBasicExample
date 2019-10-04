// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "arduinouno.hpp"

int main()
{
    // This implements the well-known Blink example from the Arduino IDE.
    typedef ArduinoUno arduinoUno;

    arduinoUno::LED_BUILTIN::setType(AvrInputOutput::OUTPUT_HIGH);
    while (true)
    {
        _delay_ms(1000);
        arduinoUno::LED_BUILTIN::clearPort();
        _delay_ms(1000);
        arduinoUno::LED_BUILTIN::setPort();
    }
}
