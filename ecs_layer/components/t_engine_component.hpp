#ifndef T_ENGINE_COMPONENT_H
#define T_ENGINE_COMPONENT_H

#include "../t_component_defines.hpp"


// Двигатель является контейнером и упрощен до двух переменных,
// и не содержит ограничетелей по скорости.

class t_engine_component
{
public:
    t_engine_component(const t_engine_power_value power = 1000.);
    ~t_engine_component() = default;

    const t_engine_power_value get_power() const;

    const t_speed_value get_speed() const;

protected:
    const t_engine_power_value _power { 1000. };

    // По большому счету, данную переменную можно вынести в класс шасси, так
    // как для расчетов скорости, двигатель как контейнер не очень подходит,
    // в силу отсутсвия коробки передач.
    t_speed_value _speed {};

private:
    friend void t_set_engine_speed(t_engine_component& engine, const t_speed_value speed);

    friend void t_set_engine_power(t_engine_component& engine, const t_engine_power_value power);
};


void t_set_engine_speed(const t_speed_value speed, t_engine_component& engine);

#endif // T_ENGINE_COMPONENT_H
