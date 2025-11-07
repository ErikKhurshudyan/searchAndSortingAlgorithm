#include <gtest/gtest.h>
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/SingleList.hpp"
#include "headers/function.hpp"
#include <cstdlib>

TEST(VectorSortTest, AlreadySorted)
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    mergeSort(vec);

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

    mergeSort(vec);

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

    mergeSort(vec);

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

    mergeSort(vec);

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

    mergeSort(vec);

    EXPECT_EQ(vec[0], 42);
}



// List tests 
TEST(ListSortTest, AlreadySorted) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);

    mergeSort(list1);

    int expected[] = {1, 2, 3, 4, 5};
    typename List<int>::iterator it = list1.begin();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(*it, expected[i]);
        ++it;
    }
}

TEST(ListSortTest, ReverseOrder) {
    List<int> list1;
    list1.push_back(9);
    list1.push_back(7);
    list1.push_back(5);
    list1.push_back(3);
    list1.push_back(1);

    mergeSort(list1);

    int expected[] = {1, 3, 5, 7, 9};
    typename List<int>::iterator it = list1.begin();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(*it, expected[i]);
        ++it;
    }
}

TEST(ListSortTest, RandomOrder) {
    List<int> list1;
    list1.push_back(8);
    list1.push_back(3);
    list1.push_back(9);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(7);
    list1.push_back(6);

    mergeSort(list1);

    int expected[] = {1, 2, 3, 6, 7, 8, 9};
    typename List<int>::iterator it = list1.begin();
    for (int i = 0; i < 7; ++i) {
        EXPECT_EQ(*it, expected[i]);
        ++it;
    }
}

TEST(ListSortTest, Duplicates) {
    List<int> list1;
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(1);

    mergeSort(list1);

    int expected[] = {1, 2, 2, 4, 4};
    typename List<int>::iterator it = list1.begin();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(*it, expected[i]);
        ++it;
    }
}

TEST(ListSortTest, SingleElement) {
    List<int> list1;
    list1.push_back(42);

    mergeSort(list1);

    typename List<int>::iterator it = list1.begin();
    EXPECT_EQ(*it, 42);
}

TEST(ListSortTest, EmptyList) {
    List<int> list1;

    mergeSort(list1);  // Should not crash

    EXPECT_TRUE(list1.begin() == list1.end());
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

