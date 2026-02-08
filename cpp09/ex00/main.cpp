#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.database("data.csv");
    btc.procinput(argv[1]);
}