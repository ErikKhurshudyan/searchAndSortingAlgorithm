#include "headers/functions.hpp"
#include "headers/List.hpp"
#include "headers/SingleList.hpp"
#include "headers/Vector.hpp"
#include "headers/functions.hpp"
#include <gtest/gtest.h>

TEST(Vector, b)
{
    Vector<char> v; 
    v.push_back('a');
    v.push_back('d');
    v.push_back('e');
    v.push_back('r');
    v.push_back('d');
    v.push_back('s');
    v.push_back('g');
    v.push_back('s');
    v.push_back('c');
    v.push_back('a');
    bubbleSort(v);
    std::stringstream ss;
    print(v.begin(), v.end(), ss);
    EXPECT_EQ(ss.str(), "{ a a c d d e g r s s }");
}

TEST(List, b)
{
    Vector<double> s; 
    s.push_back(3);
    s.push_back(2);
    s.push_back(99);
    s.push_back(543);
    s.push_back(31);
    s.push_back(2);
    s.push_back(123);
    s.push_back(967);
    s.push_back(325);
    s.push_back(32151);
    bubbleSort(s);
    std::stringstream ss;
    print(s.begin(), s.end(), ss);
    EXPECT_EQ(ss.str(), "{ 2 2 3 31 99 123 325 543 967 32151 }");
}


TEST(SingleList, b)
{
    SingleList<std::string> s; 
    s.push_front("3");
    s.push_front("2");
    s.push_front("99");
    s.push_front("543");
    s.push_front("31");
    s.push_front("2");
    s.push_front("123");
    s.push_front("967");
    s.push_front("325");
    s.push_front("32151");
    bubbleSort(s);
    std::stringstream ss;
    print(s.begin(), s.end(), ss);
    EXPECT_EQ(ss.str(), "{ 123 2 2 3 31 32151 325 543 967 99 }");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
