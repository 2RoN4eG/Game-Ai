#ifndef T_GOB_RUNNER_H
#define T_GOB_RUNNER_H

#include "interfaces/t_goal_interface.hpp"
#include "interfaces/t_behavior_interface.hpp"

#include "t_gob_node.hpp"
#include "t_gob_transition.hpp"

#include <memory>
#include <vector>


namespace ai::gob
{
    namespace interfaces
    {
        class t_behavior_interface;
        class t_goal_interface;
    }

    // Ответсвенность данного класса:
    // Хранить все узлы
    // Хранить все переходы на узлы
    class t_brain
    {
    public:
        t_brain();
        ~t_brain() = default;

        const t_node_identifier hold_behavior(std::unique_ptr<interfaces::t_behavior_interface>&& behaviour);

        const t_transition_identifier hold_transition(const t_node_identifier from_node_identifier,
                                                      const t_node_identifier to_node_identifier,
                                                      std::unique_ptr<interfaces::t_goal_interface>&& goal);

        void finish_preparing();

        void update(const t_delta_time delta);

    protected:
        t_node_pointer                          _root;

        std::vector<t_transition_pointer>       _transitions;

        t_node_identifier_maker                 _node_identifier_generator;

        std::vector<t_node_pointer>             _node_holder;

        t_transition_identifier_maker           _transition_identifier_generator;

        std::vector<t_transition_pointer>       _transition_holder;

        friend class t_brain_maker;
    };

}   // namespace ai::gob

#endif // T_GOB_RUNNER_H
