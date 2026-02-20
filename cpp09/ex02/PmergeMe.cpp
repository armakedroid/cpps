#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->s_v = other.s_v;
    this->s_d = other.s_d;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->s_d = other.s_d;
        this->s_v = other.s_v;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char **s)
{
    (void)argc;
    for(int i = 1; s[i]; i++)
    {
        long a = std::strtol(s[i], NULL, 10);
        if (a < 0 || a > INT_MAX)
            throw (std::runtime_error("Error"));

        s_d.push_back(a);
        s_v.push_back(a);
    }
}

void PmergeMe::print_b()
{
    std::cout<<"Before : ";
    for(size_t i = 0; i < s_v.size(); i++)
        std::cout<<s_v[i]<<" ";
    std::cout<<std::endl;

}

void PmergeMe::print_a()
{
    std::cout<<"After : ";
    for(size_t i = 0; i < s_v.size(); i++)
        std::cout<<s_v[i]<<" ";
    std::cout<<std::endl;
    
}

void PmergeMe::print_times(double v, double d)
{
    std::cout << "Time to process a range of "
          << s_v.size()
          << " elements with vector : "
          << v << " us" << std::endl;
    std::cout << "Time to process a range of "
          << s_d.size()
          << " elements with vector : "
          << d << " us" << std::endl;

}
void PmergeMe::sortvec(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    std::vector<int> small;
    std::vector<int> big;
    size_t i = 0;
    while (i + 1 < v.size())
    {
        if (v[i] < v[i + 1])
        {
            small.push_back(v[i]);
            big.push_back(v[i + 1]);
        }
        else
        {
            small.push_back(v[i + 1]);
            big.push_back(v[i]);
        }
        i += 2;
    }
    int last = -1;
    bool hasLast = false;
    if (v.size() % 2 != 0)
    {
        last = v[v.size() - 1];
        hasLast = true;
    }
    sortvec(big);
    for (size_t j = 0; j < small.size(); j++)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), small[j]);

        big.insert(pos, small[j]);
    }
    if (hasLast)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), last);

        big.insert(pos, last);
    }
    v = big;
}

void PmergeMe::sortdeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;

    std::deque<int> small;
    std::deque<int> big;
    size_t i = 0;
    while (i + 1 < d.size())
    {
        if (d[i] < d[i + 1])
        {
            small.push_back(d[i]);
            big.push_back(d[i + 1]);
        }
        else
        {
            small.push_back(d[i + 1]);
            big.push_back(d[i]);
        }
        i += 2;
    }
    int last = -1;
    bool hasLast = false;
    if (d.size() % 2 != 0)
    {
        last = d[d.size() - 1];
        hasLast = true;
    }
    sortdeque(big);
    for (size_t j = 0; j < small.size(); j++)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), small[j]);

        big.insert(pos, small[j]);
    }
    if (hasLast)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), last);

        big.insert(pos, last);
    }
    d = big;
}


void PmergeMe::run()
{
    print_b();

    clock_t start = clock();
    sortvec(s_v);
    clock_t end = clock();
    double v = double(end - start)/CLOCKS_PER_SEC * 1000000;

    start = clock();
    sortdeque(s_d);
    end = clock();
    double d = double(end - start)/CLOCKS_PER_SEC * 1000000;
    print_a();
    print_times(v,d);
}
