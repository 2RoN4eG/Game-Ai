#include "t_game_scene.hpp"

#include "t_game_database.hpp"

#include "components/t_engine_component.hpp"
#include "components/t_chassis_component.hpp"

#include "components/t_vehicle_entity.hpp"


template<typename t_component>
t_component get_database_component(const t_game_database& database, const t_vehicle_entity& entity, const t_vehicle_part vehicle_part)
{
    struct t_identifier_finder
    {
        const t_identifier_value component_identifier {};

        t_identifier_finder(const t_vehicle_part vehicle_part)
            : component_identifier { make_identifier_value(vehicle_part, t_unique_part {}) }
        {
        }

        const bool operator()(const t_identifier_value identifier)
        {
            return (component_identifier & identifier) == identifier;
        }
    };

    t_vehicle_entity::const_iterator iterator = std::find_if(entity.begin(), entity.end(), t_identifier_finder { vehicle_part });

    if (iterator == entity.end())
    {
        throw std::runtime_error { "component identifier for t_vehicle_part does not exist into entity" };
    }

    const t_entry_holder<t_component>& entry_holder = database.get_entry_holder<t_component>();

    const t_identifier_value identifier { *iterator };

    return entry_holder.get_component(identifier);
}

void make_game_scene_vehicle_entity(const t_vehicle_entity& entity, const t_game_database& database, t_game_scene& game_scene)
{
    t_engine_component engine = get_database_component<t_engine_component>(database, entity, t_vehicle_part::t_engine);

    // t_chassis_component chassis = get_component<t_chassis_component>(database, entity, t_vehicle_part::t_chassis);

    // t_gun_component gun = get_component<t_gun_component>(database, entity, t_vehicle_part::t_gun);

    // t_gun_component gun = get_component<t_gun_component>(database, entity, t_vehicle_part::t_gun);
}

const t_vehicle_entity make_vehicle_entity(const t_unique_part unique)
{
    const t_vehicle_entity vehicle
    {
        make_identifier_value(t_vehicle_part::t_engine,     unique), // engine
        make_identifier_value(t_vehicle_part::t_chassis,    unique), // chassis
        make_identifier_value(t_vehicle_part::t_gun,        unique), // gun
        make_identifier_value(t_vehicle_part::t_turret,     unique), // turret
        make_identifier_value(t_vehicle_part::t_radio,      unique), // radio
        make_identifier_value(t_vehicle_part::t_visibility, unique), // visibility
    };

    return vehicle;
}


t_game_scene create_2_vehicles_game_scene(const t_game_database& database)
{
    t_game_scene game_scene {};

    for (t_unique_part unique {}; unique < 2; ++ unique)
    {
        const t_vehicle_entity vehicle = make_vehicle_entity(unique);

        // making vehicle entity from database to game scene

        make_game_scene_vehicle_entity(vehicle, database, game_scene);
    }
}
