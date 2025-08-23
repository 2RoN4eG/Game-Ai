#pragma once

#include "t_component_defines.hpp"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>
#include <utility>


#define CLASS_NAME(T) typeid(T).name()


using t_holder_information_printers = std::vector<std::function<void ()>>;

t_holder_information_printers& get_global_holder_information_printers();

template <typename t_entry>
class t_entry_holder
{
public:
    using t_entry_holder_container = std::vector<t_entry>;

    using t_entry_holder_container_constant_iterator = typename t_entry_holder_container::const_iterator;

    using t_entry_holder_container_iterator = typename t_entry_holder_container::iterator;

public:
    t_entry_holder()
    {
    }

    template <typename... t_arguments>
    t_entry& create_component(t_arguments&&... arguments)
    {
        return _container.emplace_back(std::forward<t_arguments>(arguments)...);
    }

    template <typename... t_arguments>
    t_entry& create_component(const t_go_identifier_value identifier, t_arguments&&... arguments)
    {
        return _container.emplace_back(identifier, std::forward<t_arguments>(arguments)...);
    }

    t_entry& get_mutable_component(const t_go_identifier_value identifier)
    {
        if (t_entry_holder_container_iterator iterator = std::find_if(_container.begin(), _container.end(), t_component_finder { identifier }); iterator != _container.end())
        {
            return *iterator;
        }

        throw std::runtime_error { "component_holder does not contain component by component identifier { " + std::to_string(identifier) + " }" };
    }

    t_entry& get_mutable_component()
    {
        if (_container.size() != 1)
        {
            return _container.front();
        }

        throw std::runtime_error { "component_holder contains " + std::to_string(_container.size()) + " components, use t_entry& get_mutable_component(const t_go_identifier_value) instead, " + CLASS_NAME(t_entry) };
    }

    const t_entry& get_component(const t_go_identifier_value identifier) const
    {
        if (t_entry_holder_container_constant_iterator iterator = std::find_if(_container.begin(), _container.end(), t_component_finder { identifier }); iterator != _container.end())
        {
            return *iterator;
        }

        throw std::runtime_error { "component_holder<> does not contain component by component identifier { " + std::to_string(identifier) + " }" };
    }

    const t_entry& get_component() const
    {
        if (_container.size() != 1)
        {
            throw std::runtime_error { "component_holder<> contains " + std::to_string(_container.size()) + " components, use t_entry& get_component(const t_go_identifier_value) instead" };
        }

        return _container.front();
    }

    void set_component(const t_entry& entry)
    {
        _container.emplace_back(entry);
    }

    void set_components(const t_entry_holder_container& container)
    {
        _container.insert(_container.end(), container.begin(), container.end());
    }

    template <typename t_predicate>
    t_entry_holder_container select(t_predicate&& predicate) const
    {
        t_entry_holder_container to_container {};

        std::copy_if(_container.begin(), _container.end(), std::back_inserter(to_container), std::move(predicate));

        return to_container;
    }


    const size_t amount() const
    {
        return size();
    }

    inline const size_t size() const
    {
        return _container.size();
    }

    void print_debug_information() const
    {
        std::cout << "t_entry_holder contains " << _container.size() << " components" << std::endl;
    }

private:
    t_entry_holder_container _container {};

private:
    struct t_component_finder
    {
        const t_identifier_value identifier {};

        bool operator()(const t_entry& entry) const
        {
            return identifier == entry.get_identifier();
        }
    };

    friend t_entry_holder_container_constant_iterator begin(const t_entry_holder<t_entry>& entry_holder)
    {
        return entry_holder._container.begin();
    }

    friend t_entry_holder_container_constant_iterator end(const t_entry_holder<t_entry>& entry_holder)
    {
        return entry_holder._container.cend();
    }

    friend t_entry_holder_container_iterator begin(t_entry_holder<t_entry>& entry_holder)
    {
        return entry_holder._container.begin();
    }

    friend t_entry_holder_container_iterator end(t_entry_holder<t_entry>& entry_holder)
    {
        return entry_holder._container.end();
    }
};

// Создать класс t_component_holder из класса t_entry_holder и сделать
// аналогичное решение только для класса t_event_holder. Различием станет
// только вызов методов apply() и disapply() для эффекта.
