#include "FileEncoder.hpp"
#include "FileReaderMock.hpp"
#include "FileWriterMock.hpp"
#include "gtest/gtest.h"

using namespace testing;
using namespace after;

namespace
{
const auto kFilePath = "ʕ•ᴥ•ʔ";
}

struct FileEncoderTest : public Test
{
    MockFileReader mFileReader;
    MockFileWriter mFileWriter;
    FileEncoder mFileEncoder{mFileReader, mFileWriter};
};

TEST_F(FileEncoderTest, encode_WhenCalled_WillReadFromCorrectFile)
{
    EXPECT_CALL(mFileReader, read(kFilePath));

    mFileEncoder.encode(kFilePath);
}

TEST_F(FileEncoderTest, encode_WhenInvalidFile_WillNotEncodeFile)
{
    EXPECT_CALL(mFileReader, read(_)).WillOnce(Return(std::nullopt));
    EXPECT_CALL(mFileWriter, write(_, _)).Times(0);

    EXPECT_FALSE(mFileEncoder.encode(kFilePath));
}

TEST_F(FileEncoderTest, encode_WhenValidFile_WillCreateEncodedFile)
{
    EXPECT_CALL(mFileReader, read(_))
        .WillOnce(Return(std::make_optional<std::string>("")));
    EXPECT_CALL(mFileWriter, write(kFilePath + std::string(".encoded"), _));

    mFileEncoder.encode(kFilePath);
}

TEST_F(FileEncoderTest, encode_WhenFileSuccessfullyWritten_WillReturnTrue)
{
    EXPECT_CALL(mFileReader, read(_))
        .WillOnce(Return(std::make_optional<std::string>("")));
    EXPECT_CALL(mFileWriter, write(_, _)).WillOnce(Return(true));

    EXPECT_TRUE(mFileEncoder.encode(kFilePath));
}

TEST_F(FileEncoderTest, encode_WhenFileUnsuccessfullyWritten_WillReturnFalse)
{
    EXPECT_CALL(mFileReader, read(_))
        .WillOnce(Return(std::make_optional<std::string>("")));
    EXPECT_CALL(mFileWriter, write(_, _)).WillOnce(Return(false));

    EXPECT_FALSE(mFileEncoder.encode(kFilePath));
}

TEST_F(FileEncoderTest,
       encode_WhenValidFile_WillNotEncodeAlphanumericCharacters)
{
    const auto nonAlphanumericContents = "\n\t\t\t\t";
    EXPECT_CALL(mFileReader, read(_))
        .WillOnce(
            Return(std::make_optional<std::string>(nonAlphanumericContents)));
    EXPECT_CALL(mFileWriter, write(_, nonAlphanumericContents));

    mFileEncoder.encode(kFilePath);
}

TEST_F(FileEncoderTest, encode_WhenValidFile_WillEncodeAlphanumericCharacters)
{
    const auto alphanumericContents = "abc123\n";
    const auto encodedContents      = "bcd234\n";
    EXPECT_CALL(mFileReader, read(_))
        .WillOnce(
            Return(std::make_optional<std::string>(alphanumericContents)));
    EXPECT_CALL(mFileWriter, write(_, encodedContents));

    mFileEncoder.encode(kFilePath);
}
