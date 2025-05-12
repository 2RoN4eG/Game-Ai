#ifndef T_VEHICLE_COMPONENT_H
#define T_VEHICLE_COMPONENT_H

#include "t_chassis_component.hpp"
#include "t_turret_component.hpp"
#include "t_radio_component.hpp"
#include "t_visibility_component.hpp"

#include "../tools/t_2d_vector.hpp"


class t_engine_component;
class t_gun_component;

using t_position_component = t_2d_position;


class t_vehicle_component
{
public:
    t_vehicle_component(const t_go_identifier_value identifier, 
                        const t_turret_component& turret,
                        const t_chassis_component& chassis);

    /** turret part */

    t_turret_component& get_mutable_turret();

    t_gun_component& get_mutable_gun();

    /** chassis part */

    t_chassis_component& get_mutable_chassis();

    t_engine_component& get_mutable_engine();

    /** */

    t_radio_component& get_mutable_radio();

    /** */

    t_position_component& get_mutable_position();

    /** */

    const t_identifier_value get_identifier() const;

    const t_weight_value get_weight() const;

    const t_speed_limit_value get_speed_limit() const;

private:
    const t_identifier_value        _identifier {};

    // TODO: Move out to component manager to avoid overheading ...
    t_turret_component              _turret;

    // TODO: Move out to component manager to avoid overheading ...
    t_chassis_component             _chassis;

    t_radio_component               _radio;

    t_weight_value                  _weight {};

    // TODO: Replace me to speed limit range if it necessary ...
    t_speed_limit_value             _speed_limit {};

    t_position_component            _position {};

private:
    friend void t_set_vehicle_speed(t_vehicle_component& vehicle, const t_speed_value speed);

    friend void t_set_vehicle_weight(t_vehicle_component& vehicle, const t_weight_value weight);

    friend void t_set_vehicle_speed_limit(t_vehicle_component& vehicle, const t_vehicle_speed_limit_value speed_limit);

    friend void t_set_vehicle_radio_distance(t_vehicle_component& vehicle, const t_vehicle_radio_distance_value radio_distance);
};

#endif // T_VEHICLE_COMPONENT_H
