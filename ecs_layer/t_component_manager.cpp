#include "t_component_manager.hpp"


t_hidden_component_manager::t_hidden_component_manager()
{
}


bool t_hidden_component_manager::register_component(const t_identifier game_object_identifier, t_chassis_component&& component)
{
    _chassis_components.emplace_back(std::move(component));

    return true;
}

bool t_hidden_component_manager::register_component(const t_identifier game_object_identifier, t_vehicle_component&& component)
{
    _vehicle_components.emplace_back(std::move(component));

    return true;
}

bool t_hidden_component_manager::register_component(const t_identifier game_object_identifier, t_turret_component&& component)
{
    _turret_components.emplace_back(std::move(component));

    return true;
}


std::vector<t_chassis_component> t_hidden_component_manager::get_chassis_components() const
{
    return _chassis_components;
}

std::vector<t_vehicle_component> t_hidden_component_manager::get_vehicle_components() const
{
    return _vehicle_components;
}

std::vector<t_turret_component> t_hidden_component_manager::get_turret_components() const
{
    return _turret_components;
}

std::vector<t_rotating_to_course_cache> t_hidden_component_manager::get_rotating_to_course_caches() const
{
    return _rotating_to_course_caches;
}

std::vector<t_rotating_to_course_cache>& t_hidden_component_manager::rotating_to_course_caches()
{
    return _rotating_to_course_caches;
}


t_component_manager::t_component_manager()
{
}
