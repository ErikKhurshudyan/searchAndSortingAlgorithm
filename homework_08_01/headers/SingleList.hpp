#ifndef __SINGLE_LIST_T_HPP__
#define __SINGLE_LIST_T_HPP__

#include <iostream>

template <typename T> class SingleList;
template <typename T> std::istream& operator>>(std::istream& in, SingleList<T>& rhv);
template <typename T> std::ostream& operator<<(std::ostream& out, const SingleList<T>& rhv);

template <typename T>
class SingleList
{
private:
    template <typename T1> friend std::istream& operator>>(std::istream& in, SingleList<T1>& rhv);
    template <typename T1> friend std::ostream& operator<<(std::ostream& out, const SingleList<T1>& rhv);
    template <typename T1>
    friend void bubbleSort(SingleList<T1>& rhv);

    struct Node {
        Node(T data = T(), Node* next = NULL) : data_(data), next_(next) {}
        T data_;
        Node* next_;
    };

public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

public:
    SingleList();
    SingleList(const size_type size, const T& initialValue = T());
    SingleList(const long size, const T& initialValue = T());
    SingleList(const int size, const T& initialValue = T());
    SingleList(const SingleList& rhv);
    template <typename InputIterator> SingleList(InputIterator fist, InputIterator last);
    ~SingleList();
    const SingleList<T>& operator=(const SingleList<T>& rhv);
    void resize(const size_type newSize, const T& initialValue = T());
    size_type size() const;
    size_type max_size() const;
    void clear();
    
    void push_front(const T& value);
    void pop_front();
    const_reference front() const;
    reference front();
    
    void swap(SingleList<T>& rhv);
    void unique();
    void merge(SingleList<T>& rhv);
    void sort();
    void reverse();
    void remove(const T& value);

    bool empty() const;
    bool operator==(const SingleList<T>& rhv) const;
    bool operator!=(const SingleList<T>& rhv) const;
    bool operator< (const SingleList<T>& rhv) const;
    bool operator> (const SingleList<T>& rhv) const;
    bool operator>=(const SingleList<T>& rhv) const;
    bool operator<=(const SingleList<T>& rhv) const;

    class const_iterator {
        friend class SingleList<T>; 
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        ~const_iterator();
        const const_iterator& operator=(const const_iterator& rhv);
        const_reference operator*() const;
        const value_type* operator->() const;
        const_iterator operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
        bool operator> (const const_iterator& rhv) const;
        bool operator< (const const_iterator& rhv) const;
        bool operator<=(const const_iterator& rhv) const;
        bool operator>=(const const_iterator& rhv) const;
    protected:
        explicit const_iterator(Node* ptr);
        void increment();
        void destroy();
        Node* getPtr() const;
        void setPtr(Node* ptr);
        const_iterator next() const;
        void next(const const_iterator& rhv);
    private:
        Node* ptr_;
    };

    class iterator : public const_iterator {
        friend class SingleList<T>; 
    public:
        iterator();
        iterator(const iterator& rhv);
        const iterator& operator=(const iterator& rhv);
        ~iterator();
        reference operator*();
        value_type* operator->();
        iterator operator++();
        iterator operator++(int);
    private:
        explicit iterator(Node* ptr);
        iterator next();
        void next(iterator rhv);
    };

    const_iterator begin() const;
    const_iterator end() const;
    iterator begin();
    iterator end();

    iterator insert(iterator pos, const T& x = T());
    void insert(iterator pos, const size_type size, const T& x);
    void insert(iterator pos, const long size, const T& x);
    void insert(iterator pos, const int size, const T& x);
    template <typename InputIterator> void insert(iterator pos, InputIterator first, InputIterator last);
    
    iterator insert_after(iterator pos, const T& x = T());
    void insert_after(iterator pos, const size_type size, const T& x);
    void insert_after(iterator pos, const long size, const T& x);
    void insert_after(iterator pos, const int size, const T& x);
    template <typename InputIterator> void insert_after(iterator pos, InputIterator first, InputIterator last);

    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
    iterator erase_after(iterator pos);

    void splice(iterator pos, SingleList& rhv);
    void splice(iterator pos, SingleList& rhv, iterator it);
    void splice(iterator pos, SingleList& rhv, iterator first, iterator last);
    
    void splice_after(iterator pos, iterator prev);
    void splice_after(iterator pos, iterator before_first, iterator before_last);

    void bubbleSort();

private:
    template <typename InputIterator>
    void copyHelper(InputIterator first, InputIterator last);

private:
    Node* begin_;
    Node* end_;

};

#include "templates/SingleList.cpp"
#endif /// __SINGLE_LIST_T_HPP__

