#ifndef __FUNCTIONS_CPP__
#define __FUNCTIONS_CPP__

#include "../headers/functions.hpp"
#include <cstddef>
#include <stack>
#include <algorithm> 

template <typename T>
void
shellSort(Vector<T>& rhv)
{
    size_t size = rhv.size();
    for (size_t gap = size / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < size; ++i) {
            T temp = rhv[i];
            size_t j = i;
            while (j >= gap && rhv[j - gap] > temp) {
                rhv[j] = rhv[j - gap];
                j -= gap;
            }
            rhv[j] = temp;
        }
    }
}

/// ======List=====

template <typename T>
void 
shellSortList(List<T>& rhv)
{
    typedef typename List<T>::Node* Node;
    size_t size = distanse<T>(rhv.begin_, rhv.end_);
    if (size < 2) return;

    size_t gap;
    for (gap = size / 2; gap > 0; gap /= 2) {
        size_t i;
        for (i = gap; i < size; ++i) {
            Node current = myAdvance<T>(rhv.begin_, i);
            if (0 == current) break;

            T temp = current->data_;
            size_t pos = i;

            Node jNode = current;
            Node cmpNode = (pos >= gap) ? myAdvance<T>(rhv.begin_, pos - gap) : NULL;

            while (cmpNode != NULL && cmpNode->data_ > temp) {
                jNode->data_ = cmpNode->data_;
                jNode = cmpNode;

                if (pos < gap) break;
                pos -= gap;

                cmpNode = (pos >= gap) ? myAdvance<T>(rhv.begin_, pos - gap) : NULL;
            }

            jNode->data_ = temp;
        }
    }
}

template <typename T>
void
shellSortSingleList(SingleList<T>& rhv)
{
    typedef typename SingleList<T>::Node* Node;
    size_t size = distanse<T>(rhv.begin_, rhv.end_);
    if (size < 2) return;

    size_t gap;
    for (gap = size / 2; gap > 0; gap /= 2) {
        size_t i;
        for (i = gap; i < size; ++i) {
            Node current = myAdvance<T>(rhv.begin_, i);
            if (0 == current) break;

            T temp = current->data_;
            size_t pos = i;

            Node jNode = current;
            Node cmpNode = (pos >= gap) ? myAdvance<T>(rhv.begin_, pos - gap) : NULL;

            while (cmpNode != NULL && cmpNode->data_ > temp) {
                jNode->data_ = cmpNode->data_;
                jNode = cmpNode;

                if (pos < gap) break;
                pos -= gap;

                cmpNode = (pos >= gap) ? myAdvance<T>(rhv.begin_, pos - gap) : NULL;
            }

            jNode->data_ = temp;
        }
    }
}

template <typename T>
typename List<T>::Node*
myAdvance(typename List<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; i < count; ++i) rhv = rhv->next_;
    return rhv;
}

template <typename T>
size_t
distanse(typename List<T>::Node* first, typename List<T>::Node* last)
{
    size_t i = 0;
    for (typename List<T>::Node* ptr = first; ptr != last; ptr = ptr->next_) ++i;
    return i;
}

template <typename T>
typename SingleList<T>::Node*
myAdvance(typename SingleList<T>::Node* rhv, const size_t count)
{
    for (size_t i = 0; i < count; ++i) rhv = rhv->next_;
    return rhv;
}

template <typename T>
size_t
distanse(typename SingleList<T>::Node* first, typename SingleList<T>::Node* last)
{
    size_t i = 0;
    for (typename SingleList<T>::Node* ptr = first; ptr != last; ptr = ptr->next_) ++i;
    return i;
}

#endif /// __FUNCTIONS_HPP__

