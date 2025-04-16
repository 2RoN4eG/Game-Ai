#include "t_behavior_interface.hpp"

namespace ai::gob::interfaces
{
    t_behavior_interface::~t_behavior_interface()
    {
    }

    bool t_behavior_interface::is_successful() const
    {
        return true;
    }

    bool t_behavior_interface::is_failed() const
    {
        return false;
    }

    bool t_behavior_interface::is_possible() const
    {
        return true;
    }

    bool t_behavior_interface::is_reachable() const
    {
        return true;
    }
}
