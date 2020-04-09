#ifndef CPP_REFACTORING_WEBINAR_MYPINREADER_HPP
#define CPP_REFACTORING_WEBINAR_MYPINREADER_HPP

#include "PinReader.hpp"

struct MyPinReader : public PinReader
{
    bool read(int pin) const override;
};

#endif // CPP_REFACTORING_WEBINAR_MYPINREADER_HPP
