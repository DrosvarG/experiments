#ifndef MYARRAY_MYARRAY_H
#define MYARRAY_MYARRAY_H

#include <cstdlib>

namespace myarray
{
class MyIntArray
{
public:
    using size_type = std::size_t;
    using value_type = int;

public:
    MyIntArray(size_type);
    MyIntArray(const MyIntArray&);
    MyIntArray(MyIntArray&&);
    ~MyIntArray();

    int& operator[](size_type);
    const int& operator[](size_type) const;

    size_type size() const;

private:
    value_type* values_;
    size_type size_ = 0;
};
}

#endif // MYARRAY_MYARRAY_H