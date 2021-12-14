#ifndef ANIMACIONES_H
#define ANIMACIONES_H
#include <chrono>
#include <thread>
#include "configuracion.h"
#include <iomanip>
#include <iostream>

//PRE: milisegundos_retardo > 0.
//POS: Imprime por pantalla colores.
void bombardeo(int milisegundos_retardo);

//PRE: milisegundos_duracion > 0.
//POS: Imprime por pantalla un trueno.
void trueno(int milisegundos_duracion, string color);

//PRE: cant_truenos > 0.
//POS: Imprimer por pantalla lluvia y truenos.
void tormenta(int cant_truenos);

//PRE: t_visible > 0, num_gotas > 0, t_espera > 0.
//POS: Imprime por pantalla lluvia.
void lluvia(int t_visible, int num_gotas, int t_espera);

//PRE: limite_filas > 0, limite_columnas > 0, fila > 0, columna > 0.
//POS: Guarda en fila y columna coordenadas aleatorias.
void coordenadas_aleatorias(int limite_filas, int limite_columnas, int &fila, int &columna);

//PRE: -
//POS: Devuelve un numero aleatorio.
int numero_aleatorio(int limite_sup, int limite_inf);

//PRE: cantidad_metal > 0, cantidad_piedra > 0, cantidad_madera > 0, cantidad_andycoins > 0.
//POS: Guarda en las variables pasadas por parametro un numero aleatorio.
void generar_cantidades_de_recursos(int &cantidad_metal, int &cantidad_piedra, int &cantidad_madera, int &cantidad_andycoins);

#endif //ANIMACIONES_H