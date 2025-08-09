#pragma once

#include "interfaces/t_sound_player_interface.hpp"

#include <trompeloeil.hpp>


class mock_sound_player : public t_sound_player_interface
{
public:
    ~mock_sound_player() override = default;

    void play(const t_identifier_value identifier) override
    {
    }

    // MAKE_MOCK1(play, void (const t_identifier_value), override);
};
