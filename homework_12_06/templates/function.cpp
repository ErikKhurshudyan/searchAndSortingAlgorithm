#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <iterator>
#include <algorithm>
#include <stack>

template <typename Bidirectional>
Bidirectional
partition(Bidirectional first, Bidirectional last)
{
    typedef typename std::iterator_traits<Bidirectional>::value_type T;
    const typename std::iterator_traits<Bidirectional>::difference_type count1 = std::distance(first, last);
    Bidirectional pivotIt = first;
    advance(pivotIt, count1 - 1);

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
    std::stack<std::pair<Bidirectional, Bidirectional> > stack;

    stack.push(std::make_pair(first,last));

    while (!stack.empty()) {
        std::pair<Bidirectional, Bidirectional> range = stack.top();
        stack.pop();

        Bidirectional low = range.first;
        Bidirectional high = range.second;

        if (low == high) continue;

        Bidirectional pivotPosition = partition(low, high);
        Bidirectional nextPivot = pivotPosition;
        ++nextPivot;
        if (nextPivot != high) {
            stack.push(std::make_pair(nextPivot, high));
        }
        if (pivotPosition != low) {
            stack.push(std::make_pair(low, pivotPosition));
        }
    }
}

#endif // __FUNCTION_CPP__

