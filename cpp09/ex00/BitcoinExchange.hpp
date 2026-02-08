#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <string>


class BitcoinExchange
{
    private:
        std::map<std::string, double> _map;
    public:
        bool valid(const std::string &st);
        void database(const std::string& file);
        double getRate(const std::string& date);
        void procinput(const std::string &filename);
        BitcoinExchange();
        BitcoinExchange&operator=(const BitcoinExchange& other);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
};