
#include "Matriz_casillero.h"
#include "Interfaz.h"

int main(void)
{
    Matriz_casillero mapa;
    mapa.agrandar_matriz(2, 2);
    Casillero *vecino;
    mapa.agregar_casillero(CASILLERO_TRANSITABLE, 0, 0, false);
    mapa.agregar_casillero(CASILLERO_CONSTRUIBLE, 1, 0, false);
    mapa.agregar_casillero(CASILLERO_INACCESIBLE, 0, 1, false);
    mapa.agregar_casillero(CASILLERO_CONSTRUIBLE, 1, 1, true);

    vecino = mapa.obtener_casillero_vecino(mapa.obtener_dato(0, 0), DERECHA);
    vecino = mapa.obtener_casillero_vecino(vecino, ABAJO);
    vecino->habitar_casillero();
    vecino->obtener_posicion().mostrar();
    mostrar_mapa(mapa, 5, 3);
}