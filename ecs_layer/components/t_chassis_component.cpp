#include "t_chassis_component.hpp"


t_chassis_component::t_chassis_component(const t_go_identifier_value identifier,
                                         const t_weight_value weight,
                                         const t_engine_component& engine)
    : _identifier { identifier }
    , _weight { weight }
    , _engine { engine }
{
}

t_chassis_component::t_chassis_component(const t_engine_component& engine)
    : t_chassis_component { {}, {}, engine }
{
}

const t_identifier_value t_chassis_component::get_identifier() const
{
    return _identifier;
}

t_engine_component& t_chassis_component::get_mutable_engine()
{
    return _engine;
}

const t_engine_component& t_chassis_component::get_engine() const
{
    return _engine;
}

const t_weight_value t_chassis_component::get_weight() const
{
    return _weight + _engine.get_weight();
}


void t_set_chassis_speed(t_chassis_component& chassis, const t_speed_value speed)
{
    t_engine_component& engine = chassis.get_mutable_engine();

    static_assert(std::is_same_v<t_engine_speed_value, t_speed_value>, "t_speed_value has to be the same that t_engine_speed_value");

    t_set_engine_speed(engine, speed);
}
