#pragma once

#include <algorithm>


template <typename t_value>
class t_range;

class t_event;

class t_demo_keyboard_event;

template <typename t_identifier_value>
class t_identifier_creator;

class t_go_identifier_value_creator;


using t_floating                                = float;

using t_double                                  = double;

using t_1d_position_value                       = t_floating;

using t_delta_position_component                = t_floating;

using t_across_component                        = t_delta_position_component;

using t_speed_value                             = t_floating;

using t_power_value                             = t_floating;

using t_weight_value                            = t_floating;

using t_engine_speed_value                      = t_speed_value;

using t_engine_power_value                      = t_power_value;

using t_engine_weight_value                     = t_weight_value;

using t_vehicle_speed_value                     = t_speed_value;

using t_speed_limit_value                       = t_speed_value;

using t_vehicle_speed_limit_value               = t_speed_limit_value;

using t_delta_speed_value                       = t_speed_value;

using t_speed_scale_value                       = t_speed_value;

using t_frame_delta_time_value                  = t_floating;

using t_range_value                             = t_floating;

using t_input_device                            = int;

using t_moving_forward_event                    = t_demo_keyboard_event;

using t_turn_left_event                         = t_demo_keyboard_event;

using t_turn_right_event                        = t_demo_keyboard_event;

using t_chassis_weight_value                    = t_weight_value;

using t_vehicle_weight_value                    = t_weight_value;

using t_identifier_value                        = std::size_t;

using t_game_object_identifier_value            = t_identifier_value;

using t_go_identifier_value                     = t_game_object_identifier_value;

using t_degrees_value                           = t_floating;

using t_radians_value                           = t_floating;

using t_angle_degrees_value                     = t_degrees_value;

using t_angle_radians_value                     = t_radians_value;

using t_course_degrees_value                    = t_degrees_value;

using t_course_radians_value                    = t_radians_value;

using t_angular_speed_degrees_per_second_value  = t_degrees_value;

using t_angular_speed_radians_per_second_value  = t_radians_value;

using t_heading_degrees_value                   = t_degrees_value;

using t_heading_radians_value                   = t_radians_value;

using t_heading_speed_degrees_per_second_value  = t_degrees_value;

using t_heading_speed_radians_per_second_value  = t_radians_value;

using t_azimuth_degrees_value                   = t_degrees_value;

using t_azimuth_radians_value                   = t_radians_value;

using t_elevation_degrees_value                 = t_degrees_value;

using t_elevation_radians_value                 = t_radians_value;

using t_input_device_range_value                = t_floating;

using t_distance_value                          = t_floating;

using t_radio_distance_value                    = t_distance_value;

using t_visibility_distance_value               = t_distance_value;

using t_vehicle_radio_distance_value            = t_radio_distance_value;


template <typename t_value>
class t_range
{
public:
    t_range(t_value minimum, t_value maximum)
        : _minimum { minimum }
        , _maximum { maximum }
    {
    }

    const t_value restrict(const t_value value) const
    {
        const t_value temporary = std::max(_minimum, value);

        return std::min(temporary, _maximum);
    }

    const bool is_in_range(const t_value value) const
    {
        return _minimum <= value && value <= _maximum;
    }

    const bool is_minimum(const t_value value) const
    {
        return std::abs(_minimum - value) < std::numeric_limits<t_value>::epsilon();
    }

    const bool is_maximum(const t_value value) const
    {
        return std::abs(_maximum - value) < std::numeric_limits<t_value>::epsilon();
    }

    const t_value get_minimum() const
    {
        return _minimum;
    }

    const t_value get_maximum() const
    {
        return _maximum;
    }

private:
    t_value _minimum;

    t_value _maximum;
};

class t_event
{
public:
    virtual ~t_event() = 0;

    virtual bool operator()() const = 0;
};

class t_demo_keyboard_event : public t_event
{
public:
    t_demo_keyboard_event(const t_input_device& input_device, const t_input_device& key);
    ~t_demo_keyboard_event() = default;

    t_range_value get_deviation_value() const;

    bool is_pressed() const;

    bool is_released() const;

    bool operator()() const;

private:
    const t_input_device& _input_device;

    const t_input_device _key;
};

template <typename t_identifier_value>
class t_identifier_creator
{
public:
    t_identifier_creator(t_identifier_value identifier = {})
        : _identifier { identifier }
    {
    }

protected:
    inline const t_identifier_value increase()
    {
        return (++ _identifier);
    }

    inline const t_identifier_value decrease()
    {
        return (-- _identifier);
    }

private:
    t_identifier_value _identifier {};
};

class t_go_identifier_value_creator : public t_identifier_creator <t_go_identifier_value>
{
public:
    const t_go_identifier_value get_identifier()
    {
        return increase();
    }

    const t_go_identifier_value operator()()
    {
        return get_identifier();
    }
};
