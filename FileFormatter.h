#pragma once
#include "ILogFormatter.h"

class FileFormatter : public ILogFormatter
{
public:
    FileFormatter() = default;
    virtual ~FileFormatter() = default;
    std::string Format(ILoggableEvent& event) override;
            
};
