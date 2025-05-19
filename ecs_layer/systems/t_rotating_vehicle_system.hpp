#ifndef T_ROTATING_VEHICLE_SYSTEM_H
#define T_ROTATING_VEHICLE_SYSTEM_H

#include "../tools/t_2d_vector.hpp"
#include "../interfaces/t_updatable_interface.hpp"

#include "subsystems/t_rotating_vehicle_subsystem.hpp"


/**
 * @brief The t_rotating_vehicle_system class
 */
class t_rotating_vehicle_system : public t_updatable_interface
{
public:
    t_rotating_vehicle_system(const t_input_device& input);

    ~t_rotating_vehicle_system() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

private:
    const t_input_device& _input_device;

    t_chassis_turn_subsystem _turn_left_subsystem;

    t_chassis_turn_subsystem _turn_right_subsystem;
};


using t_chassis_turn_system = t_rotating_vehicle_system;

#endif // T_ROTATING_VEHICLE_SYSTEM_H
