#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "ABB.h"
#include "Edificio.h"

using namespace std;

class Diccionario {

    //Atributos

    ABB<Edificio*>* arbol;

    private:


    //Metodos

    /*
    constructor
    PRE:
    POST:
    */
    Diccionario();

    /*
    PRE:
    POST:
    */
    void alta(Edificio* edificio);

    /*
    PRE:
    POST:
    */
    void baja(Edificio* edificio);

    /*
    PRE:
    POST:
    */
    bool consulta(string nombre_edificio);
    
    /*
    PRE:
    POST:
    */
    void recorrer();

    /*
    destructor
    PRE:
    POST:
    */
    ~Diccionario();

};


#endif //DICCIONARIO_H