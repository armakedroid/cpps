#include "iter.hpp"
#include <iostream>
#include <cstddef>

template <typename T>
void f(const T& a)
{
    std::cout<<"your charecter = "<<a<<std::endl;
}

int main()
{
    char a[4] = "Art";
    int c[4] = {23, 1, 1, 432};
    const int b = 4;
    iter(a, b, f);
    iter(c, b, f);
}