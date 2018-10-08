#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>

using real_type = int;

struct Point2D
{
   real_type x;
   real_type y;

   Point2D( real_type x_, real_type y_ ) : x( x_ ), y( y_ )
    { /* empty */ }

   Point2D( const Point2D & source ) = default;
   Point2D&  operator=( const Point2D& ) = default;

};

class Circle
{
    private:
        real_type m_radius; //!< raio
        Point2D m_center; //!< centro do circulo.

    public:
        //=== Membros especiais
        /// Construtor master
        Circle( real_type r=0,
                real_type x=0,
                real_type y=0 )
            : m_radius{ r }, m_center{ x, y }
        { /* empty */ }

        /// construtor copia
        Circle( const Circle & clone )
        {
            std::cout << ">>> Dentro do construtor copia.\n";
            m_radius = clone.m_radius;
            m_center = clone.m_center;
            //m_center.x = clone.m_center.x;
            //m_center.y = clone.m_center.y;
        }

        /// destrutor
        ~Circle( void )
        {
            std::cout << "<<< Destrutor chamado.\n";
        }

        /// Assignment operator.
        Circle&  operator= ( const Circle& rhs );

        //=== Accessors.
        /// Recupera o raio do circulo.
        real_type get_radius( void ) const;
        /// Recupera a coordenada x do centro.
        real_type get_x( void ) const;
        /// Recupera a coordenada y do centro.
        real_type get_y( void ) const;
        /// Recupera o centro.
        inline Point2D get_center( void ) const
        { return m_center; }

        //=== Modificadores
        /// modifica o raio do circulo para o valor `nr`
        void set_radius( real_type nr );
        /// Modifica o centro do circulo (1).
        void set_center( const Point2D& nc );
        /// Modifica o centro do circulo (2).
        void set_center( real_type x, real_type y );

        //=== Sobrecarga de operadores
        bool operator==( const Circle& rhs )
        {
            return ( this->m_radius == rhs.m_radius and
                 this->m_center.x == rhs.m_center.x and
                 this->m_center.y == rhs.m_center.y ) ;
        }
        friend bool operator!=( const Circle &,  const Circle& );

        //=== Operacoes sobre circulo.
        real_type area( void ) const;
};

#endif
