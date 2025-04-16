#pragma once

#include "../tools/t_2d_vector.hpp"


/**
 * @brief The t_rotating_heading_to_course_component class
 */
class t_rotating_heading_to_course_component
{
public:
    /**
     * 
     */
    t_go_identifier_value                       _identifier {};

    /**
     * @brief _heading - heading value, radians
     */
    t_heading_radians_value                     _heading {};

    /**
     * @brief _course - course value, radians
     */
    t_course_radians_value                      _course {};

    /**
     * @brief _heading_speed - heading speed value, radians per second
     */
    t_heading_speed_radians_per_second_value    _heading_speed {};
};


void t_set_heading_radians_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_radians_value heading);

void t_set_heading_degrees_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_degrees_value heading);


void t_set_course_radians_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_course_radians_value course);

void t_set_course_degrees_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_course_degrees_value course);


void t_set_heading_speed_radians_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_speed_radians_per_second_value heading_speed);

void t_set_heading_speed_degrees_to_rotating_to_course_cache(t_rotating_heading_to_course_component& cache, const t_heading_speed_degrees_per_second_value heading_speed);
