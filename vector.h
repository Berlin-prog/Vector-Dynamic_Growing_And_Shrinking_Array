#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <utility>
template <typename T>
class Vector 
{
public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();
    void push_back(const T& value);
    void pop_back();
    const T& operator[](const std::size_t index) const;
    T& operator[](const std::size_t index);
    std::size_t size() const;
    std::size_t capacity() const;
private:
    T* _arr;
    std::size_t _size;
    std::size_t _capacity;
private:
    void resize();

};
#include "vector.tpp"
#endif // VECTOR_H