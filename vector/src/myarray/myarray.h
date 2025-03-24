#ifndef MYARRAY_MYARRAY_H
#define MYARRAY_MYARRAY_H

#include <cstddef>
#include <limits>

namespace myarray
{
class MyIntArray
{
public:
    using iterator = int*;
    using const_iterator = const iterator;
    using size_type = std::size_t;
    using value_type = int;

public:
    explicit MyIntArray(size_type);
    MyIntArray(const MyIntArray&);
    MyIntArray(MyIntArray&&);
    ~MyIntArray();

    MyIntArray& operator=(const MyIntArray&);
    MyIntArray& operator=(MyIntArray&&);

    int& operator[](size_type id) { return values_[id]; }
    const int& operator[](size_type id) const { return values_[id]; }

    iterator begin() { return values_; }
    iterator end() { return values_ + size_; }
    iterator begin() const { return values_; };
    iterator end() const { return values_ + size_; };

    size_type size() const { return size_; }
    size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); }
    bool empty() const { return size() == 0; }

private:
    void destroy();

private:
    value_type* values_ = nullptr;
    size_type size_ = 0;
};
}

#endif // MYARRAY_MYARRAY_H