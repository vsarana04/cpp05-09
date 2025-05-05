#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <list>

void printBefore(const std::vector<int>& data);
void printAfter(const std::vector<int>& data);
void printTiming(double vecTime, double listTime, size_t size);

#endif
