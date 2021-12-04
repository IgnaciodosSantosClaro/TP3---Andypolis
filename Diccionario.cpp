#include "Diccionario.h"

Diccionario::Diccionario() {
    ABB<Edificio*>* arbol = new ABB<Edificio*>();
}

void Diccionario::alta(Edificio* edificio) {
    string nombre = edificio->obtener_nombre();
    arbol->insertar_nodo(nombre, edificio);
}

void Diccionario::baja(Edificio* edificio) {
    arbol->remover_nodo(edificio->obtener_nombre());
}

bool Diccionario::consulta(string nombre_edificio) {
    return arbol->buscar(nombre_edificio);
}
    
void Diccionario::recorrer() {//imprime por pantalla el recorrido in order
    arbol->imprimir_in_order();
}

Diccionario::~Diccionario() {
    arbol->~ABB();
}