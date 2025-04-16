#include "t_helper.hpp"

#include "components/t_engine_component.hpp"
#include "components/t_gun_component.hpp"


t_vehicle_component create_testable_vehicle()
{
    const t_identifier_value identifier {};

    const t_engine_component engine { identifier, t_engine_power_value { 1000. } };

    const t_chassis_component chassis { identifier, t_weight_value { 40. }, engine };

    const t_gun_component gun { t_elevation_degrees_value {} };

    const t_turret_component turret { t_azimuth_degrees_value {}, gun };

    t_vehicle_component vehicle { identifier, turret, chassis };

    return vehicle;
}
