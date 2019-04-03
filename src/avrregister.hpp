#ifndef AVRREGISTER_HPP
#define AVRREGISTER_HPP

#include <stdint.h>
#include <avrinputoutput.hpp>
#include "avrinternalregister.hpp"


template<typename PortRegister, typename DdrRegister, typename PinRegister>
struct AvrRegister
{
    // setType(PinType const pinType, uint8_t const bitMask) only set those bits, that are 0b1 in bitMask
    static void setType(AvrInputOutput::PinType const pinType, typename DdrRegister::Type const bitMask = 0xff)
    {
        switch (pinType)
        {
        case AvrInputOutput::OUTPUT_HIGH:
            DdrRegister::setBitMask(bitMask);       // output
            PortRegister::setBitMask(bitMask);      // high
            break;
        case AvrInputOutput::OUTPUT_LOW:
            DdrRegister::setBitMask(bitMask);       // output
            PortRegister::clearBitMask(bitMask);    // low
            break;
        case AvrInputOutput::INPUT:
            DdrRegister::clearBitMask(bitMask);     // input
            PortRegister::clearBitMask(bitMask);    // no pull-up
            break;
        case AvrInputOutput::INPUT_PULLUP:
            DdrRegister::clearBitMask(bitMask);     // input
            PortRegister::setBitMask(bitMask);      // pull-up [PUD in MCUCR needs to be low]
            // break;
        }
    }

    static typename PortRegister::Type readPort()
    {
        return PortRegister::readRegister();
    }

    static typename DdrRegister::Type readDdr()
    {
        return DdrRegister::readRegister();
    }

    static typename PinRegister::Type readPin()
    {
        return PinRegister::readRegister();
    }
};

#endif // AVRREGISTER_H
