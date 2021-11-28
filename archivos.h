#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
#include "errores.h"
#include "Vector_material.h"
//#include "Vector_edificio.h" ->implementar como arbol
#include "Coordenada.h"
#include "Matriz_casillero.h"
#include <cstring>
#include "configuracion.h"
#include "mensajes.h"
#include "Material_consumible.h"
Errores abrir_archivo(std::ifstream &archivo, std::string path);
//PRE: Recibe un Vector de materiales no nulo
//POS: Carga ese vector con el contenido de materiales.txt
void cargar_materiales(Vector_material &materiales);

//PRE: Recibe un Vector de edificios no nulo
//POS: Carga el vector con el contenido de edificios.txt
//void procesar_edificios(Vector_edificio &edificios);

//PRE: Recibe un objeto matriz casillero
//POS: Porcesa el contenido de mapa.txt y asigna a cada casillero un objeto casillero correspondiente
void procesar_mapa(Matriz_casillero &mapa);

//PRE:Recibe vectores de edificios (luego de procesar_edificios) y matriz de casilleros (luego de procesar_mapa)
//POS: Carga la matriz con los casille
//void procesar_ubicaciones(Vector_edificio &edificios, Matriz_casillero &mapa);

//PRE: Vector materiales bien cargado.
//POS: Actualiza el archivo de materiales. Si no existe lo crea.
void actualizar_archivo_materiales(Vector_material &materiales);

//PRE: Vector edificios bien cargado.
//POS: Actualiza el archivo de edificios. Si no esxiste lo crea.
//void actualizar_archivo_edificios(Vector_edificio &edificios);

//PRE: Matriz de casilleros bien cargada.
//POS: Actualiza el archivo de ubicaciones.
void actualizar_archivo_ubicaciones(Matriz_casillero &mapa);

//PRE: -
//POS: Actualiza los archivos de materiales, edificios y ubicaciones.
//void guardar_y_salir(Vector_edificio &edificios, Vector_material &materiales, Matriz_casillero &mapa);

#endif