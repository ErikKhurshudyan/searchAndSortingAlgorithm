#ifndef __FUNCTION_CPP__
#define __FUNCTION_CPP__

#include "../headers/Vector.hpp"
#include "../headers/List.hpp"
#include "../headers/SingleList.hpp"
#include "../headers/Set.hpp"

template <typename T>
bool
binarySearch(const Vector<T>& rhv, const T& key)
{
    T* begin = rhv.begin_;
    T* end = rhv.end_;

    while (begin < end) {
        T* middle = begin + (end - begin) / 2;   
        if (*middle < key) {
            begin = middle + 1;
            continue;
        }
        if (*middle > key) {
            end = middle;
            continue;
        }
        return true;
    }
    return false;
}

template <typename T>
bool
binarySearch(const List<T>& rhv, const T& key)
{
    typename List<T>::Node* left = rhv.begin_;
    typename List<T>::Node* right = rhv.end_;

    while (left != right) {
        const size_t count = myDistance<T>(left, right) / 2;
        typename List<T>::Node* middle = left;
        myAdvance<T>(middle, count);

        if (middle->data_ < key) {
            left = middle->next_;
            continue;
        }
        if (key < middle->data_) {
            right = middle;
            continue;
        } 
        return true;
    }
    return false;
}

template <typename T>
bool
binarySearch(const SingleList<T>& rhv, const T& key)
{
    typename SingleList<T>::Node* left = rhv.begin_;
    typename SingleList<T>::Node* right = rhv.end_;

    while (left != right) {
        const size_t count = myDistance<T>(left, right) / 2;
        typename SingleList<T>::Node* middle = left;
        myAdvance<T>(middle, count);

        if (middle->data_ < key) {
            left = middle->next_;
            continue;
        }
        if (key < middle->data_) {
            right = middle;
            continue;
        } 
        return true;
    }
    return false;
}

template <typename T>
bool
binarySearch(const Set<T>& rhv, const T& key)
{
    typename Set<T>::Node* ptr = rhv.root_;
    while (ptr != NULL) {
        if (key < ptr->data_) {
            ptr = ptr->left_; 
            continue;
        }    
        if (ptr->data_ < key) {
            ptr = ptr->right_;
            continue;
        }    
        return true;
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

