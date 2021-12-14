#ifndef MECANICAS_JUEGO_H
#define MECANICAS_JUEGO_H

#include <iostream>
#include <string>
#include "Diccionario.h"
#include "Jugador.h"
#include "configuracion.h"
#include "mensajes.h"
#include "Input.h"
#include "utiles.h"
#include "interfaz.h"
#include "animaciones.h"
#include <climits>
// Poner en minúscula el nombre del archivo

// PRE: El diccionario esta cargado
// POS: Modifica la cantidad de materiales de construccion que necesitan los edificios
void modificar_edificio(Diccionario &diccionario);

// PRE: El jugador esta cargado y no esta vacio.
// POS: Se realiza la compra de bombas en caso de tener la cantidad de andycoins suficiente.
// void comprar_bombas(Jugador &jugador);
void atacar(Matriz_casillero &mapa, Jugador *jugador);

// PRE:
// POS:
void comprar_bombas(Jugador *jugador);

// PRE: El jugador esta bien cargado.
// POS: Recolecta los recursos producidos por los edificios correspondientes.
void recolectar_recursos_producidos(Jugador *jugador);

void consultar_coordenada(Matriz_casillero &mapa);

void reparar(Matriz_casillero &mapa, Jugador *jugador);

void lluvia_recursos(Matriz_casillero &mapa);

void asignar_objetivos(Vector_objetivo &vector, Jugador *jugador, int cantidad_secundarios);

bool indice_repetido(int indice_a_revisar, Vector<int> indices);

// PRE: La Matriz_casillero, el Grafo y el Jugador estan bien cargados.
// POS: Construye un edificio.
void construir_edificio(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador);

// PRE: La Matriz_casillero, el Grafo y el Jugador estan bien cargados.
// POS: Destruye un edificio.
void demoler_edificio(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, int numero_jugador);

//PRE: mapa, grafo y jugador estan bien cargados.
//POS: Desplaza al jugador.
void desplazarse(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, int numero_jugador);

#endif // MECANICAS_JUEGO_H
