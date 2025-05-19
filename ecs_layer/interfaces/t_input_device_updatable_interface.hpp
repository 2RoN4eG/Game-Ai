#ifndef T_INPUT_DEVICE_UPDATABLE_INTERFACE_HPP
#define T_INPUT_DEVICE_UPDATABLE_INTERFACE_HPP

#include "../tools/t_2d_vector.hpp"


/**
 * @brief The t_input_device_updatable_interface class
 */
class t_input_device_updatable_interface
{
public:
    virtual ~t_input_device_updatable_interface() = 0;

    virtual void update(const t_input_device_range_value value,
                        const t_frame_delta_time_value delta_time) = 0;
};

#endif // T_INPUT_DEVICE_UPDATABLE_INTERFACE_HPP
