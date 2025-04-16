#ifndef T_AI_DEMO_LINEAR_MOVING_SYSTEM_H
#define T_AI_DEMO_LINEAR_MOVING_SYSTEM_H

#include "../t_component_defines.hpp"
#include "../interfaces/t_updatable_interface.hpp"


class t_ai_demo_movable_component;


class t_ai_demo_linear_moving_system : public t_updatable_interface
{
public:
    t_ai_demo_linear_moving_system(t_ai_demo_movable_component& movable_entity);

    ~t_ai_demo_linear_moving_system() override = default;

    void update(const t_frame_delta_time_value delta_time) override;

private:
    t_ai_demo_movable_component& _movable_entity;
};


using t_moving_system = t_ai_demo_linear_moving_system;

#endif // T_AI_DEMO_LINEAR_MOVING_SYSTEM_H
