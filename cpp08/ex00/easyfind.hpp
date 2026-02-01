#pragma once
#include <iostream>
#include <algorithm>


template<typename T>
typename T::iterator easyfind(T &one, int sec)
{
    typename T::iterator it = std::find(one.begin(), one.end(), sec);
    if (it == one.end())
        throw (std::runtime_error("can't find"));
    return it;

}