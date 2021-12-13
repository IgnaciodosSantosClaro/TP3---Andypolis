#ifndef VECTOR_JUGADOR_H
#define VECTOR_JUGADOR_H

#include "Vector.h"
#include "Jugador.h"
#include <iostream>
#include <iomanip>
#include "errores.h"

class Vector_jugador : public Vector<Jugador *>
{
public:
    // constructor
    // PRE: -
    // POS: Construye un Vector_jugador.
    Vector_jugador();

    // Destructor
    // PRE: -
    // POS: Libera los espacios de memoria que contengan a un elemento Jugador o Jugador_casillero.
    ~Vector_jugador();

    // PRE: El nombre del jugador debe ser valido y pertenecer al vector de jugadores.
    // POS: Devuelve el objeto jugador.
    int obtener_pos_jugador(std::string nombre);

    // PRE: El nombre del jugador debe ser valido y pertenecer al vector de jugadores.
    // POS: Devuelve el objeto jugador.
    Jugador obtener_por_nombre(std::string nombre);

    // PRE: Recibe el nombre del jugador y una cantidad entera y positiva.
    // POS: Reserva memoria y agrega un objeto Jugador al vector Vector_jugador inicializandolo con la cantidad indicada.
    void agregar_jugador_al_final(std::string nombre_jugador, tipo_jugador identidad);
};

#endif // VECTOR_JUGADOR_H