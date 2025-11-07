#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include <iterator>

template <typename BidirectionalIterator>
void
selectionSort(BidirectionalIterator first, BidirectionalIterator last)
{
    while (first != last) {
        BidirectionalIterator it = first;
        BidirectionalIterator min = it;
        ++it;
        while (it != last) {
            if (*it < *min) min = it;
            ++it;
        }
        std::swap(*first, *min);
        ++first;
    }
}

#endif // __FUNCTION_CPP__

