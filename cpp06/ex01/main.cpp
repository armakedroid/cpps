#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data d;
    Data* p1 = &d;

    uintptr_t raw = Serializer::serialize(p1);
    Data* p2 = Serializer::deserialize(raw);

    std::cout << (p1 == p2) << std::endl;
}
