#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "Casillero.h"
#include "Material.h"
#include <iostream>
#include <string.h>
#include "mensajes.h"
#include "configuracion.h"
#include <iomanip>
#include "Material_consumible.h"
#include "Matriz_casillero.h"
class Casillero_transitable : public Casillero
{
private:
    Material_consumible material;

public:
    // Constructores
    // PRE:
    // POS:Inicializa el objeto en coordandas (0,0) y esta_ocupado=false
    Casillero_transitable();
    Casillero_transitable(char tipo_terreno, int posicion_x, int posicion_y, bool esta_ocupado);

    // Casillero_transitable(tipos_casillero casillero, int posicion_x, int posicion_y, bool esta_ocupado);

    // Constructor por parametros.
    // PRE:Recibe posicion en el eje x , posicion en el eje y y un booleano que indica si el casillero esta ocupado
    // POS:Inicializa la posicion del casillero y si esta ocupado =>esta_ocupado=true
    Casillero_transitable(int posicion_x, int posicion_y, bool esta_ocupado);

    // PRE: -
    // POS: Imprime por pantalla la informacion del casillero.
    void mostrar();

    // PRE: recibe el ancho de la grilla del mapa, un booleano que indica si la fila corresponde al medio
    // del casillero y un booleano que indica si la fila a imprimir es la última del casillero
    // POS: Imprime por pantalla una fila de la grilla del mapa, si es la ultima fila imprime el
    // DELIMITADOR_INFERIOR, si es la del medio entonces imprime del materiañ que ocupa esa posicion (si corresponde)
    void mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima);

    // PRE: -
    // POS: Guarda en el objeto el material que lo ocupa.
    void fijar_material(Material_consumible material);

    // PRE: Recibe un objeto edificio
    // POS: Copia el edificio recibido en el atributo de Casillero_construible y fija esta_ocupado=true
    void ocupar_casillero(Material_consumible material);

    // PRE
    // POS: Devuelve el objeto edificio alojado en Casillero_construible
    Material_consumible obtener_material();
};

#endif // CASILLERO_TRANSITABLE_H
