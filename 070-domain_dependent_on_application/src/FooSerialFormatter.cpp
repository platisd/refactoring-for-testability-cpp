#include "FooSerialFormatter.hpp"

std::string FooSerialFormatter::format(const std::string& input)
{
    return std::to_string(mSequenceNumber++) + ":" + input;
}
