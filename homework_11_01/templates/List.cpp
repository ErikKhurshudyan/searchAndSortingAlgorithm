#include "../headers/List.hpp"

#include <cstddef>
#include <cassert>
#include <limits>
#include <cmath>
#include <memory>
#include <cstring>

template <typename T>
std::istream& 
operator>>(std::istream& in, List<T>& rhv)
{
    for (typename List<T>::iterator it = rhv.begin(); it != rhv.end(); ++it) {
        in >> *it;
    }
    return in;
}

template <typename T>
std::ostream& 
operator<<(std::ostream& out, const List<T>& rhv)
{
    out << "{";
    for (typename List<T>::const_iterator it = rhv.begin(); it != rhv.end(); ++it) {
        out << ' ' << *it;
    }
    out << " }";
    return out;
}

template <typename T>
List<T>::List()
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
}

template <typename T>
List<T>::List(const size_type size)
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
    resize(size);
}

template <typename T>
List<T>::List(const size_type size, const T& initialValue)
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
    resize(size, initialValue);
}

template <typename T>
List<T>::List(const int size, const T& initialValue)
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
    resize(size, initialValue);
}

template <typename T>
List<T>::List(const long int size, const T& initialValue)
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
    resize(size, initialValue);
}

template <typename T>
List<T>::List(const List& rhv)
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
    copyHelper(rhv.begin(), rhv.end());
}

template <typename T>
template <typename InputIterator>
List<T>::List(InputIterator first, InputIterator last)
    : begin_(new Node(T(), NULL, NULL))
    , end_(begin_)
{
    end_->next_ = end_;
    end_->prev_ = end_;
    copyHelper(first, last);
}

template <typename T>
List<T>::~List()
{
    clear();
    delete end_;
    begin_ = NULL;
    end_ = NULL;
}

template <typename T>
void 
List<T>::clear()
{
    if (!empty()) {
        erase(begin(), end());
        begin_ = end_;
    }
}

template <typename T>
const List<T>& 
List<T>::operator=(const List<T>& rhv)
{
    if (this == &rhv) { return *this; }
    copyHelper(rhv.begin(), rhv.end());
    return *this;
}

template <typename T>
template <typename InputIterator>
void 
List<T>::copyHelper(InputIterator first, InputIterator last)
{
    iterator it = begin();
    while (first != last && it != end()) { *it++ = *first++; }
    while (first != last) { push_back(*first++); }
}

template <typename T>
void
List<T>::resize(const size_type newSize, const T& initialValue)
{
    assert(newSize <= max_size());
    size_type currentSize = size();
    while (currentSize < newSize) {
        push_back(initialValue);
        ++currentSize;
    }
    while (currentSize > newSize) {
        pop_back();
        --currentSize;
    } 
}

template <typename T>
typename List<T>::size_type
List<T>::size() const
{
    size_type counter = 0;
    const_iterator it = begin();
    while (it != end()) {
        ++it;
        ++counter;
    }
    return counter;
}

template <typename T>
typename List<T>::size_type
List<T>::max_size() const
{
    return std::numeric_limits<unsigned int>::max() / 4 * sizeof(Node);
}

template <typename T>
void 
List<T>::push_front(const T& value)
{
    begin_ = new Node(value, end_, begin_);
    begin_->next_->prev_ = begin_;
    end_->next_ =  begin_;
}

template <typename T>
void 
List<T>::push_back(const T& value)
{
    Node* temp = new Node(value, end_->prev_, end_);
    temp->prev_->next_ = temp;
    end_->prev_ = temp;
    if (begin_ == end_) {
        begin_ = temp;
    }
}

template <typename T>
void 
List<T>::pop_front()
{
    assert(!empty());
    Node* temp = begin_;
    begin_ = begin_->next_;
    begin_->prev_ = end_;
    end_->next_ = begin_;
    delete temp;
}

template <typename T>
void 
List<T>::pop_back()
{
    assert(!empty());
    Node* temp = end_->prev_;
    temp->prev_->next_ = end_;
    end_->prev_ = temp->prev_;
    if (begin_ == temp) {
        begin_ = end_;
    }
    delete temp;
}

template <typename T>
typename List<T>::const_reference 
List<T>::front() const
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename List<T>::reference 
List<T>::front()
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename List<T>::const_reference 
List<T>::back() const
{
    assert(!empty());
    return end_->prev_->data_;
}

template <typename T>
typename List<T>::reference 
List<T>::back()
{
    assert(!empty());
    return end_->prev_->data_;
}

