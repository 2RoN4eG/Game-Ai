#ifndef T_GOAL_INTERFACE_H
#define T_GOAL_INTERFACE_H

#include <string_view>

#include "../../t_defines.hpp"


namespace ai::gob::interfaces
{
    class t_goal_interface
    {
    public:
        virtual ~t_goal_interface() = 0;

        virtual std::string_view description() const = 0;

        virtual t_priority priority() const = 0;

        virtual bool is_reached() const = 0;
    };
}

#endif // T_GOAL_INTERFACE_H
