#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

template <typename T1>
void count(Vector<T1>& rhv);

template <typename T1>
void count(List<T1>& rhv);

template <typename T1>
void count(SingleList<T1>& rhv);

#include "../templates/functions.cpp"

#endif /// __FUNCTIONS_HPP__
 
