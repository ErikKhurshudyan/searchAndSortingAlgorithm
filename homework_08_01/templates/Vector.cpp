#include "headers/Vector.hpp"

#include <cassert>
#include <cstring>
#include <limits>
#include <cmath>
#include <iterator>
#include <memory>

template <typename T>
std::istream& 
operator>>(std::istream& in, Vector<T>& rhv)
{
    const typename Vector<T>::const_iterator end = rhv.end();
    for (typename Vector<T>::iterator it = rhv.begin(); it != end; ++it) {
        in >> *it;
    }
    return in;
}

template <typename T>
std::ostream& 
operator<<(std::ostream& out, const Vector<T>& rhv)
{
    const typename Vector<T>::const_iterator end = rhv.end();
    out << "{";
    for (typename Vector<T>::const_iterator it = rhv.begin(); it != end; ++it) {
        out << ' ' << *it;
    }
    out << " }";
    return out;
}

template <typename T>
Vector<T>::Vector()
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{}

template <typename T>
Vector<T>::Vector(const size_type size)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    resize(size);
}

template <typename T>
Vector<T>::Vector(const size_type size, const T& initialValue)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    resize(size, initialValue);
}

template <typename T>
Vector<T>::Vector(const long size, const T& initialValue)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    resize(size, initialValue);
}

template <typename T>
Vector<T>::Vector(const int size, const T& initialValue)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    resize(size, initialValue);
}

template <typename T>
Vector<T>::Vector(const Vector& rhv)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    copyHelper(rhv.begin(), rhv.end());
}

template <typename T>
template <typename InputIterator> 
Vector<T>::Vector(InputIterator first, InputIterator last)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    copyHelper(first, last);
}

template <typename T>
Vector<T>::~Vector()
{
    clear();
}

template <typename T>
void 
Vector<T>::clear()
{
    if (begin_ != NULL) {
        const size_type oldSize = size();
        for (size_type i = 0; i < oldSize; ++i) { (begin_ + i)->~T(); }
        ::operator delete [](begin_);
        begin_ = NULL;
        end_ = NULL;
        bufferEnd_ = NULL;
    }
}

template <typename T>
const Vector<T>& 
Vector<T>::operator=(const Vector<T>& rhv)
{
    if (this == &rhv) { return *this; }
    copyHelper(rhv.begin(), rhv.end());
    return *this;
}

template <typename T>
template <typename InputIterator>
void 
Vector<T>::copyHelper(InputIterator first, InputIterator last)
{
    iterator it = begin();
    while (first != last && it != end()) { *it++ = *first++; }
    while (it != end()) { pop_back(); }
    while (first != last) { push_back(*first++); }
}

template <typename T>
void
Vector<T>::resize(const size_type newSize, const T& initialValue)
{
    assert(newSize < max_size());
    reserve(newSize);
    const size_type currentSize = size();
    for (size_type i = newSize; i < currentSize; ++i) { begin_[i].~T();           }
    for (size_type i = currentSize; i < newSize; ++i) { new (begin_ + i) T(initialValue); }
    end_ = begin_ + newSize;
}

template <typename T>
void 
Vector<T>::reserve(const size_type newCapacity)
{
    if (newCapacity > capacity()) {
        const size_type oldSize = size();
        pointer newPtr = reinterpret_cast<pointer>(::operator new[](newCapacity * sizeof(T)));
        if (begin_ != NULL) {
            std::memcpy(reinterpret_cast<void*>(newPtr), reinterpret_cast<void*>(begin_), newCapacity * sizeof(T));
            ::operator delete [](begin_);
        }
        begin_ = newPtr;
        end_ = begin_ + oldSize;
        bufferEnd_ = begin_ + newCapacity;
    } 
}

template <typename T>
typename Vector<T>::size_type
Vector<T>::size() const
{
    return end_ - begin_;
}

template <typename T>
typename Vector<T>::size_type 
Vector<T>::capacity() const
{
    return bufferEnd_ - begin_;
}

template <typename T>
typename Vector<T>::size_type
Vector<T>::max_size() const
{
    return std::numeric_limits<unsigned int>::max() / 4 * 3 * sizeof(T*);
}

