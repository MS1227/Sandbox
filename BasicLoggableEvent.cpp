#include "BasicLoggableEvent.h"
#include "ILogFormatter.h"
#include "Utils.h"

BasicLoggableEvent::BasicLoggableEvent(const Logging::Level level, const std::string file, const std::string function, const int lineNumber) :
    level{ level},
    file{ file },
    function{ function },
    lineNumber {lineNumber}
{}

std::map<Enumerations::FieldKeyDictionary, std::string> BasicLoggableEvent::Tokenize()
{
    std::map<Enumerations::FieldKeyDictionary, std::string> keyValueTokens;
    keyValueTokens[Enumerations::FieldKeyDictionary::Level] = Logging::LoggingLevelToString(level);
    keyValueTokens[Enumerations::FieldKeyDictionary::File] = file;
    keyValueTokens[Enumerations::FieldKeyDictionary::Function] = function;
    keyValueTokens[Enumerations::FieldKeyDictionary::Line] = std::to_string(lineNumber);

    return keyValueTokens;
}

std::string BasicLoggableEvent::ToString(ILogFormatter& formatter)
{
    return formatter.Format(*this);
}
