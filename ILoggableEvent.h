#pragma once
#include "Enumerations.h"
#include <map>
#include <string>
class ILogFormatter;

class ILoggableEvent
{
public:
    virtual ~ILoggableEvent() = default;
    virtual std::map<Enumerations::FieldKeyDictionary, std::string> Tokenize() = 0;
    virtual std::string ToString(ILogFormatter& formatter) = 0;
};
