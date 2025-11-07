#ifndef __FUNCTIONS_CPP__
#define __FUNCTIONS_CPP__

#include "../headers/functions.hpp"
#include <cstddef>
#include <algorithm> 

template <typename T1>
void
count(Vector<T1>& rhv)
{
    if (0 == rhv.size()) return;

    const T1 minValue = *std::min_element(rhv.begin_, rhv.end_);
    const T1 maxValue = *std::max_element(rhv.begin_, rhv.end_);
    const size_t range = static_cast<size_t>(maxValue - minValue + 1);

    Vector<size_t> count(range, 0);

    for (T1* i = rhv.begin_; i != rhv.end_; ++i)
        ++count[static_cast<size_t>(*i - minValue)];

    for (size_t i = 1; i < range; ++i)
        count[i] += count[i - 1];

    Vector<T1> output(rhv.size());
    for (size_t i = 0; i < rhv.size(); ++i)
        output[i] = T1(); 

    for (T1* i = rhv.end_; i != rhv.begin_; ) {
        --i;
        const size_t index = static_cast<size_t>(*i - minValue);
        output[--count[index]] = *i;
    }

    for (size_t i = 0; i < rhv.size(); ++i) {
        rhv[i] = output[i];
    }
}

template <typename T1>
void
count(List<T1>& rhv)
{
    const size_t size = rhv.size();
    T1 minValue = rhv.begin_->data_;
    T1 maxValue = rhv.begin_->data_;
    for (typename List<T1>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        if (ptr->data_ < minValue) minValue = ptr->data_;
        if (ptr->data_ > maxValue) maxValue = ptr->data_;
    }
    const size_t range = static_cast<size_t>(maxValue - minValue + 1);
    Vector<size_t> count(range, 0);
    
    for (typename List<T1>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        ++count[static_cast<size_t>(ptr->data_ - minValue)];
    }
     
    for (size_t i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    Vector<T1> output(size);
    typename List<T1>::Node* ptr = rhv.begin_;
    for (size_t i = size; i > 0; --i) {
        const size_t index = static_cast<size_t>(ptr->data_ - minValue);
        output[--count[index]] = ptr->data_;
        ptr = ptr->next_;
    }
    
    ptr = rhv.begin_;
    for (size_t i = 0; i < size; ++i) {
        ptr->data_ = output[i];
        ptr = ptr->next_;
    }
}

template <typename T1>
void
count(SingleList<T1>& rhv)
{
    const size_t size = rhv.size();
    T1 minValue = rhv.begin_->data_;
    T1 maxValue = rhv.begin_->data_;
    for (typename SingleList<T1>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        if (ptr->data_ < minValue) minValue = ptr->data_;
        if (ptr->data_ > maxValue) maxValue = ptr->data_;
    }
    const size_t range = static_cast<size_t>(maxValue - minValue + 1);
    Vector<size_t> count(range, 0);
    
    for (typename SingleList<T1>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        ++count[static_cast<size_t>(ptr->data_ - minValue)];
    }
     
    for (size_t i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    Vector<T1> output(size);
    typename SingleList<T1>::Node* ptr = rhv.begin_;
    for (size_t i = size; i > 0; --i) {
        const size_t index = static_cast<size_t>(ptr->data_ - minValue);
        output[--count[index]] = ptr->data_;
        ptr = ptr->next_;
    }
    
    ptr = rhv.begin_;
    for (size_t i = 0; i < size; ++i) {
        ptr->data_ = output[i];
        ptr = ptr->next_;
    }
}

#endif /// __FUNCTIONS_HPP__

