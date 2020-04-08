#ifndef CPP_REFACTORING_WEBINAR_CURLDOWNLOADER_HPP
#define CPP_REFACTORING_WEBINAR_CURLDOWNLOADER_HPP

#include "Downloader.hpp"

struct CurlDownloader : public Downloader
{
    bool download(const std::string& url,
                  const std::string& destination) const override;
};

#endif // CPP_REFACTORING_WEBINAR_CURLDOWNLOADER_HPP
