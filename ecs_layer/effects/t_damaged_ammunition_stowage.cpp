#include "t_damaged_ammunition_stowage.hpp"

#include "../interfaces/t_sound_player_interface.hpp"

#include "../tools/t_2d_vector.hpp"


t_identifier_value t_damaged_ammunition_stowage_apply_sound_identifier = {};

t_identifier_value t_damaged_ammunition_stowage_disapply_sound_identifier = {};


t_damaged_ammunition_stowage::t_damaged_ammunition_stowage(t_sound_player_interface& sound_player)
    : t_effect_interface { t_timestamp { 40 } }
    , _sound_player { sound_player } 
{
}

t_damaged_ammunition_stowage::~t_damaged_ammunition_stowage()
{
}

void t_damaged_ammunition_stowage::apply()
{
    _sound_player.play(t_damaged_ammunition_stowage_disapply_sound_identifier);
}

void t_damaged_ammunition_stowage::disapply()
{
    _sound_player.play(t_damaged_ammunition_stowage_apply_sound_identifier);
}
