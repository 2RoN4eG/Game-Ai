#include "t_self_detecting_enemy_system.hpp"

#include "../components/t_vehicle_component.hpp"

#include "../t_game_scene.hpp"

#include <ranges>


namespace
{
    struct t_by_visibility_distance_selector
    {
        const t_team_value _team {};

        const t_vehicle_position_value _position {};

        const t_vehicle_visibility_distance_value _visibility {};

        bool operator()(const t_vehicle_component& vehicle) const
        {
            const t_team_value team = t_get_vehicle_team(vehicle);

            if (_team == team)
            {
                return false;
            }

            const t_vehicle_position_value position = t_get_vehicle_position(vehicle);

            const t_distance_value distance = t_get_distance(_position, position);

            return _visibility >= distance;
        }
    };

    struct t_to_detected_converter
    {
        const t_identifier_value _identifier {};

        t_detected_enemy_component operator()(const t_vehicle_component& vehicle) const
        {
            const t_identifier_value enemy_identifier = t_get_vehicle_identifier(vehicle);

            return t_detected_enemy_component { _identifier, t_visibility_source::self_detected, enemy_identifier };
        }
    };

    using t_detected_vehicle_components = std::vector<t_detected_enemy_component>;

    void print_detected_vehicles(const t_detected_vehicle_components& detected_vehicles)
    {
    }
}

t_self_detecting_enemy_system::t_self_detecting_enemy_system(t_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

t_self_detecting_enemy_system::~t_self_detecting_enemy_system()
{
}

void t_self_detecting_enemy_system::update(const t_frame_delta_time_value delta_time)
{
    // getting team holder for vehicles on the map

    // getting

    const t_entry_holder<t_vehicle_component>& vehicle_entry_holder = _game_scene.get_entry_holder<t_vehicle_component>();

    // Каждый vehicle смотрит на дистацию видиомости, что бы сформировать массив машин которые видны

    for (const t_vehicle_component& vehicle : vehicle_entry_holder)
    {
        const t_identifier_value identifier { t_get_vehicle_identifier(vehicle) };

        const t_team_value team { t_get_vehicle_team(vehicle) };

        const t_vehicle_position_value position { t_get_vehicle_position(vehicle) };

        const t_vehicle_visibility_distance_value visibility { t_get_vehicle_visibility_distance(vehicle) };

        auto visible_vehicles = vehicle_entry_holder
                              | std::views::filter(t_by_visibility_distance_selector { team, position, visibility })
                              ;

        std::vector<t_detected_enemy_component> detected_vehicles {};

        std::transform(visible_vehicles.begin(), visible_vehicles.end(), std::back_inserter(detected_vehicles), t_to_detected_converter { identifier });

        std::cout << "vehicle { identifier: " << identifier << ", position { x: " << std::setw(4) << position.x() << ", y: " << std::setw(4) << position.y() << ", visibility distance: " << visibility << " }" << " } detected " << detected_vehicles.size() << " vehicles" << std::endl;

        t_entry_holder<t_detected_enemy_component>& detected_entry_holder = _game_scene.get_mutable_entry_holder<t_detected_enemy_component>();

        detected_entry_holder.set_components(detected_vehicles);
    }

    std::cout << std::endl;
}