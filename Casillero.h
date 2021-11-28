#ifndef CASILLERO_H
#define CASILLERO_H
#include "Coordenada.h"
#include <iostream>
#include "Material.h"
#include "Edificio.h"
#include "configuracion.h"
#include <iomanip>
using namespace std;

class Casillero
{
protected:
    int energia_necesaria;
    Coordenada posicion;
    bool esta_ocupado;
    bool esta_habitado;
    char icono = ' ';
    string color_fondo = COLOR_GRIS;
    string color_texto = COLOR_TEXTO_NEGRO;

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
    //PRE: -
    //POS: fija esta_ocupado como true
    virtual void ocupar_casillero();
    //PRE: -
    //POS: fija esta_habitado y esta_ocupado como true
    virtual void habitar_casillero();
    //PRE: -
    //POS: fija esta_habitado y esta_ocupado como false
    virtual void deshabitar_casillero();
    //Metodos virtuales puros
    virtual void mostrar() = 0;

    void mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima);

    //Destructor
    virtual ~Casillero();

    // PRE: -
    // POS: Fija esta_ocupado como falso.
    void desocupar_casillero();
    // PRE: Recibe una cadena con un Color de fondo
    // POS: fija color_fondo =color
    void fijar_color_fondo(string color);
    // PRE: Recibe una cadena con un Color de fondo
    // POS: fija color_texto =color
    void fijar_color_texto(string color);
    // PRE: Recibe un caracter
    // POS: fija icono=icono
    void fijar_icono(char icono);
    // Pre:
    // POS:Devuelve el estado del casillero, si tiene un objeto en su interior devuelve true.
    bool casillero_ocupado();
    // Pre:
    // POS:Devuelve el estado del casillero, si tiene un jugador en su interior devuelve true.
    bool casillero_habitado();
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