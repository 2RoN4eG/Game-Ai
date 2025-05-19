#include "t_detecting_enemy_system.hpp"

#include "../components/t_vehicle_component.hpp"

#include "../t_game_scene.hpp"

#include <ranges>


namespace
{
    struct t_select_by_visibility_distance
    {
        const t_vehicle_position_value _position {};

        const t_vehicle_visibility_distance_value _visibility {};

        const bool operator()(const t_vehicle_component& vehicle) const
        {
            const t_vehicle_position_value position = t_get_vehicle_position(vehicle);

            const t_distance_value distance = t_get_distance(_position, position);

            return _visibility >= distance;
        }
    };

    struct t_convert_to
    {
        const t_identifier_value _identifier {};

        t_detected_component operator()(const t_vehicle_component& vehicle) const
        {
            const t_identifier_value identifier = t_get_vehicle_identifier(vehicle);

            return t_detected_component { t_visibility_source::self_detected, _identifier, identifier };
        }
    };
}

t_detecting_enemy_system::t_detecting_enemy_system(t_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

t_detecting_enemy_system::~t_detecting_enemy_system()
{
}

void t_detecting_enemy_system::update(const t_frame_delta_time_value delta_time)
{
    const t_entry_holder<t_vehicle_component>& entry_holder = _game_scene.get_entry_holder<t_vehicle_component>();

    for (const t_vehicle_component& vehicle : entry_holder)
    {
        const t_identifier_value identifier { t_get_vehicle_identifier(vehicle) };

        const t_vehicle_position_value position { t_get_vehicle_position(vehicle) };

        const t_vehicle_visibility_distance_value visibility { t_get_vehicle_visibility_distance(vehicle) };

        auto visible_vehicles = entry_holder
            | std::views::filter(t_select_by_visibility_distance { position, visibility })
            ;

        std::vector<t_detected_component> detected_vehicles {};

        std::transform(visible_vehicles.begin(), visible_vehicles.end(), std::back_inserter(detected_vehicles), t_convert_to { identifier });

        std::cout << "vehicle { identifier: " << identifier << " } detected " << detected_vehicles.size() << " vehicles" << std::endl;
    }
}