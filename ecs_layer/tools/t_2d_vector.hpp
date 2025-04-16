#ifndef T_2D_VECTOR_H
#define T_2D_VECTOR_H

#include "../t_component_defines.hpp"


using t_2d_vector_axis_value = t_floating;

class t_2d_vector
{
public:
    t_2d_vector();
    t_2d_vector(const t_2d_vector_axis_value x, const t_2d_vector_axis_value y);

    t_2d_vector_axis_value x() const;

    t_2d_vector_axis_value y() const;

private:
    t_2d_vector_axis_value _x {};

    t_2d_vector_axis_value _y {};
};


t_2d_vector operator+(const t_2d_vector& lhs, const t_2d_vector& rhs);

t_2d_vector operator-(const t_2d_vector& lhs, const t_2d_vector& rhs);

t_2d_vector operator*(const t_2d_vector& lhs, const t_2d_vector& rhs);

t_2d_vector operator/(const t_2d_vector& lhs, const t_2d_vector& rhs);


t_2d_vector operator/(const t_2d_vector& vector, const t_2d_vector_axis_value& value);

t_2d_vector operator*(const t_2d_vector& vector, const t_2d_vector_axis_value& value);


using t_position_2d_vector          = t_2d_vector;

using t_heading_2d_vector           = t_2d_vector;

using t_course_2d_vector            = t_2d_vector;

using t_angular_velocity_2d_vector  = t_2d_vector;


///
/// \brief t_normilize_vector
/// \param vector
/// \return
///
t_2d_vector t_normilize_vector(const t_2d_vector& vector);

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
t_2d_vector t_make_vector_from_angle_along_x_axis_radians(const t_angle_radians_value radians);

///
/// \brief t_make_vector_from_angle_along_x_axis_degrees creates 2D vector from angle (in degrees)
/// \param degrees - angle in degrees.
/// \return 2D vector.
///
t_2d_vector t_make_vector_from_angle_along_x_axis_degrees(const t_angle_degrees_value degrees);

///
/// \brief t_make_vector_from_degrees_along_y_axis_radians creates 2D vector from angle in radians.
/// \param radians - angle in radians.
/// \return 2D vector.
///
t_2d_vector t_make_vector_from_degrees_along_y_axis_radians(const t_angle_radians_value radians);

///
/// \brief t_make_vector_from_degrees_along_y_axis_degrees creates 2D vector from angle in degrees.
/// \param degrees - angle in degrees.
/// \return 2D vector.
///
t_2d_vector t_make_vector_from_degrees_along_y_axis_degrees(const t_angle_degrees_value degrees);

///
/// \brief operator<< prints contained variables to stream
/// \param stream for printing vector variables
/// \param 2D vector
/// \return
///
std::ostream& operator<<(std::ostream& stream, const t_2d_vector& vector);

#endif // T_2D_VECTOR_H
