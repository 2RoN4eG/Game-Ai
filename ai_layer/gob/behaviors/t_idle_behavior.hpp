#ifndef T_IDLE_BEHAVIOR_HPP
#define T_IDLE_BEHAVIOR_HPP

#include "../interfaces/t_behavior_interface.hpp"


namespace ai::gob
{
    class t_idle_behavior : public interfaces::t_behavior_interface
    {
    public:
        t_idle_behavior() = default;

        ~t_idle_behavior() override = default;

        std::string_view description() const override;

        void behave(const t_delta_time delta_time) override;
    };
}

#endif // T_IDLE_BEHAVIOR_HPP
