#include "Diccionario.h"

Diccionario::Diccionario()
{
    arbol = new ABB<Edificio>;
}

void Diccionario::alta(Edificio edificio)
{
    string nombre = edificio.obtener_nombre();
    arbol->insertar_nodo(nombre, edificio);
}

void Diccionario::baja(string nombre_edificio)
{
    arbol->remover_nodo(nombre_edificio);
}

Edificio *Diccionario::consulta(string nombre_edificio)
{
    Nodo_ABB<Edificio> *edificio_buscado = arbol->buscar(nombre_edificio);
    if (edificio_buscado == nullptr)
    {
        return nullptr;
    }
    return arbol->buscar(nombre_edificio)->obtener_dato();
}

void Diccionario::recorrer()
{ // imprime por pantalla el recorrido in order con las claves de cada nodo del ABB
    arbol->imprimir_in_order();
}

Vector<Edificio *> Diccionario::arbol_a_vector()
{
    Vector<Edificio *> vector;
    arbol->arbol_a_vector(vector);
    return vector;
}

Diccionario::~Diccionario()
{
    delete arbol;
}