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

// PRE: El diccionario esta cargado
// POS: Modifica la cantidad de materiales de construccion que necesitan los edificios
void modificar_edificio(Diccionario &diccionario);

// PRE: El jugador esta cargado y no esta vacio.
// POS: Se realiza la compra de bombas en caso de tener la cantidad de andycoins suficiente.
void atacar(Matriz_casillero &mapa, Jugador *jugador);

// PRE: jugador no es nullptr.
// POS: Compra bombas.
void comprar_bombas(Jugador *jugador, bool &gano);

// PRE: jugador no es nullptr.
// POS: Recolecta los recursos producidos por los edificios correspondientes.
void recolectar_recursos_producidos(Jugador *jugador);

// PRE: jugador no es nullptr.
// POS: Devuelve true si se completo un objetivo. False en caso contrario.
bool verificar_objetivos_inventario(Jugador *jugador);

// PRE: Mapa esta bien cargado.
// POS: Imprime por pantalla el contenido de las coordenadas.
void consultar_coordenada(Matriz_casillero &mapa);

// PRE: jugador no es nullptr y mapa esta bien cargado.
// POS: Repara un edificio.
void reparar(Matriz_casillero &mapa, Jugador *jugador);

// PRE: Mapa esta bien cargado.
// POS: Se generan aleatoriamente sobre el mapa conjuntos de materiales.
void lluvia_recursos(Matriz_casillero &mapa);

// PRE: jugador no es nullptr, vector esta bien cargado y cantidad_secundarios > 0.
// POS: Asigna objetivos al jugador.
void asignar_objetivos(Vector_objetivo &vector, Jugador *jugador, int cantidad_secundarios);

// PRE: indice_a_revisar >= 0.
// POS: Devuelve true si un indice esta repetido. False en caso contrario.
bool indice_repetido(int indice_a_revisar, Vector<int> indices);

// PRE: La Matriz_casillero, el Grafo y el Jugador estan bien cargados.
// POS: Construye un edificio.
void construir_edificio(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, bool &gano);

// PRE: La Matriz_casillero, el Grafo y el Jugador estan bien cargados.
// POS: Destruye un edificio.
void demoler_edificio(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, int numero_jugador);

// PRE: mapa, grafo y jugador estan bien cargados.
// POS: Desplaza al jugador.
void desplazarse(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, int numero_jugador);

#endif // MECANICAS_JUEGO_H
