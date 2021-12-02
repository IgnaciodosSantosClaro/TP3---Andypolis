#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H


#include "CaminoMinimo.h"

class Dijkstra : public Camino_minimo{
//Atributos
private:
    bool * vertices_visitados;
    int * distancia;
    int * recorrido;

//Métodos
    //PRE: -
    //POS: pone todos los valores del vector de verticesVisitados en "false" menos el origen
    void inicializar_visitados(int origen);

    //PRE: -
    //POS: pone las distancias exactamente igual que la distanciaOrigen
    void inicializar_distancia(const int * distancia_origen);

    //PRE: -
    //POS: llena el vector de recorrido con el origen
    void inicializar_recorrido(int origen);

    //PRE: -
    //POS: devuelve el número de vértice con menor distancia al origen
    int vertice_minima_distancia();

    //PRE: -
    //POS: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizar_distancia(int vertice);

    //PRE: para que tenga sentido, debe ejecutarse un recorrido previamente
    //POS: muestra por pantalla el resultado del recorrido.
    void mostrar_recorrido(int origen, int destino);

    //PRE: -
    //POS: muestra el estado instantaneo del vector de recorrido, distancia y visitados.
    void mostrar_iteracion(int iteracion);
public:
    Dijkstra(Lista<Vertice> * vertices, int ** matriz_adyacencia);

    //PRE: -
    //POS: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void camino_minimo(int origen, int destino) override;

    ~Dijkstra() override;

};


#endif //GRAFOS_DIJKSTRA_H
