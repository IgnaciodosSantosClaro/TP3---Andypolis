#ifndef OBJETIVO_MATERIAL_H
#define OBJETIVO_MATERIAL_H
#include "Objetivo.h"
#include "Material_consumible.h"
class Objetivo_material : public Objetivo
{
private:
    Material_consumible material_objetivo;
    bool es_de_inventario;
    int cantidad_actual = 0;

public:
    Objetivo_material(string nombre, string descripcion, Material_consumible material);
    void fijar_material_objetivo(Material_consumible material);
    int obtener_cantidad_objetivo();
    Material_consumible obtener_material_objetivo();
    estado_objetivo actualizar_objetivo(int cantidad_incremento);
    void mostrar();
    void mostrar_restante();
};
#endif