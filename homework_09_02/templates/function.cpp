#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/function.hpp"
#include <cstddef>

template <typename T1> 
void
mergeSort(Vector<T1>& rhv)
{
    mergeSort(rhv.begin_, rhv.end_ - 1);
}

template <typename T1> 
void
mergeSort(T1* first, T1* last)
{
    if (first >= last) return;

    T1* middle = first + (last - first) / 2;

    mergeSort(first, middle);
    mergeSort(middle + 1, last);
    merge(first, middle, last);
}

template <typename T1> 
void
merge(T1* first, T1* middle, T1* last)
{
    T1* start1 = first;
    T1* end1   = middle;
    T1* start2 = middle + 1;
    T1* end2   = last;

    while (start1 <= end1 && start2 <= end2) {
        if (*start1 <= *start2) {
            ++start1;
            continue;
        }
        const typename Vector<T1>::value_type value = *start2;
        T1* ptr = start2;
        while (ptr != start1) {
            *ptr = *(ptr - 1);
            --ptr;
        }
        *start1 = value;
        ++start1;
        ++end1;
        ++start2;
    }
}

template <typename T>
typename List<T>::Node*
myAdvance1(typename List<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; rhv && i < count; ++i)
        rhv = rhv->next_;
    return rhv;
}

template <typename T>
size_t myDistance1(typename List<T>::Node* first, typename List<T>::Node* last)
{
    size_t i = 0;
    for (typename List<T>::Node* ptr = first; ptr && ptr != last; ptr = ptr->next_)
        ++i;
    return i;
}

template <typename T1>
void
mergeSort(List<T1>& rhv)
{
    if (rhv.begin_ == rhv.end_ || rhv.begin_->next_ == rhv.end_)
        return;

    mergeSort1<T1>(rhv.begin_, rhv.end_->prev_);
}

template <typename T1>
void
mergeSort1(typename List<T1>::Node* first, typename List<T1>::Node* last)
{
    if (!first || !last || first == last) return;

    size_t difference = myDistance1<T1>(first, last);
    if (0 == difference) return;

    typename List<T1>::Node* middle = myAdvance1<T1>(first, difference / 2);

    mergeSort1<T1>(first, middle);
    mergeSort1<T1>(middle->next_, last);
    merge1<T1>(first, middle, last);
}

template <typename T1>
void
merge1(typename List<T1>::Node* first,
       typename List<T1>::Node* middle,
       typename List<T1>::Node* last)
{
    typename List<T1>::Node* start1 = first;
    typename List<T1>::Node* end1   = middle;
    typename List<T1>::Node* start2 = middle->next_;
    typename List<T1>::Node* end2   = last;

    while (start1 != end1->next_ && start2 != end2->next_) {
        if (start1->data_ <= start2->data_) {
            start1 = start1->next_;
            continue;
        } 
        const T1 value = start2->data_;
        typename List<T1>::Node* ptr = start2;
        while (ptr != start1) {
            ptr->data_ = ptr->prev_->data_;
            ptr = ptr->prev_;
        }
        start1->data_ = value;
        start1 = start1->next_;
        end1 = end1->next_;
        start2 = start2->next_;
    }
}

template <typename T1>
typename SingleList<T1>::Node*
mergeSortNodes(typename SingleList<T1>::Node* head)
{
    if (!head || !head->next_) return head;

    typename SingleList<T1>::Node* slow = head;
    typename SingleList<T1>::Node* fast = head->next_;

    while (fast && fast->next_) {
        slow = slow->next_;
        fast = fast->next_->next_;
    }

    typename SingleList<T1>::Node* middle = slow->next_;
    slow->next_ = NULL;

    typename SingleList<T1>::Node* left  = mergeSortNodes<T1>(head);
    typename SingleList<T1>::Node* right = mergeSortNodes<T1>(middle);

    return mergeNodes<T1>(left, right);
}

template <typename T1>
typename SingleList<T1>::Node*
mergeNodes(typename SingleList<T1>::Node* left,
           typename SingleList<T1>::Node* right)
{
    typename SingleList<T1>::Node dummy;
    typename SingleList<T1>::Node* tail = &dummy;

    while (left && right) {
        if (left->data_ <= right->data_) {
            tail->next_ = left;
            left = left->next_;
        } else {
            tail->next_ = right;
            right = right->next_;
        }
        tail = tail->next_;
    }

    tail->next_ = (left ? left : right);

    return dummy.next_;
}

template <typename T1>
void
mergeSort(SingleList<T1>& rhv)
{
    if (!rhv.head_ || !rhv.head_->next_) return;
    rhv.begin_ = mergeSortNodes<T1>(rhv.begin_);

    typename SingleList<T1>::Node* ptr = rhv.begin_;
    while (ptr && ptr->next_) ptr = ptr->next_;
    rhv.tail_ = ptr;
}

template <typename T>
void
myAdvance(typename List<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; i < count; ++i) rhv = rhv->next_;
}

template <typename T>
size_t
myDistance(typename List<T>::Node* first, typename List<T>::Node* last)
{
    size_t i = 0;
    for (typename List<T>::Node* ptr = first; ptr != last; ptr = ptr->next_) ++i;
    return i;
}

template <typename T>
void
myAdvance(typename SingleList<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; i < count; ++i) rhv = rhv->next_;
}

template <typename T>
size_t
myDistance(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last)
{
    size_t i = 0;
    for (typename SingleList<T>::Node* ptr = first; ptr != last; ptr = ptr->next_) ++i;
    return i;
}

#include "../templates/function.cpp"

#endif /// __FUNCTION_CPP__

