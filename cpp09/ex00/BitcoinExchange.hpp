#pragma once
#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _map;
    public:
        bool valid(const std::string &st);
        void database(const std::string& file);
        void procinput(const std::string &filename);
        BitcoinExchange();
        BitcoinExchange&operator=(BitcoinExchange& other);
        BitcoinExchange(BitcoinExchange &other);
        ~BitcoinExchange();
};