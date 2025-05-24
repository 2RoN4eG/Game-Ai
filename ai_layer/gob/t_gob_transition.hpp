#pragma once

#include "../t_defines.hpp"


namespace ai::gob
{
    namespace interfaces
    {
        class t_goal_interface;
    }

    class t_transition
    {
    public:
        t_transition(const t_transition_identifier identifier,
                     const t_node_identifier from,
                     const t_node_identifier to,
                     std::unique_ptr<interfaces::t_goal_interface>&& goal);

        ~t_transition() = default;

        t_transition_identifier identifier() const;

        bool is_goal_reached() const;

        t_priority goal_priority() const;

        t_node_identifier get_from_node_identifier() const;

        t_node_identifier get_to_node_identifier() const;

    protected:
        t_transition_identifier _identifier {};

        t_node_identifier _from_node {};

        t_node_identifier _to_node {};

        std::unique_ptr<interfaces::t_goal_interface> _goal;
    };

    using t_transition_pointer = std::shared_ptr<t_transition>;

    t_transition_pointer make_transition(const t_transition_identifier identifier,
                                         const t_node_identifier from,
                                         const t_node_identifier to,
                                         std::unique_ptr<interfaces::t_goal_interface>&& goal);
}
