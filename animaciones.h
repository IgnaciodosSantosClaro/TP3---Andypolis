#ifndef ANIMACIONES_H
#define ANIMACIONES_H
#include <chrono>
#include <thread>
#include "configuracion.h"
#include <iomanip>
#include <iostream>
//#include "utiles.h"
void bombardeo(int retardo_milisegundos);
void trueno(int milisegundos_duracion, string color);
void tormenta(int cant_truenos);
void lluvia(int t_visible, int num_gotas, int t_espera);
void coordenadas_aleatorias(int limite_filas, int limite_columnas, int &fila, int &columna);
int numero_aleatorio(int limite_sup, int limite_inf);
void generar_cantidades_de_recursos(int &cantidad_metal, int &cantidad_piedra, int &cantidad_madera);
#endif