#ifndef T_GOB_NODE_H
#define T_GOB_NODE_H

#include "../t_defines.hpp"


namespace ai::gob
{
    namespace interfaces
    {
        class t_behavior_interface;
    }

    class t_node
    {
    public:
        t_node(const t_node_identifier identifier,
               std::unique_ptr<interfaces::t_behavior_interface>&& behaviour);

        ~t_node() = default;

        t_node_identifier get_identifier() const;

        void behave(const t_delta_time delta);

    protected:
        t_node_identifier _identifier {};

        std::unique_ptr<interfaces::t_behavior_interface> _behavior;
    };

    using t_node_pointer = std::shared_ptr<t_node>;

    t_node_pointer make_transition(const t_node_identifier identifier,
                                   std::unique_ptr<interfaces::t_behavior_interface>&& goal);
}

#endif // T_GOB_NODE_H
