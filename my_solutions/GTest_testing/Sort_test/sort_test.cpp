#include "gtest/gtest.h"
#include <algorithm>
#include <vector>

struct SortOnVector : public testing::TestWithParam<std::vector<int>> {
    std::vector<int> expected = {1, 2, 3};

    void setDataForGreaterComp(){
        expected = {3, 2, 1};
    }
};

TEST_P(SortOnVector, GivenAVectorWhenSortIsCalledThenVectorIsSorted) {
    //GIVEN
    auto v = GetParam();

    //WHEN
    std::sort(v.begin(), v.end());

    //THEN
    ASSERT_EQ(v, expected);
}

TEST_P(SortOnVector, GivenAVectorWhenSortIsCalledWithGreaterThenComparatorThenVectorIsSortedDescending) {
    //GIVEN
    auto v = GetParam();
    setDataForGreaterComp();

    //WHEN
    std::sort(v.begin(), v.end(), std::greater<int>{});

    //THEN
    ASSERT_EQ(v, expected);
}

INSTANTIATE_TEST_SUITE_P(ThreeElementsVector,
                         SortOnVector,
                         testing::Values(std::vector<int>{1, 2, 3},
                                         std::vector<int>{1, 3, 2},
                                         std::vector<int>{2, 1, 3},
                                         std::vector<int>{2, 3, 1},
                                         std::vector<int>{3, 1, 2},
                                         std::vector<int>{3, 2, 1}));



// TEST(SortTest, TestOnVector321){
//     std::vector v = {3, 2, 1};
//     std::sort(v.begin(), v.end());
//     std::vector expected = {1, 2, 3};

//     ASSERT_EQ(v, expected);
// }

// TEST(SortTest, TestOnVector123){
//     std::vector v = {1, 2, 3};
//     std::sort(v.begin(), v.end());
//     std::vector expected = {1, 2, 3};

//     ASSERT_EQ(v, expected);
// }