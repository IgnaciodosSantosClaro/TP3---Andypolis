#ifndef MENU_H
#define MENU_H

#include "configuracion.h"
#include "Jugador.h"
#include "Matriz_casillero.h"
#include "Input.h"
#include "utiles.h"
#include "mensajes.h"
#include "archivos.h"
#include "mecanicas_juego.h"
#include "Vector_jugador.h"
#include "Vector_grafo.h"

enum opciones_iniciales
{
    INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE = 1,
    INICIO_LISTAR_TODOS_EDIFICIOS,
    INICIO_MOSTRAR_MAPA,
    INICIO_COMENZAR_PARTIDA,
    INICIO_GUARDAR_Y_SALIR_INICIAL,
    OPCION_INICIAL_INVALIDA,
};
enum opciones_juego
{
    CONSTRUIR_EDIFICIO_POR_NOMBRE = 1,
    LISTAR_EDIFICIOS_CONSTRUIDOS,
    DEMOLER_EDIFICIO_POR_COORDENADA,
    ATACAR_EDIFICIO_POR_COORDENADA,
    REPARAR_EDIFICIO_POR_COORDENADA,
    COMPRAR_BOMBAS,
    CONSULTAR_COORDENADA,
    MOSTRAR_INVENTARIO,
    MOSTRAR_OBJETIVOS,
    RECOLECTAR_RECURSOS_PRODUCIDOS,
    MOVERSE_A_UNA_COORDENADA,
    FINALIZAR_TURNO,
    GUARDAR_Y_SALIR,
    OPCION_JUEGO_INVALIDA,
};

// PRE: -
// POS:
void iniciar_juego();

// PRE: El mapa, dicc_edificios, jugador_vec y grafo_vec estan bien cargados.
// POS: Procesa la opcion elegida por el usuario.
//  Cambia indice, recibir por referencia
// bool procesar_menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, int &indice, Jugador *jugador_vec, Grafo *grafo_vec, bool &jugo_1, bool &jugo_2, bool es_partida_nueva);
bool procesar_menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, int &indice, Vector_jugador &jugadores, Vector_grafo &grafos_vec, bool &jugo_1, bool &jugo_2, bool es_partida_nueva);

// PRE: mapa, dicc_edificios, jugador1, jugador2, grafo1 y grafo2 estan bien cargados.
// POS: Muestra el menu inicial y procesa la opcion ingredasa por usuario.
void menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Vector_jugador &jugadores, Vector_grafo &grafos_vec, bool es_partida_nueva);

// PRE: mapa, dicc_edificios, jugador1, jugador2, grafo1 y grafo2 estan bien cargados.
// POS: Procesa la opcion elegida por el usuario.
bool procesar_menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Vector_jugador &jugadores, Vector_grafo &grafos_vec, bool es_partida_nueva);

// PRE:
// POS:
int obtener_opcion_ingresada();

// PRE: -
// POS: Imprime por pantalla el menu inicial.
void mostrar_menu_inicio();

// PRE: mapa, dicc_edificios, jugador1, jugador2, grafo1 y grafo2 estan bien cargados.
// POS:
void menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, Vector_jugador &jugadores, Vector_grafo &grafos_vec, bool es_partida_nuva);

// PRE: -
// POS: Imprime por pantalla el menu de la partida.
void mostrar_menu_juego();

#endif // MENU_H
