#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <algorithm>
#include <vector>

// ================= Vector merge sort =================
template <typename T>
void
mergeForVector(T* first, T* middle, T* last)
{
    T* start1 = first;
    T* end1   = middle - 1;
    T* start2 = middle;
    T* end2   = last - 1;

    while (start1 <= end1 && start2 <= end2) {
        if (*start1 <= *start2) {
            ++start1;
            continue;
        }
        T value = *start2;
        T* ptr = start2;
        while (ptr != start1) {
            *ptr = *(ptr - 1);
            --ptr;
        }
        *start1 = value;
        ++start1;
        ++end1;
        ++start2;
    }
}

template <typename T>
void
mergeSort(Vector<T>& vec)
{
    const size_t n = vec.size();
    if (n <= 1) return;

    for (size_t step = 1; step < n; step *= 2) {
        for (size_t left = 0; left < n - step; left += 2 * step) {
            const size_t mid = left + step;
            const size_t right = std::min(left + 2 * step, n);
            mergeForVector(vec.begin_ + left, vec.begin_ + mid, vec.begin_ + right);
        }
    }
}

// ================= List merge sort =================
template <typename T>
void
myAdvance(typename List<T>::Node*& rhv, const size_t count)
{
    for (size_t i = 0; i < count && rhv != nullptr; ++i)
        rhv = rhv->next_;
}

template <typename T>
void
mergeForList(typename List<T>::Node* first, typename List<T>::Node* middle, typename List<T>::Node* last)
{
    typename List<T>::Node* start1 = first;
    typename List<T>::Node* start2 = middle;

    while (start1 != middle && start2 != last) {
        if (start1->data_ <= start2->data_) {
            start1 = start1->next_;
            continue;
        }

        T value = start2->data_;
        typename List<T>::Node* ptr = start2;
        while (ptr != start1) {
            ptr->data_ = ptr->prev_->data_;
            ptr = ptr->prev_;
        }
        start1->data_ = value;
        middle = middle->next_;

        start1 = start1->next_;
        start2 = start2->next_;
    }
}

template <typename T>
void
mergeSort(List<T>& list)
{
    const size_t n = list.size();
    if (n <= 1) return;
    for (size_t step = 1; step < n; step *= 2) {
        for (size_t left = 0; left < n - step; left += 2 * step) {
            const size_t mid = left + step;
            const size_t right = std::min(left + 2 * step, n);
            typename List<T>::Node* first = list.begin_;
            myAdvance<T>(first, left);
            typename List<T>::Node* middle = list.begin_;
            myAdvance<T>(middle, mid);
            typename List<T>::Node* last = list.begin_;
            myAdvance<T>(last, right);
            mergeForList<T>(first, middle, last);
        }
    }
}
// ---- SingleList ----


template <typename T>
void
myAdvance(typename SingleList<T>::Node*& rhv, const size_t count)
{
    for (size_t i = 0; i < count && rhv != NULL; ++i)
        rhv = rhv->next_;
}

template <typename T>
void
merge(typename SingleList<T>::Node* first, typename SingleList<T>::Node* middle, typename SingleList<T>::Node* last)
{
    std::vector<T> temp;
    typename SingleList<T>::Node* left  = first;
    typename SingleList<T>::Node* right = middle;

    while (left != middle && right != last) {
        if (left->data_ <= right->data_) {
            temp.push_back(left->data_);
            left = left->next_;
            continue;
        }
        temp.push_back(right->data_);
        right = right->next_;
    }

    while (left != middle) {
        temp.push_back(left->data_);
        left = left->next_;
    }

    while (right != last) {
        temp.push_back(right->data_);
        right = right->next_;
    }

    typename SingleList<T>::Node* node = first;
    typename std::vector<T>::iterator it = temp.begin();
    for (; node != last && it != temp.end(); ++it, node = node->next_) {
        node->data_ = *it;
    }
}

template <typename T>
void
mergeSort(SingleList<T>& list)
{
    const size_t n = list.size();
    if (n <= 1) return;

    for (size_t step = 1; step < n; step *= 2) {
        for (size_t left = 0; left < n - step; left += 2 * step) {
            const size_t mid   = left + step;
            const size_t right = std::min(left + 2 * step, n);

            typename SingleList<T>::Node* first = list.begin_;
            myAdvance<T>(first, left);

            typename SingleList<T>::Node* middle = list.begin_;
            myAdvance<T>(middle, mid);

            typename SingleList<T>::Node* last = list.begin_;
            myAdvance<T>(last, right);

            merge<T>(first, middle, last);
        }
    }
}

#endif // __FUNCTION_CPP__

