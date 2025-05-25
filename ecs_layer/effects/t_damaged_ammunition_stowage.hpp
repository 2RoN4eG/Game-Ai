#pragma once

#include "../interfaces/t_effect_interface.hpp"


class t_sound_player_interface;


class t_damaged_ammunition_stowage : public t_effect_interface
{
public:
    t_damaged_ammunition_stowage(t_sound_player_interface& sound_player);
    ~t_damaged_ammunition_stowage() override;

    void apply() override;

    void disapply() override;

private:
    t_sound_player_interface& _sound_player;
};