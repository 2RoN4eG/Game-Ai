#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cmath>


TEST_CASE( "round" )
{
    SECTION( "testing 'long double round(long double)'" )
    {
        struct t_testable {
            long double value {};
            long double expected {};
        };

        std::vector<t_testable> testables {
            { 0.4l, 0.0l },
            { 0.5l, 1.0l },
            { 1.0l, 1.0l },
            { 1.1l, 1.0l },
            { 1.5l, 2.0l }
        };

        for (const t_testable& testable : testables) {
            const long double value = testable.value;
            const long double expected = testable.expected;
            const long double rounded = std::round(value);

            REQUIRE(rounded == expected);
        }
    }

    SECTION( "testing 'double round(double)'" )
    {
        struct t_testable {
            double value {};
            double expected {};
        };

        std::vector<t_testable> testables {
            { 0.4, 0.0 },
            { 0.5, 1.0 },
            { 1.0, 1.0 },
            { 1.1, 1.0 },
            { 1.5, 2.0 }
        };

        for (const t_testable& testable : testables) {
            const double value = testable.value;
            const double expected = testable.expected;
            const double rounded = std::round(value);

            REQUIRE(rounded == expected);
        }
    }

    SECTION( "testing 'float round(float)'" )
    {
        struct t_testable {
            float value {};
            float expected {};
        };

        std::vector<t_testable> testables {
            { 0.4f, 0.0f },
            { 0.5f, 1.0f },
            { 1.0f, 1.0f },
            { 1.1f, 1.0f },
            { 1.5f, 2.0f }
        };

        for (const t_testable& testable : testables) {
            const float value = testable.value;
            const float expected = testable.expected;
            const float rounded = std::round(value);

            REQUIRE(rounded == expected);
        }
    }

    SECTION( "testing 'long double roundl(long double)'" )
    {
        struct t_testable {
            long double value {};
            long double expected {};
        };

        std::vector<t_testable> testables {
            { 0.4l, 0.0l },
            { 0.5l, 1.0l },
            { 1.0l, 1.0l },
            { 1.1l, 1.0l },
            { 1.5l, 2.0l }
        };

        for (const t_testable& testable : testables) {
            const long double value = testable.value;
            const long double expected = testable.expected;
            const long double rounded = std::roundl(value);

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
            { 0.4f, 0.0f },
            { 0.5f, 1.0f },
            { 1.0f, 1.0f },
            { 1.1f, 1.0f },
            { 1.5f, 2.0f }
        };

        for (const t_testable& testable : testables) {
            const float value = testable.value;
            const float expected = testable.expected;
            const float rounded = std::roundf(value);

            REQUIRE(rounded == expected);
        }
    }
}
