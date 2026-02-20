#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <ctime>

class PmergeMe
{
private:
    std::deque<int> s_d;
    std::vector<int> s_v;

public:
    PmergeMe(int ac, char **av);
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator=(const PmergeMe &other);
    void sortvec(std::vector<int>& v);
    void sortdeque(std::deque<int>& d);
    void print_b();
    void print_a();
    void print_times(double v, double d);
    void run();
};