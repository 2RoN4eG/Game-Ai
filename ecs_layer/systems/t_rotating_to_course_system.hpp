#pragma once

#include "../t_component_defines.hpp"
#include "../interfaces/t_updatable_interface.hpp"

#include "../caches/t_rotating_heading_to_course_cache.hpp"

#include <vector>


/**
 * @brief The t_rotating_to_course_system class
 */
class t_rotating_to_course_system : public t_updatable_interface
{
public:
    t_rotating_to_course_system();
    ~t_rotating_to_course_system() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

private:
    std::vector<t_rotating_heading_to_course_cache> _rotating_to_course_caches;
};
