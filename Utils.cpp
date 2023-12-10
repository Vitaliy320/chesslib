#include "Utils.h"


std::vector<std::string> splitString(const std::string input, const char delimiter) {
    std::vector<std::string> output;
    size_t start = 0;
    size_t end = 0;

    while ((end = input.find(delimiter, start)) != std::string::npos) {
        output.push_back(input.substr(start, end - start));
        start = end + 1;
    }

    output.push_back(input.substr(start));
    return output;
}
