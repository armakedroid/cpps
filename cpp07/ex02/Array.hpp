#pragma once
#include <iostream>
#include <exception>
#include <cstddef>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
    public:
        Array();
        Array(const Array &other);
        Array(unsigned int n);
        Array &operator=(const Array &other);
        const T& operator[](unsigned int n) const;
        T& operator[](unsigned int n);
        ~Array();
        unsigned int size() const;   
        class except : public std::exception
        {
        public:
            const char* what() const throw()
            {
                return "out of range";
            }
        };
    private:
        T* _arr;
        unsigned int _size;
};
#include <Array.tpp>