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
    POST: crea una instancia de la clase diccionario
    */
    Diccionario();

    /*
    PRE: el diccionario fue creado
    POST: da de alta 
    */
    void alta(Edificio edificio);

    /*
    PRE: el diccionario fue creado y no esta vacio
    POST:
    */
    void baja(Edificio edificio);

    /*
    PRE: el diccionario fue creado
    POST: devuelve true en caso de hallar una clave compatible con el nombre de diccionario pasado por parametro, y false en caso contrario
    */
    Edificio* consulta(string nombre_edificio);
    
    /*
    PRE: el diccionario fue creado
    POST: imprime por pantalla el recorrido in order del arbol
    */
    void recorrer();

    /*
    destructor
    PRE: el diccionario fue creado
    POST: destruye el objeto diccionario liberando la memoria del arbol
    */
    ~Diccionario();

};

#endif //DICCIONARIO_H