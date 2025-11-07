#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <iterator>
#include <algorithm>
#include <stack>

template <typename BidirectionalIterator>
void
shellSort(BidirectionalIterator first, BidirectionalIterator last)
{
    const size_t size = std::distance(first, last);

    if (size < 2) return;

    for (size_t gap = size / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < size; ++i) {
            BidirectionalIterator current = first;
            std::advance(current, i);

            typename std::iterator_traits<BidirectionalIterator>::value_type temp = *current;

            size_t position = i;
            BidirectionalIterator j = current;

            BidirectionalIterator cmp;
            while (position >= gap) {
                cmp = first;
                std::advance(cmp, position - gap);

                if (*cmp <= temp) break;

                *j = *cmp; 
                j = cmp;
                position -= gap;
            }

            *j = temp;
        }
    }
}


#endif // __FUNCTION_CPP__

