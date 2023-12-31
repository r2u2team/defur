#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "variable.h"
#include "str.h"

int main(int argc, char **argv)
{
    std::ifstream file(argv[1]);

    Variables vars{};

    for (std::string sourceLine; std::getline(file, sourceLine); ) {
        std::string line = replaceAllVars(trim(sourceLine), vars);

        std::vector<std::string> expressions = split(replace(line, ";", "&&"), "&&");
        for (std::string expression : expressions) {
            std::vector<std::string> words = split(replace(trim(expression), "\"", ""), " ");
            if (words[0] == "set") {
                std::vector<std::string> varExpression = split(words[1], "=");
                vars.push_back(Variable(varExpression[0], varExpression[1]));
            }
        }

        std::cout << line << std::endl;
    }
    return 0;
}
