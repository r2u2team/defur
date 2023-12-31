#include "str.h"

std::string replace(std::string str, std::string oldStr, std::string newStr)
{
    std::string out = str;
    size_t pos = 0;

    while ((pos = out.find(oldStr)) != std::string::npos)
        out = out.replace(pos, oldStr.size(), newStr);

    return out;
}
std::vector<std::string> split(std::string str, std::string splitter)
{
    std::string data = str + splitter;
    std::vector<std::string> out{};
    size_t pos = 0;

    while ((pos = data.find(splitter)) != std::string::npos) {
        out.push_back(data.substr(0, pos));
        data.erase(0, pos + splitter.size());
    }

    return out;
}
