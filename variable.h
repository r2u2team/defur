#pragma once
#include <string>
#include <vector>

class Variable
{
private:
    std::string name;
    std::string value;
public:
    Variable(std::string name, std::string value)
    {
        this->name = name;
        this->value = value;
    }
    std::string getName()
    {
        return this->name;
    }

    operator std::string() const
    {
        return this->value;
    }
    operator bool() const
    {
        return !(this->value.empty());
    }
    char operator[](unsigned index) const
    {
        return this->value[index];
    }
};
typedef std::vector<Variable> Variables;

std::string replaceAllVars(std::string line, Variables vars);
