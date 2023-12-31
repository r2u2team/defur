#include <iostream>
#include "variable.h"
#include "str.h"

std::string getValue(std::string name, Variables vars)
{
    for (Variable var : vars)
        if (var.getName() == name)
            return (std::string) var;
    return std::string("");
}

std::string replaceAllVars(std::string line, Variables vars)
{
    std::string out = "";
    bool inVar = false;
    std::string expression{};

    for (char ch : line) {
        if (ch == '%') {
            inVar = !inVar;
            if (!inVar) {
                size_t pos = 0;
                if ((pos = expression.find(":~")) != std::string::npos) {
                    std::string name = split(expression, ":~")[0];
                    std::string index = split(expression, ":~")[1];
                    int valueIndex = std::stoi(split(index, ",")[0]);
                    int valueLength = std::stoi(split(index, ",")[1]);

                    std::string outputExpression = getValue(name, vars);
                    if (!outputExpression.empty())
                        out += outputExpression.substr(valueIndex, valueLength);
                }
                else
                    out += getValue(expression, vars);
                expression.clear();
            }
        }
        else if (inVar)
            expression += ch;
        else
            out += ch;
    }

    return out;
}
