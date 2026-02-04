#include "Span.hpp"

Span::Span(unsigned int N) : _a(N) {}
Span::Span() :_a(0){}
Span::~Span(){}
Span& Span::operator=(const Span &other)
{
    if (this != &other)
        return *this ;
    return *this;
}

void Span::addNumber(int i)
{
    if (_s.size() >= _a)
        throw std::runtime_error("Span is full");
    _s.push_back(i);
}

int Span::shortestSpan()
{
    if (_s.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::deque<int> tmp = _s;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan()
{
    if (_s.size() < 2)
        throw std::runtime_error("Not enough numbers");
    int min = *std::min_element(_s.begin(), _s.end());
    int max = *std::max_element(_s.begin(), _s.end());
    return max - min;
}
