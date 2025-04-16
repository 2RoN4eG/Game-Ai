#ifndef T_BEHAVIOR_INTERFACE_H
#define T_BEHAVIOR_INTERFACE_H

#include "../../t_defines.hpp"


namespace ai::gob::interfaces
{
    /**
     * @brief The t_behavior_interface class
     */
    class t_behavior_interface
    {
    public:
        virtual ~t_behavior_interface() = 0;

        virtual std::string_view description() const = 0;

        virtual void behave(const t_delta_time) = 0;

        virtual bool is_successful() const;

        virtual bool is_failed() const;
    };
}

#endif // T_BEHAVIOR_INTERFACE_H
