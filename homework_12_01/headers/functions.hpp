#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

template <typename T>
void quickSort(Vector<T>& rhv);
template <typename T>
void quickSort(T* first, T* last);
template <typename T>
T* partition(T* first, T* last);

template <typename T>
void quickSortList(List<T>& rhv);
template <typename T>
void quickSortList(typename List<T>::Node* first, typename List<T>::Node* last);
template <typename T>
typename List<T>::Node* partitionList(typename List<T>::Node* first, typename List<T>::Node* last);

template <typename T>
void quickSortSingleList(SingleList<T>& rhv);
template <typename T>
void quickSortSingleList(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last);
template <typename T>
typename SingleList<T>::Node* partitionSingleList(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last);

template <typename T>
void myAdvance(typename List<T>::Node* rhv, const size_t count);
template <typename T>
size_t distanse(typename List<T>::Node* first, typename List<T>::Node* last);

template <typename T>
void myAdvance(typename SingleList<T>::Node* rhv, const size_t count);
template <typename T>
size_t distanse(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last);


#include "../templates/functions.cpp"

#endif /// __FUNCTIONS_HPP__
 
