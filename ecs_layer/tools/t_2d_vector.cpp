#include "t_2d_vector.hpp"

#include <iomanip>
#include <cmath>


t_2d_vector_value::t_2d_vector_value()
    : t_2d_vector_value { {}, {} }
{
}

t_2d_vector_value::t_2d_vector_value(const t_2d_vector_axis_value x, const t_2d_vector_axis_value y)
    : _x { x }
    , _y { y }
{
}

t_2d_vector_axis_value t_2d_vector_value::x() const
{
    return _x;
}

t_2d_vector_axis_value t_2d_vector_value::y() const
{
    return _y;
}


t_2d_vector_value operator+(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs)
{
    return { lhs.x() + rhs.x(), lhs.y() + rhs.y() };
}

t_2d_vector_value operator-(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs)
{
    return { lhs.x() - rhs.x(), lhs.y() - rhs.y() };
}

t_2d_vector_value operator/(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs)
{
    return { lhs.x() / rhs.x(), lhs.y() / rhs.y() };
}

t_2d_vector_value operator*(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs)
{
    return { lhs.x() * rhs.x(), lhs.y() * rhs.y() };
}


t_2d_vector_value operator/(const t_2d_vector_value& vector, const t_2d_vector_axis_value& value)
{
    return { vector.x() / value, vector.y() / value };
}

t_2d_vector_value operator*(const t_2d_vector_value& vector, const t_2d_vector_axis_value& value)
{
    return { vector.x() * value, vector.y() * value };
}


t_floating_value t_get_vector_length(const t_2d_vector_value& vector)
{
    return std::sqrt( vector.x() * vector.x() + vector.y() * vector.y() );
}


t_2d_vector_value t_normilize_vector(const t_2d_vector_value& vector)
{
    const t_2d_vector_axis_value vector_length = t_get_vector_length(vector);

    return vector / vector_length;
}


t_angle_radians_value t_convert_degrees_to_radians(const t_angle_degrees_value degrees)
{
    return degrees * M_PI / 180.;
}

t_angle_degrees_value t_convert_radians_to_degrees(const t_angle_radians_value radians)
{
    return radians / M_PI * 180.;
}


t_2d_vector_value t_make_vector_from_angle_along_x_axis_radians(const t_angle_radians_value radians)
{
    return { std::cos(radians), std::sin(radians) };
}

t_2d_vector_value t_make_vector_from_angle_along_x_axis_degrees(const t_angle_degrees_value degrees)
{
    const t_2d_vector_axis_value radians = t_convert_degrees_to_radians(degrees);

    return t_make_vector_from_angle_along_x_axis_radians(radians);
}


t_2d_vector_value t_make_vector_from_degrees_along_y_axis_radians(const t_angle_radians_value radians)
{
    const t_radians_value converted = t_convert_degrees_to_radians(90.);

    return t_make_vector_from_angle_along_x_axis_radians(radians + converted);
}

t_2d_vector_value t_make_vector_from_degrees_along_y_axis_degrees(const t_angle_degrees_value degrees)
{
    return t_make_vector_from_angle_along_x_axis_degrees(90.);
}

t_distance_value t_get_distance(const t_2d_vector_value& lhs, const t_2d_vector_value& rhs)
{
    const t_2d_vector_axis_value x { lhs.x() - rhs.x() };

    const t_2d_vector_axis_value y { lhs.y() - rhs.y() };

    return sqrt(x * x + y * y);
}


std::ostream& operator<<(std::ostream& stream, const t_2d_vector_value& vector)
{
    stream << "x: " << std::setw(12) << vector.x()
           << ", y: " << std::setw(12) << vector.y()
           << ", length: " << t_get_vector_length(vector)
           << std::endl;

    return stream;
}
