#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <vector>
#include <algorithm>

SCENARIO("Testing STL function - std::sort()")
{
    GIVEN("Checking with unsorted std::vector<int>")
    {
        auto vec = GENERATE(std::vector{1, 2, 4, 3, 10, 5, 7},
                            std::vector{2, 1, 4, 3, 10, 5, 7},
                            std::vector{3, 2, 4, 5, 10, 1, 7},
                            std::vector{5, 2, 4, 3, 10, 7, 1},
                            std::vector{7, 5, 10, 3, 4, 2, 1});

        WHEN("Launching std::sort() for:" << vec[0]<<vec[1]<<vec[2]<<vec[3]<<vec[4]<<vec[5]<<vec[6])
        {
            std::sort(vec.begin(), vec.end());

            THEN("Comparing sorted vector with expected value")
            {
                std::vector<int> vec_expected = {1, 2, 3, 4, 5, 7, 10};
                //REQUIRE(vec == vec_expected);
                REQUIRE_THAT(vec, Catch::Matchers::Equals(vec_expected));
            }
        }
    }
}


