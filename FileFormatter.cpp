#include "FileFormatter.h"
#include "ILoggableEvent.h"
#include <iostream>

std::string FileFormatter::Format(ILoggableEvent& event)
{
    std::map<Enumerations::FieldKeyDictionary, std::string> keyValues = event.Tokenize();
    std::string formattedString;

    formattedString += keyValues.find(Enumerations::FieldKeyDictionary::Level)->second + ":" +
        keyValues.find(Enumerations::FieldKeyDictionary::File)->second + ":" +
        keyValues.find(Enumerations::FieldKeyDictionary::Function)->second + ":" +
        keyValues.find(Enumerations::FieldKeyDictionary::Line)->second + "\n";

    return formattedString;
}
