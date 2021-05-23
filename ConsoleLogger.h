#pragma once
#include "ILoggable.h"
#include <memory>
class ILogFormatter;

class ConsoleLogger : public ILoggable
{
public:
    ConsoleLogger(std::unique_ptr<ILogFormatter> formatter);
    ~ConsoleLogger() = default;
    void Log(ILoggableEvent& event) override;

private:
    std::unique_ptr<ILogFormatter> formatter;
};
