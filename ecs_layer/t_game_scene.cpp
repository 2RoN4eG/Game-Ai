#include "t_game_scene.hpp"

#include "t_game_database.hpp"

#include "components/t_engine_component.hpp"
#include "components/t_chassis_component.hpp"

#include "components/t_vehicle_entity.hpp"


const t_identifier_value get_entity_identifier(const t_vehicle_entity& entity, const t_component_enumenated_value component_part)
{
    struct t_identifier_finder
    {
        const t_identifier_value _identifier {};

        t_identifier_finder(const t_component_enumenated_value component_part)
            : _identifier { make_identifier(component_part, t_unique_identifier_value {}) }
        {
        }

        bool operator()(const t_identifier_value identifier)
        {
            return (_identifier & identifier) == identifier;
        }
    };

    t_vehicle_entity::const_iterator iterator = std::find_if(entity.begin(), entity.end(), t_identifier_finder { component_part });

    if (iterator == entity.end())
    {
        throw std::runtime_error { "component identifier for t_component_enumenated_value does not exist into entity" };
    }

    return *iterator;
}

template<typename t_component>
void copy_component_from_database_to_game_scene(const t_game_database& database, const t_vehicle_entity& entity, t_game_scene& game_scene)
{
    const t_component_enumenated_value component_part { t_component::t_part };

    const t_identifier_value identifier = get_entity_identifier(entity, component_part);

    const t_entry_holder<t_component>& database_entry_holder = database.get_entry_holder<t_component>();

    const t_component& component = database_entry_holder.get_component(identifier);

    t_entry_holder<t_component>& game_scene_entry_holder = game_scene.get_mutable_entry_holder<t_component>();

    game_scene_entry_holder.set_component(component);
}

void make_game_scene_vehicle_entity(t_game_scene& game_scene, const t_game_database& database, const t_vehicle_entity& entity)
{
    copy_component_from_database_to_game_scene<t_engine_component>    (database, entity, game_scene);
    copy_component_from_database_to_game_scene<t_chassis_component>   (database, entity, game_scene);
    copy_component_from_database_to_game_scene<t_gun_component>       (database, entity, game_scene);
    copy_component_from_database_to_game_scene<t_turret_component>    (database, entity, game_scene);
    copy_component_from_database_to_game_scene<t_radio_component>     (database, entity, game_scene);
    copy_component_from_database_to_game_scene<t_visibility_component>(database, entity, game_scene);
}

const t_vehicle_entity create_vehicle_entity(const t_unique_identifier_value unique)
{
    const t_vehicle_entity entity
    {
        make_identifier(t_component_enumenated_value::t_engine,     unique), // engine
        make_identifier(t_component_enumenated_value::t_chassis,    unique), // chassis
        make_identifier(t_component_enumenated_value::t_gun,        unique), // gun
        make_identifier(t_component_enumenated_value::t_turret,     unique), // turret
        make_identifier(t_component_enumenated_value::t_radio,      unique), // radio
        make_identifier(t_component_enumenated_value::t_visibility, unique), // visibility
    };

    return entity;
}

t_vehicle_component& get_game_scene_vehicle(t_game_scene& scene)
{
    const t_go_identifier_value identifier {};

    static t_gun_component gun { identifier, t_elevation_degrees_value {} };

    static t_turret_component turret { identifier, t_azimuth_degrees_value {} };

    static t_engine_component engine { identifier, t_engine_power_value { 1000. } };

    static t_chassis_component chassis { identifier, t_weight_value {}, engine };

    static t_vehicle_component vehicle { identifier, turret, chassis };

    return vehicle;
}


t_game_scene create_vehicles_game_scene(const t_game_database& database, size_t vehicle_amount)
{
    t_game_scene game_scene {};

    for (t_unique_identifier_value unique {}; unique < 2; ++ unique)
    {
        const t_vehicle_entity entity = create_vehicle_entity(unique);

        make_game_scene_vehicle_entity(game_scene, database, entity);
    }

    return game_scene;
}

void create_game_scene_vehicle(t_game_scene& game_scene)
{
    
}