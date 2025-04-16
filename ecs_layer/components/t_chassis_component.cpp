#include "t_chassis_component.hpp"



t_chassis_component::t_chassis_component(const t_identifier game_object_identifier,
                                         const t_weight_value weight,
                                         t_engine_component&& engine)
    : _game_object_identifier { game_object_identifier }
    , _weight { weight }
    , _engine { std::move(engine) }
{
}

t_chassis_component::t_chassis_component(t_engine_component&& engine)
    : t_chassis_component { {}, {}, std::move(engine) }
{
}

const t_identifier t_chassis_component::get_identifier() const
{
    return _game_object_identifier;
}

t_engine_component& t_chassis_component::get_mutable_engine()
{
    return _engine;
}
