
#include "Matriz_casillero.h"
#include "interfaz.h"
#include "archivos.h"
#include <iostream>
#include "configuracion.h"
#include "Objetivo_material.h"
#include "Material_consumible.h"
int main(void)
{
    Matriz_casillero mapa;
    /*     ifstream mapa_txt;
    if (abrir_archivo(mapa_txt, RUTA_MAPA) != EXITO)
    {
        cout << "No encontré mapa" << endl;
    } */
    procesar_mapa(mapa);
    mostrar_mapa(mapa, 5, 3);
    cout << mapa.obtener_dato(0, 0)->obtener_energia_necesaria()[0] << " : " << mapa.obtener_dato(0, 0)->obtener_energia_necesaria()[1] << endl;
    Material_consumible k = Material_consumible("Piedra", 100, 'Y');
    Objetivo_material objetivo_1 = Objetivo_material("Edad de piedra", DESCRIPCION_EDAD_PIEDRA, k);
    objetivo_1.mostrar();
    if (objetivo_1.actualizar_objetivo(2) == OBJETIVO_COMPLETO)
    {
        cout << "Objetivo 1 completo" << endl;
    }
    objetivo_1.mostrar_restante();

    return 0;
}