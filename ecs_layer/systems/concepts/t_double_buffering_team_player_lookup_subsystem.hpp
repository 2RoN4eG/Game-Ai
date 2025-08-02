#pragma once

#include "../../t_component_defines.hpp"

#include <vector>
#include <span>
#include <iostream>


class t_player_component
{
public:
    t_identifier_value  _identifier {};

    t_team_value        _team {};

    t_player_component(const t_identifier_value identifier, const t_team_value team)
        : _identifier { identifier }
        , _team { team }
    {
    }
};

using t_player_container    = std::vector<t_player_component>;

using t_player_holder       = std::span<t_player_component>;

// naming: std::span is _holder
// std::vector is _container

class t_team_component
{
    // TODO: rename team player to player team or team players

public:
    const t_team_value              _team {};

    std::span<t_player_component>   _player_holder {};

public:
    t_team_component(const t_team_value team, t_player_container::iterator begin, t_player_container::iterator end)
        : _team { team }
        , _player_holder { begin, end }
    {
    }

    t_team_value operator()() const
    {
        return _team;
    }
};


struct t_team_finder
{
    const t_team_value _team {};

    t_team_finder(const t_team_value team)
        : _team { team }
    {
    }

    bool operator()(const t_player_component& player) const 
    {
        return _team == player._team;
    }

    bool operator()(const t_team_component& team) const
    {
        return _team == team();
    }
};


class t_double_buffering_team_player_lookup_subsystem
{
public:
    void create_team_player(const t_team_value team, const t_identifier_value identifier)
    {
        _players.emplace_back(identifier, team);
    }

    std::span<t_player_component> get_team_player_holder(const t_team_value team) const
    {
        using t_team_component = std::vector<t_team_component>;

        using t_team_player_holder_constant_iterator = t_team_component::const_iterator;

        t_team_player_holder_constant_iterator iterator = std::find_if(_team_container.begin(), _team_container.end(), t_team_finder { team });

        if (iterator == _team_container.end())
        {
            throw std::runtime_error { "team " + std::to_string(team) + " does not exist" };
        }

        return iterator->_player_holder;
    }

private:
    std::vector<t_team_component>   _team_container;

    std::vector<t_player_component> _players;

private:
    friend class t_exit_sorter;
};


struct t_player_comparator
{
    const bool operator()(const t_player_component& lhs, const t_player_component& rhs) const 
    {
        if (lhs._team == rhs._team)
        {
            return lhs._identifier < rhs._identifier;
        }

        return lhs._team < rhs._team;
    }
};


struct t_player_sorter
{
    bool operator()(const t_player_component& lhs, const t_player_component& rhs) const 
    {
        if (lhs._team == rhs._team)
        {
            return lhs._team < rhs._team;
        }

        return lhs._identifier < rhs._identifier;
    }
};


class t_exit_sorter
{
public:
    t_exit_sorter(t_double_buffering_team_player_lookup_subsystem& system)
        : _players { system._players }
        , _team_container ( system._team_container )
    {
    }

    ~t_exit_sorter()
    {
        process(_players, _team_container);
    }

    void process(std::vector<t_player_component>& players, std::vector<t_team_component>& team_holder_holder)
    {
        std::sort(players.begin(), players.end(), t_player_comparator {});

        for (t_player_container::iterator begin = players.begin(); begin != players.end();)
        {
            const t_team_value team { begin->_team };

            t_player_container::iterator end = std::find_if_not(begin, players.end(), t_team_finder { team });

            team_holder_holder.emplace_back(team, begin, end);

            begin = end;
        }
    }

private:
    std::vector<t_player_component>&    _players;

    std::vector<t_team_component>&      _team_container;
};


// Необходимо ответить на следующие вопросы, что бы получить:
// 1. Необходимо получить отсортированный массив _players по team в порядке возростания и identifier в порядке возрастания.
// 2. Необходимо получить отсортированный массив _players по team в порядке возростания и заполнить внутренний span диапазонами из массива _players .

// 1. Будет ли быстро заполнить массив _players данными а по завершению запустить t_exit_sorter (отсортировать заполненный массив по команде и identifier пользователя)?
// 2. Вставку в массив _players быстрее производить по элементно расширяя диапазоны _team_container для конкретной команды?
