#include "../headers/function.hpp"

template <typename T>
bool
linearSearch(const Vector<T>& rhv, const T& key)
{
    return linearSearchHelper(rhv.begin_, rhv.end_, key);
}

template <typename T>
bool
linearSearchHelper(T* begin, T* end, const T& key)
{
    if (begin >= end)  return false;
    if (key == *begin) return true;
    return linearSearchHelper(begin + 1, end, key);
}


template <typename T>
bool
linearSearchHelper(typename List<T>::Node* first, typename List<T>::Node* end, const T& key)
{
    if (first == end)        return false;
    if (key == first->data_) return true;
    return linearSearchHelper(first->next_, end, key);
}

template <typename T>
bool
linearSearch(const List<T>& rhv, const T& key)
{
    typename List<T>::Node* first = rhv.begin_;
    typename List<T>::Node* end = rhv.end_;
    return linearSearchHelper(first, end, key);
}

template <typename T>
bool
linearSearchHelper(typename SingleList<T>::Node* first, typename SingleList<T>::Node* end, const T& key)
{
    if (first == end)       return false;
    if (key == first->data_) return true;
    return linearSearchHelper(first->next_, end, key);
}

template <typename T>
bool
linearSearch(const SingleList<T>& rhv, const T& key)
{
    return linearSearchHelper(rhv.begin_, rhv.end_, key);
}

