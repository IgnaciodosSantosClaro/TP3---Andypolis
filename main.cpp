
#include "Matriz_casillero.h"
#include "Interfaz.h"
#include "Archivos.h"
#include <iostream>
#include "Configuracion.h"
#include "Objetivo_material.h"
#include "Material_consumible.h"
#include "Grafo.h"
#include "ABB.h"
#include "Menu.h"
#include "Mecanicas_juego.h"

int main(void)
{
    Matriz_casillero mapa;
    Grafo grafo1;
    Grafo grafo2;
    Jugador jugador1;
    Jugador jugador2;
    //    ABB<int> arbol;
    Diccionario diccionario;

    procesar_mapa(mapa);
    cargar_materiales(jugador1, jugador2);
    cout << "aca" << endl;
    procesar_edificios(diccionario, jugador1, jugador2);
    procesar_ubicaciones(mapa, jugador1, jugador2);
    cout << "aca2" << endl;
    listar_todos_edificios(diccionario);
    comprar_bombas(jugador2);
    mostrar_mapa(mapa, 5, 3);

    return 0;
};