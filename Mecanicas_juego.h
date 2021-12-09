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

//PRE: El diccionario esta cargado
//POS: Modifica la cantidad de materiales de construccion que necesitan los edificios
void modificar_edificio(Diccionario &diccionario);

#endif //MECANICAS_JUEGO_H
