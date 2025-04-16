#include "t_gob_transition.hpp"

#include "interfaces/t_goal_interface.hpp"

#include <iostream>


namespace ai::gob
{
    t_transition::t_transition(const t_transition_identifier identifier,
                               const t_node_identifier from,
                               const t_node_identifier to,
                               std::unique_ptr<interfaces::t_goal_interface>&& goal)
        : _identifier { identifier }
        , _from_node { from }
        , _to_node { to }
        , _goal { std::move(goal) }
    {
    }

    t_transition_identifier t_transition::identifier() const
    {
        return _identifier;
    }

    t_node_identifier t_transition::get_from_node_identifier() const
    {
        return _from_node;
    }

    t_node_identifier t_transition::get_to_node_identifier() const
    {
        return _to_node;
    }

    bool t_transition::is_goal_reached() const
    {
        return _goal->is_reached();
    }

    t_priority t_transition::goal_priority() const
    {
        return _goal->priority();
    }

    t_transition::t_pointer t_transition::make_transition(const t_transition_identifier identifier,
                                                          const t_node_identifier from,
                                                          const t_node_identifier to,
                                                          std::unique_ptr<interfaces::t_goal_interface>&& goal)
    {
        return std::make_shared<t_transition>(identifier, from, to, std::move(goal));
    }
}
