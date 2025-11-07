#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"
#include <sstream>

template <typename Iterator>
void print(Iterator first, Iterator last, std::stringstream& ss);

template <typename T>
void bubbleSort(Vector<T>& rhv);

template <typename T>
void bubbleSort(List<T>& rhv);

template <typename T>
void bubbleSort(SingleList<T>& rhv);

#include "../templates/functions.cpp"

#endif /// __FUNCTIONS_HPP__
 
