#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <cstddef>


template <typename InputIterator, typename key>
InputIterator
linearSearch(InputIterator first, InputIterator last, const key& value)
{
    while (first != last) {
        if (value == *first) {
            return first;
        }
        ++first;
    }
    return last;
}

#endif /// __FUNCTION_CPP__

