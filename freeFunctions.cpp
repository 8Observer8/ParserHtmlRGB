
#include <string>
#include <QRegExp>
#include <QDebug>
#include "freeFunctions.h"

void parseColors( const QString &content, std::vector<QString> &colors )
throw( EmptyArgument )
{
    std::string functionName = "parseColors()";

    // Check argument
    if ( content.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Find all colors
    QString pattern( "#[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f]" );
    QRegExp regExp( pattern );
    int pos = 0;
    while( ( pos = regExp.indexIn( content, pos ) ) != -1 ) {
        colors.push_back( regExp.cap( 0 ) );
        pos += regExp.matchedLength( );
    }
}
