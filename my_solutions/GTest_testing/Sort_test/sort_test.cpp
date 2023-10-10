#include "gtest/gtest.h"
#include <algorithm>
#include <vector>

TEST(SortTest, TestOnVector321){
    std::vector v = {3, 2, 1};
    std::sort(v.begin(), v.end());
    std::vector expected = {1, 2, 3};

    ASSERT_EQ(v, expected);
}

TEST(SortTest, TestOnVector123){
    std::vector v = {1, 2, 3};
    std::sort(v.begin(), v.end());
    std::vector expected = {1, 2, 3};

    ASSERT_EQ(v, expected);
}