#include "Span.hpp"
int main()
{
    Span sp = Span(5);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}