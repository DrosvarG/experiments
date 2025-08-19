#ifndef MYARRAY_MYARRAY_H
#define MYARRAY_MYARRAY_H

#include <cstddef>
#include <iterator>
#include <limits>
#include <memory>

namespace myarray
{

template <typename T>
class MyArray
{
public:
    class Iterator
    {
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;

    public:
        Iterator(pointer ptr)
            : ptr_(ptr)
        {
        }

    public:
        // Forward Iterator requirements
        reference operator*() const { return *ptr_; }
        pointer operator->() { return ptr_; }

        Iterator& operator++()
        {
            ++ptr_;
            return *this;
        }
        Iterator operator++(int)
        {
            auto tmp = *this;
            ++ptr_;
            return tmp;
        }

        bool operator==(const Iterator& other) { return ptr_ == other.ptr_; }
        bool operator!=(const Iterator& other) { return ptr_ != other.ptr_; }

        // Bidrectionnal requirements
        Iterator& operator--()
        {
            --ptr_;
            return *this;
        }
        Iterator operator--(int)
        {
            auto tmp = *this;
            --ptr_;
            return tmp;
        }

        // Random access requirements

        Iterator& operator+=(const difference_type& movement)
        {
            ptr_ += movement;
            return *this;
        }
        Iterator operator+(const difference_type& movement)
        {
            auto oldPtr = ptr_;
            ptr_ += movement;
            auto tmp = *this;
            ptr_ = oldPtr;
            return tmp;
        }
        Iterator& operator-=(const difference_type& movement)
        {
            ptr_ -= movement;
            return *this;
        }
        Iterator operator-(const difference_type& movement)
        {
            auto oldPtr = ptr_;
            ptr_ -= movement;
            auto tmp = *this;
            ptr_ = oldPtr;
            return tmp;
        }

        auto operator<=>(const Iterator&) const = default;

        difference_type operator-(const Iterator& other) { return std::distance(other.ptr_, ptr_); }
        Iterator& operator[](const difference_type& movement) { return *(this + movement); }

    private:
        pointer ptr_ = nullptr;
    };

public:
    using iterator = Iterator;
    using const_iterator = const Iterator;
    using size_type = std::size_t;
    using value_type = T;

    MyArray();
    MyArray(const MyArray&);
    MyArray(MyArray&&);
    ~MyArray() = default;

    explicit MyArray(size_type);

    MyArray& operator=(const MyArray&);
    MyArray& operator=(MyArray&&);

    int& operator[](size_type id) { return values_[id]; }
    const int& operator[](size_type id) const { return values_[id]; }

    iterator begin() { return Iterator(values_.get()); }
    iterator end() { return Iterator(values_.get() + size_); }
    const_iterator begin() const { return Iterator(values_.get()); };
    const_iterator end() const { return Iterator(values_.get() + size_); };

    size_type size() const { return size_; }
    size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); }
    bool empty() const { return size() == 0; }

private:
    std::unique_ptr<value_type[]> values_ = nullptr;
    size_type size_ = 0;
};
}

#include "myarray/myarray.tpp"

#endif // MYARRAY_MYARRAY_H