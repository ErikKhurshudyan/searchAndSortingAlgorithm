#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include <iterator>

template <typename BidirectionalIterator>
void
insertionSort(BidirectionalIterator first, BidirectionalIterator last)
{
    for (BidirectionalIterator it = first; it != last; ++it) {
        BidirectionalIterator prevJt = it;
        BidirectionalIterator jt = prevJt;
        ++jt;
        if (jt == last) {
            return;
        }
        while (jt != first && *jt < *prevJt) {
            std::swap(*jt, *prevJt);
            --prevJt;
            --jt;
        }
    }
}


#endif // __FUNCTION_CPP__

