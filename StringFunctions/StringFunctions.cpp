//
// Created by Filip on 08-Apr-21.
//

#include "StringFunctions.h"

std::vector<std::string> splitLineByDelimiter(std::string line, std::string delimiter) {
    std::vector<std::string> splitLine;
    int position = 0;
    while ((position = line.find(delimiter)) != std::string::npos) {
        std::string token = line.substr(0, position);
        splitLine.push_back(token);
        line.erase(0, delimiter.length() + position);
    }
    splitLine.push_back(line);
    return splitLine;
}
