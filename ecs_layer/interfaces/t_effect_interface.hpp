#pragma once

#include <string>

#include "../tools/t_2d_vector.hpp"


using t_timestamp = int;

using t_description = std::string;


class t_effect_interface
{
public:
    t_effect_interface(const t_timestamp expire_after);

    virtual ~t_effect_interface() = 0;


    virtual void apply() = 0;

    virtual void disapply() = 0;


    const t_timestamp expire_after() const;

    [[maybe_unused]]
    t_description get_description() const;

private:
    t_timestamp _expire_after {};
};


class t_updatable_effect_interface
{
public:
    virtual void update(const t_frame_delta_time_value delta_time) = 0;
};
