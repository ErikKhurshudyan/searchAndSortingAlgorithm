#include <gtest/gtest.h>
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/SingleList.hpp"
#include "headers/Set.hpp"
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
    EXPECT_TRUE(linearSearch(ob1, 53));
}

TEST(LinearSearchListTest, FirstElement)
{
    List<int> ob1;
    ob1.push_back(55);
    ob1.push_back(51);
    ob1.push_back(52);
    ob1.push_back(53);
    ob1.push_back(54);
    ob1.push_back(59);
    ob1.push_back(523);
    EXPECT_TRUE(linearSearch(ob1, 53));
}

TEST(LinearSearchSingleListTest, FirstElement)
{
    SingleList<int> ob1;
    ob1.push_front(55);
    ob1.push_front(51);
    ob1.push_front(52);
    ob1.push_front(53);
    ob1.push_front(54);
    ob1.push_front(59);
    ob1.push_front(523);
    EXPECT_TRUE(linearSearch(ob1, 53));
}


TEST(LinearSetListTest, FirstElement)
{
    Set<int> ob1;
    ob1.insert(55);
    ob1.insert(51);
    ob1.insert(52);
    ob1.insert(53);
    ob1.insert(54);
    ob1.insert(59);
    ob1.insert(523);
    EXPECT_TRUE(linearSearch(ob1, 53));
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

