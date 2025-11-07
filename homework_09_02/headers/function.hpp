#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

template <typename T1> 
void mergeSort(Vector<T1>& rhv);

template <typename T1> 
void mergeSort(T1* first, T1* last);

template <typename T1> 
void merge(T1* first, T1* middle, T1* last);
    
template <typename T1>
void mergeSort(List<T1>& rhv);

template <typename T1>
void mergeSort1(typename List<T1>::Node* first, typename List<T1>::Node* last);

template <typename T1>
void merge1(typename List<T1>::Node* first, typename List<T1>::Node* middle, typename List<T1>::Node* last);

template <typename T>
typename List<T>::Node*
myAdvance1(typename List<T>::Node* rhv, const size_t count);

template <typename T>
size_t myDistance1(typename List<T>::Node* first, typename List<T>::Node* last);
////////////////////////////
template <typename T1>
typename SingleList<T1>::Node*
mergeSortNodes(typename SingleList<T1>::Node* head);

template <typename T1>
typename SingleList<T1>::Node*
mergeNodes(typename SingleList<T1>::Node* left,
           typename SingleList<T1>::Node* right);

template <typename T1>
void
mergeSort(SingleList<T1>& rhv);

template <typename T>
void myAdvance(typename List<T>::Node* rhv, const size_t count);
template <typename T>
size_t myDistance(typename List<T>::Node* first, typename List<T>::Node* last);

template <typename T>
void myAdvance(typename SingleList<T>::Node* rhv, const size_t count);
template <typename T>
size_t myDistance(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last);

#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP__

