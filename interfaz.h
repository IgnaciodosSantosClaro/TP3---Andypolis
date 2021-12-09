#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Matriz_casillero.h"
#include "Diccionario.h"

enum filas_con_referencia
{
    PRIMERA_FILA,
    SEGUNDA_FILA,
    TERCERA_FILA,
    CUARTA_FILA,
    QUINTA_FILA,
};
// PRE:Recibe el color de fondo y la cadena con el nombre del tipo de terreno.
// POS:Imprime el nombre del tipo de terreno con un cuadrado del color correspondiente al lado.
void mostrar_leyenda_tipo_terreno(string color, string nombre);

// PRE: Recibe el color de fondo, de texto, el carácter que representa al material/edificio y la cadena con el nombre del tipo de material/edificio.
// POS:Imprime por pantalla la Leyenda del objeto con el símbolo que lo representa y el color de fondo del casillero.
//  donde puede existir ese objeto
void mostrar_leyenda_casillero(string color_fondo, string color_letra, char icono, string nombre);

// PRE: Recibe el vector de los edificios disponibles.
// POS: Imprime la leyenda que vincula los símbolos del mapa con el tipo de casillero/Material/Edificio.
// void mostrar_encabezado_mapa(Vector_edificio &edificios);

// PRE:Recibe la matriz de casilleros,la posición de la fila a imprimir, el ancho de cada grilla y el largo de la grilla.
// POS:Imprime la primera fila del mapa con grillas de ancho ancho grilla y altura largo_grilla.
void mostrar_fila(Matriz_casillero &mapa, int fila, int ancho_grilla, int largo_grilla);

// PRE:Recibe la matriz de casilleros, el ancho de cada grilla y el largo de la grilla.
// POS:Imprime todas las filas del mapa con grillas de tamaño ancho grillaxlargo_grilla.
void mostrar_mapa(Matriz_casillero &mapa, int ancho_grilla, int largo_grilla);

//PRE: El diccionario esta cargado.
//POS: Imprimer por pantalla la informacion de los edificios.
void listar_todos_edificios(Diccionario &dicc);
#endif