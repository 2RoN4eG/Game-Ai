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

// +--------------------+----------------+--------------------+
// |             source |    detected by |  detected (target) |
// +--------------------+----------------+--------------------+
// |      self_detected |              2 |                  1 |
// +--------------------+----------------+--------------------+
//                                                          ...
// +--------------------+----------------+--------------------+


// Таблица обнаруженных машин машиной с идентификатором 3

// +--------------------+----------------+--------------------+
// |             source |    detected by |  detected (target) |
// +--------------------+----------------+--------------------+
// |           by_radio |              3 |                  1 |
// +--------------------+----------------+--------------------+
//                                                          ...
// +--------------------+----------------+--------------------+


class t_detected_enemy_component
{
public:
    // [[maybe_unused]] t_identifier_value _holder {};

    // Источник обнаружения
    t_detecting_source _detecting_source {};

    // Идентификатор машины обнаружевшей машину противника
    t_identifier_value _detected_by {};

    // Идентификатор машины противника (t_target)
    t_identifier_value _enemy {};
};


using t_detected_enemy_components = std::vector<t_detected_enemy_component>;


inline std::ostream& operator<<(std::ostream& stream, const t_detected_enemy_component& detected_enemy)
{
    stream << detected_enemy._detecting_source << ", " << detected_enemy._detected_by << ", " << detected_enemy._enemy << std::endl;

    return stream;
}
