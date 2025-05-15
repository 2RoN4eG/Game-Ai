#pragma once

#include "../t_component_defines.hpp"


/**
 * @brief The t_sound_player_interface class
 */
class t_sound_player_interface
{
public:
    virtual ~t_sound_player_interface() = 0;

    virtual void play(const t_identifier_value identifier) = 0;
};
