#ifndef BOMBA_H
#define BOMBA_H

#include "Material_consumible.h"
#include "Casillero_construible.h"
#include "Edificio.h"
#include "animaciones.h"
#include <chrono>
#include <thread>

class Bomba : public Material
{

public:
    // PRE: -
    // POS: Construye un objeto bomba con cantidad 0.
    Bomba();

    // PRE: -
    // POS: Devuelve la cantidad de bombas.
    int obtener_cantidad();

    // PRE: Cantidad es un numero entero.
    // POS: Modifica la cantidad de bombas.
    void modificar_cantidad(int cantidad);

    // PRE:
    // POS:
    void tirar_bomba(Casillero_construible &casillero_objetivo);
};

#endif // BOMBA_H
