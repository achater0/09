#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>


int check_pipe(std::string line);
int check_date(std::string line);
int check_value(std::string line, double *value);

#endif