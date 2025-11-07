#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "SingleList.hpp"
#include "../headers/Vector.hpp"
#include "../headers/List.hpp"
#include "../headers/SingleList.hpp"
#include "../headers/Set.hpp"

template <typename T>
bool linearSearch(const Vector<T>& rhv, const T& k);

template <typename T>
bool linearSearch(const List<T>& rhv, const T& k);

template <typename T>
bool linearSearch(const SingleList<T>& rhv, const T& k);

template <typename T>
bool linearSearch(const Set<T>& rhv, const T& k);


#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP__

