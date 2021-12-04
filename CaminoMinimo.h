#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Vector.h"
#include <iostream>

const int INFINITO = 99999999;

class Camino_minimo {
//Atributos
protected:
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    int cantidad_vertices;
    Vector<string>* camino_recorrido;

//Métodos
public:
    Camino_minimo(Lista<Vertice> * vertices, int** matriz_adyacencia);

    //POS: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual Vector<string>* camino_minimo(int origen, int destino) = 0;

    //POS: devuelve el peso de la arista que une el vertice origen con el vertice destino.
    virtual int obtener_arista(int origen, int destino) = 0;

    virtual ~Camino_minimo() = default;
};


#endif //GRAFOS_CAMINOMINIMO_H
