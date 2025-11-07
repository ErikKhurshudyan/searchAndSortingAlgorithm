#include <gtest/gtest.h>
#include <vector>
#include <list>
#include "headers/function.hpp"

TEST(CountTest, VectorInt) {
    std::vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);

    count(v.begin(), v.end()); 

    EXPECT_EQ(v.size(), 5u); 
}

TEST(CountTest, ListInt) {
    std::list<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(1);
    l.push_back(2);

    count(l.begin(), l.end());

    EXPECT_EQ(l.size(), 4u); 
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

