#include "myarray/myarray.h"

#include <iostream>

namespace myarray
{
MyIntArray::MyIntArray(size_type size)
    : size_(size)
{
    values_ = new int[size_];
    for(auto i = size_type(0); i < size_; i++)
        values_[i] = 0;
}

MyIntArray::MyIntArray(const MyIntArray& other)
    : size_(other.size_)
{
    values_ = new int[size_];
    for(auto i = size_type(0); i < size_; i++)
        values_[i] = other.values_[i];
}

MyIntArray::MyIntArray(MyIntArray&& other)
    : size_(other.size_)
{
    std::swap(values_, other.values_);
}

MyIntArray::~MyIntArray()
{
    delete values_;
}

int& MyIntArray::operator[](size_type id)
{
    return values_[id];
}
const int& MyIntArray::operator[](size_type id) const
{
    return values_[id];
}

MyIntArray::size_type MyIntArray::size() const
{
    return size_;
}
}