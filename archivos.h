#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
#include "errores.h"
#include "Vector_material.h"
#include "Vector_jugador.h"
#include "utiles.h"
#include "Diccionario.h"
#include "Coordenada.h"
#include "Matriz_casillero.h"
#include <cstring>
#include "configuracion.h"
#include "mensajes.h"
#include "Material_consumible.h"
#include "Vector_grafo.h"
#include <cctype>

Errores abrir_archivo(std::ifstream &archivo, std::string path);

// PRE: Recibe dos objetos Jugador.
// POS: Carga el inventario de los jugadores con el contenido de materiales.txt
void cargar_materiales(Jugador *jugador1, Jugador *jugador2);

// PRE: Recibe un Vector de edificios no nulo
// POS: Carga el vector con el contenido de edificios.txt
void procesar_edificios(Diccionario &dicc, Vector_jugador &jugadores);

// PRE: Recibe un objeto matriz casillero
// POS: Porcesa el contenido de mapa.txt y asigna a cada casillero un objeto casillero correspondiente
void procesar_mapa(Matriz_casillero &mapa);

// PRE:Recibe vectores de edificios (luego de procesar_edificios) y matriz de casilleros (luego de procesar_mapa)
// POS: Carga la matriz con los casille
void procesar_ubicaciones(Matriz_casillero &mapa, Vector_jugador &jugadores, Vector_grafo &grafos, bool &es_vacio);

// PRE: Recibe un objeto Grafo y un mapa bien cargado.
// POS: Carga el grafo con los casilleros como vertices y las energias como aristas.
void cargar_grafo(Grafo *grafo, Matriz_casillero &mapa, int num_jugador);

// PRE: mapa, jugadores y diccionario estan bien cargados.
// POS: Actualiza los archivos de materiales, edificios y ubicaciones.
void guardar_y_salir(Matriz_casillero &mapa, Vector_jugador &jugadores, Diccionario &diccionario);

// PRE: jugadores esta bien cargado.
// POS: Actualiza el archivo de materiales. Si no existe lo crea.
void actualizar_archivo_materiales(Vector_jugador &jugadores);

// POS: mapa y jugadores estan bien cargados.
// POS: Actualiza el archivo de materiales. Si no existe lo crea.
void actualizar_archivo_ubicaciones(Matriz_casillero &mapa, Vector_jugador &jugadores);

// PRE: El diccionario esta bien cargado.
// POS: Actualiza el archivo de edificios. Si no existe lo crea.
void actualizar_archivo_edificios(Diccionario &diccionario);

//PRE: mapa y jugadores estan bien cargados.
//POS: Actualiza los archivos de materiales, edificios y ubicaciones.
void guardar_y_salir(Matriz_casillero &mapa, Vector_jugador &jugadores, Diccionario &diccionario);

//PRE: jugadores esta bien cargado.
//POS: Actualiza el archivo de materiales. Si no existe lo crea.
void actualizar_archivo_materiales(Vector_jugador &jugadores);

//POS: mapa y jugadores estan bien cargados.
//POS: Actualiza el archivo de materiales. Si no existe lo crea.
void actualizar_archivo_ubicaciones(Matriz_casillero &mapa, Vector_jugador &jugadores);

#endif // ARCHIVO_H