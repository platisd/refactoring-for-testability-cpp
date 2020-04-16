#ifndef CPP_REFACTORING_FOR_TESTABILITY_PINREADER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_PINREADER_HPP

struct PinReader
{
    virtual ~PinReader() = default;

    virtual bool read(int pin) const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_PINREADER_HPP
