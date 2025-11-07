#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <iterator>
#include <algorithm>

template <typename Bidirectional>
Bidirectional
partition(Bidirectional first, Bidirectional last)
{
    typedef typename std::iterator_traits<Bidirectional>::value_type T;
    Bidirectional pivotIt = last;
    --pivotIt;
    T pivot = *pivotIt;

    Bidirectional i = first;
    for (Bidirectional j = first; j != pivotIt; ++j) {
        if (*j < pivot) {
            std::iter_swap(i, j);
            ++i;
        }
    }
    std::iter_swap(i, pivotIt);
    return i;
}

template <typename Bidirectional>
void
quickSort(Bidirectional first, Bidirectional last)
{
    if (first == last) return;
    Bidirectional next = first;
    ++next;
    if (next == last) return;

    Bidirectional pivot = partition(first, last);

    quickSort(first, pivot);
    ++pivot;
    quickSort(pivot, last);
}

#endif // __FUNCTION_CPP__

