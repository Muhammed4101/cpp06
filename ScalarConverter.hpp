#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other)
    
    public:
        static void convert(const std::string& literal);
    
};
    
# endif