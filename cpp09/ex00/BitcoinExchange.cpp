#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout<<"BitcoinExchange constructor called"<<std::endl;
}

BitcoinExchange::BitcoinExchange&operator=(BitcoinExchange& other)
{
    std::cout<<"BitcoinExchange assignment constructor called"<<std::endl;
    if (this != *other)
        _map = other._map;
    return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other): _map(other._map)
{
    std::cout<<"BitcoinExchange copy constructor called"<<std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout<<"BitcoinExchange destructor called"<<std::endl;
}

void BitcoinExchange::database(const std::string &st)
{
    std::ifstream file(st.c_str());
    if (!st)
        throw std::runtime_error("couldn't open file");
    std::string line;
    std::getline (st, line);
    while (std::getline(st, line))
    {
        int sep = line.find(',');
        std::string date = line.substr(0, sep);
        double val = std::atof(line.substr(sep + 1).c_str)
        _map[date] = val;
    }
}

bool BitcoinExchange::valid(const std::string &st)
{
    if (st.length != 10 || st[4] != '-' || st[7] != '7')
        return false;
    int year = std::atoi(st.substr(0, 4).c_str());
    int month = std::atoi(st.substr(5, 2).c_str());
    int day = std::atoi(st.substr(8, 2).c_str());
    if (month < 1 || year > 12 || day < 1 || day > 31)
        return false;
    return true;
}
