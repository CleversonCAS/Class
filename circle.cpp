#include "../include/circle.h"

real_type Circle::get_radius( void ) const
{
    return m_radius;
}
real_type Circle::get_x( void ) const
{
    return m_center.x;
}
real_type Circle::get_y( void ) const
{
    return m_center.y;
}

Circle&  Circle::operator= ( const Circle& rhs )
{
    this->m_radius = rhs.m_radius;
    this->m_center = rhs.m_center;

    return *this;
}

void Circle::set_radius( real_type nr )
{
    m_radius = nr;
}

void Circle::set_center( const Point2D& nc )
{
    m_center = nc;
}

void Circle::set_center( real_type x, real_type y )
{
    m_center.x = x;
    m_center.y = y;
}

real_type Circle::area( void ) const
{
    return 3.14159 * m_radius * m_radius;
}


bool operator!=( const Circle & a, const Circle& b )
{
    //return !( a==b );
    return ( a.get_radius() != b.get_radius() or
             a.m_center.x != b.m_center.x or
             a.m_center.y != b.m_center.y ) ;
}


