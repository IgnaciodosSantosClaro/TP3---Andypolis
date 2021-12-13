#ifndef MATRIZ_CASILLERO_H
#define MATRIZ_CASILLERO_H

#include "Matriz.h"
#include "Casillero.h"
#include "Casillero_construible.h"
#include "Casillero_transitable.h"
#include "Casillero_inaccesible.h"
#include "mensajes.h"
enum tipos_casillero
{
    CASILLERO_CONSTRUIBLE,
    CASILLERO_TRANSITABLE,
    CASILLERO_LAGO,
    CASILLERO_BETUN,
    CASILLERO_MUELLE,
    CASILLERO_INACCESIBLE,
};
enum direcciones
{
    ARRIBA,
    ABAJO,
    DERECHA,
    IZQUIERDA,
};
class Matriz_casillero : public Matriz<Casillero *>
{
private:
    int cantidad_construibles;
    int cantidad_transitables;
    int cantidad_inaccesibles;

public:
    // Constructor
    Matriz_casillero();

    // Destructor
    //PRE:
    //POS: Elimina todas las posiciones de la matriz en las que se agrego un casillero.
    ~Matriz_casillero();

    //PRE:
    //POS:devuelve la cantidad de casilleros transitables.
    int obtener_cant_transitables();

    //PRE: -
    //POS:devuelve la cantidad de casilleros inaccesibles.
    int obtener_cant_inaccesibles();

    //PRE: -
    //POS:devuelve la cantidad de casilleros construibles.
    int obtener_cant_construibles();

    //PRE:Recible la cantidad de casilleros contruibles.
    //POS:establece la cantidad de casilleros construibles.
    void fijar_cant_construibles(int cantidad);

    //PRE:Recible la cantidad de casilleros transitables.
    //POS:establece la cantidad de casilleros transitables.
    void fijar_cant_transitables(int cantidad);

    //PRE:Recible la cantidad de casilleros inaccesibles.
    //POS:establece la cantidad de casilleros inaccesibles.
    void fijar_cant_inaccesibles(int cantidad);

    //PRE:Recibe un elemento de tipos_casillero, una fila , una columna y un booleano que indica si el casillero
    // está ocupado.
    //POS: Pide posición para un casillero del tipo casillero_elegido y lo ubica en la fila y columna indicada.
    void agregar_casillero(tipos_casillero casillero_elegido, int fila, int columna, bool esta_ocupado);

    //PRE:Recibe un caracter con el tipo de terreno (igual al de mapa.txt), una fila , una columna y un booleano que indica si el casillero
    // está ocupado.
    //POS: Pide posición para un casillero del tipo casillero_elegido y lo ubica en la fila y columna indicada.
    void agregar_casillero(const char tipo_terreno, int fila, int columna, bool esta_ocupado);

    //PRE:Recibe una fila y columna válidas.
    //POS:Devuelve un elemento de tipos_casillero indicando de que tipo es el casillero consultado.
    tipos_casillero obtener_tipo_casillero(int fila, int columna);

    //PRE:Recibe un casillero dentro de la matriz de casilleros y una dirección donde buscar el vecino
    //POS:Devuelve el dato vecino, si el vecino no es alcanzable devuelve NULL
    Casillero *obtener_casillero_vecino(Casillero *casillero_actual, direcciones direccion_vecino);
};

#endif