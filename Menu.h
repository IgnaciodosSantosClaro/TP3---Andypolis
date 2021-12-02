#ifndef MENU_H
#define MENU_H

#include "configuracion.h"
#include "Matriz_casillero.h"
#include "Jugador.h"
#include "Vector_material.h"
#include "Input.h"

enum opciones_iniciales {
    MODIFICAR_EDIFICIO_POR_NOMBRE = 1,
    LISTAR_TODOS_EDIFICIOS,
    MOSTRAR_MAPA,
    COMENZAR_PARTIDA,
    GUARDAR_Y_SALIR_INCIAL,
};
enum opciones_juego {
    CONSTRUIR_EDIFICIO_POR_NOMBRE = 1,
    LISTAR_EDIFICIOS_CONSTRUIDOS,
    DEMOLER_EDIFICIO_POR_COORDENADA,
    ATACAR_EDIFICIO_POR_COORDENADA,
    COMPRAR_BOMBAS,
    CONSULTAR_COORDENADA,
    MOSTAR_INVENTARIO,
    MOSTAR_OBJETIVOS,
    RECOLECTAR_RECURSOS_PRODUCIDOS,
    MOVERSE_A_UNA_COORDENADA,
    FINALIZAR_TURNO,
    GUARDAR_Y_SALIR,
};

class Menu {
private:
    Input opcion;

public:
    //Constructor
    //PRE: -
    //POS: Construye un objeto menu con opcion = 0.
    Menu();

    //PRE: -
    //POS: Imprime por pantalla el menu inicial.
    void mostrar_menu_inicio();

    //PRE: -
    //POS: Imprime por pantalla el menu de la partida.
    void mostrar_menu_juego();


};

#endif //MENU_H
