#include <gtest/gtest.h>
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/function.hpp"
#include <cstdlib>


template <typename T>
std::vector<T> toStdVector(const SingleList<T>& lst)
{
    std::vector<T> v;
    typename SingleList<T>::const_iterator it = lst.begin();
    for (; it != lst.end(); ++it)
    {
        v.push_back(*it);
    }
    return v;
}

TEST(SingleListSortTest, ReverseOrder)
{
    SingleList<int> lst;
    lst.push_front(1);
    lst.push_front(3);
    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(9);

    mergeSort(lst);

    const int expected[] = {1, 3, 5, 7, 9};
    std::vector<int> actual = toStdVector(lst);

    ASSERT_EQ(actual.size(), 5u);
    for (size_t i = 0; i < actual.size(); ++i)
    {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

template <typename T>
std::vector<T> toStdVector(const List<T>& lst) {
    std::vector<T> v;
    for (typename List<T>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        v.push_back(*it);
    }
    return v;
}

TEST(ListSortTest, ReverseOrder)
{
    List<int> lst;
    lst.push_back(9);
    lst.push_back(7);
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(1);

    mergeSort(lst);

    const int expected[] = {1, 3, 5, 7, 9};
    std::vector<int> actual = toStdVector(lst);
    for (size_t i = 0; i < actual.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

TEST(ListSortTest, RandomOrder)
{
    List<int> lst;
    lst.push_back(8);
    lst.push_back(3);
    lst.push_back(9);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(7);
    lst.push_back(6);

    mergeSort(lst);

    const int expected[] = {1, 2, 3, 6, 7, 8, 9};
    std::vector<int> actual = toStdVector(lst);
    for (size_t i = 0; i < actual.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

TEST(ListSortTest, Duplicates)
{
    List<int> lst;
    lst.push_back(4);
    lst.push_back(2);
    lst.push_back(4);
    lst.push_back(2);
    lst.push_back(1);

    mergeSort(lst);

    const int expected[] = {1, 2, 2, 4, 4};
    std::vector<int> actual = toStdVector(lst);
    for (size_t i = 0; i < actual.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

TEST(ListSortTest, SingleElement)
{
    List<int> lst;
    lst.push_back(42);

    mergeSort(lst);

    std::vector<int> actual = toStdVector(lst);
    ASSERT_EQ(actual.size(), 1);
    EXPECT_EQ(actual[0], 42);
}

TEST(ListSortTest, EmptyList)
{
    List<int> lst;

    mergeSort(lst);

    std::vector<int> actual = toStdVector(lst);
    EXPECT_EQ(actual.size(), 0);
}


TEST(ListSortTest, AlreadySorted)
{
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    mergeSort(lst);

    const int expected[] = {1, 2, 3, 4, 5};
    std::vector<int> actual = toStdVector(lst);
    for (size_t i = 0; i < actual.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}


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

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

