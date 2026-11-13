#include "t_core_defines.hpp"

#include <limits>


t_event_interface::~t_event_interface()
{
}


t_demo_keyboard_event::t_demo_keyboard_event(const t_input_device& input_device, const t_input_device& key)
    : _input_device { input_device }
    , _key { key }
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


t_identifier_value make_component_identifier(const t_enumerated_component_value component_id, const t_identifier_unique_number_value unique_number)
{
    constexpr size_t t_unique_part_size { sizeof(t_identifier_unique_number_value) };

    constexpr size_t t_component_part_size { sizeof(t_enumerated_component_value) };

    constexpr size_t shift_to_bits { (t_unique_part_size - t_component_part_size) * 8 };

    constexpr t_identifier_value unique_number_restrictor { std::numeric_limits<t_identifier_value>::max() >> size_t { t_component_part_size * 8 } };

    return (static_cast<t_identifier_value>(component_id) << shift_to_bits) | (unique_number & unique_number_restrictor);
}
