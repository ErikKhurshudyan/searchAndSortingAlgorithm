#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include "../headers/Vector.hpp"
#include "../headers/List.hpp"

template <typename T>
void
selectionSort(Vector<T>& rhv)
{
    for (T* ptr = rhv.begin_; ptr != rhv.end_ - 1; ++ptr) {
        T* min = ptr;
        for (T* innerPtr = ptr + 1; innerPtr != rhv.end_; ++innerPtr) {
            if (*innerPtr < *min) {
                min = innerPtr;
            }
        }
        std::swap(*ptr, *min);
    }
}

template <typename T>
void
selectionSort(List<T>& rhv)
{
    for (typename List<T>::Node* ptr = rhv.begin_; ptr != rhv.end_->previous_; ptr = ptr->next_) {
        typename List<T>::Node* min = ptr;
        for (typename List<T>::Node* innerPtr = ptr->next_; innerPtr != rhv.end_; innerPtr = innerPtr->next_) {
            if (innerPtr->data_ < min->data_) {
                min = innerPtr;
            }
        }
        std::swap(ptr->data_, min->data_);
    }
}

template <typename T>
void
selectionSort(SingleList<T>& rhv)
{
    for (typename SingleList<T>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        typename SingleList<T>::Node* min = ptr;
        for (typename SingleList<T>::Node* innerPtr = ptr->next_; innerPtr != rhv.end_; innerPtr = innerPtr->next_) {
            if (innerPtr->data_ < min->data_) {
                min = innerPtr;
            }
        }
        std::swap(ptr->data_, min->data_);
    }
}

#endif /// __FUNCTION_CPP__

