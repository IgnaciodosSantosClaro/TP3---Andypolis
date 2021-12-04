
#include "Matriz_casillero.h"
#include "interfaz.h"
#include "archivos.h"
#include <iostream>
#include "configuracion.h"
#include "Objetivo_material.h"
#include "Material_consumible.h"
#include "Grafo.h"
#include "ABB.h"
#include "Menu.h"

int main(void)
{
    Matriz_casillero mapa;
    /*     ifstream mapa_txt;
    if (abrir_archivo(mapa_txt, RUTA_MAPA) != EXITO)
    {
        cout << "No encontré mapa" << endl;
    } */
    Grafo grafo1;
    Grafo grafo2;
    Menu menu;
    Jugador jugador1;
    Jugador jugador2;
    ABB<int> arbol;
    arbol.insertar_nodo(5);
    arbol.insertar_nodo(2);
    arbol.insertar_nodo(7);
    arbol.insertar_nodo(3);

    arbol.imprimir_in_order();
    cout << endl;

    procesar_mapa(mapa);
    cargar_materiales(jugador1, jugador2);
    jugador1.mostrar_inventario();
    jugador2.mostrar_inventario();
    cargar_grafo(grafo1, mapa, 1);
    cargar_grafo(grafo2, mapa, 2);

//    grafo1.mostrar_grafo();
//    grafo2.mostrar_grafo();

    grafo1.usar_floyd();
    Vector<string>* caminos = grafo1.camino_minimo("(0, 0)", "(7, 8)");
    for(int i = 0; i < caminos->obtener_largo(); i++) {
        cout << caminos->obtener_valor(i) << " ";
    }
    caminos->liberar_vector();
    cout << endl;
    cout << grafo1.obtener_arista("(0, 0)", "(7, 8)") << endl;

    menu.mostrar_menu_inicio();
    menu.mostrar_menu_juego();

    mostrar_mapa(mapa, 5, 2);
    cout << mapa.obtener_dato(0, 0)->obtener_energia_necesaria()[0] << " : " << mapa.obtener_dato(0, 0)->obtener_energia_necesaria()[1] << endl;
    Material_consumible k = Material_consumible("Piedra", 100, 'Y');
    Objetivo_material objetivo_1 = Objetivo_material("Edad de piedra", DESCRIPCION_EDAD_PIEDRA, k);
    objetivo_1.mostrar();
    if (objetivo_1.actualizar_objetivo(2) == OBJETIVO_COMPLETO)
    {
        cout << "Objetivo 1 completo" << endl;
    }
    objetivo_1.mostrar_restante();

    return 0;
}