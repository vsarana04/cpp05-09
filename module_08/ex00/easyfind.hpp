#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <iostream>
#include "easyfind.tpp"

template <typename T>
typename T::iterator easyfind(T& container, int value);


#endif