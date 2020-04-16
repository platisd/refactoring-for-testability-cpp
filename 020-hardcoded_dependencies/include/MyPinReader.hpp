#ifndef CPP_REFACTORING_FOR_TESTABILITY_MYPINREADER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MYPINREADER_HPP

#include "PinReader.hpp"

struct MyPinReader : public PinReader
{
    bool read(int pin) const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MYPINREADER_HPP
