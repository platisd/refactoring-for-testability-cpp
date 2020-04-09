#include "FileEncoder.hpp"
#include "MyFileReader.hpp"
#include "MyFileWriter.hpp"

using namespace after;

namespace
{
const auto kFilePath = "write.txt"; // File with some contents
}

int main()
{
    MyFileReader fileReader;
    MyFileWriter fileWriter;

    FileEncoder f{fileReader, fileWriter};
    const auto r = f.encode(kFilePath);

    return r ? 0 : 1;
}
