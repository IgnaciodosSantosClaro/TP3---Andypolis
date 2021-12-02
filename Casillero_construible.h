#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H
#include "Casillero_construible.h"
#include <iostream>
#include "mensajes.h"
#include "configuracion.h"
#include "Casillero.h"
#include "Edificio.h"
#include <iomanip>
class Casillero_construible : public Casillero
{
private:
    Edificio edificio;

public:
    //Constructores
    //PRE:
    //POS:Inicializa el objeto en coordandas (0,0) y esta_ocupado=false
    Casillero_construible();

    //PRE:Recibe posicion en el eje x , posicion en el eje y y un booleano que indica si el casillero esta ocupado
    //POS:Inicializa la posicion del casillero y si esta ocupado =>esta_ocupado=true
    Casillero_construible(int posicion_x, int posicion_y, bool esta_ocupado, string color_texto);
    Casillero_construible(int posicion_x, int posicion_y, bool esta_ocupado);
    //PRE: -
    //POS: Imprime por pantalla la informacion del casillero.
    void mostrar();

    //PRE: recibe el ancho de la grilla del mapa, un booleano que indica si la fila corresponde al medio
    //del casillero y un booleano que indica si la fila a imprimir es la última del casillero
    //POS: Imprime por pantalla una fila de la grilla del mapa, si es la ultima fila imprime el
    //DELIMITADOR_INFERIOR, si es la del medio entonces imprime del edificio que ocupa esa posicion (si corresponde)
    void mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima);

    //PRE: -
    //POS: Guarda en el casillero un edificio.
    void fijar_edificio(Edificio &edificio);

    //PRE: -
    //POS: Devuelve el objeto edificio alojado en Casillero_construible
    Edificio obtener_edificio();

    //PRE: Recibe un objeto edificio
    //POS: Copia el edificio recibido en el atributo de Casillero_construible y fija esta_ocupado=true
    void ocupar_casillero(Edificio edificio, string color_estado_edificio);
    void desocupar_casillero();
};

#endif //CASILLERO_CONSTRUIBLE_H
