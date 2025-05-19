#pragma once

#include "t_component_defines.hpp"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>


using t_holder_information_printers = std::vector<std::function<void ()>>;

t_holder_information_printers& get_global_holder_information_printers();

template <typename t_entry>
class t_entry_holder
{
public:
    using t_entry_holder_container = std::vector<t_entry>;

    using t_entry_holder_container_constant_iterator = typename t_entry_holder_container::const_iterator;

public:
    t_entry_holder()
    {
        t_holder_information_printers& holder_information_printers = get_global_holder_information_printers();

        holder_information_printers.emplace_back([this]()
        {
            std::cout << "component holder contains " << std::setw(2) << this->_container.size() << " components" << std::endl;
        });

        std::cout << "global holder information printers contains " << holder_information_printers.size() << " printers" << std::endl;
    }

    template <typename... t_arguments>
    void create_component(const t_go_identifier_value identifier, t_arguments... arguments)
    {
        _container.emplace_back(identifier, arguments ...);
    }

    t_entry& get_mutable_component(const t_go_identifier_value identifier)
    {
        using t_entry_holder_container_iterator = typename t_entry_holder_container::iterator;

        t_entry_holder_container_iterator iterator = std::find_if(_container.begin(), _container.end(), t_component_finder { identifier });

        if (iterator != _container.end())
        {
            return *iterator;
        }

        throw std::runtime_error { "component_holder does not contain component by component identifier { " + std::to_string(identifier) + " }" };
    }

    const t_entry& get_component(const t_go_identifier_value identifier) const
    {
        t_entry_holder_container_constant_iterator iterator = std::find_if(_container.begin(), _container.end(), t_component_finder { identifier });

        if (iterator != _container.end())
        {
            return *iterator;
        }

        throw std::runtime_error { "component_holder does not contain component by component identifier { " + std::to_string(identifier) + " }" };
    }

    template <typename t_predicate>
    t_entry_holder_container select(const t_predicate& predicate)
    {
        t_entry_holder_container to_container {};

        std::copy_if(_container.begin(), _container.end(), std::back_inserter(to_container), predicate);

        return to_container;
    }

    const size_t amount() const
    {
        return _container.size();
    }

private:
    t_entry_holder_container _container {};

private:
    struct t_component_finder
    {
        const t_identifier_value identifier {};

        const bool operator()(const t_entry& entry) const
        {
            return entry.get_identifier() == identifier;
        }
    };

    friend t_entry_holder_container_constant_iterator begin(const t_entry_holder<t_entry>& entry_holder)
    {
        return entry_holder._container.begin();
    }

    friend t_entry_holder_container_constant_iterator end(const t_entry_holder<t_entry>& entry_holder)
    {
        return entry_holder._container.end();
    }
};