template <typename T>
typename List<T>::const_iterator 
List<T>::begin() const
{
    return const_iterator(begin_);
}
template <typename T>
typename List<T>::const_iterator 
List<T>::end() const
{
    return const_iterator(end_);
}

template <typename T>
typename List<T>::iterator 
List<T>::begin()
{
    return iterator(begin_);
}

template <typename T>
typename List<T>::iterator
List<T>::end()
{
    return iterator(end_);
}

template <typename T>
typename List<T>::const_reverse_iterator 
List<T>::rbegin() const
{
    return const_reverse_iterator(end_->prev_);
}

template <typename T>
typename List<T>::const_reverse_iterator 
List<T>::rend() const
{
    return const_reverse_iterator(end_);
}

template <typename T>
typename List<T>::reverse_iterator
List<T>::rbegin()
{
    return reverse_iterator(end_->prev_);
}

template <typename T>
typename List<T>::reverse_iterator
List<T>::rend()
{
    return reverse_iterator(end_);
}

template <typename T>
typename List<T>::iterator 
List<T>::insert(iterator pos, const T& x)
{
    Node* posNode = pos.getPtr();
    assert(posNode != NULL);  

    Node* temp = new Node(x, posNode->prev_, posNode);
    posNode->prev_ = temp;
    temp->prev_->next_ = temp;
    if (begin() == pos) {
        begin_ = temp;
    }
    return iterator(temp); 
}

template <typename T>
void 
List<T>::insert(iterator pos, const size_type size, const T& x)
{
    for (size_type i = 0; i < size; ++i) {
        insert(pos, x);
    }
}

template <typename T>
void List<T>::insert(iterator pos, const int size, const T& x)
{
    insert(pos, size_type(size), x);
}

template <typename T>
void List<T>::insert(iterator pos, const long size, const T& x)
{
    insert(pos, size_type(size), x);
}

template <typename T>
template <typename InputIterator>
void 
List<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) {
        insert(pos, *(first++));
    }
}

template <typename T>
typename List<T>::iterator 
List<T>::insert_after(iterator pos, const T& x)
{
    Node* posNode = pos.getPtr();
    assert(posNode != NULL);  
    assert(pos != end());
    
    Node* temp = new Node(x, posNode, posNode->next_);
    posNode->next_ = temp;
    temp->next_->prev_ = temp;
    return iterator(temp);
}

template <typename T>
void 
List<T>::insert_after(iterator pos, const size_type size, const T& x)
{
    for (size_type i = 0; i < size; ++i) {
        insert_after(pos, x);
    }
}

template <typename T>
void 
List<T>::insert_after(iterator pos, const int size, const T& x)
{
    insert_after(pos, size_type(size), x);
}

template <typename T>
void 
List<T>::insert_after(iterator pos, const long size, const T& x)
{
    insert_after(pos, size_type(size), x);
}

template <typename T>
template <typename InputIterator>
void 
List<T>::insert_after(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) { pos = insert_after(pos, *first++); }
}

template <typename T>
typename List<T>::iterator 
List<T>::erase(iterator pos)
{
    Node* posNode = pos.getPtr();
    assert(pos != end() && posNode != NULL);
    
    Node* temp = posNode->next_;
    posNode->prev_->next_ = temp;
    temp->prev_ = posNode->prev_;
    if (begin_ == posNode) {
        begin_ = temp;
    }
    delete posNode;
    return iterator(temp);
}

template <typename T>
typename List<T>::iterator 
List<T>::erase(iterator first, iterator last)
{
    while (first != last) { first = erase(first); }
    return first;
}

template <typename T>
typename List<T>::iterator 
List<T>::erase_after(iterator pos)
{
    Node* posNode = pos.getPtr();
    assert(posNode != NULL);
    assert(pos != end() && iterator(posNode->next_) != end());
    
    Node* temp = posNode->next_;
    posNode->next_ = temp->next_;
    temp->next_->prev_ = posNode;
    delete temp;
    return pos;
}

template <typename T>
void
List<T>::splice(iterator pos, List& rhv)
{
    assert(*this != rhv);
    Node* posNode = pos.getPtr();
    Node* prevNode = posNode->prev_;
    
    prevNode->next_ = rhv.begin_;
    rhv.begin_->prev_ = prevNode;
    
    Node* lastNode = rhv.end_->prev_;
    posNode->prev_ = lastNode;
    lastNode->next_ = posNode; 
    
    begin_ = end_->next_;
    rhv.begin_ = rhv.end_;
}

