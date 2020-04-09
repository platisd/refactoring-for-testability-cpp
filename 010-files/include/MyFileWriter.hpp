#ifndef CPP_REFACTORING_WEBINAR_MYFILEWRITER_HPP
#define CPP_REFACTORING_WEBINAR_MYFILEWRITER_HPP

#include "FileWriter.hpp"

struct MyFileWriter : public FileWriter
{
    bool write(const std::string& filePath,
               const std ::string& content) const override;
};

#endif // CPP_REFACTORING_WEBINAR_MYFILEWRITER_HPP
