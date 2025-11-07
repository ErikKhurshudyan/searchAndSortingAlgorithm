#include "headers/function.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <list>

TEST(LinearSearchTest, VectorFound)
{
    std::vector<int> v;
    v.push_back(11);
    v.push_back(23);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    insertionSort(v.begin(), v.end());

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

    insertionSort(lst.begin(), lst.end());

    const int expected[] = {1, 2, 3, 4, 5};
    std::list<int>::const_iterator lit = lst.begin();
    const int* eit = expected;

    for (; lit != lst.end(); ++lit, ++eit)
    {
        EXPECT_EQ(*lit, *eit);
    }
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
