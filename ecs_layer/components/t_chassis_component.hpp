#pragma once

#include "t_engine_component.hpp"


struct t_rotatable_heading_cache
{
    // 
    t_identifier_value                    _identifier;

    // Направление (куда смотрит нос)
    t_heading_radians_value                     _heading {};

    // Скорость вращения носа (градус в секунду)
    t_heading_speed_radians_per_second_value    _heading_speed {};
};


class t_chassis_component
{
public:
    static const t_enumerated_component_value t_part { t_enumerated_component_value::t_chassis };

public:
    t_chassis_component(const t_go_identifier_value identifier,
                        const t_weight_value weight,
                        const t_engine_component& engine);

    t_chassis_component(const t_engine_component& engine);


    t_engine_component& get_mutable_engine();

    const t_engine_component& get_engine() const;

    void set_engine(const t_engine_component& engine)
    {
        _engine = engine;
    }


    const t_identifier_value get_identifier() const;

    const t_weight_value get_weight() const;

private:
    const t_identifier_value                    _identifier;

    const t_weight_value                        _weight;

    t_engine_component                          _engine;

    // Направление шасси (куда смотрит шасси)
    t_heading_radians_value                     _heading {};

    // Скорость вращения шасси (градус в секунду)
    t_heading_speed_radians_per_second_value    _heading_speed {};

private:
    friend void t_set_chassis_speed(t_chassis_component& chassis, const t_speed_value speed);
};

inline std::string_view get_component_name(const t_chassis_component&)
{
    return "t_chassis_component";
}

inline t_enumerated_component_value get_enumerated_component_value(const t_chassis_component&)
{
    return t_enumerated_component_value::t_chassis;
}
