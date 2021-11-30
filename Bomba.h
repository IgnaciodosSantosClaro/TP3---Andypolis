#ifndef BOMBA_H
#define BOMBA_H
#include "Material_consumible.h"
#include "Casillero_construible.h"
#include "Edificio.h"
class Bomba : public Material
{

public:
    //PRE: -
    //POS: Construye un objeto bomba con cantidad 0.
    Bomba();

    //PRE: -
    //POS: Devuelve la cantidad de bombas.
    int obtener_cantidad();

    //PRE:
    //POS:
    void tirar_bomba(Casillero_construible &casillero_objetivo, string color_texto_edificio_herido);
};

#endif //BOMBA_H
