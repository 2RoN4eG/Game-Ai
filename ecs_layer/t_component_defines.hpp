#pragma once

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>


using t_floating_value                          = float;

using t_double_value                            = double;

using t_1d_position_value                       = t_floating_value;

using t_delta_position_component                = t_floating_value;

using t_across_component                        = t_delta_position_component;


using t_speed_value                             = t_floating_value;

using t_speed_limit_value                       = t_floating_value;


using t_power_value                             = t_floating_value;

using t_weight_value                            = t_floating_value;


using t_engine_speed_value                      = t_speed_value;

using t_engine_power_value                      = t_power_value;

using t_engine_weight_value                     = t_weight_value;


using t_vehicle_speed_value                     = t_speed_value;

using t_vehicle_speed_limit_value               = t_speed_limit_value;



using t_delta_speed_value                       = t_speed_value;

using t_speed_scale_value                       = t_speed_value;


using t_frame_delta_time_value                  = t_floating_value;

using t_range_value                             = t_floating_value;

using t_input_device                            = int;

class t_demo_keyboard_event;

using t_moving_forward_event                    = t_demo_keyboard_event;

using t_turn_left_event                         = t_demo_keyboard_event;

using t_turn_right_event                        = t_demo_keyboard_event;

using t_chassis_weight_value                    = t_weight_value;

using t_vehicle_weight_value                    = t_weight_value;

using t_identifier_value                        = std::size_t;

using t_game_object_identifier_value            = t_identifier_value;

using t_go_identifier_value                     = t_game_object_identifier_value;

using t_sound_identifier_value                  = t_game_object_identifier_value;

using t_degrees_value                           = t_floating_value;

using t_radians_value                           = t_floating_value;

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

using t_input_device_range_value                = t_floating_value;

using t_unsigned_short = unsigned short;


enum t_component_enumenated_value : t_unsigned_short
{
    t_undefined = 0,

    t_engine    = 1,
    t_chassis,

    t_gun,
    t_turret,

    t_radio,
    t_visibility,

    t_vehicle
};


using t_unique_identifier_value = t_identifier_value;


// game object part { engine, chassis, sound, effect } | countable part (index part)
t_identifier_value make_identifier(t_component_enumenated_value vehicle_part, const t_unique_identifier_value unique_part);


template <typename t_value>
class t_range
{
public:
    t_range(const t_value minimum, const t_value maximum)
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
    const t_value _minimum;

    const t_value _maximum;
};


class t_event_interface
{
public:
    virtual ~t_event_interface() = 0;

    virtual bool operator()() const = 0;
};


class t_demo_keyboard_event : public t_event_interface
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


template <typename t_identifier>
class t_identifier_maker
{
public:
    t_identifier_maker(t_identifier identifier = {})
        : _identifier { identifier }
    {
    }

protected:
    inline const t_identifier increase()
    {
        return (++ _identifier);
    }

    inline const t_identifier decrease()
    {
        return (-- _identifier);
    }

    inline const t_identifier get_identifier() const
    {
        return _identifier;
    }

private:
    t_identifier _identifier {};
};

template <typename t_identifier, t_component_enumenated_value vehicle_part>
class t_component_identifier_maker : public t_identifier_maker<t_identifier>
{
public:
    t_component_identifier_maker()
        : t_identifier_maker<t_identifier>(make_identifier(vehicle_part, t_unique_identifier_value {}))
    {
        const t_identifier_value identifier = t_identifier_maker<t_identifier>::get_identifier();

        std::cout << "t_component_identifier_maker starts with " << std::setw(16) << std::hex << identifier << std::dec << " identifier" << std::endl;
    }

    inline const t_identifier operator()()
    {
        return t_identifier_maker<t_identifier>::increase();
    }
};


using t_undefined_identifier_maker  = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_undefined>;

using t_engine_identifier_maker     = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_engine>;

using t_chassis_identifier_maker    = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_chassis>;

using t_gun_identifier_maker        = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_gun>;

using t_turret_identifier_maker     = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_turret>;

using t_radio_identifier_maker      = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_radio>;

using t_visibility_identifier_maker = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_visibility>;

using t_vehicle_identifier_maker    = t_component_identifier_maker<t_go_identifier_value, t_component_enumenated_value::t_vehicle>;


using t_integer_value               = int;


using t_acceleration_value          = t_floating_value;

using t_time_floating_value         = t_floating_value;

using t_time_value                  = t_integer_value;

using t_time_second_value           = t_time_value;

using t_delta_time_floating_value   = t_floating_value;

using t_frame_per_second_value      = t_time_second_value;


using t_team_value                  = t_integer_value;

using t_health_points_value         = t_integer_value;
