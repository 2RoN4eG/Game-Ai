#pragma once

#include "t_entry_holder.hpp"


template <typename... t_components>
class t_entry_holder_aggregator : public t_entry_holder<t_components>...
{
public:
    template <typename t_entry>
    inline t_entry_holder<t_entry>& get_mutable_entry_holder()
    {
        return *this;
    }

    template <typename t_entry>
    inline const t_entry_holder<t_entry>& get_entry_holder() const
    {
        return *this;
    }

    void print_debug_information() const
    {
        (t_entry_holder<t_components>::print_debug_information(), ...); // Вызов show() для всех EntryHolder
    }
};
