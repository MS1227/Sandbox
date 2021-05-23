#pragma once
#include "Enumerations.h"
namespace Logging
{
    static std::string LoggingLevelToString(Logging::Level level)
    {
        switch(level)
        {
            case Logging::Level::Debug:
                return "DEBUG";
                break;
            case Logging::Level::Info:
                return "INFO";
                break;
            case Logging::Level::Warn:
                return "WARN";
                break;
            case Logging::Level::Fatal:
                return "FATAL";
            default:
                return "UNKN";
                break;
        }
    }
}
