#pragma once
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double i> _map;
    public:
        bool valid(const std::string &st);
        void database(const std::string& file);
        BitcoinExchange();
        BitcoinExchange&operator=(BitcoinExchange& other);
        BitcoinExchange(BitcoinExchange &other);
        ~BitcoinExchange();

}