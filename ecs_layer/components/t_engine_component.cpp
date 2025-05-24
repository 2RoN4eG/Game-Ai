#include "t_engine_component.hpp"

#include <iostream>

constexpr t_floating_value epsilon_value = 1e-10;

constexpr t_engine_speed_value t_speed_epsilon_value = epsilon_value;

constexpr t_engine_power_value t_power_epsilon_value = epsilon_value;


t_engine_component::t_engine_component(const t_identifier_value identifier, const t_engine_power_value power)
    : _identifier { identifier }
    , _power { power }
    , _speed {}
    , _weight {}
{
}


const t_identifier_value t_engine_component::get_identifier() const
{
    return _identifier;
}

const t_engine_power_value t_engine_component::get_power() const
{
    return _power;
}

const t_speed_value t_engine_component::get_speed() const
{
    return _speed;
}

const t_weight_value t_engine_component::get_weight() const
{
    return _weight;
}


void t_set_engine_speed(t_engine_component& engine, const t_engine_speed_value speed)
{
    engine._speed = speed < t_speed_epsilon_value ? 0 : speed;
}

void t_set_engine_power(t_engine_component& engine, const t_engine_power_value power)
{
    engine._power = power < t_power_epsilon_value ? 0 : power;
}

void t_set_engine_weight(t_engine_component& engine, const t_engine_weight_value weight)
{
    engine._weight = weight < epsilon_value ? 0 : weight;
}


const t_engine_speed_value t_get_engine_speed(t_engine_component& engine)
{
    return engine.get_speed();
}

const t_engine_power_value t_get_engine_power(t_engine_component& engine)
{
    return engine.get_power();
}

const t_engine_weight_value t_get_engine_weight(t_engine_component& engine)
{
    return engine.get_weight();
}


bool operator==(const t_engine_component& lhs, const t_engine_component& rhs)
{
    return lhs._speed == rhs._speed && lhs._power == rhs._power;
}
