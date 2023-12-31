#pragma once
#include <string>
#include <vector>
#include <algorithm>

std::string replace(std::string str, std::string oldStr, std::string newStr);
std::vector<std::string> split(std::string str, std::string splitter);

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
static std::string trim(std::string s) {
    std::string out = s;
    rtrim(out);
    ltrim(out);
    return out;
}
