template <typename T>
Vector<T>::Vector() : _arr{nullptr}, _size{0}, _capacity{2} 
{
    _arr = new T[_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& other) : _arr{nullptr}, _size{other._size}, _capacity{other._capacity}
{
    _arr = new T[_capacity];
    for(std::size_t i = 0; i < _size; ++i)
    {
        _arr[i] = other._arr[i];
    }
} 

template <typename T>
Vector<T>::Vector(Vector&& other) : _arr{std::move(other._arr)}, _size{other._size}, _capacity{other._capacity}
{
    other._arr = nullptr;
    other._size = 0;
    other._capacity = 0;
}

template <typename T>
Vector<T>::~Vector()
{
    delete [] _arr;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
    if(_size >= _capacity)
    {
        resize();
    }
    _arr[_size++] = value;
}

template <typename T>
void Vector<T>::pop_back()
{
    --_size;
}

template <typename T> 
const T& Vector<T>::operator[](const std::size_t index) const 
{
    return _arr[index];
}

template <typename T>
T& Vector<T>::operator[](const std::size_t index) 
{
    return const_cast<T&>(static_cast<const Vector<T>&>(*this)[index]);
}

template <typename T>
std::size_t Vector<T>::size() const 
{
    return _size;
}

template <typename T>
std::size_t Vector<T>::capacity() const 
{
    return _capacity;
}

template <typename T>
void Vector<T>::resize() 
{
    T* newArr = new T[_capacity * 2];
    for(std::size_t i = 0; i < _capacity; ++i)
    {
        newArr[i] = _arr[i];
    }
    _capacity = _capacity * 2;
    delete _arr;
    _arr = newArr;
}