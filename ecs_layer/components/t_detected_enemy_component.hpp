#pragma once

#include "../t_component_defines.hpp"

#include <vector>


// Машина может быть видна в двух случаях:
// - обнаружена самостоятельно
// - получены координаты видимости машины на карте по радио

enum t_detecting_source
{
    self_detected,
    transmited_by_radio,

    received_by_radio = transmited_by_radio,
    by_friendly_radio = received_by_radio,

    by_radio = by_friendly_radio,
    by_self = self_detected
};

using t_visibility_source = t_detecting_source;


// Таблица обнаруженных машин машиной с идентификатором 2

// +--------+-------------------+----------------+-----------+
// | holder | detected (target) |       position | timestamp |
// +--------+-------------------+----------------+-----------+
// |      2 |                 1 | x:   0, y:   0 |       100 |
// +--------+-------------------+----------------+-----------+
// |      3 |                 1 | x:   0, y:   0 |      1100 |
// +--------+-------------------+----------------+-----------+
// |                                                     ... |
// +--------+-------------------+----------------+-----------+

struct t_self_detected_enemy_component
{
};


// Машины 2 (x: 0, y: 300), 3 (x: 300, y: 300), 4 из команды 2, машина 1 из команды 1.
//
// Машина 1 будет видима для машины 3 пока она в зоне видимости машины 2.
// После потери видимости от машины 2 будет видима 5 секунд (последние
// координаты будут доступны).

// Таблица обнаруженных машин машиной с идентификатором 4

// position will be updated and timestamp will be zero in case if detected by sees detected (target).

// +--------+-------------------+-------------+----------------+-----------+
// | holder | detected (target) | detected by |       position | timestamp |
// +--------+-------------------+-------------+----------------+-----------+
// |      4 |                 1 |           2 | x:   0, y:   0 |       100 |
// +--------+-------------------+-------------+----------------+-----------+
// |                                                                   ... |
// +--------+-------------------+-------------+----------------+-----------+

// Record with "detected by 2" used because timestamp for this is minimum (is 100 for vehicle 2 instead of 1100 for vehicle 3).

class t_radio_detected_enemy_component
{
};


class t_detected_enemy_component
{
public:
    // [[maybe_unused]] t_identifier_value _team_identifier {};

    // [[maybe_unused]] t_identifier_value _vehicle_identifier {};

    // Идентификатор машины противника (t_target)
    t_identifier_value _enemy_identifier {};

    // Идентификатор машины обнаружевшей машину противника
    t_identifier_value _detected_by {};

    // Источник обнаружения
    t_detecting_source _detecting_source {};

    t_position_value _position {};

    // t_detecting_timestamp _detected_timestamp {};

    t_detected_enemy_component(t_identifier_value detected_by, t_detecting_source detecting_source, t_identifier_value enemy_identifier) 
        : _detected_by { detected_by }
        , _detecting_source { detecting_source }
        , _enemy_identifier { enemy_identifier }
    {
    }
};


using t_detected_enemy_components = std::vector<t_detected_enemy_component>;


inline std::ostream& operator<<(std::ostream& stream, const t_detected_enemy_component& detected_enemy)
{
    stream << detected_enemy._detecting_source << ", " << detected_enemy._detected_by << ", " << detected_enemy._enemy_identifier << std::endl;

    return stream;
}
