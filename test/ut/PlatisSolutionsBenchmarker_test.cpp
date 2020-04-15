#include "MockDownloader.hpp"
#include "PlatisSolutionsBenchmarker.hpp"
#include "gtest/gtest.h"
#include <chrono>
#include <thread>

using namespace testing;
using namespace after;

struct BenchmarkerTest : public Test
{
    MockDownloader mDownloader;
    PlatisSolutionsBenchmarker mBenchmarker{mDownloader};
};

TEST_F(BenchmarkerTest, getResponseTime_WhenCalled_WillDownloadFromWebsite)
{
    EXPECT_CALL(mDownloader, download(_, _));

    mBenchmarker.getResponseTime();
}

TEST_F(BenchmarkerTest,
       getResponseTime_WhenDownloadNotSuccessful_WillReturnInvalid)
{
    EXPECT_CALL(mDownloader, download(_, _)).WillOnce(Return(false));

    EXPECT_FALSE(mBenchmarker.getResponseTime());
}

TEST_F(BenchmarkerTest,
       getResponseTime_WhenDownloadSuccessful_WillReturnValidTime)
{
    EXPECT_CALL(mDownloader, download(_, _)).WillOnce(Return(true));
    EXPECT_TRUE(mBenchmarker.getResponseTime());
}

TEST_F(BenchmarkerTest,
       getResponseTime_WhenDownloadSuccessful_WillReturnCorrectTime)
{
    // If you really want to test the benchmarking/time calculation
    // you can do so **at the expense of your execution time**.
    // Alternatively, you can abstract time out as well, as described
    // in the `time` chapter.
    using namespace std::chrono_literals;
    const auto executionTime = 1ms; // Or something larger that would not
                                    // normally happen with gmock but not
                                    // too large to make your tests slow
    EXPECT_CALL(mDownloader, download(_, _))
        .WillOnce(DoAll(InvokeWithoutArgs([&executionTime]() {
                            std::this_thread::sleep_for(executionTime);
                        }),
                        Return(true)));
    const auto validTime = mBenchmarker.getResponseTime();
    ASSERT_TRUE(validTime);
    EXPECT_GE(validTime.value(), executionTime);
}
