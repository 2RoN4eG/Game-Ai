#pragma once

#include "../t_component_defines.hpp"


using t_2d_vector_axis_value = t_floating_value;


class t_2d_vector_value
{
public:
    t_2d_vector_value();
    t_2d_vector_value(const t_2d_vector_axis_value x, const t_2d_vector_axis_value y);

    t_2d_vector_axis_value x() const;

    t_2d_vector_axis_value y() const;

private:
    t_2d_vector_axis_value _x {};

    t_2d_vector_axis_value _y {};
};


t_2d_vector_value operator+(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs);

t_2d_vector_value operator-(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs);

t_2d_vector_value operator*(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs);

t_2d_vector_value operator/(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs);


t_2d_vector_value operator/(const t_2d_vector_value& vector, const t_2d_vector_axis_value& value);

t_2d_vector_value operator*(const t_2d_vector_value& vector, const t_2d_vector_axis_value& value);


using t_2d_position_value                   = t_2d_vector_value;

using t_2d_heading_value                    = t_2d_vector_value;

using t_2d_course                           = t_2d_vector_value;

using t_2d_angular_velocity                 = t_2d_vector_value;

using t_position_value                      = t_2d_position_value;

using t_vehicle_position_value              = t_position_value;

using t_distance_value                      = t_2d_vector_axis_value;

using t_braking_distance_value              = t_distance_value;

using t_visibility_distance_value           = t_distance_value;

using t_vehicle_visibility_distance_value   = t_visibility_distance_value;

using t_radio_distance_value                = t_distance_value;

using t_vehicle_radio_distance_value        = t_radio_distance_value;


///
/// \brief t_normilize_vector
/// \param vector
/// \return
///
t_2d_vector_value t_normilize_vector(const t_2d_vector_value& vector);

///
/// \brief t_convert_degrees_to_radians
/// \param degrees - angle in degrees.
/// \return angle in radians.
///
t_angle_radians_value t_convert_degrees_to_radians(const t_angle_degrees_value degrees);

///
/// \brief t_convert_radians_to_degrees
/// \param radians - angle in radians.
/// \return angle in degrees.
///
t_angle_degrees_value t_convert_radians_to_degrees(const t_angle_radians_value radians);

///
/// \brief t_make_vector_from_angle_along_x_axis_radians
/// \param radians - angle in radians.
/// \return 2D vector.
///
t_2d_vector_value t_make_vector_from_angle_along_x_axis_radians(const t_angle_radians_value radians);

///
/// \brief t_make_vector_from_angle_along_x_axis_degrees creates 2D vector from angle (in degrees)
/// \param degrees - angle in degrees.
/// \return 2D vector.
///
t_2d_vector_value t_make_vector_from_angle_along_x_axis_degrees(const t_angle_degrees_value degrees);

///
/// \brief t_make_vector_from_degrees_along_y_axis_radians creates 2D vector from angle in radians.
/// \param radians - angle in radians.
/// \return 2D vector.
///
t_2d_vector_value t_make_vector_from_degrees_along_y_axis_radians(const t_angle_radians_value radians);

///
/// \brief t_make_vector_from_degrees_along_y_axis_degrees creates 2D vector from angle in degrees.
/// \param degrees - angle in degrees.
/// \return 2D vector value.
///
t_2d_vector_value t_make_vector_from_degrees_along_y_axis_degrees(const t_angle_degrees_value degrees);

///
/// \brief t_get_distance gets distance between 2 2D vectors (points).
/// \param lhs - 2D vector.
/// \param rhs - 2D vector.
/// \return linear distance value.
///
t_distance_value t_get_distance(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs);

///
/// \brief operator<< prints contained variables to stream
/// \param stream for printing vector variables
/// \param vector is 2D vector
/// \return
///
std::ostream& operator<<(std::ostream& stream, const t_2d_vector_value& vector);
