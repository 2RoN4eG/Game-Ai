#pragma once

#include <string>


using t_timestamp = int;

using t_description = std::string;


class t_effect_interface
{
public:
    virtual ~t_effect_interface() = 0;

    virtual void apply() = 0;

    virtual void disapply() = 0;

    virtual const t_timestamp expire_after() const = 0;

    [[maybe_unused]]
    virtual t_description get_description() const { return {}; }
};
