#include "t_effect_interface.hpp"

#include <vector>


namespace 
{
    std::vector<t_effect_interface*> global_effect_collection;
}


t_effect_interface::t_effect_interface()
{
    global_effect_collection.emplace_back(this);
}

t_effect_interface::~t_effect_interface()
{
}
