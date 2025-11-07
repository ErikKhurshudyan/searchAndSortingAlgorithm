#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/Vector.hpp"
#include "../headers/SingleList.hpp"
#include "../headers/Set.hpp"
#include "../headers/function.hpp"

template <typename T>
bool
binarySearch(const Vector<T>& rhv, const T& key)
{
    return binarySearchHelper(rhv.begin_, rhv.end_, key);
}

template <typename T>
bool
binarySearchHelper(T* first, T* last, const T& key)
{
    if (first == last) return false;
    typename std::iterator_traits<T*>::difference_type dist = std::distance(first, last);
    T* middle = first;
    std::advance(middle, dist / 2);
    if (key < *middle) return binarySearchHelper(first, middle, key);
    if (key > *middle) return binarySearchHelper(++middle, last, key);
    return true;
}

template <typename T>
bool
binarySearch(const SingleList<T>& rhv, const T& key)
{
    return binarySearchHelper1<T>(rhv.begin_, rhv.end_, key);
}

template <typename T>
bool
binarySearchHelper1(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last, const T& key)
{
    if (first == last) return false;
    typename std::iterator_traits<T*>::difference_type dist =myDistance<T>(first, last);
    typename SingleList<T>::Node* middle = first;
    myAdvance<T>(middle, dist / 2);
    if (key < middle->data_) return binarySearchHelper1<T>(first, middle, key);
    if (key > middle->data_) return binarySearchHelper1<T>(middle->next_, last, key);
    return true;
}

template <typename T>
bool
binarySearch(const List<T>& rhv, const T& key)
{
    return binarySearchHelper2<T>(rhv.begin_, rhv.end_, key);
}

template <typename T>
bool
binarySearchHelper2(typename List<T>::Node* first, typename List<T>::Node* last, const T& key)
{
    if (first == last) return false;
    typename std::iterator_traits<T*>::difference_type dist =myDistance<T>(first, last);
    typename List<T>::Node* middle = first;
    myAdvance<T>(middle, dist / 2);
    if (key < middle->data_) return binarySearchHelper2<T>(first, middle, key);
    if (key > middle->data_) return binarySearchHelper2<T>(middle->next_, last, key);
    return true;
}

template <typename T>
bool
binarySearch(const Set<T>& rhv, const T& key)
{
    for (typename Set<T>::Node* ptr = Set<T>::getLeftMost(rhv.root_); ptr != NULL; ) {
        if (ptr->data_ == key) { return true; }
        if (NULL == ptr->right_) { 
            while (ptr->parent_ != NULL && ptr->parent_->right_ == ptr) {
                ptr = ptr->parent_;
            }
            ptr = ptr->parent_;
            continue;
        }
        ptr = Set<T>::getLeftMost(ptr->right_);
    }
    return false;
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


#endif /// __FUNCTION_CPP__

