#ifndef T_DEFINES_HPP
#define T_DEFINES_HPP

#include <memory>
#include <string>

#include "../ecs_layer/t_component_defines.hpp"


namespace ai
{
    template <typename t_identifier_value>
    class t_ai_identifier_maker : public t_identifier_maker <t_identifier_value>
    {
    public:
        inline const t_identifier_value get_identifier()
        {
            return t_identifier_maker <t_identifier_value>::increase();
        }

        const t_identifier_value operator()()
        {
            return get_identifier();
        }
    };

    using t_node_identifier = std::size_t;

    using t_node_identifier_maker = t_ai_identifier_maker <t_node_identifier>;

    using t_transition_identifier = std::size_t;

    using t_transition_identifier_maker = t_ai_identifier_maker <t_transition_identifier>;

    using t_floating = ::t_floating;

    using t_integer = int;

    using t_delta_time = t_frame_delta_time_value;

    using t_priority = t_floating;

    constexpr t_priority t_default_priority { 1.f };

    using t_description_view = std::string_view;
}

#endif // T_DEFINES_HPP
