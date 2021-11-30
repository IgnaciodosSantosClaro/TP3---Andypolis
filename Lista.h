#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template < typename Tipo >
class Lista{

private:
    int cantidad_de_elementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

public:
    Lista();

    //PRE: -
    //POS: devuelve la cantidad de elementos que tiene la lista
    int obtener_cantidad_de_elementos();

    //PRE: -
    //POS: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(string nombre);

    //PRE: -
    //POS: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtener_nombre(int posicion);

    //PRE: -
    //POS: agrega un nuevo elemento a la lista
    void agregar(string nuevo_elemento);

    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidad_de_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtener_cantidad_de_elementos() {
    return cantidad_de_elementos;
}

template < typename Tipo >
int Lista<Tipo>::obtener_posicion(string nombre) {
    bool elemento_encontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(!elemento_encontrado && i < cantidad_de_elementos){
        if(auxiliar -> obtener_nombre() == nombre){
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elemento_encontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(string nuevo_elemento) {
    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(nuevo_elemento);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad_de_elementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista<Tipo>::obtener_nombre(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_de_elementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

#endif //GRAFOS_LISTA_H
