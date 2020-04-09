#include "FileEncoder.hpp"

using namespace before;

namespace
{
const auto kFilePath = "write.txt"; // File with some contents
}

int main()
{
    FileEncoder f;
    const auto r = f.encode(kFilePath);

    return r ? 0 : 1;
}
