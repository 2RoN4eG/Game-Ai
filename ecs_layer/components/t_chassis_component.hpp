#ifndef T_CHASSIS_COMPONENT_H
#define T_CHASSIS_COMPONENT_H

#include "t_engine_component.hpp"


struct t_rotatable_heading_cache
{
    // Направление (куда смотрит)
    t_heading_radians_value                     _heading {};

    // Скорость вращения (градус в секунду)
    t_heading_speed_radians_per_second_value    _heading_speed {};
};


class t_vehicle_component;


class t_chassis_component
{
public:
    t_chassis_component(const t_identifier game_object_identifier,
                        const t_weight_value weight,
                        t_engine_component&& engine);

    t_chassis_component(t_engine_component&& engine);

    const t_identifier get_identifier() const;

    t_engine_component& get_mutable_engine();

private:
    const t_identifier                          _game_object_identifier;

    t_weight_value                              _weight;

    t_engine_component                          _engine;

    // Направление шасси (куда смотрит шасси)
    t_heading_radians_value                     _heading;

    // Скорость вращения шасси (градус в секунду)
    t_heading_speed_radians_per_second_value    _heading_speed;
};

#endif // T_CHASSIS_COMPONENT_H
