#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if(ac == 1)
    {
        std ::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    std::deque<int> deq;
    for(int i = 1; av[i];i++)
    {
        if(check(av[i]))
        {
            std ::cerr << "Error" << std::endl;
            return 1;
        }
        double d = std::strtod(av[i], NULL);
        if(d == HUGE_VAL || d > 2147483647)
        {
            std ::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(d);
        deq.push_back(d);
    }
    sort_vec(vec);
    
}