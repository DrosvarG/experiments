#ifndef MYARRAY_MYARRAY_TPP
#define MYARRAY_MYARRAY_TPP

#include "myarray/myarray.h"

#include <algorithm>
#include <memory>

namespace myarray
{

template <typename T>
MyArray<T>::MyArray()
    : size_(size_type())
{
    values_ = std::make_unique<value_type[]>(size_);
    for(size_type i = 0; i < size_; ++i)
        values_[i] = value_type();
}

template <typename T>
MyArray<T>::MyArray(const MyArray& other)
    : size_(other.size_)
{
    values_ = std::make_unique<value_type[]>(size_);
    std::copy(other.begin(), other.end(), begin());
}

template <typename T>
MyArray<T>::MyArray(MyArray&& other)
    : size_(other.size_)
{
    std::swap(values_, other.values_);
}

template <typename T>
MyArray<T>::MyArray(size_type size)
    : size_(size)
{
    values_ = std::make_unique<value_type[]>(size_);
    for(size_type i = 0; i < size_; ++i)
        values_[i] = value_type();
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& other)
{
    if(size_ != other.size_)
    {
        size_ = other.size_;
        values_ = std::make_unique<value_type[]>(size_);
    }
    std::copy(other.begin(), other.end(), begin());
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
}

#endif // MYARRAY_MYARRAY_TPP