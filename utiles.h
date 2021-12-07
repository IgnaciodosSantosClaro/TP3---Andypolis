#ifndef UTILES_H
#define UTILES_H
#include <iostream>
#include <string>
#include "configuracion.h"
#include "Input.h"

using namespace std;

//PRE:
//POS:
string separar_hasta(string cadena_a_separar, char caracter);

//PRE:
//POS:
string pedir_nombre();

//PRE:
//POS:
bool es_edificio(string nombre);

//PRE:
//POS:
bool es_jugador(string nombre);

//PRE:
//POS:
bool confirmar_decision();

//PRE:
//POS:
bool validar_opcion(string opcion_elegida, Input &input, int min, int max);

//PRE:
//POS:
void confirmar_opcion_valida(string &opcion, Input &input, int min, int max);

#endif //UTILIES_H