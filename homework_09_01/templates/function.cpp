#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include "../headers/Vector.hpp"

template <typename T>
void 
mergeSort(Vector<T>& rhv)
{
    mergeSort(rhv.begin_, rhv.end_ - 1);
}

template <typename T>
void 
mergeSort(T* first, T* last)
{
    if (first >= last) return;

    T* middle = first + (last - first) / 2;

    mergeSort(first, middle);
    mergeSort(middle + 1, last);
    merge(first, middle, last);
}

template <typename T>
void
merge(T* first, T* middle, T* last)
{
    Vector<T> temp;

    T* left = first;
    T* right = middle + 1;
    while (left <= middle && right <= last) {
        if (*left <= *right) { 
            temp.push_back(*left++);
            continue;
        }
        temp.push_back(*right++);
    }
    while (left <= middle) temp.push_back(*left++);
    while (right <= last)  temp.push_back(*right++);
    std::copy(temp.begin(), temp.end(), first);
}

#endif /// __FUNCTION_CPP__

