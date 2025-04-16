#ifndef T_DEFINES_HPP
#define T_DEFINES_HPP

#include <memory>
#include <string>

#include "../ecs_layer/t_component_defines.hpp"


namespace ai
{
    using t_node_identifier = std::size_t;

    using t_transition_identifier = std::size_t;

    template <typename t_identifier>
    class t_identifier_creator
    {
    public:
        t_identifier_creator(t_identifier identifier = 0)
            : _identifier { identifier }
        {
        }

        inline const t_identifier increase()
        {
            return (++ _identifier);
        }

        inline const t_identifier decrease()
        {
            return (-- _identifier);
        }

        const t_identifier get_identifier()
        {
            return increase();
        }

    private:
        t_identifier _identifier {};
    };

    using t_floating = ::t_floating;

    using t_integer = int;

    using t_delta_time = t_frame_delta_time_value;

    using t_priority = t_floating;

    constexpr t_priority t_default_priority { 1.f };

    using t_description_view = std::string_view;
}

#endif // T_DEFINES_HPP
