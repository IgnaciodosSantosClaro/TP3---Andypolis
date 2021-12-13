#include "Diccionario.h"

Diccionario::Diccionario()
{
    cout << "cree diccionario" << endl;
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

// void Diccionario::reemplazar(string viejo, Edificio* edificio) {
//     Nodo_ABB<Edificio>* aux = arbol->buscar(viejo);
//     aux->~Nodo_ABB(); //borro la memoria que ocupaba el dato viejo
//     aux->setear_dato(edificio); //establezco el dato nuevo
//     aux->setear_clave(edificio->obtener_nombre()); //establezco la clave nueva para el nodo
//     arbol->buscar(viejo)->~Nodo_ABB();
//     arbol->buscar(viejo)->setear_dato(edificio);
// }

Vector<Edificio *> Diccionario::arbol_a_vector()
{
    Vector<Edificio *> vector;
    arbol->arbol_a_vector(vector);
    return vector;
}

Diccionario::~Diccionario()
{
    // arbol->~ABB();
    cout << "Elimine Diccionario" << endl;
    delete arbol;
}