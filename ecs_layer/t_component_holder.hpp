#pragma once

#include "t_component_defines.hpp"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>


using t_holder_information_printers = std::vector<std::function<void ()>>;

t_holder_information_printers& get_global_holder_information_printers();


template <typename t_component>
class t_component_holder
{
public:
    using t_component_container = std::vector<t_component>;

    using t_component_container_iterator = t_component_container::iterator;

public:
    t_component_holder()
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

    t_component& get_component(const t_go_identifier_value identifier)
    {
        struct t_component_finder
        {
            const t_go_identifier_value identifier {};

            bool operator()(const t_component& game_object) const
            {
                return identifier == game_object.get_identifier();
            }
        };

        t_component_container_iterator iterator = std::find_if(_container.begin(), _container.end(), t_component_finder { identifier });

        if (iterator != _container.end())
        {
            return *iterator;
        }

        throw std::runtime_error { "component_holder does not contain component by component identifier { " + std::to_string(identifier) + " }" };
    }

    const size_t amount() const
    {
        return _container.size();
    }

private:
    t_component_container _container {};
};
