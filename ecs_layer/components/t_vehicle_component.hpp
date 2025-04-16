#ifndef T_VEHICLE_COMPONENT_H
#define T_VEHICLE_COMPONENT_H

#include "t_chassis_component.hpp"
#include "t_turret_component.hpp"


class t_engine_component;
class t_gun_component;


class t_vehicle_component
{
public:
    t_vehicle_component(const t_identifier game_object_identifier,
                        const t_weight_value weight,
                        t_engine_component&& engine);

    const t_identifier get_identifier() const;

    /** Turret part */

    t_turret_component& get_mutable_turret();

    t_gun_component& get_mutable_gun();

    /** Chassis part */

    t_chassis_component& get_mutable_chassis();

    t_engine_component& get_mutable_engine();


    const t_weight_value get_weight() const;

    const t_speed_limit_value get_speed_limit() const;

private:
    const t_identifier      _game_object_identifier;

    t_turret_component      _turret;

    t_gun_component&        _gun;

    t_chassis_component     _chassis;

    t_engine_component&     _engine;

    t_weight_value          _weight;

    t_speed_limit_value     _speed_limit;

};

#endif // T_VEHICLE_COMPONENT_H
