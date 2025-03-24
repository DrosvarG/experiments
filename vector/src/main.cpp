#include "myarray/myarray.h"

#include <cstdlib>
#include <iostream>

void printArray(const myarray::MyIntArray a)
{
    for(auto x: a)
        std::cout << x << ",";
    std::cout << std::endl;
}

int main()
{
    auto array = myarray::MyIntArray(3);
    auto array2 = myarray::MyIntArray(5);

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
