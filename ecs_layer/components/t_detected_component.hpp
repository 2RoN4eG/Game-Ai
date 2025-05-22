#pragma once

#include "../t_component_defines.hpp"


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


class t_detected_component
{
public:
    // Источник обнаружения
    t_visibility_source _source {};

    // Идентификатор машины обнаружевшей машину противника
    t_identifier_value _detected_by {};

    // Идентификатор машины противника
    t_identifier_value _target {};
};


using t_detected_components = std::vector<t_detected_component>;
