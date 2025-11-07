#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <iterator>
#include <algorithm>
#include <vector>

template <typename Bidirectional>
void
count(Bidirectional first, Bidirectional last)
{
    if (first == last) return;

    typedef typename std::iterator_traits<Bidirectional>::value_type T;

    const T minValue = *std::min_element(first, last);
    const T maxValue = *std::max_element(first, last);
    const size_t range = static_cast<size_t>(maxValue - minValue + 1);

    std::vector<size_t> count(range, 0);
    for (Bidirectional it = first; it != last; ++it) {
        ++count[static_cast<size_t>(*it - minValue)];
    }

    for (size_t i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    std::vector<T> output(std::distance(first, last));

    for (Bidirectional it = last; it != first; ) {
        --it;
        size_t index = static_cast<size_t>(*it - minValue);
        output[--count[index]] = *it;
    }

    std::copy(output.begin(), output.end(), first);
}

#endif // __FUNCTION_CPP__

