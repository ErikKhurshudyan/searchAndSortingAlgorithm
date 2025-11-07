#include "headers/List.hpp"
#include "headers/Set.hpp"
#include "headers/Vector.hpp"
#include "headers/SingleList.hpp"
#include "headers/function.hpp"
#include <gtest/gtest.h>

TEST(Vector, b)
{
    Vector<char> s; 
    s.push_back('a');
    s.push_back('a');
    s.push_back('c');
    s.push_back('d');
    s.push_back('d');
    s.push_back('e');
    s.push_back('g');
    s.push_back('r');
    s.push_back('s');
    s.push_back('s');
    EXPECT_TRUE(binarySearch(s ,'a'));
    EXPECT_FALSE(binarySearch(s, 'x'));
}

TEST(List, b)
{
    List<double> s; 
    s.push_back(2);
    s.push_back(2);
    s.push_back(3);
    s.push_back(31);
    s.push_back(99);
    s.push_back(123);
    s.push_back(325);
    s.push_back(543);
    s.push_back(967);
    s.push_back(32151);
    EXPECT_TRUE(binarySearch(s, 325.0));
    EXPECT_FALSE(binarySearch(s ,12345.0));
}

TEST(SingleList, b)
{
    SingleList<int> s; 
    s.push_front(123);
    s.push_front(2);
    s.push_front(2);
    s.push_front(3);
    s.push_front(31);
    s.push_front(32151);
    s.push_front(325);
    s.push_front(543);
    s.push_front(967);
    s.push_front(99);
    EXPECT_TRUE(binarySearch(s, 123));
    EXPECT_FALSE(binarySearch(s, 12345));
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
