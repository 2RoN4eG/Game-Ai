#ifndef T_CHASSIS_ROTATION_H
#define T_CHASSIS_ROTATION_H

#include "t_component_defines.hpp"


/**
 * @brief The t_chassis_rotation class
 */
class t_chassis_rotation
{
public:
    t_chassis_rotation(const t_angle_degrees_value heading_angle_in_degrees,
                       const t_floating direction_sign,
                       const t_angle_degrees_value course_angle_in_degrees);

    void set_direction_sign(const t_floating direction_sign);

    void set_heading_angle_in_degrees(const t_angle_degrees_value heading_angle_in_degrees);

    void set_course_angle_in_degrees(const t_angle_degrees_value course_angle_in_degrees);

private:
    t_floating _direction;

    t_degrees_value _heading_degrees;

    t_degrees_value _course_degrees;
};

#endif // T_CHASSIS_ROTATION_H
