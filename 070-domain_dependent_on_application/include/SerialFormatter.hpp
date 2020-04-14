#ifndef CPP_REFACTORING_WEBINAR_SERIALFORMATTER_HPP
#define CPP_REFACTORING_WEBINAR_SERIALFORMATTER_HPP

#include <string>

struct SerialFormatter
{
    virtual ~SerialFormatter() = default;

    virtual std::string format(const std::string& input) = 0;
};

#endif // CPP_REFACTORING_WEBINAR_SERIALFORMATTER_HPP
