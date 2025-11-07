#include <gtest/gtest.h>
#include "headers/function.hpp"
#include <vector>
#include <list>
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

TEST(MergeSortTest, VectorSorted) {
    std::vector<int> vec;
    vec.push_back(1); vec.push_back(2); vec.push_back(3); vec.push_back(4); vec.push_back(5);
    mergeSort(vec.begin(), vec.end());
    EXPECT_TRUE(isSorted(vec));
}

TEST(MergeSortTest, VectorUnsorted) {
    std::vector<int> vec;
    vec.push_back(5); vec.push_back(3); vec.push_back(1); vec.push_back(4); vec.push_back(2);
    mergeSort(vec.begin(), vec.end());

    std::vector<int> expected;
    expected.push_back(1); expected.push_back(2); expected.push_back(3); expected.push_back(4); expected.push_back(5);

    EXPECT_TRUE(vec == expected);
}

TEST(MergeSortTest, VectorDuplicates) {
    std::vector<int> vec;
    vec.push_back(4); vec.push_back(2); vec.push_back(4); vec.push_back(1); vec.push_back(3); vec.push_back(1);
    mergeSort(vec.begin(), vec.end());

    std::vector<int> expected;
    expected.push_back(1); expected.push_back(1); expected.push_back(2); expected.push_back(3); expected.push_back(4); expected.push_back(4);

    EXPECT_TRUE(vec == expected);
}

TEST(MergeSortTest, VectorEmpty) {
    std::vector<int> vec;
    mergeSort(vec.begin(), vec.end());
    EXPECT_TRUE(vec.empty());
}

TEST(MergeSortTest, VectorSingle) {
    std::vector<int> vec;
    vec.push_back(42);
    mergeSort(vec.begin(), vec.end());
    EXPECT_EQ(vec.front(), 42);
}

// ------------------ LIST TESTS ------------------

TEST(MergeSortTest, ListUnsorted) {
    std::list<int> lst;
    lst.push_back(3); lst.push_back(1); lst.push_back(4); lst.push_back(1); lst.push_back(5);
    mergeSort(lst.begin(), lst.end());

    std::list<int> expected;
    expected.push_back(1); expected.push_back(1); expected.push_back(3); expected.push_back(4); expected.push_back(5);

    EXPECT_TRUE(lst == expected);
}

TEST(MergeSortTest, ListEmpty) {
    std::list<int> lst;
    mergeSort(lst.begin(), lst.end());
    EXPECT_TRUE(lst.empty());
}

TEST(MergeSortTest, ListSingle) {
    std::list<int> lst;
    lst.push_back(7);
    mergeSort(lst.begin(), lst.end());
    EXPECT_EQ(lst.front(), 7);
}

TEST(MergeSortTest, ForwardListUnsorted) {
    std::forward_list<int> flst;
    int arr[] = {8,2,5,1,9};
    flst.assign(arr, arr + sizeof(arr)/sizeof(arr[0]));

    // forward_list cannot be sorted by bidirectional mergeSort
    // Workaround: copy to vector, sort, copy back
    std::vector<int> temp(flst.begin(), flst.end());
    mergeSort(temp.begin(), temp.end());

    std::forward_list<int>::iterator it = flst.begin();
    for (size_t i=0; i<temp.size(); ++i, ++it) {
        *it = temp[i];
    }

    // check if sorted
    std::vector<int> check(flst.begin(), flst.end());
    EXPECT_TRUE(std::is_sorted(check.begin(), check.end()));
}

TEST(MergeSortTest, ForwardListEmpty) {
    std::forward_list<int> flst;
    std::vector<int> temp(flst.begin(), flst.end());
    mergeSort(temp.begin(), temp.end());
    // copy back
    std::forward_list<int>::iterator it = flst.begin();
    for (size_t i=0; i<temp.size(); ++i, ++it) *it = temp[i];
    EXPECT_TRUE(flst.begin() == flst.end());
}



int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

