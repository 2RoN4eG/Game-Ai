#ifndef T_ROTATING_TO_COURSE_CACHE_HPP
#define T_ROTATING_TO_COURSE_CACHE_HPP

#include "../t_component_defines.hpp"


/**
 * @brief The t_rotating_to_course_cache class
 */
class t_rotating_to_course_cache
{
public:
    /**
     * @brief _heading - heading value, radians
     */
    t_heading_radians_value _heading {};

    /**
     * @brief _course - course value, radians
     */
    t_course_radians_value _course {};

    /**
     * @brief _heading_speed - heading speed value, radians per second
     */
    t_heading_speed_radians_per_second_value _heading_speed {};
};


void t_set_heading_radians_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_radians_value heading);

void t_set_heading_degrees_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_degrees_value heading);


void t_set_course_radians_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_course_radians_value course);

void t_set_course_degrees_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_course_degrees_value course);


void t_set_heading_speed_radians_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_speed_radians_per_second_value heading_speed);

void t_set_heading_speed_degrees_to_rotating_to_course_cache(t_rotating_to_course_cache& cache, const t_heading_speed_degrees_per_second_value heading_speed);

#endif // T_ROTATING_TO_COURSE_CACHE_HPP
