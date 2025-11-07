#include "gtest/gtest.h"
#include "headers/function.hpp"
#include <vector>
#include <list>

TEST(ShellSortTest, VectorInt)
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);

    shellSort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(ShellSortTest, ListInt)
{
    std::list<int> l;
    l.push_back(10);
    l.push_back(7);
    l.push_back(2);
    l.push_back(9);
    l.push_back(5);

    shellSort(l.begin(), l.end());
    EXPECT_TRUE(std::is_sorted(l.begin(), l.end()));
}

TEST(ShellSortTest, EmptyContainer)
{
    std::vector<int> v;
    shellSort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(ShellSortTest, SingleElement)
{
    std::vector<int> v;
    v.push_back(42);
    shellSort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(ShellSortTest, AlreadySorted)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    shellSort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}


int 
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


