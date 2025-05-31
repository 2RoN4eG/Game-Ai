#pragma once

#include "../../t_component_defines.hpp"

#include <vector>
#include <span>
#include <iostream>


class t_player
{
public:
    t_team_value _team {};

    t_identifier_value _identifier {};

    t_player(const t_team_value team, const t_identifier_value identifier)
        : _team { team }
        , _identifier { identifier }
    {
    }
};


using t_player_holder = std::vector<t_player>;


class t_team_player
{
public:
    const t_team_value          _team {};

    const std::span<t_player>   _player_holder {};

public:
    t_team_player(const t_team_value team, t_player_holder::iterator begin, t_player_holder::iterator end)
        : _team { team }
        , _player_holder { begin, end }
    {
    }
};


class t_double_buffering_team_player_lookup_system
{
public:
    void create_team_player(const t_team_value team, const t_identifier_value identifier)
    {
        _players.emplace_back(team, identifier);
    }

    std::span<t_player> get_team_player_holder(const t_team_value team) const
    {
        using t_team_player_holder = std::vector<t_team_player>;

        using t_team_player_holder_constant_iterator = t_team_player_holder::const_iterator;

        struct t_team_player_finder
        {
            const t_team_value _team {};

            const bool operator()(const t_team_player& span_holder) const
            {
                return _team == span_holder._team;
            }
        };

        t_team_player_holder_constant_iterator iterator = std::find_if(_team_player_holder.begin(), _team_player_holder.end(), t_team_player_finder { team });

        if (iterator == _team_player_holder.end())
        {
            throw std::runtime_error { "team " + std::to_string(team) + " does not exist" };
        }

        return iterator->_player_holder;
    }

private:
    std::vector<t_team_player>  _team_player_holder;

    std::vector<t_player>       _players;

private:
    friend class t_exit_sorter;
};


struct t_player_comparator
{
    const bool operator()(const t_player& lhs, const t_player& rhs) const 
    {
        if (lhs._team == rhs._team)
        {
            return lhs._identifier < rhs._identifier;
        }

        return lhs._team < rhs._team;
    }
};


struct t_team_player_finder
{
    const t_team_value _team {};

    t_team_player_finder(const t_team_value team)
        : _team { team }
    {
    }

    bool operator()(const t_player& player) const 
    {
        return _team == player._team;
    }
};


struct t_player_sorter
{
    bool operator()(const t_player& lhs, const t_player& rhs) const 
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
    t_exit_sorter(t_double_buffering_team_player_lookup_system& system)
        : _players { system._players }
        , _team_player_holder ( system._team_player_holder )
    {
    }

    ~t_exit_sorter()
    {
        process(_players, _team_player_holder);
    }

    void process(std::vector<t_player>& players, std::vector<t_team_player>& team_holder_holder)
    {
        std::sort(players.begin(), players.end(), t_player_comparator {});

        for (t_player_holder::iterator begin = players.begin(); begin != players.end();)
        {
            const t_team_value team { begin->_team };

            t_player_holder::iterator end = std::find_if_not(begin, players.end(), t_team_player_finder { team });

            team_holder_holder.emplace_back(team, begin, end);

            begin = end;
        }
    }

private:
    std::vector<t_player>&      _players;

    std::vector<t_team_player>& _team_player_holder;
};


// Необходимо ответить на следующие вопросы, что бы получить:
// 1. Необходимо получить отсортированный массив _players по team в порядке возростания и identifier в порядке возрастания.
// 2. Необходимо получить отсортированный массив _players по team в порядке возростания и заполнить внутренний span диапазонами из массива _players .

// 1. Будет ли быстро заполнить массив _players данными а по завершению запустить t_exit_sorter (отсортировать заполненный массив по команде и identifier пользователя)?
// 2. Вставку в массив _players быстрее производить по элементно расширяя диапазоны _team_player_holder для конкретной команды?
