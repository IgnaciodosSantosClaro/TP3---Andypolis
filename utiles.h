#ifndef UTILES_H
#define UTILES_H
#include <iostream>
#include <string>
#include "configuracion.h"
#include "Input.h"
#include "mensajes.h"
#include "Vector_objetivo.h"
#include "Jugador.h"
#include "Casillero.h"
#include "Diccionario.h"
#include "Grafo.h"
using namespace std;
// PRE:-
// POS:Es bloqueante, espera que el usuario ingrese un entero;
// int obtener_opcion_ingresada();

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

bool puede_reparar(Casillero *casillero_elegido, Jugador *jugador);

bool tiene_energia(Jugador *jugador, int energia_necesaria);

// PRE: -
// POS: Imprime por pantalla el mensaje correspondiente al error.
void procesar_errores(Errores error);

// PRE: El Jugador esta bien cargado.
// POS: Devuelve el estado de la verificacion de la construccion.
Errores verificar_construccion(Jugador *jugador, string nombre_edificio);

// PRE: -
// POS: Devuelve el estado de la validacion de las coordenadas.
Errores validar_coordenadas_construccion(int coord_x, int coord_y, Matriz_casillero &mapa);

// PRE: -
// POS: Devuelve el estado de la validacion de las coordenadas.
Errores validar_coordenadas_destruccion(int coord_x, int coord_y, Matriz_casillero &mapa, int numero_jugador);

// PRE: Jugador esta bien cargado.
// POS: Devuelve un string con el color de edificio sano correspondiente al numero de jugador.
string asignar_color_edificio_sano(Jugador *jugador);

// PRE: El Grafo y la Matriz_casillero estan bien cargados.
// POS: Actualiza las aristas de un vertice.
void actualizar_aristas_grafo(Matriz_casillero &mapa, Grafo *grafo, Coordenada coordenada, int peso);

// PRE: Jugador  y mapa estan bien cargados.
// POS: Ubica al jugador en la coordenada ingresada por el usuario.
void inicializar_posicion_jugador(Matriz_casillero &mapa, Jugador *jugador);

// PRE: Jugador esta bien cargado.
// POS: Devuelve true si la energia > 0 y false en caso contrario.
bool es_turno_valido(Jugador *jugador);

//PRE: El jugadaor esta bien cargado.
//POS: Actualiza el inventario del jugador con el material pasado por parametro.
void actualizar_inventario(Jugador &jugador, Material_consumible &material);

//PRE: El jugador esta bien cargado.
//POS: Recolecta el material que se encuentra en casillero.
void recolectar_material(Casillero* casillero, Jugador &jugador);


#endif // UTILIES_H