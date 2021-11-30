
#include "Matriz_casillero.h"
#include "interfaz.h"
#include "archivos.h"
#include <iostream>
#include "configuracion.h"
#include "Objetivo_material.h"
#include "Material_consumible.h"
#include "Edificio.h"
#include "Bomba.h"
int main(void)
{
    Matriz_casillero mapa;
    procesar_mapa(mapa);
    Edificio mina;
    mina = Edificio("mina", 10, 1, 2);
    Casillero_construible *construible_ptr = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(0, 3));
    construible_ptr->ocupar_casillero(mina, COLOR_EDIFICIO_SANO_JUG_1);
    Casillero_construible *vecino_construible_ptr = dynamic_cast<Casillero_construible *>(mapa.obtener_casillero_vecino(construible_ptr, ABAJO));
    vecino_construible_ptr->ocupar_casillero(mina, COLOR_EDIFICIO_SANO_JUG_2);
    mostrar_mapa(mapa, 5, 3);
    Bomba bomba_jug_1;
    bomba_jug_1.fijar_cantidad(3);
    //bomba_jug_1.tirar_bomba(*construible_ptr, COLOR_EDIFICIO_HERIDO_JUG_1);
    bomba_jug_1.tirar_bomba(*vecino_construible_ptr, COLOR_EDIFICIO_HERIDO_JUG_2); //¿Debería poder atacar sus propios edificios?
    bomba_jug_1.tirar_bomba(*vecino_construible_ptr, COLOR_EDIFICIO_HERIDO_JUG_2);
    mostrar_mapa(mapa, 5, 3);
    return 0;
}