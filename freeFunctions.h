#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <vector>
#include <QString>
#include "EmptyArgument.h"

void parseColors( const QString &content, std::vector<QString> &colors )
throw( EmptyArgument );

#endif // FREEFUNCTIONS_H
