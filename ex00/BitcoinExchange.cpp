#include "BitcoinExchange.hpp"

int check_pipe(std::string line)
{
    int x = 0;
    for(int i = 0; line[i]; i++)
    {
        if(line[i] == '|')
            x++;
    }
    if(x != 1)
        return 1;
    return 0;
}

int check_year(std::string line)
{
    if(line.length() != 4)
        return 1;
    for(int i = 0;line[i]; i++)
    {
        if(!isdigit(line[i]))
            return 1;
    }
    return 0;
}

int check_mounth(std::string line)
{
    if(line.length() != 2)
        return 1;
    for(int i = 0;line[i]; i++)
    {
        if(!isdigit(line[i]))
            return 1;
    }
    int x = std::atoi(line.c_str());
    if(x <= 0 || x > 12)
        return 1;
    return 0;
}

int check_day(std::string mounth, std::string day,std::string year)
{
    if(day.length() != 2)
        return 1;
    for(int i = 0;day[i]; i++)
    {
        if(!isdigit(day[i]))
            return 1;
    }
    int d = std::atoi(day.c_str());
    int m = std::atoi(mounth.c_str());
    int y = std::atoi(year.c_str());

    if(m == 4 || m == 6 || m == 9 || m == 11)
    {
        if(d <= 0 || d >= 31)
            return 1;
    }
    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if(d <= 0 || d >= 32)
            return 1;
    }
    else
    {
        if(y % 4 == 0 && (y %100 != 0 || y % 400 == 0))
        {
            if(d <= 0 || d >= 30)
                return 1;
        }
        else
        {
            if(d <= 0 || d >= 29)
                return 1;
        }
    }
    return 0;
}

int check_date(std::string line, int *flag)
{
    int x = 0;
    for(int i = 0; line[i]; i++)
    {
        if(line[i] == '-')
            x++;
    }
    if(x != 2)
        return 1;
    std :: string date[3];
    size_t pos1 = line.find('-');
    size_t pos2 = line.find('-', pos1 + 1);

    date[0] = line.substr(0, pos1);
    date[1] = line.substr(pos1 + 1,pos2 - pos1 -1);
    date[2] = line.substr(pos2 + 1);

    if(check_year(date[0]) || check_mounth(date[1]) || check_day(date[1], date[2], date[0]))
        return 1;
    if(date[0] > "2022" || (date[0] == "2022" && date[1] > "03") ||(date[0] == "2022" && date[1] == "03" && date[2] > "29"))
        *flag = 2;
    else if(date[0] < "2009"  ||(date[0] == "2009" && date[1] == "01" && date[2] < "02"))
        *flag = 1;
    else
        *flag = 0;
    return 0;
}

int check_value(std::string line, double *value)
{
    int x = 0;
    if(line.empty())
    {
        std ::cout << "Eroor: bad input" << std::endl;
        return 1;
    }
    for(int i = 0; line[i]; i++)
    {
        if(line[i] == '.')
            x++;
    }
    if(x > 1)
    {
        std::cout << "Error: bad number"<<std::endl;
        return 1;
    }
    if(x == 1 && (line[0] == '.' || line[line.length() - 1] == '.'))
    {
        std::cout << "Error: bad number" << std::endl;
        return 1;
    }
    int i = 0;
    if(line[i] == '+' || line[i] == '-')
        i++;
    if((line[0] == '+' || line[0] == '-') && line.length() == 1)
    {
        std::cout << "Error: bad number" << std::endl;   
        return 1;
    }
    for(;line[i]; i++)
    {
        if(!isdigit(line[i]) && line[i] != '.')
        {
            std::cout << "Error: bad number" << std::endl;   
            return 1;
        }
        if(line[i] == '.' && !isdigit(line[i - 1]))
        {
            std::cout << "Error: bad number" << std::endl;   
            return 1;
        }  
     }
    double d = std::strtod(line.c_str(), NULL);
    if(d < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return 1;
    }
    if(d > 1000)
    {
        std ::cout << "Error: too large a number." << std::endl;
        return 1;
    }
    *value = d;
    return 0; 

}