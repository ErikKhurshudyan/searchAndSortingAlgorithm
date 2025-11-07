#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "Vector.hpp"

template <typename T>
void mergeSort(Vector<T>& rhv);

template <typename T>
void mergeSort(T* first, T* last);

template <typename T>
void merge(T* first, T* middle, T* last);

#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP__

