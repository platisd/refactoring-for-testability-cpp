#ifndef CPP_REFACTORING_WEBINAR_BARSERIALFORMATTER_HPP
#define CPP_REFACTORING_WEBINAR_BARSERIALFORMATTER_HPP

#include "SerialFormatter.hpp"

struct BarSerialFormatter : public SerialFormatter
{
    std::string format(const std::string& input) override;
};

#endif // CPP_REFACTORING_WEBINAR_BARSERIALFORMATTER_HPP
