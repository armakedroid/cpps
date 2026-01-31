#pragma once
#include <cstddef>

template <typename T>
void iter(T* arr, size_t len, void (*f)(T&))
{
    size_t i = 0;
    while (i < len)
    {
        f(arr[i]);
        i++;
    }
}

template <typename T>
void iter(const T* arr, size_t len, void (*f)(const T&))
{
    size_t i = 0;
    while (i < len)
    {
        f(arr[i]);
        i++;
    }
}
