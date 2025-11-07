#include <gtest/gtest.h>
#include "headers/functions.hpp"
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/SingleList.hpp"
#include <algorithm>
#include <forward_list>

template <typename Container>
bool
isSorted(const Container& c)
{
    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator next = it;
    if (it == c.end()) return true;
    ++next;
    for (; next != c.end(); ++it, ++next) {
        if (*it > *next) return false;
    }
    return true;
}

// ------------------ VECTOR TESTS ------------------

TEST(MergeSortTest, VectorSorted)
{
    Vector<int> vec;
    vec.push_back(1); vec.push_back(2); vec.push_back(3); vec.push_back(4); vec.push_back(5);
    quickSort(vec);
    EXPECT_TRUE(isSorted(vec));
}

TEST(MergeSortTest, VectorUnsorted) {
    Vector<int> vec;
    vec.push_back(5); vec.push_back(3); vec.push_back(1); vec.push_back(4); vec.push_back(2);
    quickSort(vec);

    Vector<int> expected;
    expected.push_back(1); expected.push_back(2); expected.push_back(3); expected.push_back(4); expected.push_back(5);

    EXPECT_TRUE(vec == expected);
}

TEST(MergeSortTest, VectorDuplicates) {
    Vector<int> vec;
    vec.push_back(4); vec.push_back(2); vec.push_back(4); vec.push_back(1); vec.push_back(3); vec.push_back(1);
    quickSort(vec);

    Vector<int> expected;
    expected.push_back(1); expected.push_back(1); expected.push_back(2); expected.push_back(3); expected.push_back(4); expected.push_back(4);

    EXPECT_TRUE(vec == expected);
}

TEST(MergeSortTest, VectorEmpty) {
    Vector<int> vec;
    quickSort(vec);
    EXPECT_TRUE(vec.empty());
}

TEST(MergeSortTest, VectorSingle) {
    Vector<int> vec;
    vec.push_back(42);
    quickSort(vec);
    EXPECT_EQ(vec.front(), 42);
}

// ------------------ LIST TESTS ------------------

TEST(MergeSortTest, ListUnsorted)
{
    List<int> lst;
    lst.push_back(3); lst.push_back(1); lst.push_back(4); lst.push_back(1); lst.push_back(5);
    quickSortList(lst);

    List<int> expected;
    expected.push_back(1); expected.push_back(1); expected.push_back(3); expected.push_back(4); expected.push_back(5);

    EXPECT_TRUE(lst == expected);
}

TEST(MergeSortTest, ListEmpty)
{
    List<int> lst;
    quickSortList(lst);
    EXPECT_TRUE(lst.empty());
}

TEST(MergeSortTest, ListSingle)
{
    List<int> lst;
    lst.push_back(7);
    quickSortList(lst);
    EXPECT_EQ(lst.front(), 7);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

