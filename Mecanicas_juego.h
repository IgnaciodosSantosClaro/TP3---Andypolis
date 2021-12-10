#ifndef MECANICAS_JUEGO_H
#define MECANICAS_JUEGO_H

#include <iostream>
#include <string>
#include "Diccionario.h"
#include "Jugador.h"
#include "Configuracion.h"
#include "Mensajes.h"
#include "Input.h"
#include "Utiles.h"
// Poner en minúscula el nombre del archivo
// PRE: El diccionario esta cargado
// POS: Modifica la cantidad de materiales de construccion que necesitan los edificios
void modificar_edificio(Diccionario &diccionario);

// PRE: El jugador esta cargado y no esta vacio.
// POS: Se realiza la compra de bombas en caso de tener la cantidad de andycoins suficiente.
// void comprar_bombas(Jugador &jugador);
void atacar(Matriz_casillero &mapa, Jugador &jugador);

#endif // MECANICAS_JUEGO_H
