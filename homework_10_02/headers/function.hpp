#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

template <typename T>
void mergeSort(Vector<T>& rhv);


template <typename T>
void mergeForVector(T* first, T* middle, T* last);

template <typename T>
void merge(typename SingleList<T>::Node* first,
           typename SingleList<T>::Node* middle,
           typename SingleList<T>::Node* last);


template <typename T>
void mergeForList(typename List<T>::Node* first, typename List<T>::Node* middle, typename List<T>::Node* last);

template <typename T>
void mergeSort(List<T>& list);

template <typename T>
void myAdvance(typename SingleList<T>::Node*& rhv, const size_t count);


template <typename T>
void mergeSort(SingleList<T>& list);


template <typename T>
void myAdvance(typename List<T>::Node*& rhv, const size_t count);

template <typename T>
size_t distanse(typename List<T>::Node* first, typename List<T>::Node* last);







#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP__

