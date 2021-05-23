#pragma once
#include "ILogFormatter.h"

class ConsoleFormatter : public ILogFormatter
{
public:
    ConsoleFormatter() = default;
    virtual ~ConsoleFormatter() = default;
    std::string Format(ILoggableEvent& event) override;
            
};
