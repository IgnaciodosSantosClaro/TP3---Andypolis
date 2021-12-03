#include "Diccionario.h"

Diccionario::Diccionario() {
    ABB<Edificio*>* arbol = new ABB();
}

void Diccionario::alta(Edificio* edificio) {
    arbol->insertar_nodo(edificio);
}

void Diccionario::baja(Edificio* edificio) {
    arbol->remover_nodo(edificio);
}

bool Diccionario::consulta(string nombre_edificio) {
    return arbol->buscar(nombre_edificio);
}
    
void Diccionario::recorrer() {//imprime por pantalla el recorrido in order
    arbol->imprimir_in_oder();
}

Diccionario::~Diccionario() {
    arbol->~ABB();
}