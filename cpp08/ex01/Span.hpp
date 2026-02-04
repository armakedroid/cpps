#pragma once
#include <iostream>
#include <deque>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int    _a;
    std::deque<int> _s;

public:
    Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    Span(unsigned int N);
    void addNumber(int value);
    int shortestSpan();
    int longestSpan();
};
