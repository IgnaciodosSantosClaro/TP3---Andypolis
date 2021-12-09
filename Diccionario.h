#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "ABB.h"
#include "Edificio.h"
#include "Vector.h"

using namespace std;

class Diccionario {
private:
    //Atributos

    ABB<Edificio>* arbol;

public:
    //Metodos

    /*
    constructor
    PRE: -
    POS: crea una instancia de la clase diccionario
    */
    Diccionario();

    /*
    PRE: el diccionario fue creado
    POS: da de alta en el arbol la direccion de memoria del objeto edificio pasado por parametro
    */
    void alta(Edificio edificio);

    /*
    PRE: el diccionario fue creado y no esta vacio
    POS: da de baja el valor que tenga por clave al nombre_edificio pasado por parametro
    */
    void baja(string nombre_edificio);

    /*
    PRE: el diccionario fue creado
    POS: devuelve true en caso de hallar un nombre_edificio compatible con el nombre de diccionario pasado por parametro, y false en caso contrario
    */
    Edificio* consulta(string nombre_edificio);
    
    /*
    PRE: el diccionario fue creado
    POS: imprime por pantalla el recorrido in order del arbol
    */
    void recorrer();

    /*
    PRE: la nombre_edificio corresponde a una nombre_edificio del diccionario
    POS: reemplaza el valor asociado al nombre_edificio pasado por parametro liberando la memoria del dato del nodo anterior
    */
//    void reemplazar(string viejo, Edificio* edificio);

    //PRE:
    //POS: devuelve un vector que contiene los datos del ABB
    Vector<Edificio*> arbol_a_vector();

    /*
    destructor
    PRE: el diccionario fue creado
    POS: destruye el objeto diccionario liberando la memoria del arbol
    */
    ~Diccionario();

};

#endif //DICCIONARIO_H