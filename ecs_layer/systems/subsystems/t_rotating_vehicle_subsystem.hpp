#ifndef T_ROTATING_VEHICLE_SUBSYSTEM_H
#define T_ROTATING_VEHICLE_SUBSYSTEM_H

#include "../../tools/t_2d_vector.hpp"

#include "../../tools/t_2d_vector.hpp"

#include "../../interfaces/t_input_device_updatable_interface.hpp"


/**
 * @brief The t_rotating_chassis_subsystem class
 */
class t_rotating_chassis_subsystem : public t_input_device_updatable_interface
{
public:
    t_rotating_chassis_subsystem(const t_heading_degrees_value heading,
                                 const t_heading_speed_degrees_per_second_value heading_speed);

    ~t_rotating_chassis_subsystem() override = default;

    void update(const t_range_value joystick_value, const t_frame_delta_time_value frame_delta_time) override;

private:
    t_degrees_value _heading;

    const t_heading_speed_degrees_per_second_value _heading_speed;
};


using t_chassis_turn_subsystem = t_rotating_chassis_subsystem;

#endif // T_ROTATING_VEHICLE_SUBSYSTEM_H
