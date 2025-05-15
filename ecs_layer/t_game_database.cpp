#include "t_game_database.hpp"


t_component_database& create_engine_database(t_component_database& database, t_engine_identifier_maker& identifier_maker)
{
    return database;
}

t_component_database& create_chassis_database(t_component_database& database, t_chassis_identifier_maker& identifier_maker)
{
    return database;
}

t_component_database& create_gun_database(t_component_database& database, t_gun_identifier_maker& identifier_maker)
{
    t_entry_holder<t_gun_component> holder = database.get_component_holder<t_gun_component>();

    holder.create_component(t_go_identifier_value {}, t_elevation_degrees_value {});
    holder.create_component(t_go_identifier_value {}, t_elevation_degrees_value {});
    holder.create_component(t_go_identifier_value {}, t_elevation_degrees_value {});

    return database;
}

t_component_database& create_turret_database(t_component_database& database, t_turret_identifier_maker& identifier_maker)
{
    t_entry_holder<t_turret_component> holder = database.get_component_holder<t_turret_component>();

    holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});
    holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});
    holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});

    return database;
}

t_component_database& create_radio_database(t_component_database& database, t_radio_identifier_maker& identifier_maker)
{
    t_entry_holder<t_radio_component> holder = database.get_component_holder<t_radio_component>();

    holder.create_component(identifier_maker(), t_radio_distance_value { 100 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 200 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 300 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 400 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 500 });

    return database;
}
