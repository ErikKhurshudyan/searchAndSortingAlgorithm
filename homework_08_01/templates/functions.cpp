#ifndef __FUNCTIONS_CPP__
#define __FUNCTIONS_CPP__

#include "../headers/functions.hpp"
#include <iostream>

template <typename Iterator>
void
print(Iterator first, Iterator last, std::stringstream& ss)
{
    ss << "{ ";
    for (; first != last; ++first) {
        ss << *first << ' '; 
    }
    ss << "}";
}

template <typename T>
void
bubbleSort(Vector<T>& rhv)
{
    for (T* it = rhv.begin_; it < rhv.end_; ++it) {
        bool flag = false;
        for (T* jt = rhv.begin_ + 1; jt < rhv.end_ - (it - rhv.begin_); ++jt) {
            if (*(jt - 1) > *jt) {
                std::swap(*jt, *(jt - 1));
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

template <typename T>
void
bubbleSort(List<T>& rhv)
{
    for (typename List<T>::Node* it = rhv.begin_; it != rhv.end_; it = it->next_) {
        typename List<T>::Node* prev = rhv.begin_;
        typename List<T>::Node* jt = prev->next_;
        while (jt != rhv.end_) {
            if (jt->data_ < prev->data_) {
                std::swap(jt->data_, prev->data_);
            }
            jt = jt->next_;
            prev = prev->next_;
        }
    }
}

template <typename T>
void
bubbleSort(SingleList<T>& rhv)
{
    for (typename SingleList<T>::Node* it = rhv.begin_; it != rhv.end_; it = it->next_) {
        typename SingleList<T>::Node* prev = rhv.begin_;
        typename SingleList<T>::Node* jt = prev->next_;
        while (jt != rhv.end_) {
            if (jt->data_ < prev->data_) {
                std::swap(jt->data_, prev->data_);
            }
            jt = jt->next_;
            prev = prev->next_;
        }
    }   
}

#endif /// __FUNCTIONS_HPP__

