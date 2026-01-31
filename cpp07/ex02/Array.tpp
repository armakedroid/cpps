#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array():_arr (NULL), _size(0){}

template <typename T>
Array<T>::Array(const unsigned int n): _arr(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
    _size = other._size;
    _arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] _arr;
        _size = other._size;
        _arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
    if (n >= this->_size)
        throw except();
    return this->_arr[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
    if (n >= this->_size)
        throw except();
    return this->_arr[n];
}

template <typename T>
unsigned int Array<T>::size() const {return this->_size;}

template <typename T>
Array<T>::~Array(){delete[] _arr; _size = 0;}