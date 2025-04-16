#include "t_idle_behavior.hpp"

// #include <iostream>


namespace ai::gob
{
    std::string_view t_idle_behavior::description() const
    {
        return "Пустое поведение, заглушка.";
    }

    void t_idle_behavior::behave([[maybe_unused]] const t_delta_time delta_time)
    {
        // std::cerr << "[idle] do nothing ..." << std::endl;
    }
}
