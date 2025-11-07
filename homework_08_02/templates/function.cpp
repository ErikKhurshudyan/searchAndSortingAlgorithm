#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include <iterator>

template <typename BidirectionalIterator>
void
bubleSort(BidirectionalIterator first, BidirectionalIterator last)
{
    if (first == last) return;
    BidirectionalIterator penultimate = last;
    --penultimate;
    while (first != penultimate) {
        BidirectionalIterator it = first;
        bool flag = true;
        while (it != penultimate) {
            BidirectionalIterator itNext = it;
            ++itNext;
            if (*itNext < *it) { 
                std::swap(*it, *itNext);
                flag = false;
            }
            ++it;
        }
        if (flag) return;
        --penultimate;
    }
}

#endif // __FUNCTION_CPP__

