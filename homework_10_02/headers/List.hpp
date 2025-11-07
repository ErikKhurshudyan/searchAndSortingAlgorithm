#ifndef __LIST_T_HPP__
#define __LIST_T_HPP__

#include <cstddef>
#include <iostream>

template <typename T> class List;
template <typename T> std::istream& operator>>(std::istream& in, List<T>& rhv);
template <typename T> std::ostream& operator<<(std::ostream& out, const List<T>& rhv);

template <typename T>
class List
{
private:
    template <typename T1>  friend void mergeSort(List<T1>& rhv);
    template <typename T1>  friend void myAdvance(typename List<T1>::Node*& rhv, const size_t count);
    template <typename T1>  friend size_t distanse(typename List<T1>::Node* first, typename List<T1>::Node* last);

    template <typename T1>  friend void mergeForList(typename List<T1>::Node* first, typename List<T1>::Node* middle, typename List<T1>::Node* end);




    template <typename T1> friend std::istream& operator>>(std::istream& in, List<T1>& rhv);
    template <typename T1> friend std::ostream& operator<<(std::ostream& out, const List<T1>& rhv);
    struct Node {
        Node(T data = T(), Node* prev = NULL, Node* next = NULL) 
            : data_(data), prev_(prev), next_(next) {}
        T data_;
        Node* prev_;
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
    List();
    List(const size_type size);
    List(const size_type size, const T& initialValue);
    List(const int size, const T& initialValue);
    List(const long int size, const T& initialValue);
    List(const List& rhv);
    template <typename InputIterator> List(InputIterator fist, InputIterator last);
    ~List();
    const List<T>& operator=(const List<T>& rhv);
    void resize(const size_type newSize, const T& initialValue = T());
    size_type size() const;
    size_type max_size() const;
    void clear();
    
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    const_reference front() const;
    reference front();
    const_reference back() const;
    reference back();
    
    void swap(List<T>& rhv);
    void unique();
    void merge(List<T>& rhv);
    void sort();
    void reverse();
    void remove(const T& value);

    bool operator==(const List<T>& rhv) const;
    bool operator!=(const List<T>& rhv) const;
    bool operator< (const List<T>& rhv) const;
    bool operator> (const List<T>& rhv) const;
    bool operator>=(const List<T>& rhv) const;
    bool operator<=(const List<T>& rhv) const;
    bool empty() const;

    class const_iterator {
        friend class List<T>; 
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        ~const_iterator();
        const const_iterator& operator=(const const_iterator& rhv);
        const_reference operator*() const;
        const value_type* operator->() const;
        const_iterator operator++();
        const_iterator operator++(int);
        const_iterator operator--();
        const_iterator operator--(int);
        bool operator==(const const_iterator& rhv);
        bool operator!=(const const_iterator& rhv);
        bool operator> (const const_iterator& rhv);
        bool operator< (const const_iterator& rhv);
        bool operator<=(const const_iterator& rhv);
        bool operator>=(const const_iterator& rhv);
    protected:
        void increment();
        void decrement();
        void destroy();
        Node* getPtr() const;
        void setPtr(Node* ptr);
    private:
        explicit const_iterator(Node* ptr);
    private:
        Node* ptr_;
    };

    class iterator : public const_iterator {
        friend class List<T>; 
    public:
        iterator();
        iterator(const iterator& rhv);
        const iterator& operator=(const iterator& rhv);
        ~iterator();
        reference operator*();
        value_type* operator->();
        iterator operator++();
        iterator operator++(int);
        iterator operator--();
        iterator operator--(int);
    private:
        explicit iterator(Node* ptr);
    };

    class const_reverse_iterator {
        friend class List<T>; 
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        ~const_reverse_iterator();
        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);
        const_reference operator*() const;
        const value_type* operator->() const;
        const_reverse_iterator operator++();
        const_reverse_iterator operator++(int);
        const_reverse_iterator operator--();
        const_reverse_iterator operator--(int);
        bool operator==(const const_reverse_iterator& rhv);
        bool operator!=(const const_reverse_iterator& rhv);
        bool operator> (const const_reverse_iterator& rhv);
        bool operator< (const const_reverse_iterator& rhv);
        bool operator<=(const const_reverse_iterator& rhv);
        bool operator>=(const const_reverse_iterator& rhv);
    protected:
        void increment();
        void decrement();
        void destroy();
        Node* getPtr() const;
        void setPtr(Node* ptr);
    private:
        explicit const_reverse_iterator(Node* ptr);
    private:
        Node* ptr_;
    };

    class reverse_iterator : public const_reverse_iterator {
        friend class List<T>; 
    public:
        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv);
        const reverse_iterator& operator=(const reverse_iterator& rhv);
        ~reverse_iterator();
        reference operator*();
        value_type* operator->();
        reverse_iterator operator++();
        reverse_iterator operator++(int);
        reverse_iterator operator--();
        reverse_iterator operator--(int);
    private:
        explicit reverse_iterator(Node* ptr);
    };

    const_iterator begin() const;
    const_iterator end() const;
    iterator begin();
    iterator end();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();

    iterator insert(iterator pos, const T& x = T());
    void insert(iterator pos, const size_type size, const T& x);
    void insert(iterator pos, const long size, const T& x);
    void insert(iterator pos, const int size, const T& x);
    template <typename InputIterator> void insert(iterator pos, InputIterator first, InputIterator last);
    
    iterator insert_after(iterator pos, const T& x = T());
    void insert_after(iterator pos, const size_type size, const T& x);
    void insert_after(iterator pos, const int size, const T& x);
    void insert_after(iterator pos, const long size, const T& x);
    template <typename InputIterator> void insert_after(iterator pos, InputIterator first, InputIterator last);

    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
    iterator erase_after(iterator pos);

    void splice(iterator pos, List& rhv);
    void splice(iterator pos, List& rhv, iterator it);
    void splice(iterator pos, List& rhv, iterator first, iterator last);
    void bubbleSort();

private:
    template <typename InputIterator>
    void copyHelper(InputIterator first, InputIterator last);

private:
    Node* begin_;
    Node* end_;

};

#include "templates/List.cpp"
#endif /// __LIST_T_HPP__

