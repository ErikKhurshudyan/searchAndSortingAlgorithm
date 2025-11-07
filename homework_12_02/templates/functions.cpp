#ifndef __FUNCTIONS_CPP__
#define __FUNCTIONS_CPP__

#include "../headers/functions.hpp"
#include <cstddef>
#include <stack>
#include <algorithm> 

template <typename T>
int
getMaxNumberDigitsVector(const Vector<T>& vec)
{
    assert(vec.size() > 0);
    T max = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    int digits = 0;
    while (max > 0) {
        max /= SINGLE_DIGIT_COUNT;
        ++digits;
    }
    return digits;
}

template <typename T>
void
radixSort(Vector<T>& vec)
{
    if (0 == vec.size()) return;

    const int digitOfMaxNumber = getMaxNumberDigitsVector(vec);

    Vector<Vector<T> > buckets(SINGLE_DIGIT_COUNT);     ////
    int power = 1;

    for (int d = 0; d < digitOfMaxNumber; ++d) {
        for (int i = 0; i < SINGLE_DIGIT_COUNT; ++i) {
            buckets[i].clear();
        }
        for (size_t i = 0; i < vec.size(); ++i) {
            const int index = (vec[i] / power) % SINGLE_DIGIT_COUNT;
            buckets[index].push_back(vec[i]);
        }

        size_t position = 0;
        for (int i = 0; i < SINGLE_DIGIT_COUNT; ++i) {
            for (size_t j = 0; j < buckets[i].size(); ++j) {
                vec[position++] = buckets[i][j];
            }
        }
        power *= SINGLE_DIGIT_COUNT;
    }
}

template <typename T1>
int
getMaxNumberDigitsList(const List<T1>& lst)
{
    assert(!lst.empty());

    typename List<T1>::Node* current = lst.begin_;
    T1 max = current->data_;

    while (current != lst.end_) { 
        if (current->data_ > max) {
            max = current->data_;
        }
        current = current->next_;
    }
    int digits = 0;
    while (max > 0) {
        max /= SINGLE_DIGIT_COUNT;
        ++digits;
    }

    if (0 == digits) digits = 1;

    return digits;
}


template <typename T1>
void
radixSortList(List<T1>& lst)
{
    if (lst.empty()) return;

    const int digitOfMaxNumber = getMaxNumberDigitsList(lst);
    List<T1> buckets[SINGLE_DIGIT_COUNT];
    int power = 1;

    for (int d = 0; d < digitOfMaxNumber; ++d) {
        for (int i = 0; i < SINGLE_DIGIT_COUNT; ++i)
            buckets[i].clear();

        typename List<T1>::Node* current = lst.begin_;
        while (current != lst.end_) {
            int index = (current->data_ / power) % SINGLE_DIGIT_COUNT;
            buckets[index].push_back(current->data_);
            current = current->next_;
        }

        lst.clear();
        for (int i = 0; i < SINGLE_DIGIT_COUNT; ++i) {
            typename List<T1>::Node* cur = buckets[i].begin_;
            while (cur != buckets[i].end_) {
                lst.push_back(cur->data_);
                cur = cur->next_;
            }
        }

        power *= SINGLE_DIGIT_COUNT;
    }
}

template <typename T1>
int
getMaxNumberDigitsSingleList(const SingleList<T1>& lst)
{
    assert(!lst.empty());

    typename SingleList<T1>::Node* current = lst.begin_;
    T1 max = current->data_;

    while (current != lst.end_) { 
        if (current->data_ > max) {
            max = current->data_;
        }
        current = current->next_;
    }
    int digits = 0;
    while (max > 0) {
        max /= SINGLE_DIGIT_COUNT;
        ++digits;
    }

    if (0 == digits) digits = 1;

    return digits;
}


template <typename T1>
void
radixSortSingleList(SingleList<T1>& lst)
{
    if (lst.empty()) return;

    const int digitOfMaxNumber = getMaxNumberDigitsSingleList(lst);
    SingleList<T1> buckets[SINGLE_DIGIT_COUNT];
    int power = 1;

    for (int d = 0; d < digitOfMaxNumber; ++d) {
        for (int i = 0; i < SINGLE_DIGIT_COUNT; ++i)
            buckets[i].clear();

        typename SingleList<T1>::Node* current = lst.begin_;
        const size_t count = lst.size(); 
        for (size_t i = 0; i < count; ++i) {
            int index = (current->data_ / power) % SINGLE_DIGIT_COUNT;
            buckets[index].push_front(current->data_);
            current = current->next_;
        }

        lst.clear();

        for (int i = SINGLE_DIGIT_COUNT - 1; i >= 0; --i) {
            typename SingleList<T1>::Node* cur = buckets[i].begin_;
            const size_t bucketCount = buckets[i].size(); 
            for (size_t j = 0; j < bucketCount; ++j) {
                lst.push_front(cur->data_);
                cur = cur->next_;
            }
        }

        power *= SINGLE_DIGIT_COUNT;
    }
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

