#pragma once

#include "components/t_engine_component.hpp"
#include "components/t_chassis_component.hpp"
#include "components/t_gun_component.hpp"
#include "components/t_turret_component.hpp"
#include "components/t_radio_component.hpp"

#include "t_component_holder.hpp"


class t_component_database
    : public t_component_holder<t_engine_component>
    , public t_component_holder<t_chassis_component>
    , public t_component_holder<t_gun_component>
    , public t_component_holder<t_turret_component>
    , public t_component_holder<t_radio_component>
{
public:
    t_component_database() = default;

    template <typename t_component> t_component_holder<t_component>& get_component_holder() { return *this; }
};
