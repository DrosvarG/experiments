#include "myarray/myarray.h"

#include <cstdlib>
#include <iostream>

void printArray(const myarray::MyIntArray a)
{
    for(auto i = std::size_t(0); i < a.size(); ++i)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    auto array = myarray::MyIntArray(3);
    array[0] = 5;
    array[1] = array[0];
    array[0]++;

    printArray(array);

    array[2] = array[1] + 3;

    printArray(array);
}
