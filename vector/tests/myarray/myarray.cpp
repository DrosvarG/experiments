#include "myarray/myarray.h"

#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <limits>
#include <string>
#include <thread>
#include <vector>

using myarray::MyArray;

//============================================================================

//============================================================================

TEMPLATE_TEST_CASE("Default initialized MyArray is empty", "[size]", int, std::string, std::vector<float>, MyArray<char>, std::unique_ptr<int>, std::thread)
{
    const auto array = MyArray<TestType>();

    REQUIRE(array.empty());
}

TEMPLATE_TEST_CASE("Trying to create a MyArray with a capacity superior to max_size should throw", "[size]", int, std::string, std::vector<float>, MyArray<char>, std::unique_ptr<int>, std::thread)
{
    const auto emptyArray = MyArray<TestType>();

    REQUIRE_THROWS(MyArray<TestType>(emptyArray.max_size() + 1));
}

TEMPLATE_TEST_CASE("The size of a MyArray constructed with capacity should be equal to the given capacity", "[size]", int, std::string, std::vector<float>, MyArray<char>, std::unique_ptr<int>, std::thread)
{
    const std::size_t size = GENERATE(0, 1, 42);
    const auto array = MyArray<TestType>(size);

    REQUIRE(array.size() == size);
}

TEMPLATE_TEST_CASE("The size of a MyArray constructed by copy should be equal to the copied MyArray", "[size]", int, std::string, std::vector<float>, MyArray<char>)
{
    const std::size_t size = GENERATE(0, 1, 42);
    const auto sourceArray = MyArray<TestType>(size);

    const auto copyArray = MyArray<TestType>(sourceArray);

    REQUIRE(copyArray.size() == sourceArray.size());
}
