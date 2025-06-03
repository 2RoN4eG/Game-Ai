#ifndef T_SHOOTING_GAME_SCENE_CREATOR_HPP
#define T_SHOOTING_GAME_SCENE_CREATOR_HPP

class t_shooting_game_scene;


class t_shooting_game_scene_creator
{
public:
    t_shooting_game_scene_creator(t_shooting_game_scene& game_scene);

private:
    t_shooting_game_scene& _game_scene;
};

#endif // T_SHOOTING_GAME_SCENE_CREATOR_HPP
