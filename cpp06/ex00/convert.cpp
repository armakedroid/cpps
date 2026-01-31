#include "convert.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <climits>
#include <cstdlib>  

bool isInt(std::string s)
{
    int i = 0;
    if (s[i] == '+' || s[i] == '-' )
        i++;
    if (!s[i])
        return (false);
    while(s[i] != '\0')
    {
        if (!isdigit(s[i]))
            return (false);
        i++;
    }
    return(true);

}

void ScalarConvert::convert(std::string s)
{
    long b;
    long val;
    float c;
    double d;
    char *endptr;

    if (s.empty())
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: impossible"<<std::endl;
        std::cout<<"double: impossible"<<std::endl;
        return ;
    }
    if (s.size() == 1)
    {
        std::cout << "char: '" << s[0] << "'" << std::endl;
    }
    else if (isInt(s))
    {
        val = strtol(s.c_str(), NULL, 10);
    if (val < 0 || val > 127)
        std::cout << "char: impossible\n";
    else if (val < 32 || val > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(val) << "'\n";
    }
    else
        std::cout << "char: impossible\n";

    if (isInt(s))
    {
        b = std::strtol(s.c_str(), NULL, 10);
        if (b < INT_MIN || b > INT_MAX)
            std::cout<<"int: impossible"<<std::endl;
        else
            std::cout<<"int: "<<b<<std::endl;
    }
    else
    {
        std::cout<<"int: impossible"<<std::endl;
    }
    std::cout << std::fixed << std::setprecision(1);
    if (s == "nanf" || s == "+inff" || s == "-inff")
        std::cout << "float: " << s << std::endl;
    else
    {
    c = static_cast<float>(strtod(s.c_str(), &endptr));
    if (*endptr != '\0')
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << c << "f" << std::endl;
    }
    if (s == "nan" || s == "+inf" || s == "-inf")
        std::cout << "double: " << s << std::endl;
    else
    {
        d = strtod(s.c_str(), &endptr);
        if (*endptr != '\0')
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
}
