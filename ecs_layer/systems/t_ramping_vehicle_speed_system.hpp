#ifndef T_RAMPING_VEHICLE_SPEED_SYSTEM_H
#define T_RAMPING_VEHICLE_SPEED_SYSTEM_H

#include "../t_component_defines.hpp"
#include "../interfaces/t_updatable_interface.hpp"

#include "subsystems/t_ramping_up_vehicle_speed_subsystem.hpp"
#include "subsystems/t_ramping_down_vehicle_speed_subsystem.hpp"


class t_ramping_vehicle_speed_system : public t_updatable_interface
{
public:
    t_ramping_vehicle_speed_system(const t_moving_forward_event& forward_moving_event,
                                   t_vehicle_component& chassis);

    ~t_ramping_vehicle_speed_system() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

private:
    const t_moving_forward_event& _forward_moving_event;

    const t_range<t_speed_scale_value> _speed_scale_range { 0., 1. };

    t_vehicle_component& _vehicle;

    t_ramping_up_vehicle_speed_subsystem _ramping_up_speed;

    t_ramping_down_vehicle_speed_subsystem _ramping_down_speed;
};

#endif // T_RAMPING_VEHICLE_SPEED_SYSTEM_H
