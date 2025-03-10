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
    std ::cout << "Before:";
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cout << " " <<vec[i];
    }
    std::cout << std::endl;
    clock_t start_vec = clock();
    vec = sort_vec(vec);
    clock_t end_vec = clock();
    double time_vec = ((double)(end_vec - start_vec) / CLOCKS_PER_SEC) * 1000000.0;

    clock_t start_deq = clock();
    deq = sort_deque(deq);
    clock_t end_deq = clock();
    double time_deq = ((double)(end_deq - start_deq) / CLOCKS_PER_SEC) * 1000000.0;

    std ::cout << "After: ";
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cout << " " <<vec[i];
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_vec << " us\n";
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << time_deq << " us\n";
}