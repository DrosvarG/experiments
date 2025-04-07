#include "myarray/myarray.h"

#include <cstdlib>
#include <iostream>

template <typename T>
void printArray(const myarray::MyArray<T> a)
{
    for(auto x: a)
        std::cout << x << ",";
    std::cout << std::endl;
}

int main()
{
    auto array = myarray::MyArray<int>(3);
    auto array2 = myarray::MyArray<int>(5);

    array[0] = 5;
    array[1] = array[0];
    array[0]++;

    printArray(array);

    array[2] = array[1] + 3;

    printArray(array);

    printArray(array2);
    array2 = array;
    printArray(array2);
    std::cout << array2.size();
}
