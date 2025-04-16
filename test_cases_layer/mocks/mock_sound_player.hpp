#pragma once

#include "interfaces/t_sound_player_interface.hpp"

#include <trompeloeil.hpp>


class mock_sound_player : public t_sound_player_interface
{
public:
    ~mock_sound_player() override = default;

    MAKE_CONST_MOCK0(play, void (), override);
};
