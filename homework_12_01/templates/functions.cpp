#ifndef __FUNCTIONS_CPP__
#define __FUNCTIONS_CPP__

#include "../headers/functions.hpp"
#include <cstddef>
#include <stack>
#include <algorithm> 

template <typename T>
void quickSort(Vector<T>& rhv)
{
    if (rhv.size() <= 1) return;
    quickSort(rhv.begin_, rhv.end_);
}

template <typename T>
void
quickSort(T* first, T* last)
{
    if (first >= last) return;

    std::stack<std::pair<T*, T*> > stack;
    stack.push(std::make_pair(first, last - 1));

    while (!stack.empty()) {
        std::pair<T*, T*> range = stack.top();
        stack.pop();

        T* low = range.first;
        T* high = range.second;

        if (low >= high) continue;

        T* pivotPosition = partition(low, high);

        if (pivotPosition + 1 < high) stack.push(std::make_pair(pivotPosition + 1, high));
        if (low < pivotPosition - 1)  stack.push(std::make_pair(low, pivotPosition - 1));
    }
}

template <typename T>
T*
partition(T* first, T* last)
{
    T* pivotIt = last;
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
    if (first == last || NULL == first || NULL == last) return;
    std::stack<std::pair<typename List<T>::Node*, typename List<T>::Node*> > stack;
    stack.push(std::make_pair(first, last->prev_));

    while (!stack.empty()) {
        std::pair<typename List<T>::Node*, typename List<T>::Node*> range = stack.top();
        stack.pop();

        typename List<T>::Node* low = range.first;
        typename List<T>::Node* high = range.second;

        if (low == high) continue;

        typename List<T>::Node* pivotPosition = partitionList<T>(low, high);
        if (pivotPosition->next_ != NULL && pivotPosition->next_ != high->next_) {
            stack.push(std::make_pair(pivotPosition->next_, high));
        }
        if (pivotPosition != NULL && low != pivotPosition) {
            stack.push(std::make_pair(low, pivotPosition->prev_));
        }
    }
}

template <typename T>
typename List<T>::Node* 
partitionList(typename List<T>::Node* first, typename List<T>::Node* last)
{
    typename List<T>::Node* pivotIt = last;
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
    if (first == last || NULL == first || NULL == last) return;
    std::stack<std::pair<typename SingleList<T>::Node*, typename SingleList<T>::Node*> > stack;
    const size_t count1 = distanse(first, last);
    typename SingleList<T>::Node* previousLast = first;
    myAdvance(previousLast, count1);

    stack.push(std::make_pair(first, previousLast));

    while (!stack.empty()) {
        std::pair<typename SingleList<T>::Node*, typename SingleList<T>::Node*> range = stack.top();
        stack.pop();

        typename SingleList<T>::Node* low = range.first;
        typename SingleList<T>::Node* high = range.second;

        if (low == high) continue;

        typename SingleList<T>::Node* pivotPosition = partitionList<T>(low, high);
        if (pivotPosition->next_ != NULL && pivotPosition->next_ != high->next_) {
            stack.push(std::make_pair(pivotPosition->next_, high));
        }
        if (pivotPosition != NULL && low != pivotPosition) {
            const size_t count2 = distanse(first, last);
            typename SingleList<T>::Node* previousPivotPosition = first;
            myAdvance(previousLast, count2);
            stack.push(std::make_pair(low, previousPivotPosition));
        }
    }
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

