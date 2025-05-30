#ifndef T_RAMPING_UP_VEHICLE_SPEED_SUBSYSTEM_H
#define T_RAMPING_UP_VEHICLE_SPEED_SUBSYSTEM_H

#include "../../tools/t_2d_vector.hpp"

#include "../../interfaces/t_updatable_interface.hpp"


class t_engine_component;
class t_chassis_component;
class t_vehicle_component;


class t_ramping_up_vehicle_speed_subsystem : public t_updatable_interface
{
public:
    t_ramping_up_vehicle_speed_subsystem(t_vehicle_component& vehicle,
                                         const t_range<t_speed_scale_value>& speed_scale_range);

    ~t_ramping_up_vehicle_speed_subsystem() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

private:
    t_engine_component& _engine;

    const t_speed_limit_value _speed_limit;

    const t_range<t_speed_scale_value>& _speed_scale_range;
};


const t_frame_delta_time_value t_get_rumping_up_time();

#endif // T_RAMPING_UP_VEHICLE_SPEED_SUBSYSTEM_H
