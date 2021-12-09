#ifndef UTILES_H
#define UTILES_H
#include <iostream>
#include <string>
#include "Configuracion.h"
#include "Input.h"
#include "Mensajes.h"
#include "Menu.h"
using namespace std;
// PRE:-
// POS:Es bloqueante, espera que el usuario ingrese un entero;
int obtener_opcion_ingresada();
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
bool confirmar_decision();

// PRE:
// POS:
bool validar_opcion(string opcion_elegida, Input &input, int min, int max);

// PRE:
// POS:
void confirmar_opcion_valida(string &opcion, Input &input, int min, int max);

//PRE: nombre es valido y el objeto edificio esta creado.
//POS: carga en edificio el material que otorga.
void asignar_recursos_otorgados(string nombre, Edificio &edificio);

//PRE: nombre es valido y el objeto material esta creado.
//POS: asigna a material la cantidad y el icono correspondiente.
void asignar_materiales(string nombre, Material_consumible &material);

#endif //UTILIES_H