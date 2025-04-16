#include "t_gob_node.hpp"

#include "interfaces/t_behavior_interface.hpp"


namespace ai::gob
{
    t_node::t_node(const t_node_identifier identifier,
                   std::unique_ptr<interfaces::t_behavior_interface>&& behavior)
        : _identifier { identifier }
        , _behavior { std::move(behavior) }
    {
    }

    t_node_identifier t_node::get_identifier() const
    {
        return _identifier;
    }

    void t_node::behave(const t_delta_time delta_time)
    {
        if (!_behavior)
        {
            return;
        }

        _behavior->behave(delta_time);
    }

    t_node::t_pointer t_node::make_transition(const t_node_identifier identifier,
                                              std::unique_ptr<interfaces::t_behavior_interface>&& goal)
    {
        return std::make_shared<t_node>(identifier, std::move(goal));
    }
}
