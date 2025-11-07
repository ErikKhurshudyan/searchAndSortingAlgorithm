#include <gtest/gtest.h>
#include "headers/functions.hpp"
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/SingleList.hpp"
#include <algorithm>
#include <forward_list>

TEST(CountSortTest, EmptyVector)
{
    Vector<int> v;
    count(v);
    EXPECT_EQ(v.size(), 0u);
}

// Single element test
TEST(CountSortTest, SingleElement)
{
    Vector<int> v;
    v.push_back(42);
    count(v);
    ASSERT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 42);
}

// Already sorted input
TEST(CountSortTest, AlreadySorted)
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    count(v);

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 4);
}

TEST(CountSortTest, ReverseOrder)
{
    Vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    count(v);

    for (size_t i = 0; i < v.size(); ++i)
        EXPECT_EQ(v[i], static_cast<int>(i + 1));
}

TEST(CountSortTest, RandomOrder)
{
    Vector<int> v;
    const int data[] = {7, 3, 9, 1, 3, 8, 2};
    const size_t n = sizeof(data) / sizeof(data[0]);
    for (size_t i = 0; i < n; ++i)
        v.push_back(data[i]);

    count(v);

    const int expected[] = {1, 2, 3, 3, 7, 8, 9};
    for (size_t i = 0; i < n; ++i)
        EXPECT_EQ(v[i], expected[i]);
}

TEST(CountSortTest, NegativeNumbers)
{
    Vector<int> v;
    const int data[] = {-2, -5, -1, -3, -4};
    const size_t n = sizeof(data) / sizeof(data[0]);
    for (size_t i = 0; i < n; ++i)
        v.push_back(data[i]);

    count(v);

    const int expected[] = {-5, -4, -3, -2, -1};
    for (size_t i = 0; i < n; ++i)
        EXPECT_EQ(v[i], expected[i]);
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

