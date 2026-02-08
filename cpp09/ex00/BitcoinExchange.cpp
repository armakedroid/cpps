#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout<<"BitcoinExchange constructor called"<<std::endl;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange& other)
{
    std::cout<<"BitcoinExchange assignment constructor called"<<std::endl;
    if (this != &other)
        _map = other._map;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _map(other._map)
{
    std::cout<<"BitcoinExchange copy constructor called"<<std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout<<"BitcoinExchange destructor called"<<std::endl;
}

void BitcoinExchange::database(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("couldn't open file");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t sep = line.find(',');
        if (sep == std::string::npos)
            continue;
        std::string date = line.substr(0, sep);
        double val = std::atof(line.substr(sep + 1).c_str());
        _map[date] = val;
    }
}


bool BitcoinExchange::valid(const std::string &st)
{
    if (st.length() != 10 || st[4] != '-' || st[7] != '-')
        return false;
    int year = std::atoi(st.substr(0, 4).c_str());
    int month = std::atoi(st.substr(5, 2).c_str());
    int day = std::atoi(st.substr(8, 2).c_str());
    if (month < 1 || year > 12 || day < 1 || day > 31)
        return false;
    return true;
}

double BitcoinExchange::getRate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _map.lower_bound(date);
    if (it != _map.end() && it->first == date)
        return it->second;
    if (it == _map.begin())
        throw std::runtime_error("no earlier date available.");
    --it;
    return it->second;
}

void BitcoinExchange::procinput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        std::string val = line.substr(sep + 3);
        double ret = std::atof(val.c_str());
        if (!valid(date))
        {
            std::cerr << "bad input => " << date << std::endl;
            continue;
        }
        if (ret < 0)
        {
            std::cerr << "not a positive number." << std::endl;
            continue;
        }
        if (ret > 1000)
        {
            std::cerr << "too large a number." << std::endl;
            continue;
        }
        try
        {
            double rate = getRate(date);
            std::cout << date << " => " << ret
                      << " = " << ret * rate << std::endl;
        }
        catch (...)
        {
            std::cerr << "bad input => " << date << std::endl;
        }
    }
}