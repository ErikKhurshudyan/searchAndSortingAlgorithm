#include "../headers/function.hpp"
#include "../headers/Vector.hpp"
#include "../headers/List.hpp"
#include "../headers/Set.hpp"

//template <typename T>
//typename Set<T>::Node* getLeftMost(typename Set<T>::Node* node);

template <typename T>
bool
linearSearch(const List<T>& rhv, const T& k)
{
    for (typename List<T>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        if (ptr->data_ == k) return true;
    }
    return false;
}

template <typename T>
bool
linearSearch(const Vector<T>& rhv, const T& k)
{
    for (size_t i = 0; i < rhv.size(); ++i) {
        if (rhv[i] == k) return true;
    }
    return false;
}

template <typename T>
bool
linearSearch(const SingleList<T>& rhv, const T& k)
{
    for (typename SingleList<T>::Node* ptr = rhv.begin_; ptr != rhv.end_; ptr = ptr->next_) {
        if (ptr->data_ == k) return true;
    }
    return false;
}

template <typename T>
bool
linearSearch(const Set<T>& rhv, const T& k)
{
    for (typename Set<T>::Node* ptr = Set<T>::getLeftMost(rhv.root_); ptr != NULL; ) {
        if (k == ptr->data_) { return true; }
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

