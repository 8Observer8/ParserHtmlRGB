
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <QString>
#include "freeFunctions.h"
#include "EmptyArgument.h"

TEST( parseColors001, emptyArgumentTest )
{
    QString content = "";
    std::vector<QString> colors;

    ASSERT_THROW( {
                      parseColors( content, colors );
                  }, EmptyArgument );
}

TEST( parseColors002, emptyArgumentTest )
{
    QString content = "#00ff00";
    std::vector<QString> colors;

    ASSERT_NO_THROW( {
                         parseColors( content, colors );
                     } );
}

TEST( parseColors003, oneColorTest )
{
    QString content = "#00ff00html";
    std::vector<QString> colors;

    ASSERT_NO_THROW( {
                         parseColors( content, colors );
                     } );

    // Check size
    int expectedSize = 1;
    int actualSize = colors.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Check color
    std::string expectedColor = "#00ff00";
    std::string actualColor = colors[0].toStdString( );
    ASSERT_EQ( expectedColor, actualColor );
}

TEST( parseColors004, twoColorTest )
{
    QString content = "<html><head></head><body bgcolor=\"#336633\" text=\"#FFFFFF\" marginwidth=\"0\" marginheight=\"0\" topmargin=\"0\" leftmargin=\"0\"></body></html>";
    std::vector<QString> colors;

    ASSERT_NO_THROW( {
                         parseColors( content, colors );
                     } );

    // Check size
    int expectedSize = 2;
    int actualSize = colors.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Check colors
    std::vector<QString> expectedColors;
    expectedColors.push_back( "#336633" );
    expectedColors.push_back( "#FFFFFF" );

    for ( std::size_t i = 0; i < expectedSize; i++ ) {
        std::string actual = colors[i].toStdString( );
        std::string expected = expectedColors[i].toStdString( );
        ASSERT_EQ( expected , actual );
    }
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
