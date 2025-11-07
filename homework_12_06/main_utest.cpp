#include "gtest/gtest.h"
#include "headers/function.hpp"
#include <vector>
#include <list>
#include <string>

TEST(QuickSortTest, SortIntegersVector)
{
    std::vector<int> data;
    data.push_back(5);
    data.push_back(3);
    data.push_back(8);
    data.push_back(1);
    data.push_back(4);

    quickSort(data.begin(), data.end());

    std::vector<int> expected;
    expected.push_back(1);
    expected.push_back(3);
    expected.push_back(4);
    expected.push_back(5);
    expected.push_back(8);

    EXPECT_EQ(data, expected);
}

TEST(QuickSortTest, SortStrings)
{
    std::vector<std::string> words;
    words.push_back("pear");
    words.push_back("apple");
    words.push_back("banana");

    quickSort(words.begin(), words.end());

    std::vector<std::string> expected;
    expected.push_back("apple");
    expected.push_back("banana");
    expected.push_back("pear");

    EXPECT_EQ(words, expected);
}

TEST(QuickSortTest, EmptyContainer)
{
    std::vector<int> empty;
    quickSort(empty.begin(), empty.end());
    EXPECT_TRUE(empty.empty());
}

TEST(QuickSortTest, AlreadySorted)
{
    std::vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);

    quickSort(data.begin(), data.end());

    std::vector<int> expected(data);
    EXPECT_EQ(data, expected);
}

TEST(QuickSortTest, SortList)
{
    std::list<int> data;
    data.push_back(10);
    data.push_back(5);
    data.push_back(15);
    data.push_back(0);

    quickSort(data.begin(), data.end());

    std::list<int> expected;
    expected.push_back(0);
    expected.push_back(5);
    expected.push_back(10);
    expected.push_back(15);

    EXPECT_TRUE(std::equal(data.begin(), data.end(), expected.begin()));
}

int 
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


