#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo(string nombre);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtener_siguiente();

    //post: devuelve el nombre del nodo
    string obtener_nombre();

    //post: le asigna como siguiente el nodo recibido
    void asignar_siguiente(Nodo<Tipo>* siguiente);

    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(string nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtener_siguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo<Tipo>::obtener_nombre() {
    return elemento -> obtener_nombre();
}

template<typename Tipo>
void Nodo<Tipo>::asignar_siguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
