#pragma once

#include "../t_component_defines.hpp"


// Двигатель является контейнером и упрощен до двух переменных,
// и не содержит ограничетелей по скорости.

class t_engine_component
{
public:
    t_engine_component(const t_identifier_value identifier, const t_engine_power_value power = 1000.);
    ~t_engine_component() = default;


    const t_identifier_value get_identifier() const;

    const t_engine_power_value get_power() const;

    const t_speed_value get_speed() const;

    const t_weight_value get_weight() const;

protected:
    const t_identifier_value    _identifier {};

    //
    t_engine_power_value        _power {};

    // По большому счету, данную переменную можно вынести в класс шасси, так
    // как для расчетов скорости, двигатель как контейнер не очень подходит,
    // в силу отсутсвия коробки передач.
    t_speed_value               _speed {};

    //
    t_weight_value              _weight {};

private:
    friend void t_set_engine_speed(t_engine_component& engine, const t_engine_speed_value speed);

    friend void t_set_engine_power(t_engine_component& engine, const t_engine_power_value power);

    friend void t_set_engine_weight(t_engine_component& engine, const t_engine_weight_value weight);

    friend bool operator==(const t_engine_component& lhs, const t_engine_component& rhs);
};
