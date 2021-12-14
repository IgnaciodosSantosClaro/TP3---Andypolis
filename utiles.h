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

// PRE: -
// POS: Pide que se ingrese un nombre.
string pedir_nombre();

// PRE: nombre es un string valido.
// POS: Devulve true si el nombre ingresado coincide con alguno de los edificios. False en caso contrario.
bool es_edificio(string nombre);

// PRE: nombre es un string valido.
// POS: Devuelve true si el nombre coincide con el del jugador1 o jugador2. False en caso contrario.
bool es_jugador(string nombre);

// PRE: max_jugadores > 1.
// POS: Devuelve la eleccion del numero de jugador que se desea emplear.
int elegir_jugador_inicial(int max_jugadores);

// PRE: -
// POS: Devuelve true si en caso de confirmar la decision. False en caso contrario.
bool confirmar_decision();

// PRE: -
// POS: Devuelve true si min <= opcion_elegida <= max. False en caso contrario.
bool validar_opcion(string opcion_elegida, Input &input, int min, int max);

// PRE: -
// POS: Imprime por pantalla si la opcion es invalida, y vuelve a pedir su ingreso.
void confirmar_opcion_valida(string &opcion, Input &input, int min, int max);

// PRE: nombre es valido y el objeto edificio esta creado.
// POS: carga en edificio el material que otorga.
void asignar_recursos_otorgados(string nombre, Edificio &edificio);

// PRE: nombre es valido y el objeto material esta creado.
// POS: asigna a material la cantidad y el icono correspondiente.
void asignar_materiales(string nombre, Material_consumible &material);

//PRE: El objeto objetivos_totales fue creado.
//POS: Carga los objetivos en el vector Vector_objetivo.
void cargar_objetivos(Vector_objetivo &objetivos_totales, int cant_maxima_escuela);

//PRE: El objeto Jugador fue creado.
//POS: Devuelve true si el jugador puede reparar el contenido de un casillero. False en caso contrario.
bool puede_reparar(Casillero *casillero_elegido, Jugador *jugador);

//PRE: energia_necesaria > 0.
//POS: Devuelve true si la energia del jugador >= energia_necesaria. False en caso contrario.
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

// PRE: El jugadaor esta bien cargado.
// POS: Actualiza el inventario del jugador con el material pasado por parametro.
void actualizar_inventario(Jugador *jugador, Material_consumible &material);

// PRE: El jugador esta bien cargado.
// POS: Recolecta el material que se encuentra en casillero.
void recolectar_material(Casillero *casillero, Jugador *jugador);
// PRE: El mapa esta bien cargado.
// POS: Devuelve un vector con las coordenadas y el nombre de los materiales.
Vector<string> *cadena_materiales(Matriz_casillero &mapa);

// PRE: El mapa esta bien cargado.
// POS: Devuelve un vector con las coordenadas y el nombre de los edificios.
Vector<string> *cadena_edificios(Matriz_casillero &mapa, int numero_jugador);
#endif // UTILIES_H