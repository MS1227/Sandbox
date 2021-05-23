#pragma once
#include <string>
#include "Enumerations.h"

class ILoggableEvent;

class ILogFormatter
{
public:
    virtual ~ILogFormatter() = default;
    virtual std::string Format(ILoggableEvent& event) = 0;
};
