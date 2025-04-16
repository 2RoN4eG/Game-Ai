#include "t_vehicle_component.hpp"

#include "t_engine_component.hpp"

namespace
{
    t_speed_value make_speed_limit(const t_engine_power_value engine_power, const t_vehicle_weight_value weight)
    {
        return engine_power / (weight / 4.);
    }
}


t_vehicle_component::t_vehicle_component(const t_identifier game_object_identifier,
                                         const t_weight_value weight,
                                         t_engine_component&& engine)
    : _game_object_identifier { game_object_identifier }
    , _turret { {}, {} }
    , _gun { _turret.get_mutable_gun() }
    , _chassis { std::move(engine) }
    , _engine { _chassis.get_mutable_engine() }
    , _weight { weight }
    , _speed_limit { make_speed_limit(_engine.get_power(), _weight) }
{
}

const t_identifier t_vehicle_component::get_identifier() const
{
    return _game_object_identifier;
}

t_turret_component& t_vehicle_component::get_mutable_turret()
{
    return _turret;
}

t_gun_component& t_vehicle_component::get_mutable_gun()
{
    return _gun;
}

t_chassis_component& t_vehicle_component::get_mutable_chassis()
{
    return _chassis;
}

t_engine_component& t_vehicle_component::get_mutable_engine()
{
    return _engine;
}

const t_weight_value t_vehicle_component::get_weight() const
{
    return _weight;
}

const t_speed_limit_value t_vehicle_component::get_speed_limit() const
{
    return _speed_limit;
}
