#include <iostream>
#include <cassert> // assert(?????)

#include "../include/circle.h"

void print( const Circle&  c )
{
    //Point2D center = c.get_center();

    std::cout << "[r=" << c.get_radius() << ", "
              << "(" << c.get_x() // << "(" << center.x
              << "," << c.get_y() // << "," << center.y
              << ")]\n";
}

int main( void )
{
    Circle c1; // circulo com raio 0, centro (0,0)
    Circle c2{2}; // raio =2, centro (0,0)
    Circle c3{3, 4}; // raio = 3, centro (4,0)
    Circle c4{4, 2,3 }; // raio = 1, centro (2,3)

//    c4.translate( { -2, -3 } );

    std::cout << ">>> c4: ";
    print( c4 );
    std::cout << ">>> c3: ";
    print( c3 );

    if ( c4 == c3 )
        std::cout << ">>> c4 == c3 " << std::endl;
    else
        std::cout << ">>> c4 != c3 " << std::endl;

    // Testando o operator==
    assert( c4 == c4 );
    // Testando o operator!=
    assert( c4 != c3 );

    // Testando a atribuicao
    c4 = c3;
    assert( c3 == c4 );


    Circle c5{ -3, 100, 100 };
    c3.set_radius( -3 );
    c3.set_center( Point2D{ 100,100 } );
    assert( c3 == c5 );


    std::cout << ">>> Area de c4 eh " << c4.area() << std::endl;
    /*
    std::cout << ">>> Circum. de c4 eh " << c4.circum() << std::endl;
    */


    return 0;
}