template <typename T>
void
List<T>::splice(iterator pos, List& rhv, iterator it)
{
    assert(it != rhv.end());
    Node* itNode = it.getPtr();
    Node* itPrev = itNode->prev_;

    itPrev->next_ = itNode->next_;
    itNode->next_->prev_ = itPrev;

    Node* posNode = pos.getPtr();
    Node* prevNode = posNode->prev_;
    
    prevNode->next_ = itNode;
    itNode->prev_ = prevNode;
    
    itNode->next_ = posNode;
    posNode->prev_ = itNode;
    
    begin_ = end_->next_;   
    rhv.begin_ = rhv.end_->next_;
}

template <typename T>
void
List<T>::splice(iterator pos, List& rhv, iterator first, iterator last)
{
    Node* firstNode = first.getPtr();
    Node* firstPrev = firstNode->prev_;
    Node* lastNode = last.getPtr();
    Node* lastPrev = lastNode->prev_;

    firstPrev->next_ = lastNode;
    lastNode->prev_ = firstPrev;

    Node* posNode = pos.getPtr();
    Node* prevNode = posNode->prev_;
    
    prevNode->next_ = firstNode;
    firstNode->prev_ = prevNode;
    
    lastPrev->next_ = posNode;
    posNode->prev_ = lastPrev;
    
    begin_ = end_->next_;   
    rhv.begin_ = rhv.end_->next_;
}

template <typename T>
void 
List<T>::swap(List<T>& rhv)
{
    std::swap(begin_, rhv.begin_);
    std::swap(end_, rhv.end_);
}

template <typename T>
void 
List<T>::remove(const T& value)
{
    for (iterator it = begin(); it != end(); ++it) {
        if (value == *it) {
            erase(it);
        }
    }
}

template <typename T>
void 
List<T>::unique()
{
    for (iterator it = begin(); it != end();) {
        iterator jt = it;
        ++jt;
        if (jt != end() && *it == *jt) {
            jt = erase(jt);
            continue;
        }
        ++it; 
    }
}

template <typename T>
void 
List<T>::merge(List<T>& rhv)
{
    iterator it1 = this->begin();
    iterator it2 = rhv.begin();

    while (it1 != end() && it2 != rhv.end()) {
        if (*it1 >= *it2) {
            insert(it1, *it2);
            it2 = rhv.erase(it2);
            continue;
        } 
        ++it1;
    }
    it1 = iterator(end_->prev_);
    while (it2 != rhv.end()) {
        it1 = insert_after(it1, *it2);
        it2 = rhv.erase(it2);
    }
}

template <typename T>
void 
List<T>::sort()
{
    for (iterator it = begin(); it != end(); ++it) {
        bool flag = false;
        for (iterator jt = ++begin(); jt != end(); ++jt) {
            iterator tt = jt;
            --tt;
            if (*jt < *tt) {
                std::swap(*jt, *tt);
                flag = true;
            }
        }
        if (!flag) { break; }
    }
}

template <typename T>
void 
List<T>::reverse()
{
    for (iterator it = begin(); it != end(); --it) {
        Node* itNode = it.getPtr();
        std::swap(itNode->prev_, itNode->next_);
    }
    Node* temp = begin_;
    begin_ = end_->prev_;
    end_->next_ = begin_;
    end_->prev_ = temp;
}

template <typename T>
bool
List<T>::empty() const
{
    return end_ == begin_;
}

template <typename T>
bool 
List<T>::operator==(const List<T>& rhv) const
{
    List<T>::const_iterator first = begin();
    List<T>::const_iterator second = rhv.begin();
    while (first != end() && second != rhv.end()) {
        if (*first != *second) {
            return false;
        }
        ++first;
        ++second;
    }
    return ((end() == first && rhv.end() == second) ? true : false);
}

