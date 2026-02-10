#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN
{
    private:
        stack<int> s;
    public:
        void sol(std::string sa);
        RPN();
        ~RPN();
        RPN&operator=(const RPN& other);
        RPN(const RPN& other);
};