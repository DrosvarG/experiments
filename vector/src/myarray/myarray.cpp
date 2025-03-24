#include "myarray/myarray.h"

#include <algorithm>
#include <iostream>
#include <iterator>

namespace myarray
{
MyIntArray::MyIntArray(size_type size)
    : size_(size)
{
    values_ = new int[size_];
    for(size_type i = 0; i < size_; ++i)
        values_[i] = 0;
}

MyIntArray::MyIntArray(const MyIntArray& other)
    : size_(other.size_)
{
    values_ = new int[size_];
    std::copy(other.values_, other.values_ + size_, values_);
}

MyIntArray::MyIntArray(MyIntArray&& other)
    : size_(other.size_)
{
    std::swap(values_, other.values_);
}

MyIntArray::~MyIntArray()
{
    if(values_)
        destroy();
}

MyIntArray& MyIntArray::operator=(const MyIntArray& other)
{
    if(size_ != other.size_)
    {
        destroy();
        size_ = other.size_;
        values_ = new int[size_];
    }
    std::copy(other.values_, other.values_ + size_, values_);
    return *this;
}

MyIntArray& MyIntArray::operator=(MyIntArray&& other)
{
    if(size_ != other.size_)
        size_ = other.size_;
    std::swap(values_, other.values_);
    return *this;
}

void MyIntArray::destroy()
{
    delete[] values_;
}

}