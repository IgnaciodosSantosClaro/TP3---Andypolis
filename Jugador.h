#ifndef JUGADOR_H
#define JUGADOR_H

#include "Coordenada.h"
#include "Objetivo.h"
#include "Vector_material.h"

class Jugador
{
private:
    int energia;
    Coordenada posicion;
    Objetivo* objetivos_secundarios;
    Objetivo* objetivo_principal;
    Vector_material inventario;

public:
    //Constructor
    //PRE: -
    //POS: Construye objeto jugador con energia = 50.
    Jugador();

    //PRE: -
    //POS: Devuelve la energia del jugador.
    int obtener_energia();

    //PRE: Recibe una energia que es un numero entero.
    //POS: La energia del jugador se suma a la energia pasada por parametro.
    void modificar_energia(int energia);

    //PRE: Las posiciones pos_x, pos_y son enteras y validas.
    //POS: La posicion actual del jugador pasa a ser pos_x, pos_y.
    void desplazarse(int pos_x, int pos_y);

    //PRE:
    //POS:
    bool es_ganador();

    //PRE:
    //POS:
    void asignar_objetivo_principal();

    //PRE:
    //POS:
    void asignar_objetivo_secundario();

    //PRE:
    //POS:
    bool objetivo_principal_completado(Objetivo* objetivo_principal);

    //PRE:
    //POS:
    bool objetivo_secundario_completado(Objetivo* objetivo_secundario);

};
#endif //JUGADOR_H