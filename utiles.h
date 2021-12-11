#ifndef UTILES_H
#define UTILES_H
#include <iostream>
#include <string>
#include "configuracion.h"
#include "Input.h"
#include "mensajes.h"
#include "menu.h"
#include "Vector_objetivo.h"
using namespace std;
// PRE:-
// POS:Es bloqueante, espera que el usuario ingrese un entero;
int obtener_opcion_ingresada();
// Modifica la entrada, recibir por referencia
void obtener_coordenadas(int &coord_x, int &coord_y, int max_x, int max_y);
// Modifica la entrada, recibir por referencia
void pedir_coordenada(int &coord_x, int &coord_y);

// PRE:Recibe una string y un caracter de separacion
// POS:Devuelve el string hasta la aparición del caracter
string separar_hasta(string cadena_a_separar, char caracter);

// PRE:
// POS:
string pedir_nombre();

// PRE:
// POS:
bool es_edificio(string nombre);

// PRE:
// POS:
bool es_jugador(string nombre);
// PRE:
// POS:
int elegir_jugador_inicial(int max_jugadores);
// PRE:
// POS:
bool confirmar_decision();

// PRE:
// POS:
bool validar_opcion(string opcion_elegida, Input &input, int min, int max);

// PRE:
// POS:
void confirmar_opcion_valida(string &opcion, Input &input, int min, int max);

// PRE: nombre es valido y el objeto edificio esta creado.
// POS: carga en edificio el material que otorga.
void asignar_recursos_otorgados(string nombre, Edificio &edificio);

// PRE: nombre es valido y el objeto material esta creado.
// POS: asigna a material la cantidad y el icono correspondiente.
void asignar_materiales(string nombre, Material_consumible &material);
void cargar_objetivos(Vector_objetivo &objetivos_totales, int cant_maxima_escuela);
#endif // UTILIES_H