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
// Poner en minúscula el nombre del archivo
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
void iniciar_juego();
// Cambia indice, recibir por referencia
bool procesar_menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, int &indice, Jugador *jugador_vec, bool &jugo_1, bool &jugo_2);
void menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2);
bool procesar_menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2);
int obtener_opcion_ingresada();
// PRE: -
// POS: Imprime por pantalla el menu inicial.
void mostrar_menu_inicio();
void menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2);
// PRE: -
// POS: Imprime por pantalla el menu de la partida.
void mostrar_menu_juego();

#endif // MENU_H
