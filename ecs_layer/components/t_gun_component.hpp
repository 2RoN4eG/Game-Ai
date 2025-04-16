#ifndef T_GUN_COMPONENT_HPP
#define T_GUN_COMPONENT_HPP

#include "../t_component_defines.hpp"


class t_gun_component
{
public:
    t_gun_component(const t_elevation_degrees_value elevation_degrees);

    const t_elevation_radians_value get_elevation() const;

protected:
    t_elevation_radians_value _elevation_radians;
};

#endif // T_GUN_COMPONENT_HPP
