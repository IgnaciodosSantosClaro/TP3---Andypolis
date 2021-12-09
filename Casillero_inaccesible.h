#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "Casillero.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "Configuracion.h"
#include "Mensajes.h"
class Casillero_inaccesible : public Casillero
{
public:
    Casillero_inaccesible();
    //Constructor
    //PRE: -
    //POS: Construye un Casillero_inaccesible de coordenadas (coord_x, coord_y) y estado esta_ocupado.
    Casillero_inaccesible(int posicion_x, int posicion_y, bool esta_ocupado);

    //PRE: -
    //POS: Imprime por pantalla la informacion del casillero.
    void mostrar();

    //PRE: recibe el ancho de la grilla del mapa, un booleano que indica si la fila corresponde al medio
    //del casillero y un booleano que indica si la fila a imprimir es la última del casillero
    //POS: Imprime por pantalla una fila de la grilla del mapa, si es la fila ultima fila imprime el
    //DELIMITADOR_INFERIOR.
    void mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima);
};

#endif //CASILLERO_INACCESIBLE_H#include <iostream>
