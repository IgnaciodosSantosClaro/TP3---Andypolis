#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "ABB.h"
#include "Edificio.h"

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
    POS: da de alta
    */
    void alta(Edificio edificio);

    /*
    PRE: el diccionario fue creado y no esta vacio
    POS:
    */
    void baja(Edificio edificio);

    /*
    PRE: el diccionario fue creado
    POS: devuelve true en caso de hallar una clave compatible con el nombre de diccionario pasado por parametro, y false en caso contrario
    */
    Edificio* consulta(string nombre_edificio);
    
    /*
    PRE: el diccionario fue creado
    POS: imprime por pantalla el recorrido in order del arbol
    */
    void recorrer();

    //PRE: el nombre_edificio corresponde a una clave del diccionario
    //POS: reemplaza el objeto edificio asociado a la clave nombre_edificio
    void reemplazar(Edificio* edificio);

    /*
    destructor
    PRE: el diccionario fue creado
    POS: destruye el objeto diccionario liberando la memoria del arbol
    */
    ~Diccionario();

};

#endif //DICCIONARIO_H