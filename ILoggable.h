#pragma once

class ILoggableEvent;

class ILoggable
{
public:
    virtual ~ILoggable() = default;
    virtual void Log(ILoggableEvent& event) = 0;
};
