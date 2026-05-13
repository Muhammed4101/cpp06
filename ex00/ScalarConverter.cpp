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

static bool isFloat(const std::string& str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    if (str[str.length() - 1] != 'f')
        return false;
    
    size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    bool dot = false;
    bool digit = false;
    
    for (; i < str.length() - 1; i++) 
    {
        if (str[i] == '.') 
        {
            if (dot) return false;
                dot = true;
        }
        else if (std::isdigit(str[i]))
            digit = true;
        else
            return false;
    }
    return digit && dot;
}

static bool isDouble(const std::string& str) {
    if (str == "-inf" || str == "+inf" || str == "nan") return true;
    
    size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    bool dot = false;
    bool digit = false;
    
    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (dot) return false;
                dot = true;
        }
        else if (std::isdigit(str[i]))
            digit = true;
        else
            return false;
    }
    return digit && dot;
}

void ScalarConverter::convert(const std::string& str) 
{
    bool imp_c = false, imp_i = false, imp_f = false, imp_d = false;
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    bool pseudo = (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");

    if (isChar(str)) 
    {
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } 
    else if (isInt(str)) 
    {
        long l = std::strtol(str.c_str(), NULL, 10);
        if (l < INT_MIN || l > INT_MAX)
        {
            imp_i = true; imp_c = true;
            d = std::strtod(str.c_str(), NULL);
            f = static_cast<float>(d);
        }
        else 
        {
            i = static_cast<int>(l);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
    } 
    else if (isFloat(str)) 
    {
        f = static_cast<float>(std::strtod(str.c_str(), NULL));
        d = static_cast<double>(f);
        if (pseudo || d < INT_MIN || d >= 2147483648.0) 
        {
            imp_i = true; imp_c = true;
        }
        else 
        {
            i = static_cast<int>(f);
            c = static_cast<char>(i);
        }
    }
    else if (isDouble(str)) 
    {
        d = std::strtod(str.c_str(), NULL);
        f = static_cast<float>(d);
        if (pseudo || d < INT_MIN || d >= 2147483648.0)
        {
            imp_i = true; imp_c = true;
        }
        else 
        {
            i = static_cast<int>(d);
            c = static_cast<char>(i);
        }
    } 
    else 
    {
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (!imp_i && (i < 0 || i > 127)) 
    {
        imp_c = true;
    }

    std::cout << "char:   ";
    if (imp_c)
        std::cout << "impossible";
    else if (!std::isprint(c))
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;


    std::cout << "int:    ";
    if (imp_i)
        std::cout << "impossible";
    else
        std::cout << i;
    std::cout << std::endl;


    std::cout << "float:  ";
        if (imp_f)
            std::cout << "impossible";
        else 
        {
            std::cout << f;
            if (f - std::floor(f) == 0.0 && !pseudo && f < 999999.0f && f > -999999.0f) 
                std::cout << ".0";
            std::cout << "f";
        }
        std::cout << std::endl;

        std::cout << "double: ";
        if (imp_d)
            std::cout << "impossible";
        else 
        {
            std::cout << d;
            if (d - std::floor(d) == 0.0 && !pseudo && d < 999999.0 && d > -999999.0) 
                std::cout << ".0";
        }
        std::cout << std::endl;
}