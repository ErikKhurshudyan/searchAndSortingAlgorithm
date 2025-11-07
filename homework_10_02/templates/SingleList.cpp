#include "headers/SingleList.hpp"

#include <cassert>
#include <limits>

template <typename T>
std::istream& 
operator>>(std::istream& in, SingleList<T>& rhv)
{
    const typename SingleList<T>::const_iterator end = rhv.end();
    for (typename SingleList<T>::iterator it = rhv.begin(); it != end; ++it) {
        in >> *it;
    }
    return in;
}

template <typename T>
std::ostream& 
operator<<(std::ostream& out, const SingleList<T>& rhv)
{
    const typename SingleList<T>::const_iterator end = rhv.end();
    out << "{";
    for (typename SingleList<T>::const_iterator it = rhv.begin(); it != end; ++it) {
        out << ' ' << *it;
    }
    out << " }";
    return out;
}

template <typename T>
void
SingleList<T>::bubbleSort()
{
    for (Node* it = begin_; it != end_; it = it->next_) {
        Node* prev = begin_;
        Node* jt = prev->next_;
        while (jt != end_) {
            if (jt->data_ < prev->data_) {
                std::swap(jt->data_, prev->data_);
            }
            jt = jt->next_;
            prev = prev->next_;
        }
    }
}


template <typename T>
SingleList<T>::SingleList()
    : begin_(new Node(T(), NULL))
    , end_(begin_)
{
    end_->next_ = begin_;
}

template <typename T>
SingleList<T>::SingleList(const size_type size, const T& initialValue)
    : begin_(new Node(T(), NULL))
    , end_(begin_)
{
    end_->next_ = begin_;
    resize(size, initialValue);
}

template <typename T>
SingleList<T>::SingleList(const long size, const T& initialValue)
    : begin_(new Node(T(), NULL))
    , end_(begin_)
{
    end_->next_ = begin_;
    resize(size, initialValue);
}

template <typename T>
SingleList<T>::SingleList(const int size, const T& initialValue)
    : begin_(new Node(T(), NULL))
    , end_(begin_)
{
    end_->next_ = begin_;
    resize(size, initialValue);
}


template <typename T>
SingleList<T>::SingleList(const SingleList& rhv)
    : begin_(new Node(T(), NULL))
    , end_(begin_)
{
    end_->next_ = begin_;
    copyHelper(rhv.begin(), rhv.end());
}

template <typename T>
template <typename InputIterator>
SingleList<T>::SingleList(InputIterator first, InputIterator last)
    : begin_(new Node(T(), NULL))
    , end_(begin_)
{
    end_->next_ = begin_;
    copyHelper(first, last);
}

template <typename T>
SingleList<T>::~SingleList()
{
    clear();
    delete end_;
    begin_ = NULL;
    end_ = NULL;
}

template <typename T>
void 
SingleList<T>::clear()
{
    while (begin_ != end_) { pop_front(); }
}

template <typename T>
const SingleList<T>& 
SingleList<T>::operator=(const SingleList<T>& rhv)
{
    if (this == &rhv) { return *this; }
    copyHelper(rhv.begin(), rhv.end());
    return *this;
}

template <typename T>
template <typename InputIterator>
void 
SingleList<T>::copyHelper(InputIterator first, InputIterator last)
{
    iterator it = begin();
    while (first != last && it != end()) { 
        *it++ = *first++;
    }
    while (first != last) { insert(end(), *first++); }
}

template <typename T>
void
SingleList<T>::resize(const size_type newSize, const T& initialValue)
{
    assert(newSize <= max_size());
    size_type currentSize = size();
    if (currentSize == newSize) { return; } 
    if (currentSize < newSize) {
        while (currentSize++ < newSize) {
            insert(end(), initialValue);
        }
        return;
    }
    if (0 == newSize) { clear(); return; } 
    iterator temp = begin();
    for (size_type i = 1; i < newSize; ++i) {
        ++temp;
    } 
    iterator ptr = temp; 
    while (temp.next() != end()) {
        erase_after(temp);
    }
}

template <typename T>
typename SingleList<T>::size_type
SingleList<T>::size() const
{
    size_type counter = 0;
    Node* current = begin_;
    while (current != end_) {
        current = current->next_;
        ++counter;
    }
    return counter;
}

template <typename T>
typename SingleList<T>::size_type
SingleList<T>::max_size() const
{
    return std::numeric_limits<unsigned int>::max() / 4 * sizeof(Node);
}

