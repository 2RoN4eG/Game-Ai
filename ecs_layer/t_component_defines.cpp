#include "t_component_defines.hpp"


t_event::~t_event()
{
}


t_demo_keyboard_event::t_demo_keyboard_event(const t_input_device& input_device, const t_input_device& key)
    : _input_device { input_device }
    , _key { key }
{
}

t_demo_keyboard_event::~t_demo_keyboard_event()
{
}

t_range_value t_demo_keyboard_event::get_deviation_value() const
{
    return 1.;
}

bool t_demo_keyboard_event::is_pressed() const
{
    return _input_device & _key;
}

bool t_demo_keyboard_event::is_released() const
{
    return (_input_device & _key) == 0;
}

bool t_demo_keyboard_event::operator()() const
{
    return is_pressed();
}
