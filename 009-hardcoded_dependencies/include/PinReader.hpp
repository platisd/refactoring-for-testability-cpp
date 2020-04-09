#ifndef CPP_REFACTORING_WEBINAR_PINREADER_HPP
#define CPP_REFACTORING_WEBINAR_PINREADER_HPP

struct PinReader
{
    virtual ~PinReader() = default;

    virtual bool read(int pin) const = 0;
};

#endif // CPP_REFACTORING_WEBINAR_PINREADER_HPP
