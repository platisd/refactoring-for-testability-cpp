#include "BarSerialFormatter.hpp"

std::string BarSerialFormatter::format(const std::string& input)
{
    return "M:" + input + ",";
}
