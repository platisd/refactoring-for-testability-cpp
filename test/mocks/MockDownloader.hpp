#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKDOWNLOADER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKDOWNLOADER_HPP

#include "Downloader.hpp"
#include "gmock/gmock.h"

class MockDownloader : public Downloader
{
public:
    MOCK_METHOD(bool,
                download,
                (const std::string& url, const std::string& destination),
                (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKDOWNLOADER_HPP
