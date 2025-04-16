#ifndef T_COMPONENT_MANAGER_HPP
#define T_COMPONENT_MANAGER_HPP

#include "t_component_defines.hpp"
#include "components/t_chassis_component.hpp"
#include "components/t_vehicle_component.hpp"
#include "components/t_turret_component.hpp"

#include "caches/t_rotating_to_course_cache.hpp"

#include <vector>


/**
 * @brief The t_hidden_component_manager class
 */
class t_hidden_component_manager
{
public:
    t_hidden_component_manager();


    bool register_component(const t_identifier game_object_identifier, t_chassis_component&& component);

    bool register_component(const t_identifier game_object_identifier, t_vehicle_component&& component);

    bool register_component(const t_identifier game_object_identifier, t_turret_component&& component);


    std::vector<t_chassis_component> get_chassis_components() const;

    std::vector<t_vehicle_component> get_vehicle_components() const;

    std::vector<t_turret_component> get_turret_components() const;

    std::vector<t_rotating_to_course_cache> get_rotating_to_course_caches() const;


    std::vector<t_rotating_to_course_cache>& rotating_to_course_caches();

protected:
    std::vector<t_chassis_component> _chassis_components;

    std::vector<t_vehicle_component> _vehicle_components;

    std::vector<t_turret_component> _turret_components;

    std::vector<t_rotating_to_course_cache> _rotating_to_course_caches;
};


/**
 * @brief The t_component_manager class
 */
class t_component_manager : public t_hidden_component_manager
{
public:
    t_component_manager();

    template <typename t_component>
    bool register_component(const t_identifier game_object_identifier, t_component&& component)
    {
        return register_component(std::move(component));
    }
};

#endif // T_COMPONENT_MANAGER_HPP
