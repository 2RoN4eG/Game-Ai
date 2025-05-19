#ifndef T_ROTATING_VEHICLE_TO_COURSE_SYSTEM_H
#define T_ROTATING_VEHICLE_TO_COURSE_SYSTEM_H

#include "../tools/t_2d_vector.hpp"
#include "../interfaces/t_updatable_interface.hpp"

#include "../tools/t_2d_vector.hpp"


void update_rotating_to_course(t_heading_radians_value& heading,
                               const t_course_radians_value course,
                               const t_heading_speed_radians_per_second_value heading_speed,
                               const t_frame_delta_time_value delta_time);


/**
 * @brief The t_rotating_vehicle_to_course_system class to provide steps to rotate vehicle to necesesary course.
 */
class t_rotating_vehicle_to_course_system : public t_updatable_interface
{
public:
    t_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                        const t_heading_speed_degrees_per_second_value heading_speed,
                                        const t_course_degrees_value course);

    t_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                        const t_heading_speed_degrees_per_second_value heading_speed,
                                        const t_2d_course& course);

    ~t_rotating_vehicle_to_course_system() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

protected:
    t_heading_radians_value _heading;

    t_heading_speed_radians_per_second_value _heading_speed;

    t_course_radians_value _course;
};


/**
 * @brief The t_extended_rotating_vehicle_to_course_system class to provide extended functionality to test purpose.
 */
class t_extended_rotating_vehicle_to_course_system : public t_rotating_vehicle_to_course_system
{
public:
    t_extended_rotating_vehicle_to_course_system(const t_heading_degrees_value heading_degrees,
                                                 const t_course_degrees_value course_degrees,
                                                 const t_heading_speed_degrees_per_second_value heading_speed_degrees);

    const t_heading_radians_value get_heading_radians() const;

    // TODO: Remove this method and replace to function working with rotating_vehicle_to_course_cache?
    const t_heading_degrees_value get_heading_degrees() const;

    const t_course_radians_value get_course_radians() const;

    const t_heading_speed_radians_per_second_value get_heading_speed() const;
};

#endif // T_ROTATING_VEHICLE_TO_COURSE_SYSTEM_H
