
#include <QString>
#include "gtest/gtest.h"
#include "Downloader.h"
#include "EmptyArgument.h"

TEST( fetch001, emptyArgumentTest )
{
    Downloader downloader;
    QString url = "";

    ASSERT_THROW( {
                      downloader.fetch( url );
                  }, EmptyArgument );
}

TEST( fetch001, notEmptyArgumentTest )
{
    Downloader downloader;
    QString url = "https://qt-project.org/";

    ASSERT_NO_THROW( {
                      downloader.fetch( url );
                     } );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
