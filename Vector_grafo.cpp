#include "Vector_grafo.h"

using namespace std;

Vector_grafo::Vector_grafo() {};
Vector_grafo::~Vector_grafo()
{
    for (int posicion = 0; posicion < this->obtener_largo(); posicion++)
    {
        delete obtener_valor(posicion);
    }
};
void Vector_grafo::agregar_grafo_al_final()
{
    Grafo *puntero = new Grafo();
    this->agregar_al_final(puntero);
}
