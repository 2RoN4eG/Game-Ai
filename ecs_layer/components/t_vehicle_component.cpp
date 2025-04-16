#include "t_vehicle_component.hpp"

#include "t_engine_component.hpp"

namespace
{
    const t_engine_component& get_engine_component(const t_chassis_component& chassis)
    {
        return chassis.get_engine();
    }

    const t_speed_value make_speed_limit(const t_engine_power_value engine_power, const t_vehicle_weight_value weight)
    {
        return engine_power / (weight / 4.);
    }

    const t_speed_value make_speed_limit(const t_chassis_component chassis, const t_vehicle_weight_value weight)
    {
        const t_engine_component& engine = get_engine_component(chassis);

        return make_speed_limit(engine.get_power(), weight);
    }
}


t_vehicle_component::t_vehicle_component(const t_go_identifier_value identifier)
    : t_vehicle_component { identifier,
                            t_turret_component {
                                t_azimuth_degrees_value {},
                                t_gun_component {
                                    identifier,
                                    t_elevation_degrees_value {}
                                }
                            },
                            t_chassis_component {
                                identifier,
                                t_weight_value {},
                                t_engine_component {
                                    identifier
                                } 
                            }
                        }
{
}

t_vehicle_component::t_vehicle_component(const t_go_identifier_value identifier,
                                         const t_turret_component& turret,
                                         const t_chassis_component& chassis)
    : _identifier { identifier }
    , _turret { turret }
    , _chassis { chassis }
    , _visibility { identifier, t_visibility_distance_value {} }
    , _weight { _chassis.get_weight() + _turret.get_weight() }
    , _speed_limit { make_speed_limit(_chassis, _weight) }
{
}


t_turret_component& t_vehicle_component::get_mutable_turret()
{
    return _turret;
}

t_gun_component& t_vehicle_component::get_mutable_gun()
{
    t_gun_component& gun = _turret.get_mutable_gun();

    return gun;
}

t_chassis_component& t_vehicle_component::get_mutable_chassis()
{
    return _chassis;
}

t_engine_component& t_vehicle_component::get_mutable_engine()
{
    t_engine_component& engine = _chassis.get_mutable_engine();

    return engine;
}

t_radio_component& t_vehicle_component::get_mutable_radio()
{
    return _radio;
}

t_visibility_component& t_vehicle_component::get_mutable_visibility()
{
    return _visibility;
}

t_2d_position_value& t_vehicle_component::get_mutable_position()
{
    return _position;
}


const t_identifier_value t_vehicle_component::get_identifier() const
{
    return _identifier;
}

const t_team_value t_vehicle_component::get_team() const
{
    return _team;
}

const t_weight_value t_vehicle_component::get_weight() const
{
    // TODO: Replace to accumulator of turret weight, chassis weight and radio weight

    return _weight;
}

const t_speed_limit_value t_vehicle_component::get_speed_limit() const
{
    return _speed_limit;
}

const t_health_points_value t_vehicle_component::get_health_points() const
{
    return _health_points;
}


void t_set_vehicle_speed(t_vehicle_component& vehicle, const t_speed_value speed)
{
    t_chassis_component& chassis = vehicle.get_mutable_chassis();

    t_set_chassis_speed(chassis, speed);
}

void t_set_vehicle_speed_limit(t_vehicle_component& vehicle, const t_vehicle_speed_limit_value speed_limit)
{
    vehicle._speed_limit = speed_limit;
}

void t_set_vehicle_radio_distance(t_vehicle_component& vehicle, const t_vehicle_radio_distance_value radio_distance)
{
    t_radio_component& radio = vehicle.get_mutable_radio();

    t_set_radio_distance(radio, radio_distance);
}

void t_set_vehicle_visibility_distance(t_vehicle_component& vehicle, const t_vehicle_visibility_distance_value visibility_distance)
{
    t_visibility_component& visibility = vehicle.get_mutable_visibility();

    t_set_visibility_distance(visibility, visibility_distance);
}

void t_set_vehicle_position(t_vehicle_component& vehicle, const t_position_value position)
{
    vehicle._position = position;
}

void t_set_vehicle_team(t_vehicle_component& vehicle, const t_team_value team)
{
    vehicle._team = team;
}


const t_position_value t_get_vehicle_position(const t_vehicle_component& vehicle)
{
    return vehicle._position;
}

const t_visibility_distance_value t_get_vehicle_visibility_distance(const t_vehicle_component& vehicle)
{
    const t_visibility_component& visibility = vehicle._visibility;

    return visibility.get_distance();
}

const t_radio_distance_value t_get_vehicle_radio_distance(const t_vehicle_component& vehicle)
{
    const t_radio_component& radio = vehicle._radio;

    return radio.get_distance();
}

const t_identifier_value t_get_vehicle_identifier(const t_vehicle_component& vehicle)
{
    const t_identifier_value identifier = vehicle.get_identifier();

    return identifier;
}

const t_team_value t_get_vehicle_team(const t_vehicle_component& vehicle)
{
    return vehicle._team;
}
