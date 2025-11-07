#ifndef __FUNCTIONS_CPP__
#define __FUNCTIONS_CPP__

#include "../headers/functions.hpp"
#include <iostream>

template <typename T>
void 
quickSort(Vector<T>& rhv)
{
    if (0 == rhv.size()) return;
    quickSort(rhv.begin_, rhv.end_);
}

template <typename T>
void
quickSort(T* first, T* last)
{
    if (first == last)     return; 
    if (first + 1 == last) return;
    T* pivot = partition(first, last);

    quickSort(first, pivot);
    quickSort(pivot + 1, last);
}

template <typename T>
T*
partition(T* first, T* last)
{
    T* pivotIt = last - 1;
    T pivot = *pivotIt;

    T* i = first;
    for (T* j = first; j != pivotIt; ++j) {
        if (*j < pivot) {
            std::swap(*i, *j);
            ++i;
        }
    }
    std::swap(*i, *pivotIt);
    return i;
}
/// ======List=====

template <typename T>
void 
quickSortList(List<T>& rhv)
{
    if (!rhv.begin_ || rhv.begin_ == rhv.end_) return;
    quickSortList<T>(rhv.begin_, rhv.end_);
}

template <typename T>
void 
quickSortList(typename List<T>::Node* first, typename List<T>::Node* last)
{
    if (first == last) return;
    typename List<T>::Node* next = first->next_;
    if (next == last) return;

    typename List<T>::Node* pivot = partitionList<T>(first, last);

    quickSortList<T>(first, pivot);
    quickSortList<T>(pivot->next_, last);
}

template <typename T>
typename List<T>::Node* 
partitionList(typename List<T>::Node* first, typename List<T>::Node* last)
{
    typename List<T>::Node* pivotIt = last->prev_;
    T pivot = pivotIt->data_;
    typename List<T>::Node* i = first;

    for (typename List<T>::Node* j = first; j != pivotIt; j = j->next_) {
        if (j->data_ < pivot) {
            std::swap(i->data_, j->data_);
            i = i->next_;
        }
    }

    std::swap(i->data_, pivotIt->data_);
    return i;
}

template <typename T>
void
quickSortSingleList(SingleList<T>& rhv)
{
    quickSortSingleList<T>(rhv.begin_, rhv.end_);
}

template <typename T>
void
quickSortSingleList(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last)
{
    if (first == last) return;
    typename SingleList<T>::Node* next = first->next_;
    if (next == last) return;

    typename SingleList<T>::Node* pivot = partitionList<T>(first, last);
    quickSortList<T>(first, pivot);
    quickSortList<T>(pivot->next_, last);
}

template <typename T>
typename SingleList<T>::Node*
partitionSingleList(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last)
{
    const size_t count = distanse(first, last);
    typename SingleList<T>::Node* pivotIt = first;
    myAdvance(pivotIt, count);
    T pivot = pivotIt->data_;
    typename List<T>::Node* i = first;

    for (typename List<T>::Node* j = first; j != pivotIt; j = j->next_) {
        if (j->data_ < pivot) {
            std::swap(i->data_, j->data_);
            i = i->next_;
        }
    }

    std::swap(i->data_, pivotIt->data_);
    return i;
}

template <typename T>
void
myAdvance(typename List<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; i < count; ++i) rhv = rhv->next_;
}

template <typename T>
size_t
distanse(typename List<T>::Node* first, typename List<T>::Node* last)
{
    size_t i = 0;
    for (typename List<T>::Node* ptr = first; ptr != last; ptr = ptr->next_) ++i;
    return i;
}

template <typename T>
void
myAdvance(typename SingleList<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; i < count; ++i) rhv = rhv->next_;
}

template <typename T>
size_t
distanse(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last)
{
    size_t i = 0;
    for (typename List<T>::Node* ptr = first; ptr != last; ptr = ptr->next_) ++i;
    return i;
}

#endif /// __FUNCTIONS_HPP__

