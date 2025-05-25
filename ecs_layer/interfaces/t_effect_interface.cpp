#include "t_effect_interface.hpp"

#include <vector>


namespace 
{
    std::vector<t_effect_interface*> global_effect_collection;
}


t_effect_interface::t_effect_interface(const t_timestamp expire_after)
    : _expire_after { expire_after } 
{
    global_effect_collection.emplace_back(this);
}

t_effect_interface::~t_effect_interface()
{
}

const t_timestamp t_effect_interface::expire_after() const
{
    return _expire_after;
};

t_description t_effect_interface::get_description() const
{
    return {};
}
