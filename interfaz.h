#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Matriz_casillero.h"
#include "Diccionario.h"
#include "Jugador.h"
//#include <iomanip>
#include <chrono>
#include <thread>
//#include "utiles.h"
//#include "configuracion.h"

enum filas_con_referencia
{
    PRIMERA_FILA,
    SEGUNDA_FILA,
    TERCERA_FILA,
    CUARTA_FILA,
    QUINTA_FILA,
};
// PRE:Recibe el color de fondo y la cadena con el nombre del tipo de terreno.
// POS:Imprime el nombre del tipo de terreno con un cuadrado del color correspondiente al lado.
void mostrar_leyenda_tipo_terreno(string color, string nombre);

// PRE: Recibe el color de fondo, de texto, el carácter que representa al material/edificio y la cadena con el nombre del tipo de material/edificio.
// POS:Imprime por pantalla la Leyenda del objeto con el símbolo que lo representa y el color de fondo del casillero.
//  donde puede existir ese objeto
void mostrar_leyenda_casillero(string color_fondo, string color_letra, char icono, string nombre);

// PRE:Recibe la matriz de casilleros,la posición de la fila a imprimir, el ancho de cada grilla y el largo de la grilla.
// POS:Imprime la primera fila del mapa con grillas de ancho ancho grilla y altura largo_grilla.
void mostrar_fila(Matriz_casillero &mapa, int fila, int ancho_grilla, int largo_grilla);

// PRE:Recibe la matriz de casilleros, el ancho de cada grilla y el largo de la grilla.
// POS:Imprime todas las filas del mapa con grillas de tamaño ancho grillaxlargo_grilla.
void mostrar_mapa(Matriz_casillero &mapa, int ancho_grilla, int largo_grilla);

// PRE: El diccionario esta cargado.
// POS: Imprimer por pantalla la informacion de los edificios.
void listar_todos_edificios(Diccionario &dicc);

// PRE: El objeto jugador esta cargado y no esta vacio
// POS: Imprime por pantalla la informacion de los edificios construidos.
void listar_edificios_construidos(Matriz_casillero &mapa, Jugador *jugador);

// PRE: El mapa esta bien cargado y el nombre es valido.
// POS: Imprime la coordenada del edificio ubicado en el casillero correspondiente.
void mostrar_coordenadas(Matriz_casillero &mapa, string nombre_edificio);

// PRE: El jugador esta bien cargado.
// POS: Muestra el inventario del jugador.
void mostrar_inventario(Jugador *jugador);

//PRE: retardo_milisegundos > 0.
//POS: Imprime un mesaje durante retardo_milisegundos.
void imprimir_con_retardo(string mensaje, int retardo_milisegundos);

//PRE: retardo_milisegundos > 0.
//POS: Provoca un retardo de retardo_milisegundos.
void retardo(int retardo_milisegundos);

#endif