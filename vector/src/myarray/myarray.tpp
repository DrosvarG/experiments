#ifndef MYARRAY_MYARRAY_TPP
#define MYARRAY_MYARRAY_TPP

#include "myarray/myarray.h"

#include <algorithm>

namespace myarray
{

template <typename T>
MyArray<T>::MyArray(size_type size)
    : size_(size)
{
    values_ = new value_type[size_];
    for(size_type i = 0; i < size_; ++i)
        values_[i] = value_type();
}

template <typename T>
MyArray<T>::MyArray(const MyArray& other)
    : size_(other.size_)
{
    values_ = new value_type[size_];
    std::copy(other.values_, other.values_ + size_, values_);
}

template <typename T>
MyArray<T>::MyArray(MyArray&& other)
    : size_(other.size_)
{
    std::swap(values_, other.values_);
}

template <typename T>
MyArray<T>::~MyArray()
{
    if(values_)
        destroy();
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& other)
{
    if(size_ != other.size_)
    {
        destroy();
        size_ = other.size_;
        values_ = new value_type[size_];
    }
    std::copy(other.values_, other.values_ + size_, values_);
    return *this;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(MyArray<T>&& other)
{
    if(size_ != other.size_)
        size_ = other.size_;
    std::swap(values_, other.values_);
    return *this;
}

template <typename T>
void MyArray<T>::destroy()
{
    delete[] values_;
}

}

#endif // MYARRAY_MYARRAY_TPP