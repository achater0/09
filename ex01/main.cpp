#include "RPN.hpp"

int main(int ac,char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    if(check(av[1]))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::stack<int> s;

    for(int i =0; av[1][i]; i++)
    {
        if(isdigit(av[1][i]))
        {
            int x = av[1][i] - '0';
            s.push(x);
        }
        else if(!is_op(av[1][i]))
        {
            if(s.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            int a = s.top();
            s.pop();
            int b = s.top();
            int res;
            s.pop();
            if(av[1][i] == '/' && a == 0)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            if(av[1][i] == '+')
                res = a + b;
            else if(av[1][i] == '-')
                res = b - a;
            else if(av[1][i] == '*')
                res = b * a;
            else
                res = b / a;
            s.push(res);
        }
    }
    std :: cout << s.top() << std ::endl;
    
}