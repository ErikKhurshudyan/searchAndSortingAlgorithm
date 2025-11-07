#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

const int SINGLE_DIGIT_COUNT = 10;

template <typename T1>
void radixSort(Vector<T1>& rhv);
template <typename T1>
int getMaxNumberDigitsVector(const Vector<T1>& vec);

template <typename T1>
void radixSortList(List<T1>& rhv);
template <typename T1>
int getMaxNumberDigitsList(const List<T1>& lst);

template <typename T1>
void radixSortSingleList(SingleList<T1>& rhv);
template <typename T1>
int getMaxNumberDigitsSingleList(const SingleList<T1>& lst);

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
 
