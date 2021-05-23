#include "ConsoleLogger.h"
#include "ILoggableEvent.h"
#include "ILogFormatter.h"
#include <iostream>

ConsoleLogger::ConsoleLogger(std::unique_ptr<ILogFormatter> formatter) :
    formatter{ std::move(formatter) }
{}
void ConsoleLogger::Log(ILoggableEvent& event)
{
    std::cout << event.ToString(*formatter);
}
