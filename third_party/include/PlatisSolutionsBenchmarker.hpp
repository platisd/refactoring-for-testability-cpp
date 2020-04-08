#ifndef CPP_REFACTORING_WEBINAR_PLATISSOLUTIONSBENCHMARKER_HPP
#define CPP_REFACTORING_WEBINAR_PLATISSOLUTIONSBENCHMARKER_HPP

#include "Downloader.hpp"
#include <chrono>
#include <optional>

namespace before
{
struct PlatisSolutionsBenchmarker
{
    std::optional<std::chrono::milliseconds> getResponseTime() const;
};
} // namespace before

namespace after
{
struct PlatisSolutionsBenchmarker
{
    PlatisSolutionsBenchmarker(Downloader& downloader);

    std::optional<std::chrono::milliseconds> getResponseTime() const;

private:
    Downloader& mDownloader;
};
} // namespace after
#endif // CPP_REFACTORING_WEBINAR_PLATISSOLUTIONSBENCHMARKER_HPP
