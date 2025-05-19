#pragma once

#include "../tools/t_2d_vector.hpp"


/**
 * @brief The t_updatable_interface class
 */
class t_updatable_interface
{
public:
    virtual ~t_updatable_interface() = 0;

    virtual void update(const t_frame_delta_time_value delta_time) = 0;
};
