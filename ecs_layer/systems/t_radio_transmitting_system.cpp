#include "t_radio_transmitting_system.hpp"

#include "../components/t_vehicle_component.hpp"

#include "../t_game_scene.hpp"


t_vehicle_component& get_game_scene_vehicle(t_game_scene& scene)
{
    const t_go_identifier_value identifier {};

    const t_elevation_degrees_value gun_elevation {};

    static t_gun_component gun { identifier, gun_elevation };

    const t_azimuth_degrees_value turret_azimuth {};

    static t_turret_component turret { identifier, turret_azimuth };

    static t_engine_component engine { identifier, t_engine_power_value { 1000. } };

    static t_chassis_component chassis { identifier, t_weight_value {}, engine };

    static t_vehicle_component vehicle { identifier, turret, chassis };

    return vehicle;
}


namespace
{
    using t_identifier_values = std::vector<t_identifier_value>;

    using t_vehicle_identifier_value = t_go_identifier_value;

    using t_self_detected_enemy_records = std::vector<t_detected_target_record>;

    const t_vehicle_team_value get_vehicle_team(const t_vehicle_component& vehicle)
    {
        return t_vehicle_team_value {};
    }

    const t_vehicle_identifier_value get_vehicle_identifier(const t_vehicle_component& vehicle)
    {
        return t_vehicle_identifier_value {};
    }

    const t_vehicle_position_value get_vehicle_position(const t_vehicle_component& vehicle)
    {
        return {};
    }

    t_identifier_values get_in_radio_area_team_vehicle_identifiers(const t_vehicle_team_value vehicle_team,
                                                                   const t_vehicle_position_value& vehicle_position,
                                                                   const t_vehicle_radio_distance vehicle_radio_distance)
    {
        return {};
    }

    t_self_detected_enemy_records get_self_detected_vehicles(const t_game_scene& game_scene,
                                                             const t_vehicle_identifier_value self_identifier)
    {
        const t_entry_holder<t_detected_target_record>& holder = game_scene.get_entry_holder<t_detected_target_record>();

        struct t_self_detected_predicate
        {
            t_identifier_value _detected_by {};

            bool operator()(const t_detected_target_record& record) const
            {
                return record._source == t_detecting_source::self_detected && record._detected_by = _detected_by;
            }
        };

        return holder.select(t_self_detected_predicate { self_identifier });
    }

    void set_radio_detected_enemies(const t_game_scene& game_scene,
                                    const t_vehicle_team_value vehicle_team,
                                    const t_vehicle_identifier_value self_vehicle_identifier,
                                    const t_self_detected_enemy_records& self_detected_enemies)
    {
    }
}


t_radio_transmitting_system::t_radio_transmitting_system()
{
}

t_radio_transmitting_system::~t_radio_transmitting_system()
{
}

void t_radio_transmitting_system::update(const t_frame_delta_time_value delta_time)
{
    const t_entry_holder<t_vehicle_component>& entry_holder = _game_scene.get_entry_holder<t_vehicle_component>();

    for (const t_vehicle_component& vehicle : entry_holder)
    {
        std::cout << "processing vehicle ..." << std::endl;

        const t_vehicle_identifier_value self_vehicle_identifier = get_vehicle_identifier(vehicle);

        std::cout << "vehicle identifier " << self_vehicle_identifier << std::endl;

        const t_vehicle_team_value vehicle_team = get_vehicle_team(vehicle);

        std::cout << "vehicle team " << vehicle_team << std::endl;

        const t_vehicle_position_value vehicle_position = get_vehicle_position(vehicle);

        std::cout << "vehicle team " << vehicle_team << std::endl;

        const t_vehicle_radio_distance_value vehicle_radio_distance = t_get_vehicle_radio_distance(vehicle);

        std::cout << "vehicle radio distance " << vehicle_radio_distance << std::endl;


        // 1. Для машины с identifier { number } определяем массив машин в радиусе (области видимости) радиостанции.

        const t_identifier_values team_vehicle_identifiers = get_in_radio_area_team_vehicle_identifiers(vehicle_team, vehicle_position, vehicle_radio_distance);


        // 2. Каждой дружественной машине передаем список идентификаторов обнаруженных (видимых) машин.

        const t_self_detected_enemy_records& self_detected_enemies = get_self_detected_vehicles(_game_scene, self_vehicle_identifier);


        set_radio_detected_enemies(_game_scene, vehicle_team, self_vehicle_identifier, self_detected_enemies);

        std::cout << std::endl;
    }
}
