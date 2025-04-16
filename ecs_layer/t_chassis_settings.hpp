#ifndef T_CHASSIS_SETTINGS_HPP
#define T_CHASSIS_SETTINGS_HPP

using t_wheels = int;


/// Класс для всех "константных" данных для шасси
class t_chassis_settings
{
public:
    t_chassis_settings();

    const t_wheels wheels() const;

private:
    t_wheels _wheels;
};

#endif // T_CHASSIS_SETTINGS_HPP
