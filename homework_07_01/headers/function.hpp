#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

template <typename T>
void selectionSort(Vector<T>& rhv);

template <typename T>
void selectionSort(List<T>& rhv);

template <typename T>
void selectionSort(SingleList<T>& rhv);

#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP__

