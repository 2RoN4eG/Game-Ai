#include "t_game_database.hpp"


t_component_database& create_engine_database(t_component_database& database, t_identifier_creator<t_identifier_value>& identifier_creator)
{
    return database;
}

t_component_database& create_chassis_database(t_component_database& database, t_identifier_creator<t_identifier_value>& identifier_creator)
{
    return database;
}

t_component_database& create_gun_database(t_component_database& database, t_identifier_creator<t_identifier_value>& identifier_creator)
{
    t_component_holder<t_gun_component> holder = database.get_component_holder<t_gun_component>();

    holder.create_component(t_go_identifier_value {}, t_elevation_degrees_value {});
    holder.create_component(t_go_identifier_value {}, t_elevation_degrees_value {});
    holder.create_component(t_go_identifier_value {}, t_elevation_degrees_value {});

    return database;
}

t_component_database& create_turret_database(t_component_database& database, t_identifier_creator<t_identifier_value>& identifier_creator)
{
    t_component_holder<t_turret_component> holder = database.get_component_holder<t_turret_component>();

    holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});
    holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});
    holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});

    return database;
}

t_component_database& create_radio_database(t_component_database& database, t_identifier_creator<t_identifier_value>& identifier_creator)
{
    return database;
}
