#ifndef T_ROTATING_TO_COURSE_SYSTEM_HPP
#define T_ROTATING_TO_COURSE_SYSTEM_HPP

#include "../t_component_defines.hpp"
#include "../interfaces/t_updatable_interface.hpp"

#include "../caches/t_rotating_to_course_cache.hpp"


class t_hidden_component_manager;


/**
 * @brief The t_rotating_to_course_system class
 */
class t_rotating_to_course_system : public t_updatable_interface
{
public:
    t_rotating_to_course_system(t_hidden_component_manager& component_manager);

    ~t_rotating_to_course_system() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

private:
    std::vector<t_rotating_to_course_cache>& _rotating_to_course_caches;
};

#endif // T_ROTATING_TO_COURSE_SYSTEM_HPP
