#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "Vector.hpp"
#include "List.hpp"
#include "SingleList.hpp"

template <typename T>
bool linearSearch(const Vector<T>& rhv, const T& k);

template <typename T>
bool linearSearchHelper(T* begin, T* end, const T& k);

template <typename T>
bool linearSearch(const List<T>& rhv, const T& k);

template <typename T>
bool linearSearchHelper(typename List<T>::Node* first, typename List<T>::Node* end, const T& k);

template <typename T>
bool linearSearch(const SingleList<T>& rhv, const T& k);

template <typename T>
bool linearSearchHelper(typename SingleList<T>::Node* first, typename SingleList<T>::Node* end, const T& k);

#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP__

