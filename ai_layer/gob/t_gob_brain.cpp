#include "t_gob_brain.hpp"

#include <algorithm>
#include <ranges>

#include "t_gob_node.hpp"
#include "t_gob_transition.hpp"

#include "interfaces/t_behavior_interface.hpp"
#include "interfaces/t_goal_interface.hpp"


namespace ai::gob
{
    namespace
    {
        struct t_by_priority_sorter
        {
            bool operator()(const t_transition_pointer& lhs, const t_transition_pointer& rhs) const
            {
                return lhs->get_from_node_identifier() < rhs->get_from_node_identifier();
            }
        };

        struct t_by_transition_sorter
        {
            bool operator()(const t_transition_pointer& lhs, const t_transition_pointer& rhs) const
            {
                return lhs->get_from_node_identifier() < rhs->get_from_node_identifier();
            }
        };

        struct t_by_from_node_copier
        {
            ai::t_node_identifier _node_identifier {};

            bool operator ()(const t_transition_pointer& transition) const
            {
                return transition->get_from_node_identifier() == _node_identifier;
            }
        };

        inline t_node_pointer get_node(const std::vector<t_node_pointer>& node_holder, const ai::t_node_identifier node_identifier)
        {
            for (const t_node_pointer& node : node_holder)
            {
                if (node->get_identifier() == node_identifier)
                {
                    return node;
                }
            }

            return {};
        }

        inline std::vector<t_transition_pointer> get_transitions(const std::vector<t_transition_pointer>& transitions, const ai::t_node_identifier node_identifier)
        {
            std::vector<t_transition_pointer> result;

            std::ranges::copy_if(transitions, std::back_inserter(result), t_by_from_node_copier { node_identifier });

            return result;
        }
    }


    t_brain::t_brain()
    {
    }

    const t_node_identifier t_brain::hold_behavior(std::unique_ptr<interfaces::t_behavior_interface>&& behavior)
    {
        const t_node_identifier identifier = _node_identifier_generator();

        t_node_pointer&& node = make_node(identifier, std::move(behavior));

        _node_holder.emplace_back(std::move(node));

        return identifier;
    }

    const t_transition_identifier t_brain::hold_transition(const t_node_identifier from_node_identifier,
                                                            const t_node_identifier to_node_identifier,
                                                            std::unique_ptr<interfaces::t_goal_interface>&& goal)
    {
        const t_transition_identifier identifier = _transition_identifier_generator();

        t_transition_pointer&& transition = make_transition(identifier, from_node_identifier, to_node_identifier, std::move(goal));

        _transition_holder.emplace_back(std::move(transition));

        return identifier;
    }

    void t_brain::finish_preparing()
    {
        _root = _node_holder.front();

        std::sort(_transition_holder.begin(), _transition_holder.end(), t_by_transition_sorter {});

        _transitions = get_transitions(_transition_holder, _root->get_identifier());
    }

    void t_brain::update(const t_delta_time delta_time)
    {
        if (!_root)
        {
            return;
        }

        if (_transitions.empty())
        {
            return;
        }

        _root->behave(delta_time);

        for (const t_transition_pointer& transition : _transitions)
        {
            if (!transition->is_goal_reached())
            {
                continue;
            }

            const t_node_identifier node_identifier = transition->get_to_node_identifier();

            _root = get_node(_node_holder, node_identifier);

            _transitions = get_transitions(_transition_holder, node_identifier);

            break;
        }
    }
}
