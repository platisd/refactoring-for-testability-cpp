#include "PlatisSolutionsBenchmarker.hpp"
#include <chrono>
#include <curl/curl.h> // You probably want to remove this after refactoring
#include <string>

namespace
{
const auto kUrl
    = "https://platis.solutions/assets/images/smartcar_featured.jpg";
const auto kFilePath = "/dev/null";
} // namespace

namespace before
{
std::optional<std::chrono::milliseconds>
PlatisSolutionsBenchmarker::getResponseTime() const
{
    const auto start        = std::chrono::system_clock::now();
    auto downloadSuccessful = false;
    if (auto curl = curl_easy_init())
    {
        auto fp = fopen(kFilePath, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, kUrl);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        downloadSuccessful = curl_easy_perform(curl) == CURLE_OK;

        fclose(fp);
        curl_easy_cleanup(curl);
    }
    const auto end = std::chrono::system_clock::now();

    if (downloadSuccessful)
    {
        const auto elapsedTime
            = std::chrono::duration_cast<std::chrono::milliseconds>(end
                                                                    - start);
        return std::make_optional(elapsedTime);
    }

    return std::nullopt;
}
} // namespace before

namespace after
{
PlatisSolutionsBenchmarker::PlatisSolutionsBenchmarker(Downloader& downloader)
    : mDownloader{downloader}
{
}

std::optional<std::chrono::milliseconds>
PlatisSolutionsBenchmarker::getResponseTime() const
{
    const auto start              = std::chrono::system_clock::now();
    const auto downloadSuccessful = mDownloader.download(kUrl, kFilePath);
    const auto end                = std::chrono::system_clock::now();

    if (downloadSuccessful)
    {
        const auto elapsedTime
            = std::chrono::duration_cast<std::chrono::milliseconds>(end
                                                                    - start);
        return std::make_optional(elapsedTime);
    }

    return std::nullopt;
}
} // namespace after
