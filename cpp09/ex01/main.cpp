#include "RPN.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr<<"your arguments count is not 2"<<std::endl;
        return 1;
    }
    RPN rpn;
    rpn.sol(argv[1]);
    return (0);
}