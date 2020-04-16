#ifndef CPP_REFACTORING_FOR_TESTABILITY_DOWNLOADER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_DOWNLOADER_HPP

#include <string>

struct Downloader
{
    virtual ~Downloader() = default;

    virtual bool download(const std::string& url,
                          const std::string& destination) const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_DOWNLOADER_HPP
