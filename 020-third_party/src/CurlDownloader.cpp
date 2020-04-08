#include "CurlDownloader.hpp"
#include <curl/curl.h>

bool CurlDownloader::download(const std::string& url,
                              const std::string& destination) const
{
    if (auto curl = curl_easy_init())
    {
        auto fp = fopen(destination.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        const auto downloadSuccessful = curl_easy_perform(curl) == CURLE_OK;

        fclose(fp);
        curl_easy_cleanup(curl);

        return downloadSuccessful;
    }

    return false;
}
