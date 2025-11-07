#include <gtest/gtest.h>
#include "headers/function.hpp"

TEST(LinearSearchArrayTest, FirstElement)
{
    Vector<int> ob1;
    ob1.push_back(55);
    ob1.push_back(51);
    ob1.push_back(52);
    ob1.push_back(53);
    ob1.push_back(54);
    ob1.push_back(59);
    ob1.push_back(523);
    EXPECT_TRUE(binarySearch(ob1, 53));
}

TEST(List, c)
{
    List<int> s; 
    s.push_front(1);
    s.push_front(4);
    s.push_front(3);
    s.push_front(7);
    s.push_front(9);
    s.push_front(151);
    s.push_front(5);
    s.push_front(3);
    s.push_front(7);
    s.push_front(2);
    EXPECT_TRUE(binarySearch(s, 151));
    EXPECT_FALSE(binarySearch(s, 8));
}

TEST(SingleList, b)
{
    SingleList<int> s; 
    s.push_front(1);
    s.push_front(4);
    s.push_front(3);
    s.push_front(7);
    s.push_front(9);
    s.push_front(151);
    s.push_front(5);
    s.push_front(3);
    s.push_front(7);
    s.push_front(2);
    EXPECT_TRUE(binarySearch(s, 151));
    EXPECT_FALSE(binarySearch(s, 8));
}

TEST(Set, b)
{
    Set<int> s; 
    s.insert(3);
    s.insert(2);
    s.insert(99);
    s.insert(543);
    s.insert(31);
    s.insert(2);
    s.insert(123);
    s.insert(967);
    s.insert(325);
    s.insert(32151);
    EXPECT_TRUE(binarySearch(s, 123));
    EXPECT_FALSE(binarySearch(s,12345));
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