template <typename T>
void 
SingleList<T>::push_front(const T& value)
{
    begin_ = new Node(value, begin_);
    end_->next_ = begin_;
}

template <typename T>
void 
SingleList<T>::pop_front()
{
    assert(!empty());
    Node* temp = begin_;
    begin_ = begin_->next_;
    end_->next_ = begin_;
    delete temp;
}

template <typename T>
typename SingleList<T>::const_reference 
SingleList<T>::front() const
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename SingleList<T>::reference 
SingleList<T>::front()
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename SingleList<T>::const_iterator 
SingleList<T>::begin() const
{
    return const_iterator(begin_);
}
template <typename T>
typename SingleList<T>::const_iterator 
SingleList<T>::end() const
{
    return const_iterator(end_);
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::begin()
{
    return iterator(begin_);
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::end()
{
    return iterator(end_);
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::insert(iterator pos, const T& x)
{
    if (empty()) { push_front(x); return begin(); }
    insert_after(pos, x);
    std::swap(*pos, *pos.next());
    if (pos == end()) {
        end_ = end_->next_; 
    }
    return ++pos; 
}

template <typename T>
void 
SingleList<T>::insert(iterator pos, const size_type size, const T& x)
{
    for (size_type i = 0; i < size; ++i) { insert(pos, x); }
}

template <typename T>
void 
SingleList<T>::insert(iterator pos, const long size, const T& x)
{
    insert(pos, size_type(size), x);
}

template <typename T>
void 
SingleList<T>::insert(iterator pos, const int size, const T& x)
{
    insert(pos, size_type(size), x);
}

template <typename T>
template <typename InputIterator>
void 
SingleList<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) { pos = insert(pos, *first++); }
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::insert_after(iterator pos, const T& x)
{
    //assert(pos != end());
    assert(pos != iterator(NULL));
    Node* temp = new Node(x, pos.next().getPtr());
    pos.next(iterator(temp));
    return iterator(temp);
}

template <typename T>
void 
SingleList<T>::insert_after(iterator pos, const size_type size, const T& x)
{
    for (size_type i = 0; i < size; ++i) { insert_after(pos, x); }
}

template <typename T>
void 
SingleList<T>::insert_after(iterator pos, const long size, const T& x)
{
    insert_after(pos, size_type(size), x);
}

template <typename T>
void 
SingleList<T>::insert_after(iterator pos, const int size, const T& x)
{
    insert_after(pos, size_type(size), x);
}

template <typename T>
template <typename InputIterator>
void 
SingleList<T>::insert_after(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) { pos = insert_after(pos, *first++); }
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase(iterator pos)
{
    assert(pos != end());
    assert(pos != iterator(NULL));
    if (pos == begin()) {
        pop_front();
        return begin();
    }
    iterator it = begin();
    while (it.next() != pos) {
        ++it;
    }
    it.next(pos.next());
    delete pos.getPtr();
    return it.next();
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase(iterator first, iterator last)
{
    /// while (first != last) { first = erase(first); } Complexity: O(N^2)
    /// Complexity: O(N)
    const bool isFirstEqualToBegin = (begin() == first);
    iterator it = begin();
    if (!isFirstEqualToBegin) {
        while (it.next() != first) { ++it; }
    } else { ++first; }
    
    while (first != last && it.next() != end()) {
        ++first;
        erase_after(it);
    }
    if (isFirstEqualToBegin) { pop_front(); }
    return last;
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase_after(iterator pos)
{
    assert(pos != end()); 
    assert(pos != iterator(NULL));
    assert(pos.next() != end());
    
    iterator temp = pos.next();
    pos.next(temp.next());
    delete temp.getPtr();
    return pos;
}

template <typename T>
void
SingleList<T>::splice(iterator pos, SingleList& rhv)
{
    assert(this != &rhv);
    if (rhv.empty()) { return; } 
    iterator rhvEnd = rhv.begin();
    while (rhvEnd.next() != rhv.end()) { ++rhvEnd; }
    
    if (begin() == pos) {
        rhvEnd.next(begin());
        begin_ = rhv.begin_;
        rhv.begin_ = rhv.end_;
        return;
    }
    iterator it = begin();
    while (it.next() != pos) { ++it; }
    it.next(rhv.begin());
    rhvEnd.next(pos);
    rhv.begin_ = rhv.end_;
}

template <typename T>
void
SingleList<T>::splice(iterator pos, SingleList& rhv, iterator it)
{
    if (rhv.empty()) { return; } 
    iterator rhvIt = rhv.begin();
    while (rhvIt.next() != it) { ++rhvIt; }
    rhvIt.next(it.next());

    iterator posPrev = begin();
    while (posPrev.next() != pos) { ++posPrev; }
    posPrev.next(it);
    it.next(pos);
    begin_ = end_->next_;
    rhv.begin_ = rhv.end_->next_;
}

template <typename T>
void
SingleList<T>::splice(iterator pos, SingleList& rhv, iterator first, iterator last)
{
    if (rhv.empty()) { return; } 
    iterator posPrev = begin();
    while (posPrev.next() != pos) { ++posPrev; }
    iterator prevLast = rhv.begin();
    while (prevLast.next() != last) { ++prevLast; }
    iterator prevFirst = rhv.begin();
    while (prevFirst.next() != first) { ++prevFirst; }
    
    posPrev.next(first);
    prevLast.next(pos);
    prevFirst.next(last);  
    begin_ = end_->next_;
    rhv.begin_ = rhv.end_->next_;
}

template <typename T>
void
SingleList<T>::splice_after(iterator pos, iterator prev)
{
    assert(pos != end() && prev != end());
    iterator prevNext = prev.next();
    
    prev.next(prevNext.next());
    prevNext.next(pos.next());
    pos.next(prevNext);
}

template <typename T>
void
SingleList<T>::splice_after(iterator pos, iterator before_first, iterator before_last)
{
    assert(pos != end() && before_first != end() && before_last != end());
    iterator posNext = pos.next();
    iterator last = before_last.next();
    iterator first = before_first.next();
    
    pos.next(first);
    before_last.next(posNext);
    before_first.next(last);
}

template <typename T>
bool 
SingleList<T>::operator==(const SingleList<T>& rhv) const
{
    SingleList<T>::const_iterator first = begin();
    SingleList<T>::const_iterator second = rhv.begin();
    while (first != end() && second != rhv.end()) {
        if (*first != *second) {
            return false;
        }
        ++first;
        ++second;
    }
    return end() == first && rhv.end() == second;
}

template <typename T>
bool 
SingleList<T>::operator!=(const SingleList<T>& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool 
SingleList<T>::operator<(const SingleList<T>& rhv) const
{
    SingleList<T>::const_iterator first = begin();
    SingleList<T>::const_iterator second = rhv.begin();
      
    while (first != end() && second != rhv.end()) {
        if (*first != *second) {
            return *first < *second;
        }
        ++first;
        ++second;
    }
    return end() == first && rhv.end() != second;
}

template <typename T>
bool 
SingleList<T>::operator>(const SingleList<T>& rhv) const
{
    return rhv < *this;
}

template <typename T>
bool 
SingleList<T>::operator>=(const SingleList<T>& rhv) const
{
    return !(*this < rhv); 
}

template <typename T>
bool 
SingleList<T>::operator<=(const SingleList<T>& rhv) const
{
    return !(rhv < *this);
}

template <typename T>
bool
SingleList<T>::empty() const
{
    return end_ == begin_;
}

template <typename T>
void 
SingleList<T>::swap(SingleList<T>& rhv)
{
    std::swap(begin_, rhv.begin_);
    std::swap(end_, rhv.end_);
}

template <typename T>
void 
SingleList<T>::remove(const T& value)
{
    iterator previous;
    for (iterator it = begin(); it != end(); ) {
        if (value == *it) {
            if (it == begin()) {
                pop_front();
                it = begin();
                continue;
            }
            ++it;
            erase_after(previous);
            continue;
        }
        previous = it;
        ++it;
    }
}

template <typename T>
void 
SingleList<T>::unique()
{
    for (iterator it = begin(); it != end(); ) {
        if (it.next() != end() && *it == *it.next()) {
            erase_after(it);
            continue;
        }
        ++it;
    }
}

template <typename T>
void 
SingleList<T>::merge(SingleList<T>& rhv)
{
    if (this == &rhv) { return; }
    iterator it1 = begin();
    iterator it2 = rhv.begin();

    iterator temp;
    while (it1 != end() && it2 != end()) {
        if (it1.next() == end()) {
            temp = it1;
        }
        if (*it1 >= *it2) {
            it1 = insert(it1, *it2);
            ++it2;
            continue;
        } 
        ++it1;
    }
    it1 = temp;
    while (it2 != rhv.end()) {
        it1 = insert_after(it1, *it2);
        ++it2;
    }
    rhv.begin_ = rhv.end_;
   
}

template <typename T>
void 
SingleList<T>::sort()
{
    for (iterator it1 = begin(); it1 != end(); ++it1) {
        iterator it2 = it1;
        ++it2;
        while (it2 != end()) {
            if (*it1 > *it2) {
                std::swap(*it1, *it2);
            }
            ++it2;
        }
    }
}

template <typename T>
void 
SingleList<T>::reverse()
{
    iterator first = end();
    iterator second = begin();
    iterator third = iterator(begin_->next_);
    while (second != end()) {
        second.next(first);
        first = second;
        second = third;
        ++third;
    }
    begin_ = first.getPtr();
}


/// const_iterator

template <typename T>
SingleList<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{}

template <typename T>
SingleList<T>::const_iterator::const_iterator(Node* ptr)
    : ptr_(ptr)
{}

template <typename T>
SingleList<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{}

template <typename T>
SingleList<T>::const_iterator::~const_iterator()
{
    destroy();
}

template <typename T>
void 
SingleList<T>::const_iterator::destroy()
{
    ptr_ = NULL;
}

template <typename T>
const typename SingleList<T>::const_iterator&
SingleList<T>::const_iterator::operator=(const const_iterator& rhv)
{
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename SingleList<T>::const_reference 
SingleList<T>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename SingleList<T>::value_type* 
SingleList<T>::const_iterator::operator->() const
{
    return &ptr_->data_;
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::const_iterator::operator++()
{
    return const_iterator(ptr_ = ptr_->next_);
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::const_iterator::operator++(int)
{
    Node* temp = ptr_;
    ptr_ = ptr_->next_;
    return const_iterator(temp);
}

template <typename T>
bool 
SingleList<T>::const_iterator::operator==(const const_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool 
SingleList<T>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool 
SingleList<T>::const_iterator::operator<(const const_iterator& rhv) const
{
    return ptr_ < rhv.ptr_;
}

template <typename T>
bool 
SingleList<T>::const_iterator::operator>(const const_iterator& rhv) const
{
    return rhv < *this;
}

template <typename T>
bool 
SingleList<T>::const_iterator::operator<=(const const_iterator& rhv) const
{
    return !(rhv < *this);
}

template <typename T>
bool 
SingleList<T>::const_iterator::operator>=(const const_iterator& rhv) const
{
    return !(*this < rhv);
}

template <typename T>
void 
SingleList<T>::const_iterator::setPtr(Node* ptr)
{
    ptr_ = ptr;
}

template <typename T>
typename SingleList<T>::Node* 
SingleList<T>::const_iterator::getPtr() const
{    
    return ptr_;
}

template <typename T>
void 
SingleList<T>::const_iterator::increment()
{
    ptr_ = ptr_->next_;
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::const_iterator::next() const
{
    assert(ptr_ != NULL);
    return iterator(ptr_->next_);
}

template <typename T>
void
SingleList<T>::const_iterator::next(const const_iterator& rhv)
{
    assert(ptr_ != NULL);
    ptr_->next_ = rhv.ptr_;
}

/// iterator

template <typename T>
SingleList<T>::iterator::iterator()
    : const_iterator()
{}

template <typename T>
SingleList<T>::iterator::iterator(Node* ptr)
    : const_iterator(ptr)
{}

template <typename T>
SingleList<T>::iterator::iterator(const iterator& rhv)
    : const_iterator(rhv)
{}

template <typename T>
SingleList<T>::iterator::~iterator()
{
    this->destroy();
}

template <typename T>
const typename SingleList<T>::iterator& 
SingleList<T>::iterator::operator=(const iterator& rhv)
{
    this->setPtr(rhv.getPtr());
    return *this;
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::iterator::operator*()
{
    return (this->getPtr())->data_;
}

template <typename T>
typename SingleList<T>::value_type*
SingleList<T>::iterator::operator->()
{
    return &this->getPtr();
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::iterator::operator++()
{
    this->increment();
    return iterator(this->getPtr());
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::iterator::operator++(int)
{
    Node* temp = this->getPtr();
    this->increment();
    return iterator(temp);
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::iterator::next()
{
    return iterator(const_iterator::next().getPtr());
}

template <typename T>
void
SingleList<T>::iterator::next(iterator rhv)
{
    const_iterator::next(rhv);
}

