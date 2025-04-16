#include "t_damaged_ammunition_stowage.hpp"

#include "../interfaces/t_sound_player_interface.hpp"

#include "../t_component_defines.hpp"


t_identifier_value t_damaged_ammunition_stowage_apply_sound_identifier = {};

t_identifier_value t_damaged_ammunition_stowage_disapply_sound_identifier = {};


t_damaged_ammunition_stowage::t_damaged_ammunition_stowage(t_sound_player_interface& sound_player)
    : _sound_player { sound_player } 
{
}

t_damaged_ammunition_stowage::~t_damaged_ammunition_stowage()
{
}

void t_damaged_ammunition_stowage::apply()
{
    _sound_player.play();
}

void t_damaged_ammunition_stowage::disapply()
{
}

const t_timestamp t_damaged_ammunition_stowage::expire_after() const
{
    return t_timestamp { 40 };
}
