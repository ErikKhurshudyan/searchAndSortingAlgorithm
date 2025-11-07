#include <gtest/gtest.h>
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/function.hpp"
#include <cstdlib>
#include "headers/SingleList.hpp"

TEST(VectorSortTest, AlreadySorted)
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    selectionSort(vec);

    const int expected[] = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < vec.size(); ++i)
    {
        EXPECT_EQ(vec[i], expected[i]);
    }
}

TEST(VectorSortTest, ReverseOrder)
{
    Vector<int> vec;
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);

    selectionSort(vec);

    const int expected[] = {1, 3, 5, 7, 9};
    for (size_t i = 0; i < vec.size(); ++i)
    {
        EXPECT_EQ(vec[i], expected[i]);
    }
}

TEST(VectorSortTest, RandomOrder)
{
    Vector<int> vec;
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(6);

    selectionSort(vec);

    const int expected[] = {1, 2, 3, 6, 7, 8, 9};
    for (size_t i = 0; i < vec.size(); ++i)
    {
        EXPECT_EQ(vec[i], expected[i]);
    }
}

TEST(VectorSortTest, Duplicates)
{
    Vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(1);

    selectionSort(vec);

    const int expected[] = {1, 2, 2, 4, 4};
    for (size_t i = 0; i < vec.size(); ++i)
    {
        EXPECT_EQ(vec[i], expected[i]);
    }
}

TEST(VectorSortTest, SingleElement)
{
    Vector<int> vec;
    vec.push_back(42);

    selectionSort(vec);

    ASSERT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 42);
}

TEST(ListSortTest, AlreadySorted)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    selectionSort(list);

    int expected[] = {1, 2, 3, 4, 5};
    int i = 0;
    for (List<int>::const_iterator it = list.begin(); it != list.end(); ++it, ++i)
    {
        EXPECT_EQ(*it, expected[i]);
    }
}

TEST(ListSortTest, ReverseSorted)
{
    List<int> list;
    list.push_back(5);
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);

    selectionSort(list);

    int expected[] = {1, 2, 3, 4, 5};
    int i = 0;
    for (List<int>::const_iterator it = list.begin(); it != list.end(); ++it, ++i)
    {
        EXPECT_EQ(*it, expected[i]);
    }
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

