#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>


TEST_CASE( "round" )
{
    SECTION( "testing 'double round(double)'" )
    {
        struct t_testable {
            double value {};
            double expected {};
        };

        std::vector<t_testable> testables {
            { 0.49, 0.0 },
            { 0.5, 1.0 },
            { 1.0, 1.0 },
            { 1.1, 1.0 }
        };

        for (const t_testable& testable : testables) {
            const double value = testable.value;
            const double rounded = round(value);
            const double expected = testable.expected;

            REQUIRE(rounded == expected);
        }
    }

    SECTION( "testing 'float roundf(float)'" )
    {
        struct t_testable {
            float value {};
            float expected {};
        };

        std::vector<t_testable> testables {
            { 0.49, 0.0 },
            { 0.5, 1.0 },
            { 1.0, 1.0 },
            { 1.1, 1.0 }
        };

        for (const t_testable& testable : testables) {
            const float value = testable.value;
            const float rounded = roundf(value);
            const float expected = testable.expected;

            REQUIRE(rounded == expected);
        }
    }
}