template <typename T>
bool 
List<T>::operator!=(const List<T>& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool 
List<T>::operator<(const List<T>& rhv) const
{
    List<T>::const_iterator first = begin();
    List<T>::const_iterator second = rhv.begin();
      
    while (first != end() && second != rhv.end()) {
        if (*first != *second) {
            return *first < *second;
        }
        ++first;
        ++second;
    }
    return (end() == first && rhv.end() != second ? true : false);
}

template <typename T>
bool 
List<T>::operator>(const List<T>& rhv) const
{
    return rhv < *this;
}

template <typename T>
bool 
List<T>::operator>=(const List<T>& rhv) const
{
    return !(*this < rhv); 
}

template <typename T>
bool 
List<T>::operator<=(const List<T>& rhv) const
{
    return !(rhv < *this);
}


/// const_iterator

template <typename T>
List<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{}

template <typename T>
List<T>::const_iterator::const_iterator(Node* ptr)
    : ptr_(ptr)
{}

template <typename T>
List<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{}

template <typename T>
List<T>::const_iterator::~const_iterator()
{
    destroy();
}

template <typename T>
void 
List<T>::const_iterator::destroy()
{
    ptr_ = NULL;
}

template <typename T>
const typename List<T>::const_iterator&
List<T>::const_iterator::operator=(const const_iterator& rhv)
{
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename List<T>::const_reference 
List<T>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename List<T>::value_type* 
List<T>::const_iterator::operator->() const
{
    return &ptr_;
}

template <typename T>
typename List<T>::const_iterator
List<T>::const_iterator::operator++()
{
    return const_iterator(ptr_ = ptr_->next_);
}

template <typename T>
typename List<T>::const_iterator
List<T>::const_iterator::operator++(int)
{
    Node* temp = ptr_;
    ptr_ = ptr_->next_;
    return const_iterator(temp);
}

template <typename T>
typename List<T>::const_iterator
List<T>::const_iterator::operator--()
{
    return const_iterator(ptr_ = ptr_->prev_);
}

template <typename T>
typename List<T>::const_iterator
List<T>::const_iterator::operator--(int)
{
    Node* temp = ptr_;
    ptr_ = ptr_->prev_;
    return const_iterator(temp);
}

template <typename T>
bool 
List<T>::const_iterator::operator==(const const_iterator& rhv)
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool 
List<T>::const_iterator::operator!=(const const_iterator& rhv)
{
    return !(*this == rhv);
}

template <typename T>
bool 
List<T>::const_iterator::operator<(const const_iterator& rhv)
{
    return ptr_ < rhv.ptr_;
}

template <typename T>
bool 
List<T>::const_iterator::operator>(const const_iterator& rhv)
{
    return rhv < *this;
}

template <typename T>
bool 
List<T>::const_iterator::operator<=(const const_iterator& rhv)
{
    return !(rhv < *this);
}

template <typename T>
bool 
List<T>::const_iterator::operator>=(const const_iterator& rhv)
{
    return !(*this < rhv);
}

template <typename T>
void 
List<T>::const_iterator::setPtr(Node* ptr)
{
    ptr_ = ptr;
}

template <typename T>
typename List<T>::Node* 
List<T>::const_iterator::getPtr() const
{    
    return ptr_;
}

template <typename T>
void 
List<T>::const_iterator::increment()
{
    ptr_ = ptr_->next_;
}

template <typename T>
void 
List<T>::const_iterator::decrement()
{
    ptr_ = ptr_->prev_;
}

/// iterator

template <typename T>
List<T>::iterator::iterator()
    : const_iterator()
{}

template <typename T>
List<T>::iterator::iterator(Node* ptr)
    : const_iterator(ptr)
{}

template <typename T>
List<T>::iterator::iterator(const iterator& rhv)
    : const_iterator(rhv)
{}

template <typename T>
List<T>::iterator::~iterator()
{
    this->destroy();
}

template <typename T>
const typename List<T>::iterator& 
List<T>::iterator::operator=(const iterator& rhv)
{
    this->setPtr(rhv.getPtr());
    return *this;
}

template <typename T>
typename List<T>::reference
List<T>::iterator::operator*()
{
    return (this->getPtr())->data_;
}

template <typename T>
typename List<T>::value_type*
List<T>::iterator::operator->()
{
    return &this->getPtr();
}

template <typename T>
typename List<T>::iterator 
List<T>::iterator::operator++()
{
    this->increment();
    return iterator(this->getPtr());
}

template <typename T>
typename List<T>::iterator 
List<T>::iterator::operator++(int)
{
    Node* temp = this->getPtr();
    this->increment();
    return iterator(temp);
}

template <typename T>
typename List<T>::iterator 
List<T>::iterator::operator--()
{
    this->decrement();
    return iterator(this->getPtr());
}

template <typename T>
typename List<T>::iterator 
List<T>::iterator::operator--(int)
{
    Node* temp = this->getPtr();
    this->decrement();
    return iterator(temp);
}

/// const_reverse_iterator

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{}

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator(Node* ptr)
    : ptr_(ptr)
{}

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{}

template <typename T>
List<T>::const_reverse_iterator::~const_reverse_iterator()
{
    destroy();
}

template <typename T>
void 
List<T>::const_reverse_iterator::destroy()
{
    ptr_ = NULL;
}

template <typename T>
const typename List<T>::const_reverse_iterator&
List<T>::const_reverse_iterator::operator=(const const_reverse_iterator& rhv)
{
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename List<T>::const_reference 
List<T>::const_reverse_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename List<T>::value_type* 
List<T>::const_reverse_iterator::operator->() const
{
    return &ptr_;
}

template <typename T>
typename List<T>::const_reverse_iterator
List<T>::const_reverse_iterator::operator++()
{
    return const_reverse_iterator(ptr_ = ptr_->prev_);
}

template <typename T>
typename List<T>::const_reverse_iterator
List<T>::const_reverse_iterator::operator++(int)
{
    Node* temp = ptr_;
    ptr_ = ptr_->prev_;
    return const_reverse_iterator(temp);
}

template <typename T>
typename List<T>::const_reverse_iterator
List<T>::const_reverse_iterator::operator--()
{
    return const_reverse_iterator(ptr_ = ptr_->next_);
}

template <typename T>
typename List<T>::const_reverse_iterator
List<T>::const_reverse_iterator::operator--(int)
{
    Node* temp = ptr_;
    ptr_ = ptr_->next_;
    return const_reverse_iterator(temp);
}

template <typename T>
bool 
List<T>::const_reverse_iterator::operator==(const const_reverse_iterator& rhv)
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool 
List<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhv)
{
    return !(*this == rhv);
}

template <typename T>
bool 
List<T>::const_reverse_iterator::operator<(const const_reverse_iterator& rhv)
{
    return ptr_ < rhv.ptr_;
}

template <typename T>
bool 
List<T>::const_reverse_iterator::operator>(const const_reverse_iterator& rhv)
{
    return rhv < *this;
}

template <typename T>
bool 
List<T>::const_reverse_iterator::operator<=(const const_reverse_iterator& rhv)
{
    return !(rhv < *this);
}

template <typename T>
bool 
List<T>::const_reverse_iterator::operator>=(const const_reverse_iterator& rhv)
{
    return !(*this < rhv);
}

template <typename T>
void 
List<T>::const_reverse_iterator::setPtr(Node* ptr)
{
    ptr_ = ptr;
}

template <typename T>
typename List<T>::Node* 
List<T>::const_reverse_iterator::getPtr() const
{    
    return ptr_;
}

template <typename T>
void 
List<T>::const_reverse_iterator::increment()
{
    ptr_ = ptr_->prev_;
}

template <typename T>
void 
List<T>::const_reverse_iterator::decrement()
{
    ptr_ = ptr_->next_;
}

/// reverse_iterator

template <typename T>
List<T>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{}

template <typename T>
List<T>::reverse_iterator::reverse_iterator(Node* ptr)
    : const_reverse_iterator(ptr)
{}

template <typename T>
List<T>::reverse_iterator::reverse_iterator(const reverse_iterator& rhv)
    : const_reverse_iterator(rhv)
{}

template <typename T>
List<T>::reverse_iterator::~reverse_iterator()
{
    this->destroy();
}

template <typename T>
const typename List<T>::reverse_iterator& 
List<T>::reverse_iterator::operator=(const reverse_iterator& rhv)
{
    this->setPtr(rhv.getPtr());
    return *this;
}

template <typename T>
typename List<T>::reference
List<T>::reverse_iterator::operator*()
{
    return (this->getPtr())->data_;
}

template <typename T>
typename List<T>::value_type*
List<T>::reverse_iterator::operator->()
{
    return &this->getPtr();
}

template <typename T>
typename List<T>::reverse_iterator 
List<T>::reverse_iterator::operator++()
{
    this->increment();
    return reverse_iterator(this->getPtr());
}

template <typename T>
typename List<T>::reverse_iterator 
List<T>::reverse_iterator::operator++(int)
{
    Node* temp = this->getPtr();
    this->increment();
    return reverse_iterator(temp);
}

template <typename T>
typename List<T>::reverse_iterator 
List<T>::reverse_iterator::operator--()
{
    this->decrement();
    return reverse_iterator(this->getPtr());
}

template <typename T>
typename List<T>::reverse_iterator 
List<T>::reverse_iterator::operator--(int)
{
    Node* temp = this->getPtr();
    this->decrement();
    return reverse_iterator(temp);
}

