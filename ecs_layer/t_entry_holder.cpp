#include "t_entry_holder.hpp"


namespace
{
    t_holder_information_printers g_holder_information_printers {};
}


t_holder_information_printers& get_global_holder_information_printers()
{
    return g_holder_information_printers;
}
