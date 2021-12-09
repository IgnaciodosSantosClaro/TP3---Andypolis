#include "Objetivo_material.h"
Objetivo_material::Objetivo_material(string nombre, string descripcion, Material_consumible material)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
    this->material_objetivo = material;
}
Objetivo_material::Objetivo_material(string nombre, string descripcion, string nombre_material, int cantidad_objetivo)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
    this->material_objetivo.fijar_nombre(nombre_material);
    this->material_objetivo.fijar_cantidad(cantidad_objetivo);
}
void Objetivo_material::fijar_material_objetivo(Material_consumible material)
{
    this->material_objetivo = material;
};
int Objetivo_material::obtener_cantidad_objetivo()
{
    return this->material_objetivo.obtener_cantidad();
};
Material_consumible Objetivo_material::obtener_material_objetivo()
{
    return this->material_objetivo;
};
estado_objetivo Objetivo_material::actualizar_objetivo(int cantidad_incremento)
{
    int cantidad_necesaria = this->material_objetivo.obtener_cantidad();
    this->cantidad_actual += cantidad_incremento;
    if (this->cantidad_actual >= cantidad_necesaria)
    {
        return OBJETIVO_COMPLETO;
    }
    else
    {
        this->esta_completo = true;
        return OBJETIVO_INCOMPLETO;
    };
};

void Objetivo_material::mostrar_restante()
{
    int restante = this->material_objetivo.obtener_cantidad() - this->cantidad_actual;
    cout << MENSAJE_OBJETIVO_INVENTARIO_RESTANTES_P1 << restante << MENSAJE_OBJETIVO_INVENTARIO_RESTANTES_P2;
    cout << this->material_objetivo.obtener_nombre() << MENSAJE_OBJETIVO_INVENTARIO_RESTANTES_P3 << this->nombre_objetivo << endl;
};
