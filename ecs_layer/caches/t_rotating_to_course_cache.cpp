#include "t_rotating_to_course_cache.hpp"

#include "../tools/t_2d_vector.hpp"


void t_set_heading_radians_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_radians_value heading)
{
    cache._heading = heading;
}

void t_set_heading_degrees_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_degrees_value heading)
{
    cache._heading = t_convert_degrees_to_radians(heading);
}


void t_set_course_radians_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_course_radians_value course)
{
    cache._course = course;
}

void t_set_course_degrees_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_course_degrees_value course)
{
    cache._course = t_convert_degrees_to_radians(course);
}


void t_set_heading_speed_radians_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_speed_radians_per_second_value heading_speed)
{
    cache._heading_speed = heading_speed;
}

void t_set_heading_speed_degrees_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_speed_degrees_per_second_value heading_speed)
{
    cache._heading_speed = t_convert_degrees_to_radians(heading_speed);
}