template <typename T>
typename Vector<T>::const_reference
Vector<T>::operator[](const size_type index) const
{
    assert(index < size());
    return *(begin_ + index);
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::operator[](const size_type index)
{
    assert(index < size());
    return *(begin_ + index);
}

template <typename T>
void 
Vector<T>::push_back(const T& element)
{
    if (end_ == bufferEnd_) {
        reserve(capacity() != 0 ? ::ceil(RESERVE_COEFF * capacity()) : 1);
    }
    new (end_) T(element);
    ++end_;
}

template <typename T>
void 
Vector<T>::pop_back()
{
    assert(!empty());
    --end_;
    end_->~T();
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::front() const
{
    assert(!empty());
    return *begin_;
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::front()
{
    assert(!empty());
    return *begin_;
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::back() const
{
    assert(!empty());
    return *(end_ - 1);
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::back()
{
    assert(!empty());
    return *(end_ - 1);
}

template <typename T>
typename Vector<T>::const_iterator      
Vector<T>::begin() const 
{
    return const_iterator(begin_);
}

template <typename T>
typename Vector<T>::const_iterator       
Vector<T>::end() const 
{
    return const_iterator(end_);
}

template <typename T>
typename Vector<T>::iterator
Vector<T>::begin() 
{
    return iterator(begin_);
}

template <typename T>
typename Vector<T>::iterator
Vector<T>::end() 
{
    return iterator(end_);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::rbegin() const 
{
    return const_reverse_iterator(end_ - 1);
}

template <typename T>
typename Vector<T>::const_reverse_iterator
Vector<T>::rend() const 
{
    return const_reverse_iterator(begin_ - 1);
}

template <typename T>
typename Vector<T>::reverse_iterator     
Vector<T>::rbegin() 
{
    return reverse_iterator(end_ - 1);
}

template <typename T>
typename Vector<T>::reverse_iterator     
Vector<T>::rend() 
{
    return reverse_iterator(begin_ - 1);
}

template <typename T>
typename Vector<T>::iterator     
Vector<T>::insert(iterator pos, const T& x)
{
    difference_type far = pos - begin();
    resize(size() + 1);
    pos = begin() + far;
    shiftingToEnd(pos, 1);
    *pos = x;
    return pos; 
}
    
template <typename T>
void 
Vector<T>::insert(iterator pos, const size_type n, const T& x)
{
    difference_type far = pos - begin();
    resize(size() + n);
    pos = begin() + far;
    shiftingToEnd(pos, n);
    for (iterator it = pos; it != pos + n; ++it) { *it = x; }
}
    
template <typename T>
void 
Vector<T>::insert(iterator pos, const long n, const T& x)
{
    difference_type far = pos - begin();
    resize(size() + n);
    pos = begin() + far;
    shiftingToEnd(pos, n);
    for (iterator it = pos; it != pos + n; ++it) { *it = x; }
}
    
template <typename T>
void 
Vector<T>::insert(iterator pos, const int n, const T& x)
{
    difference_type far = pos - begin();
    resize(size() + n);
    pos = begin() + far;
    shiftingToEnd(pos, n);
    for (iterator it = pos; it != pos + n; ++it) { *it = x; }
}

template <typename T>
template <typename InputIterator>
void 
Vector<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) {
        pos = insert(pos, *first++);
        ++pos;
    }
}

template <typename T>
void 
Vector<T>::shiftingToEnd(iterator pos, const size_type n)
{
    iterator it = end() - 1;
    while (it != pos + n - 1) {
        *it = *(it - n);
        --it;
    }
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::erase(iterator pos)
{
    assert(pos >= begin() && pos < end());
    iterator it = pos;
    while (it != end() - 1) {
        *it = *(it + 1);
        ++it;
    }
    pop_back();
    return pos;
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::erase(iterator first, iterator last)
{
    assert(first >= begin() && last <= end());
    assert(first <= last);
    difference_type diff = last - first;
    while (last < end()) { *first++ = *last++; }
    resize(size() - diff);
    return first;
}

template <typename T>
bool 
Vector<T>::operator==(const Vector<T>& rhv) const
{
    const size_type currentSize = size();
    if (currentSize != rhv.size()) {
        return false;
    }
    for (size_type i = 0; i < currentSize; ++i) {
        if (begin_[i] != rhv.begin_[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool 
Vector<T>::operator!=(const Vector<T>& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool 
Vector<T>::operator<(const Vector<T>& rhv) const
{
    const size_type currentSize = size();
    const size_type rhvSize = rhv.size();
    for (size_type i = 0; i < currentSize; ++i) {
        if (begin_[i] != rhv.begin_[i]) {
            return begin_[i] < rhv.begin_[i];
        }
    }
    return currentSize < rhvSize;
}

template <typename T>
bool 
Vector<T>::operator>(const Vector<T>& rhv) const
{
    return rhv < *this;
}

template <typename T>
bool 
Vector<T>::operator>=(const Vector<T>& rhv) const
{
    return !(*this < rhv); 
}

template <typename T>
bool 
Vector<T>::operator<=(const Vector<T>& rhv) const
{

    return !(rhv < *this);
}

template <typename T>
bool
Vector<T>::empty() const
{
    return begin_ == end_;
}

/// const_iterator

template <typename T>
Vector<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{}

template <typename T>
Vector<T>::const_iterator::const_iterator(pointer ptr)
    : ptr_(ptr)
{}

template <typename T>
Vector<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{}

template <typename T>
Vector<T>::const_iterator::~const_iterator()
{
    destroy();
}

template <typename T>
void 
Vector<T>::const_iterator::destroy()
{
    ptr_ = NULL;
}

template <typename T>
const typename Vector<T>::const_iterator& 
Vector<T>::const_iterator::operator=(const const_iterator& rhv)
{
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::const_iterator::operator*() const
{
    assert(ptr_ != NULL);
    return *ptr_;
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::const_iterator::operator[](const size_type size) const
{
    assert(ptr_ != NULL);
    return *(ptr_ + size);
}

template <typename T>
typename Vector<T>::pointer 
Vector<T>::const_iterator::operator->() const
{
    assert(ptr_ != NULL);
    return &ptr_;
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator+(const int value) const
{
    return const_iterator(ptr_ + value);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator-(const int value) const
{
    return const_iterator(ptr_ - value);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator++() 
{
    return const_iterator(++ptr_);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator++(int) 
{
    return const_iterator(ptr_++);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator--() 
{
    return const_iterator(--ptr_);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator--(int)
{
    return const_iterator(ptr_--);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator+=(const int value)
{
    return const_iterator(ptr_ += value);
}

template <typename T>
typename Vector<T>::const_iterator 
Vector<T>::const_iterator::operator-=(const int value)
{
    return const_iterator(ptr_ -= value);
}

template <typename T>
bool 
Vector<T>::const_iterator::operator==(const const_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool 
Vector<T>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool 
Vector<T>::const_iterator::operator<(const const_iterator& rhv) const
{
    return ptr_ < rhv.ptr_;
}

template <typename T>
bool
Vector<T>::const_iterator::operator>(const const_iterator& rhv) const
{
    return (rhv < *this);
}

template <typename T>
bool
Vector<T>::const_iterator::operator>=(const const_iterator& rhv) const
{
    return !(*this < rhv);
}

template <typename T>
bool
Vector<T>::const_iterator::operator<=(const const_iterator& rhv) const 
{
    return !(rhv < *this);
}

template <typename T>
typename Vector<T>::pointer
Vector<T>::const_iterator::getPtr() const
{
    return ptr_;
}

template <typename T>
void
Vector<T>::const_iterator::increment(const int value)
{
    ptr_ += value;
}

template <typename T>
void
Vector<T>::const_iterator::decrement(const int value)
{
    ptr_ -= value;
}

/// iterator

template <typename T>
Vector<T>::iterator::iterator()
    : const_iterator()
{}

template <typename T>
Vector<T>::iterator::iterator(const iterator& rhv)
    : const_iterator(rhv)
{}

template <typename T>
Vector<T>::iterator::iterator(pointer ptr)
    : const_iterator(ptr)
{}

template <typename T>
Vector<T>::iterator::~iterator()
{
    this->destroy();
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::iterator::operator[](const size_type size)
{
    return *(this->getPtr() + size);
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::iterator::operator*()
{
    return *(this->getPtr());
}

template <typename T>
typename Vector<T>::pointer 
Vector<T>::iterator::operator->()
{
    return this->getPtr();
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator+(const int value) const
{
    return iterator(this->getPtr() + value);
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator-(const int value) const
{
    return iterator(this->getPtr() - value);
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator++() 
{
    this->increment();
    return iterator(this->getPtr());

}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator++(int) 
{
    pointer it = this->getPtr();
    this->increment();
    return iterator(it);
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator--() 
{
    this->decrement();
    return iterator(this->getPtr());
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator--(int)
{
    pointer it = this->getPtr();
    this->decrement();
    return iterator(it);
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator+=(const int value)
{
    this->increment(value);
    return iterator(this->getPtr());
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::iterator::operator-=(const int value)
{
    this->decrement(value);
    return iterator(this->getPtr());
}

template <typename T>
typename Vector<T>::difference_type
Vector<T>::iterator::operator-(const iterator& rhv)
{
    return this->getPtr() - rhv.getPtr();
}

/// const_reverse_iterator
template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
    : ptr_(ptr)
{}

template <typename T>
Vector<T>::const_reverse_iterator::~const_reverse_iterator()
{
    destroy();
}

template <typename T>
void
Vector<T>::const_reverse_iterator::destroy()
{
    ptr_ = NULL;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& 
Vector<T>::const_reverse_iterator::operator=(const const_reverse_iterator& rhv)
{
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::const_reverse_iterator::operator[](const size_type size) const
{
    return *(ptr_ - size);
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::const_reverse_iterator::operator*() const
{
    return *ptr_;
}

template <typename T>
typename Vector<T>::pointer 
Vector<T>::const_reverse_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator+(const int value) const
{
    return const_reverse_iterator(ptr_ - value);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator-(const int value) const
{
    return const_reverse_iterator(ptr_ + value);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator++()
{
    return const_reverse_iterator(--ptr_);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator++(int)
{
    return const_reverse_iterator(ptr_--);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator--()
{
    return const_reverse_iterator(++ptr_);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator--(int)
{
    return const_reverse_iterator(ptr_++);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator+=(const int value)
{
    return const_reverse_iterator(ptr_ -= value);
}

template <typename T>
typename Vector<T>::const_reverse_iterator 
Vector<T>::const_reverse_iterator::operator-=(const int value)
{
    return const_reverse_iterator(ptr_ += value);
}

template <typename T>
bool 
Vector<T>::const_reverse_iterator::operator==(const const_reverse_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool 
Vector<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhv) const
{
    return !(rhv == *this);
}

template <typename T>
bool 
Vector<T>::const_reverse_iterator::operator<(const const_reverse_iterator& rhv) const
{
    return ptr_ > rhv.ptr_; 
}

template <typename T>
bool 
Vector<T>::const_reverse_iterator::operator>(const const_reverse_iterator& rhv) const
{
    return rhv < (*this);
}

template <typename T>
bool 
Vector<T>::const_reverse_iterator::operator>=(const const_reverse_iterator& rhv) const
{
    return !(*this < rhv);
}

template <typename T>
bool 
Vector<T>::const_reverse_iterator::operator<=(const const_reverse_iterator& rhv) const
{
    return !(rhv < *this);
}

template <typename T>
typename Vector<T>::pointer
Vector<T>::const_reverse_iterator::getPtr() const
{
    return ptr_;
}

template <typename T>
void
Vector<T>::const_reverse_iterator::increment(const int value)
{
    ptr_ -= value;
}

template <typename T>
void
Vector<T>::const_reverse_iterator::decrement(const int value)
{
    ptr_ += value;
}

/// reverse_iterator

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator(const reverse_iterator& rhv)
    : const_reverse_iterator(rhv)
{}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator(pointer ptr)
    : const_reverse_iterator(ptr)
{}

template <typename T>
Vector<T>::reverse_iterator::~reverse_iterator()
{
    this->destroy();
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::reverse_iterator::operator[](const size_type size)
{
    return *(this->getPtr() - size);
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::reverse_iterator::operator*()
{
    return *this->getPtr();
}

template <typename T>
typename Vector<T>::pointer 
Vector<T>::reverse_iterator::operator->()
{
    return this->getPtr();
}

template <typename T>
typename Vector<T>::reverse_iterator 
Vector<T>::reverse_iterator::operator+(const int value) const
{
    return reverse_iterator(this->getPtr() - value);
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::reverse_iterator::operator-(const int value) const
{
    return reverse_iterator(this->getPtr() + value);
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::reverse_iterator::operator++()
{
    this->increment();
    return reverse_iterator(this->getPtr());
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::reverse_iterator::operator++(int)
{
    pointer it = this->getPtr();
    this->increment();
    return reverse_iterator(it);
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::reverse_iterator::operator--()
{
    this->decrement();
    return reverse_iterator(this->getPtr());
}

template <typename T>
typename Vector<T>::reverse_iterator 
Vector<T>::reverse_iterator::operator--(int)
{
    pointer it = this->getPtr();
    this->decrement();
    return reverse_iterator(it);
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::reverse_iterator::operator+=(const int value)
{
    this->increment(value);
    return reverse_iterator(this->getPtr());
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::reverse_iterator::operator-=(const int value)
{
    this->decrement(value);
    return reverse_iterator(this->getPtr());
}

