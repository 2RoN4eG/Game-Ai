#pragma once

#include <stdexcept>
#include <vector>


template <typename t_component>
class t_component_holder
{
    using t_component_container = std::vector<t_component>;

    using t_component_container_iterator = t_component_container::iterator; 

public:
    t_component_holder() = default;

    template <typename... t_arguments>
    void create_component(const t_go_identifier_value identifier, t_arguments... arguments)
    {
        t_component game_object { identifier, arguments ... };

        _container.emplace_back(std::move(game_object));
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

        throw std::runtime_error { "" };
    }

    const size_t amount() const
    {
        return _container.size();
    }

private:
    t_component_container _container {};
};
