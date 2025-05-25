#include "t_game_database.hpp"


size_t create_engine_database(t_game_database& database, t_engine_identifier_maker& identifier_maker)
{
    t_entry_holder<t_engine_component>& holder = database.get_mutable_entry_holder<t_engine_component>();

    return holder.amount();
}

size_t create_chassis_database(t_game_database& database, t_chassis_identifier_maker& identifier_maker)
{
    t_entry_holder<t_chassis_component>& holder = database.get_mutable_entry_holder<t_chassis_component>();

    return holder.amount();
}

size_t create_gun_database(t_game_database& database, t_gun_identifier_maker& identifier_maker)
{
    t_entry_holder<t_gun_component>& gun_holder = database.get_mutable_entry_holder<t_gun_component>();

    gun_holder.create_component(identifier_maker(), t_elevation_degrees_value {});
    gun_holder.create_component(identifier_maker(), t_elevation_degrees_value {});
    gun_holder.create_component(identifier_maker(), t_elevation_degrees_value {});

    return gun_holder.amount();
}

size_t create_turret_database(t_game_database& database, t_turret_identifier_maker& identifier_maker)
{
    t_entry_holder<t_turret_component>& turret_holder = database.get_mutable_entry_holder<t_turret_component>();

    turret_holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});
    turret_holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});
    turret_holder.create_component(t_azimuth_degrees_value {}, t_elevation_degrees_value {});

    return turret_holder.amount();
}

size_t create_radio_database(t_game_database& database, t_radio_identifier_maker& identifier_maker)
{
    t_entry_holder<t_radio_component>& holder = database.get_mutable_entry_holder<t_radio_component>();

    holder.create_component(identifier_maker(), t_radio_distance_value { 100 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 200 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 300 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 400 });
    holder.create_component(identifier_maker(), t_radio_distance_value { 500 });

    return holder.amount();
}


size_t create_game_database(t_game_database& database)
{
    size_t record_amount {};


    t_engine_identifier_maker engine_identifier_maker {};

    record_amount += create_engine_database(database, engine_identifier_maker);


    t_chassis_identifier_maker chassis_identifier_maker {};

    record_amount += create_chassis_database(database, chassis_identifier_maker);


    t_gun_identifier_maker gun_identifier_maker {};

    record_amount += create_gun_database(database, gun_identifier_maker);


    t_turret_identifier_maker turret_identifier_maker {};

    record_amount += create_turret_database(database, turret_identifier_maker);


    t_radio_identifier_maker radio_identifier_maker {};

    record_amount += create_radio_database(database, radio_identifier_maker);


    return record_amount;
}
