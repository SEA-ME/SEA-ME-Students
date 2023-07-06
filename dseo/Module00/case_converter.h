#ifndef CASE_CONVERTER_H
#define CASE_CONVERTER_H

#include <string>
#include <algorithm>

class CaseConverter {
public:
    static std::string toUpperCase(const std::string& str);
    static std::string toLowerCase(const std::string& str);
};

std::string CaseConverter::toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string CaseConverter::toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

#endif  // CASE_CONVERTER_H
