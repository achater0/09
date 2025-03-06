#include "RPN.hpp"

int is_op(char c)
{
    if(c != '+' && c != '-' & c != '*' && c != '/')
        return 1;
    return 0;
}

int check(char *s)
{
    int n = 0;
    int o = 0;
    for(int i = 0;s[i]; i++)
    {
        if(!isdigit(s[i]) && s[i] != ' ' && is_op(s[i]))
            return 1;
        if((isdigit(s[i]) ||!is_op(s[i])) && (s[i +1] != ' ' && s[i + 1] != '\0'))
            return 1;
        if (isdigit(s[i]))
            n++;
        if(!is_op(s[i]))
            o++;
    }
    if(n != (o + 1))
        return 1;
    if(n < 2)
        return 1;
    return 0;
}