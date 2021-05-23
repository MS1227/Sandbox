#include "ConsoleLogger.h"
#include "ConsoleFormatter.h"
#include "FileFormatter.h"
#include "BasicLoggableEvent.h"
#include "Enumerations.h"
#include <iostream>
int main()
{
    auto formatter = std::make_unique<ConsoleFormatter>();
    auto formatter2 = std::make_unique<FileFormatter>();
    ConsoleLogger logger(std::move(formatter));
    ConsoleLogger loggerTwo(std::move(formatter2));

    BasicLoggableEvent event(Logging::Level::Debug, __FILE__, __FUNCTION__, __LINE__);
    logger.Log(event);
    loggerTwo.Log(event);
     
    return 0;
}
