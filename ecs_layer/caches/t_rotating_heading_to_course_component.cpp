#include "t_rotating_heading_to_course_component.hpp"

#include "../tools/t_2d_vector.hpp"


void t_set_heading_radians_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_radians_value heading)
{
    cache._heading = heading;
}

void t_set_heading_degrees_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_degrees_value heading)
{
    t_set_heading_radians_to_rotating_to_course_cache(cache, t_convert_degrees_to_radians(heading));
}


void t_set_course_radians_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_course_radians_value course)
{
    cache._course = course;
}

void t_set_course_degrees_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_course_degrees_value course)
{
    t_set_course_radians_to_rotating_to_course_cache(cache, t_convert_degrees_to_radians(course));
}


void t_set_heading_speed_radians_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_speed_radians_per_second_value heading_speed)
{
    cache._heading_speed = heading_speed;
}

void t_set_heading_speed_degrees_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_speed_degrees_per_second_value heading_speed)
{
    t_set_heading_speed_radians_to_rotating_to_course_cache(cache, t_convert_degrees_to_radians(heading_speed));
}
