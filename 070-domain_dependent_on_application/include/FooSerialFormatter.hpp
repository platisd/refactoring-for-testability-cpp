#ifndef CPP_REFACTORING_WEBINAR_FOOSERIALFORMATTER_HPP
#define CPP_REFACTORING_WEBINAR_FOOSERIALFORMATTER_HPP

#include "SerialFormatter.hpp"

struct FooSerialFormatter : public SerialFormatter
{
    std::string format(const std::string& input) override;

private:
    int mSequenceNumber{0};
};

#endif // CPP_REFACTORING_WEBINAR_FOOSERIALFORMATTER_HPP
