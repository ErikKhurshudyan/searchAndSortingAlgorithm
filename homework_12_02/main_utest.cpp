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
    radixSort(vec);
    EXPECT_TRUE(isSorted(vec));
}

TEST(MergeSortTest, VectorUnsorted) {
    Vector<int> vec;
    vec.push_back(5); vec.push_back(3); vec.push_back(1); vec.push_back(4); vec.push_back(2);
    radixSort(vec);

    Vector<int> expected;
    expected.push_back(1); expected.push_back(2); expected.push_back(3); expected.push_back(4); expected.push_back(5);

    EXPECT_TRUE(vec == expected);
}

TEST(MergeSortTest, VectorDuplicates) {
    Vector<int> vec;
    vec.push_back(4); vec.push_back(2); vec.push_back(4); vec.push_back(1); vec.push_back(3); vec.push_back(1);
    radixSort(vec);

    Vector<int> expected;
    expected.push_back(1); expected.push_back(1); expected.push_back(2); expected.push_back(3); expected.push_back(4); expected.push_back(4);

    EXPECT_TRUE(vec == expected);
}

TEST(MergeSortTest, VectorEmpty) {
    Vector<int> vec;
    radixSort(vec);
    EXPECT_TRUE(vec.empty());
}

TEST(MergeSortTest, VectorSingle) {
    Vector<int> vec;
    vec.push_back(42);
    radixSort(vec);
    EXPECT_EQ(vec.front(), 42);
}

// ------------------ LIST TESTS ------------------

TEST(MergeSortTest, ListUnsorted)
{
    List<int> lst;
    lst.push_back(3); lst.push_back(1); lst.push_back(4); lst.push_back(1); lst.push_back(5);
    radixSortList(lst);

    List<int> expected;
    expected.push_back(1); expected.push_back(1); expected.push_back(3); expected.push_back(4); expected.push_back(5);
    std::cout << lst << std::endl;
    EXPECT_TRUE(lst == expected);
}

TEST(MergeSortTest, ListEmpty)
{
    List<int> lst;
    radixSortList(lst);
    EXPECT_TRUE(lst.empty());
}

TEST(MergeSortTest, ListSingle)
{
    List<int> lst;
    lst.push_back(7);
    radixSortList(lst);
    EXPECT_EQ(lst.front(), 7);
}

// ------------------ SINGLELIST TESTS ------------------

TEST(RadixSortTest, SingleListUnsorted)
{
    SingleList<int> lst;
    lst.push_front(5);
    lst.push_front(1);
    lst.push_front(7);
    lst.push_front(3);
    lst.push_front(9);
    // հիմա ցուցակը հակառակ հերթականությամբ է → 9, 3, 7, 1, 5

    radixSortSingleList(lst);

    SingleList<int> expected;
    expected.push_front(9);
    expected.push_front(7);
    expected.push_front(5);
    expected.push_front(3);
    expected.push_front(1);
    // այսպես՝ 1, 3, 5, 7, 9

    EXPECT_TRUE(lst == expected);
}

TEST(RadixSortTest, SingleListSorted)
{
    SingleList<int> lst;
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);
    // ցուցակը այժմ՝ 1,2,3,4

    radixSortSingleList(lst);

    SingleList<int> expected;
    expected.push_front(4);
    expected.push_front(3);
    expected.push_front(2);
    expected.push_front(1);

    EXPECT_TRUE(lst == expected);
}

TEST(RadixSortTest, SingleListWithDuplicates)
{
    SingleList<int> lst;
    lst.push_front(3);
    lst.push_front(1);
    lst.push_front(5);
    lst.push_front(2);
    lst.push_front(5);
    // ցուցակը այժմ՝ 5,2,5,1,3

    radixSortSingleList(lst);

    SingleList<int> expected;
    expected.push_front(5);
    expected.push_front(5);
    expected.push_front(3);
    expected.push_front(2);
    expected.push_front(1);
    // այսպես՝ 1,2,3,5,5

    EXPECT_TRUE(lst == expected);
}

TEST(RadixSortTest, SingleListEmpty)
{
    SingleList<int> lst;
    radixSortSingleList(lst);
    EXPECT_TRUE(lst.empty());
}

TEST(RadixSortTest, SingleListSingle)
{
    SingleList<int> lst;
    lst.push_front(42);
    radixSortSingleList(lst);
    EXPECT_EQ(lst.front(), 42);
}

TEST(RadixSortTest, SingleListAllZeros)
{
    SingleList<int> lst;
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    radixSortSingleList(lst);

    SingleList<int> expected;
    expected.push_front(0);
    expected.push_front(0);
    expected.push_front(0);

    EXPECT_TRUE(lst == expected);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

