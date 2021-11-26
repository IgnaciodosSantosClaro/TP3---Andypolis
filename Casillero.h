#ifndef CASILLERO_H
#define CASILLERO_H
#include "Coordenada.h"
#include <iostream>
#include "Material.h"
#include "Edificio.h"
#include "configuracion.h"
using namespace std;

class Casillero
{
protected:
    int energia_consumida;
    Coordenada posicion;
    bool esta_ocupado; // constructor que lo ponga por defecto el falso?

public:
    //Constructor por defecto
    //PRE: -
    //POS: Construye un Casillero en la posicion (0,0) y fija esta_ocupado como verdadero.
    Casillero();

    //Constructor por parametros
    //PRE: -
    //POS: Construye un Casillero en la posicion (posicion_x, posicion_y)
    Casillero(int posicion_x, int posicion_y, bool esta_ocupado);

    //Metodos virtuales
    virtual void ocupar_casillero();

    //Metodos virtuales puros
    virtual void mostrar() = 0;

    virtual void mostrar_en_mapa(int ancho, bool es_primera, bool es_ultima) = 0;

    //Destructor
    virtual ~Casillero();

    // PRE: -
    // POS: Fija esta_ocupado como falso.
    void desocupar_casillero();

    // Pre:
    // POS:Devuelve el estado del casillero, si tiene un objeto en su interior devuelve true.
    bool casillero_ocupado();
    // PRE: -
    // POS: Fija energia_necesaria =consumo.
    void fijar_energia_necesaria(int consumo);
    // PRE: -
    // POS: Devuelve la energia necesaria para atravezar el casillero.
    int obtener_energia_necesaria();
    // PRE: -
    // POS: Devuelve un struct tipo ubicacion con la posicion del objeto.
    Coordenada obtener_posicion();
};
#endif