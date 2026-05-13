#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }


static bool isChar(const std::string& str)
{
    return str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]);
}

static bool isInt(const std::string& str)
{
    size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++)
    {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}