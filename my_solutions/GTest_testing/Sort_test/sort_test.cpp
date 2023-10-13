#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
#include <functional>

using Data = std::vector<int>;
using SortDataSet = std::tuple<Data, std::function<bool(const int&, const int&)>, Data>;

struct SortOnVector : public testing::TestWithParam<SortDataSet> {};

TEST_P(SortOnVector, GivenAVectorWhenSortIsCalledThenVectorIsSorted) {
    //GIVEN
    auto [v, comp, expected] = GetParam();

    //WHEN
    std::sort(v.begin(), v.end(), comp);

    //THEN
    ASSERT_EQ(v, expected);
}

Data expectedAscending = {1, 2, 3};
Data expectedDescending = {3, 2, 1};

INSTANTIATE_TEST_SUITE_P(ThreeElementsVectorWithLess,
                         SortOnVector,
                         testing::Values(std::make_tuple(Data{1, 2, 3}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{1, 3, 2}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{2, 1, 3}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{2, 3, 1}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{3, 1, 2}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{3, 2, 1}, std::less<int>{}, expectedAscending)));

INSTANTIATE_TEST_SUITE_P(ThreeElementsVectorWithGreater,
                         SortOnVector,
                         testing::Values(std::make_tuple(Data{1, 2, 3}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{1, 3, 2}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{2, 1, 3}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{2, 3, 1}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{3, 1, 2}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{3, 2, 1}, std::greater<int>{}, expectedDescending)));
