#include <catch2/catch_test_macros.hpp>

#include <iostream>

using t_angle_degrees = float;


const t_angle_degrees radial_distance(const t_angle_degrees from, const t_angle_degrees to)
{
    return (from - to);
}


struct t_range
{
    const t_angle_degrees minimum = -180.;

    const t_angle_degrees maximum = +180.;
};


TEST_CASE( "range [-180, +180]", "[angle is -15]" )
{
    const t_angle_degrees minimum { -180. };
    const t_angle_degrees maximum { +180. };

    const t_angle_degrees angle   { - 15. };

    std::cout << "[] " << radial_distance(angle, minimum) << " <> " << radial_distance(maximum, angle) << std::endl;

    const t_angle_degrees rotate_to = std::min(angle - minimum, maximum - angle);
}


struct t_heading_cource
{
    const t_angle_degrees heading {};

    const t_angle_degrees course {};
};


std::ostream& operator<<(std::ostream& stream, const t_heading_cource& holder)
{
    stream << "heading is " << holder.heading << ", course is " << holder.course;

    return stream;
}


TEST_CASE( "angle between course and heading" )
{
    const std::vector<t_heading_cource> heading_cource_container
    {
        { .heading =   90., .course =  180. },
        { .heading = -125., .course = - 15. }
    };

    for (const t_heading_cource& heading_cource : heading_cource_container)
    {
        std::cout << heading_cource 
                  << ", direct radial distance " << radial_distance(heading_cource.heading, heading_cource.course)
                  << ", reverse radial distance " << radial_distance(heading_cource.course, heading_cource.heading)
                  << std::endl;
    }
}
