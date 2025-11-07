#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"

template <typename InputIterator, typename key>
InputIterator
linearSearch(InputIterator first, InputIterator last, const key& value)
{
    if (first == last)   return last; 
    if (*first == value) return first;
    return linearSearch(++first, last, value);
}

#endif /// __FUNCTION_CPP__

