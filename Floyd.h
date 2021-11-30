#ifndef GRAFOS_FLOYD_H
#define GRAFOS_FLOYD_H
#include "CaminoMinimo.h"

using namespace std;

class Floyd : public Camino_minimo{
private:
    int ** matriz_costos;
    int ** matriz_caminos;

    //pre: requiere una matriz de adyacencia bien cargada
    //post: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int ** crear_matriz_costos(int ** matriz_adyacencia);

    //post: crea una matriz de caminos
    int ** crear_matriz_caminos();

    //post: libera la memoria de las matrices de costos y caminos
    void liberar_matrices();

    //post: muestra la matriz de costo y de caminos.
    void mostrar_matrices();

    //post:calcula las matrices de costos y caminos.
    void calcular_matrices();

public:
    Floyd(Lista<Vertice> *vertices, int ** matriz_adyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void camino_minimo(int origen, int destino) override;

    ~Floyd() override;
};


#endif //GRAFOS_FLOYD_H
