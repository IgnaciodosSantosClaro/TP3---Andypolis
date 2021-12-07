#include "Diccionario.h"

Diccionario::Diccionario() {
    arbol= new ABB<Edificio>();
}

void Diccionario::alta(Edificio edificio) {
    string nombre = edificio.obtener_nombre();
    arbol->insertar_nodo(nombre, edificio);
}

void Diccionario::baja(Edificio edificio) {
    arbol->remover_nodo(edificio.obtener_nombre());
}

Edificio* Diccionario::consulta(string nombre_edificio) {
    Nodo_ABB<Edificio>* edificio_buscado = arbol->buscar(nombre_edificio);
    if(edificio_buscado == NULL) {
        return NULL;
    }
    return arbol->buscar(nombre_edificio)->obtener_dato();
}
    
void Diccionario::recorrer() {//imprime por pantalla el recorrido in order
    arbol->imprimir_in_order();
}

void Diccionario::reemplazar(Edificio* edificio) {
    arbol->buscar(edificio->obtener_nombre())->setear_dato(edificio);
}

Diccionario::~Diccionario() {
    arbol->~ABB();
}