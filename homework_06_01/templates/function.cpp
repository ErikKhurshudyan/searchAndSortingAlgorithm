#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include "../headers/Vector.hpp"
#include "../headers/List.hpp"

template <typename T>
void
insertionSort(Vector<T>& rhv)
{
    for (T* ptr = rhv.begin_ + 1; ptr != rhv.end_; ++ptr) {
        typename Vector<T>::value_type temp = *ptr;
        T* current = ptr;
        while (temp < *(current - 1) && current > rhv.begin_) {
            *current = *(current - 1);
            --current;
        }
        *current = temp;
    }
}

template <typename T>
void
insertionSort(List<T>& rhv)
{
    for (typename List<T>::Node* ptr = rhv.begin_->next_; ptr != rhv.end_; ptr = ptr->next_) {
        typename List<T>::value_type temp = ptr->data_;
        typename List<T>::Node* current = ptr;
        while (current != rhv.begin_ && temp < current->previous_->data_) {
            current->data_ = current->previous_->data_;
            current = current->previous_;
        }
        current->data_ = temp;
    }
}

template <typename T>
void
insertionSort(SingleList<T>& rhv)
{
    typedef typename SingleList<T>::Node Node;
    if (!rhv.begin_ || rhv.begin_->next_ == rhv.begin_) return;

    Node* sorted = NULL;
    Node* current = rhv.begin_;
    Node* end = rhv.begin_;

    while (true) {
        Node* next = current->next_;

        Node** pos = &sorted;
        Node* start = sorted;

        while (*pos && (*pos)->data_ < current->data_) {
            pos = &((*pos)->next_);
            if (*pos == start) break;
        }

        if (!sorted) {
            sorted = current;
            sorted->next_ = sorted;
        } else {
            current->next_ = *pos ? *pos : sorted;
            *pos = current;
        }

        if (next == end) break;
        current = next;
    }

    rhv.begin_ = sorted;
}

#endif /// __FUNCTION_CPP__

