#ifndef __VECTOR_T_HPP__
#define __VECTOR_T_HPP__

#include <iostream>
#include <cstdlib>

template <typename T> class Vector;
template <typename T> std::istream& operator>>(std::istream& in, Vector<T>& rhv);
template <typename T> std::ostream& operator<<(std::ostream& out, const Vector<T>& rhv);
template <typename T>
class Vector
{
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    template <typename T1> friend std::istream& operator>>(std::istream& in, Vector<T1>& rhv);
    template <typename T1> friend std::ostream& operator<<(std::ostream& out, const Vector<T1>& rhv);
    template <typename T1>
    friend void quickSort(Vector<T1>& rhv);
    template <typename T1>
    friend void quickSort(T1* first, T1* last);
    template <typename T1>
    friend T* partition(T* first, T* last);

public:
    Vector();
    Vector(const size_type size);
    Vector(const size_type size, const T& element);
    Vector(const long size, const T& element);
    Vector(const int size, const T& element);
    Vector(const Vector& rhv);
    template <typename InputIterator> Vector(InputIterator first, InputIterator last);
    ~Vector();
    const Vector<T>& operator=(const Vector<T>& rhv);
    void resize(const size_type newSize, const T& initialValue = T());
    void reserve(const size_type newCapacity);
    size_type size() const;
    size_type capacity() const;
    size_type max_size() const;
    void clear();
    
    const_reference operator[](const size_type index) const;
    reference operator[](const size_type index);
    void push_back(const T& element);
    void pop_back();
    const_reference front() const;
    reference front();
    const_reference back() const;
    reference back();

    bool operator==(const Vector<T>& rhv) const;
    bool operator!=(const Vector<T>& rhv) const;
    bool operator< (const Vector<T>& rhv) const;
    bool operator> (const Vector<T>& rhv) const;
    bool operator>=(const Vector<T>& rhv) const;
    bool operator<=(const Vector<T>& rhv) const;
    bool empty() const;
    class const_iterator {
        friend class Vector<T>;
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        ~const_iterator();
        const const_iterator& operator=(const const_iterator& rhv);
        const_reference operator[](const size_type size) const;
        const_reference operator*() const;
        pointer operator->() const;
        const_iterator operator+(const int value) const;
        const_iterator operator-(const int value) const;
        const_iterator operator++();
        const_iterator operator++(int);
        const_iterator operator--();
        const_iterator operator--(int);
        const_iterator operator+=(const int value);
        const_iterator operator-=(const int value);
        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
        bool operator< (const const_iterator& rhv) const;
        bool operator> (const const_iterator& rhv) const;
        bool operator>=(const const_iterator& rhv) const;
        bool operator<=(const const_iterator& rhv) const; 
        pointer getPtr() const;
    protected:
        void increment(const int value = 1);
        void decrement(const int value = 1);
        void destroy();
    private:
        explicit const_iterator(pointer ptr);
    private:
        pointer ptr_;
    };

    class iterator : public const_iterator {
        friend class Vector<T>;
    public:
        iterator();
        iterator(const iterator& rhv);
        ~iterator();
        reference operator[](const size_type size);
        reference operator*();
        pointer operator->();
        iterator operator+(const int value) const;
        iterator operator-(const int value) const;
        iterator operator++();
        iterator operator++(int);
        iterator operator--();
        iterator operator--(int);
        iterator operator+=(const int value);
        iterator operator-=(const int value);
        difference_type operator-(const iterator& rhv);
    private:
        explicit iterator(pointer ptr);
    };

    class const_reverse_iterator {
        friend class Vector<T>;
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        ~const_reverse_iterator();
        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);
        const_reference operator[](const size_type size) const;
        const_reference operator*() const;
        pointer operator->() const;
        const_reverse_iterator operator+(const int value) const;
        const_reverse_iterator operator-(const int value) const;
        const_reverse_iterator operator++();
        const_reverse_iterator operator++(int);
        const_reverse_iterator operator--();
        const_reverse_iterator operator--(int);
        const_reverse_iterator operator+=(const int value);
        const_reverse_iterator operator-=(const int value);
        bool operator==(const const_reverse_iterator& rhv) const;
        bool operator!=(const const_reverse_iterator& rhv) const;
        bool operator< (const const_reverse_iterator& rhv) const;
        bool operator> (const const_reverse_iterator& rhv) const;
        bool operator>=(const const_reverse_iterator& rhv) const;
        bool operator<=(const const_reverse_iterator& rhv) const;
    protected:
        pointer getPtr() const;
        void increment(const int value = 1);
        void decrement(const int value = 1);
        void destroy();
    private:
        explicit const_reverse_iterator(pointer ptr);
    private:
        pointer ptr_;
    };

    class reverse_iterator : public const_reverse_iterator {
        friend class Vector<T>;
    public:
        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv);
        ~reverse_iterator();
        reference operator[](const size_type size);
        reference operator*();
        pointer operator->();
        reverse_iterator operator+(const int value) const;
        reverse_iterator operator-(const int value) const;
        reverse_iterator operator++();
        reverse_iterator operator++(int);
        reverse_iterator operator--();
        reverse_iterator operator--(int);
        reverse_iterator operator+=(const int value);
        reverse_iterator operator-=(const int value);
    private:
        explicit reverse_iterator(pointer ptr);
    };

    const_iterator begin() const;
    const_iterator end() const;
    iterator begin();
    iterator end();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();	

    iterator insert(iterator pos, const T& x);
    void insert(iterator pos, const size_type n, const T& x);
    void insert(iterator pos, const long n, const T& x);
    void insert(iterator pos, const int n, const T& x);
    template <typename InputIterator> void insert(iterator pos, InputIterator f, InputIterator l);
    iterator erase(iterator pos);
    iterator erase(iterator f, iterator l);
private:
    template <typename InputIterator>
    void copyHelper(InputIterator first, InputIterator last);
    void shiftingToEnd(iterator pos, const size_type n);
public:
    static constexpr double RESERVE_COEFF = 2;

private:
    T* begin_;
    T* end_;
    T* bufferEnd_;

};

#include "templates/Vector.cpp"
#endif /// __VECTOR_T_HPP__

