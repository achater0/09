#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream file("data.csv");
    if(!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::map<std::string, std::string> data;
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        size_t pos = line.find(',');
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        data[key] = value;
    }
    file.close();

    std::string input[2];
    double value;
    std::ifstream file2(av[1]);
    if(!file2.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::getline(file2,line);
    if(line != "date | value")
    {
        std::cout << "Error: bad input" << std::endl;
        return 0;
    }
    while(std::getline(file2,line))
    {
        if(check_pipe(line))
        {
            std::cout << "Error: bad input => "<< line << std::endl;
            continue;
        }
        size_t pos = line.find('|');
        input[0] = line.substr(0, pos - 1);
        input[1] = line.substr(pos + 2);
        if(check_date(input[0]))
        {
            std :: cout << "Error: not a valid date" << std::endl;
            continue;
        }
        if(check_value(input[1], &value))
            continue;
        std ::cout << value << std::endl;


    }

    return 0;
}