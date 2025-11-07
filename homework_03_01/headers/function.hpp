#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"
#include "Set.hpp"

template <typename T>
bool binarySearch(const Vector<T>& rhv, const T& k);

template <typename T>
bool binarySearch(const List<T>& rhv, const T& k);

template <typename T>
bool binarySearch(const SingleList<T>& rhv, const T& k);

template <typename T>
bool binarySearch(const Set<T>& rhv, const T& k);

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

