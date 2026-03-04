#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <utility>
template <typename T>
class Vector 
{
public:
    class iterator;
    class const_iterator;
    using reference = T&;
    using rvalue_reference = T&&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();
    void push_back(const_reference value);
    void pop_back();
    const_reference operator[](const std::size_t index) const;
    reference operator[](const std::size_t index);
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    pointer data();
    const_pointer data() const;
// <=== Iterators ===>
    iterator begin();
    const_iterator cbegin() const;

    iterator end();
    const_iterator cend() const;

    iterator rbegin();
    const_iterator crbegin() const;

    iterator rend();
    const_iterator crend() const;

    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;

// <=== Modifiers ===>
    void clear();
    iterator insert(const_iterator pos, const_reference value);
    itertor insert(const_iterator pos, rvalue_reference value);
    iterator insert(const iterator pos, std::size_t count, const_reference value);
    // 2 other prototypes 

    iterator erase(iterator pos);
    iterator erase(const_iterator pos);
    iterator erase(iterator first, iterator last);
    iterator erase(const_iterator first, const_iterator last);

    void resize(std::size_t count);
    void resize(std::size_t count, const_reference value);
private:
    pointer _arr;
    std::size_t _size;
    std::size_t _capacity;
private:
    void resize();

};

template <typename T>
class Vector<T>::iterator
{
    friend class Vector<T>;
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
public:
    iterator(pointer ptr);
    reference operator*();
    pointer operator->();
    iterator& operator++();
    iterator& operator++(int);
    itertaor& operator--();
    iterator& operator--(int);
    bool operator==(const iterator& other);
    bool operator!=(const iterator& other);
    iterator& operator=(const iterator&) = default    
private:
    pointer _ptr;
};

template <typename T>
class Vector<T>::const_iterator
{
    friend class Vector<T>;
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;
public:
    const_iterator(pointer ptr);
    const_iterator(const iterator& it);
    reference operator*() const;
    pointer operator->() const;
    const const_iterator& operator++() const;
    const const_iterator& operator++(int) const;
    const const_iterator& operator--() const;
    const const_iterator& operator--(int) const;
    bool operator==(const const_iterator& other) const;
    bool operator!=(const const_iterator& other) const;
private:
    pointer _ptr;
};
#include "vector.tpp"
#endif // VECTOR_H