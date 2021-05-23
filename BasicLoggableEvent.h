#pragma once
#include "ILoggableEvent.h"
#include <memory>
class ILogFormatter;

class BasicLoggableEvent : public ILoggableEvent
{
public:
    BasicLoggableEvent(const Logging::Level, const std::string file, const std::string function, const int line);
    virtual ~BasicLoggableEvent() = default;
    std::map<Enumerations::FieldKeyDictionary, std::string> Tokenize() override;
    std::string ToString(ILogFormatter& formatter) override;

private:
    Logging::Level level;
    std::string file;
    std::string function;
    int lineNumber;
};
