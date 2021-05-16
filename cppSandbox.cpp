#include <iostream>
#include <string_view>
#include <map>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>

enum class EventCode
{ System = 0x20000, SystemStart = 0x20001, StateChange = 0x30000, };

enum class SeverityLevel
{
    Debug,
    Info,
    Warn,
    Fatal
};
struct EventData 
{
    std::chrono::time_point<std::chrono::system_clock> eventTime;
    std::string file;
    std::string function;
    std::string line;
    std::thread::id threadId;
    std::string payload;

    friend std::ostream& operator<<(std::ostream& output, const EventData& data)
    {
        output << "ThreadId: " << data.threadId << " File: " << data.file << " - Function: " << data.function << " - Line:" << data.line << " Message: " << data.payload << "\n";
        return output;
    }

    EventData(std::chrono::time_point<std::chrono::system_clock> eventTime, std::string file, std::string function, std::string line, std::thread::id threadId, std::string payload) :
        eventTime{ eventTime },
        file{ file },
        function{ function },
        line{ line }, 
        threadId{ threadId },
        payload{ payload }
    {}

    std::stringstream Tokenize(std::time_t time, const std::string& levelString)
    {
        std::stringstream tokens;
        
        tokens << "{\n";
        tokens << "\t\"time\" : " << "\"" << std::put_time(std::gmtime(&time), "%c %Z") << "\",\n";
        tokens << "\t\"level_string\" : " << "\"" << levelString << "\",\n";
        tokens << "\t\"file\" : " << "\"" << file << "\",\n";
        tokens << "\t\"function\" : " << "\"" << function << "\",\n";
        tokens << "\t\"line\" : " << "\"" << line << "\",\n";
        tokens << "\t\"thread_id\" : " << "\"" << threadId << "\",\n";
        tokens << "\t\"payload\" : " << "\"" << payload << "\"\n";
        tokens << "}\n";

        return tokens;       
    }

};
void LogMessage(EventCode code, EventData data)
{
    std::map<EventCode, SeverityLevel> eventSeverityDictionary;
    eventSeverityDictionary[EventCode::SystemStart] = SeverityLevel::Info;
  
    std::time_t loggedTime = std::chrono::system_clock::to_time_t(data.eventTime);

    const auto level = eventSeverityDictionary.find(code);
    
    switch (level->second)
    {
        case SeverityLevel::Debug:
            std::cout << "[DEBUG] " << std::put_time(std::gmtime(&loggedTime), "%c %Z") << " - " << data;
            break;
        case SeverityLevel::Info:
            std::cout << "\033[1m\033[32m" << "[INFO] " << "\033[0m" << std::put_time(std::gmtime(&loggedTime), "%c %Z") << " - " << data;
            break;
        default:
            break;
    }
}

void LogMessageInJSON(EventCode code, EventData data)
{
    std::fstream outfile("logFile.json", std::ios::out | std::ios::app);
    std::map<EventCode, SeverityLevel> eventSeverityDictionary;
    eventSeverityDictionary[EventCode::SystemStart] = SeverityLevel::Info;
   
    std::time_t loggedTime = std::chrono::system_clock::to_time_t(data.eventTime);

    const auto level = eventSeverityDictionary.find(code);
    const std::string infoString = "[INFO]";    

    switch (level->second)
    {
        case SeverityLevel::Debug:
            outfile << "[DEBUG] " << std::put_time(std::gmtime(&loggedTime), "%c %Z") << " - " << data;
            break;
        case SeverityLevel::Info:
            outfile  << data.Tokenize(loggedTime, infoString).str();
            break;
        default:
            break;
    }

}

void LogMessageFile(EventCode code, EventData data)
{
    const std::string infoString = "\033[1m\033[32m[INFO] \033[0m";
    std::fstream outfile("logFile.txt", std::ios::out | std::ios::app);
    std::map<EventCode, SeverityLevel> eventSeverityDictionary;
    eventSeverityDictionary[EventCode::SystemStart] = SeverityLevel::Info;
   
    std::time_t loggedTime = std::chrono::system_clock::to_time_t(data.eventTime);

    const auto level = eventSeverityDictionary.find(code);
    
    switch (level->second)
    {
        case SeverityLevel::Debug:
            outfile << "[DEBUG] " << std::put_time(std::gmtime(&loggedTime), "%c %Z") << " - " << data;
            break;
        case SeverityLevel::Info:
            outfile << infoString << std::put_time(std::gmtime(&loggedTime), "%c %Z") << " - " << data;
            break;
        default:
            break;
    }
}
void start()
{
    EventData data(std::chrono::system_clock::now(),__FILE__, __FUNCTION__, std::to_string(__LINE__), std::this_thread::get_id(), "System starting...");
    LogMessage(EventCode::SystemStart, data);
    LogMessageInJSON(EventCode::SystemStart, data);
    LogMessageFile(EventCode::SystemStart, data);
}
int main()
{
    // starting the system
    start();
    return 0;
}
