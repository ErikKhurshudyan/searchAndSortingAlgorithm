#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "headers/function.hpp"
#include <vector>
#include <iterator>
#include <algorithm>

template <typename Bidirectional>
void
merge(Bidirectional first, Bidirectional middle, Bidirectional last)
{
    typedef typename std::iterator_traits<Bidirectional>::value_type T;
    std::vector<T> temp;

    Bidirectional left  = first;
    Bidirectional right = middle;

    while (left != middle && right != last) {
        if (*left <= *right) {
            temp.push_back(*left);
            ++left;
            continue;
        }
        temp.push_back(*right);
        ++right;
    }

    while (left != middle) {
        temp.push_back(*left);
        ++left;
    }

    while (right != last) {
        temp.push_back(*right);
        ++right;
    }
    Bidirectional it = first;
    typename std::vector<T>::iterator vit = temp.begin();
    for (; it != last && vit != temp.end(); ++it, ++vit) {
        *it = *vit;
    }
}

template <typename Bidirectional>
void
mergeSort(Bidirectional first, Bidirectional last)
{
    const size_t n = std::distance(first, last);
    if (n <= 1) return;
    for (size_t step = 1; step < n; step *= 2) {
        Bidirectional leftIt = first;
        size_t remaining = n;

        while (remaining > 0) {
            const size_t leftSize = std::min(step, remaining);
            Bidirectional midIt = leftIt;
            std::advance(midIt, leftSize);

            const size_t rightSize = std::min(step, remaining - leftSize);
            Bidirectional rightIt = midIt;
            std::advance(rightIt, rightSize);

            merge(leftIt, midIt, rightIt);

            leftIt = rightIt;
            remaining -= (leftSize + rightSize);
        }
    }
}

#endif // __FUNCTION_CPP__

