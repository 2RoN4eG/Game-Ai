#pragma once

#include "components/t_engine_component.hpp"
#include "components/t_chassis_component.hpp"
#include "components/t_gun_component.hpp"
#include "components/t_turret_component.hpp"
#include "components/t_radio_component.hpp"

#include "t_entry_holder.hpp"


class t_component_database
    : public t_entry_holder<t_engine_component>
    , public t_entry_holder<t_chassis_component>
    , public t_entry_holder<t_gun_component>
    , public t_entry_holder<t_turret_component>
    , public t_entry_holder<t_radio_component>
{
public:
    t_component_database() = default;

    template <typename t_entry>
    t_entry_holder<t_entry>& get_component_holder()
    {
        return *this;
    }
};


t_component_database& create_engine_database(t_component_database& database, t_engine_identifier_maker& identifier_maker);

t_component_database& create_chassis_database(t_component_database& database, t_chassis_identifier_maker& identifier_maker);

t_component_database& create_gun_database(t_component_database& database, t_gun_identifier_maker& identifier_maker);

t_component_database& create_turret_database(t_component_database& database, t_turret_identifier_maker& identifier_maker);

t_component_database& create_radio_database(t_component_database& database, t_radio_identifier_maker& identifier_maker);
