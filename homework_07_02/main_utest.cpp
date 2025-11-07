#include "headers/function.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <set>

TEST(LinearSearchTest, VectorFound)
{
    std::vector<int> v;
    v.push_back(11);
    v.push_back(23);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    selectionSort(v.begin(), v.end());

    const int expected[] = {3, 4, 5, 11, 23};
    const size_t size = sizeof(expected) / sizeof(expected[0]);

    std::vector<int>::const_iterator vit = v.begin();
    const int* eit = expected;

    for (; vit != v.end() && (eit - expected) < static_cast<int>(size); ++vit, ++eit)
    {
        EXPECT_EQ(*vit, *eit);
    }
    EXPECT_EQ(v.size(), size);
}

TEST(ListSortTest, AlreadySorted)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    selectionSort(lst.begin(), lst.end());

    const int expected[] = {1, 2, 3, 4, 5};
    std::list<int>::const_iterator lit = lst.begin();
    const int* eit = expected;

    for (; lit != lst.end(); ++lit, ++eit)
    {
        EXPECT_EQ(*lit, *eit);
    }
}


/*
TEST(LinearSearchTest, VectorNotFound)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::vector<int>::iterator it = binarySearch(v.begin(), v.end(), 10);
    EXPECT_EQ(it, v.end());
}

TEST(LinearSearchTest, ListFound)
{
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    std::list<int>::iterator it = binarySearch(l.begin(), l.end(), 20);
    EXPECT_NE(it, l.end());
    EXPECT_EQ(*it, 20);
}

TEST(LinearSearchTest, ListNotFound)
{
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    std::list<int>::iterator it = binarySearch(l.begin(), l.end(), 40);
    EXPECT_EQ(it, l.end());
}

TEST(LinearSearchTest, SetFound)
{
    std::set<int> s;
    s.insert(7);
    s.insert(14);
    s.insert(21);
    std::set<int>::iterator it = binarySearch(s.begin(), s.end(), 14);
    EXPECT_NE(it, s.end());
    EXPECT_EQ(*it, 14);
}

TEST(LinearSearchTest, SetNotFound)
{
    std::set<int> s;
    s.insert(7);
    s.insert(14);
    s.insert(21);
    std::set<int>::iterator it = binarySearch(s.begin(), s.end(), 99);
    EXPECT_EQ(it, s.end());
}
*/
int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


