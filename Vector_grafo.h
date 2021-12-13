#ifndef VECTOR_GRAFO_H
#define VECTOR_GRAFO_H

#include "Vector.h"
#include "Grafo.h"
#include <iostream>
#include <iomanip>
#include "errores.h"

class Vector_grafo : public Vector<Grafo *>
{
public:
    // constructor
    // PRE: -
    // POS: Construye un Vector_grafo.
    Vector_grafo();

    // Destructor
    // PRE: -
    // POS: Libera los espacios de memoria que contengan a un elemento Grafo o Grafo_casillero.
    ~Vector_grafo();

    // PRE: Recibe el nombre del grafo y una cantidad entera y positiva.
    // POS: Reserva memoria y agrega un objeto Grafo al vector Vector_grafo inicializandolo con la cantidad indicada.
    void agregar_grafo_al_final();
};

#endif // VECTOR_JUGADOR_H