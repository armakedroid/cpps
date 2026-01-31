#pragma once
#include <string>
#include <iostream>

class ScalarConvert
{
    private:
        ScalarConvert();
        ScalarConvert& operator=(const ScalarConvert &other);
        ScalarConvert(const ScalarConvert &other);
    public:
       static void convert(std::string s);
};