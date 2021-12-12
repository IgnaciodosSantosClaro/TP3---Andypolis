#include "Material.h"

Material::Material()
{
    this->nombre_material = NOMBRE_RECURSO_POR_DEFECTO;
    this->cantidad = 0;
}

Material::Material(std::string nombre_material, int cantidad)
{
    this->nombre_material = nombre_material;
    this->cantidad = cantidad;
}
void Material::mostrar_leyenda(char icono)
{
    cout << COLOR_GRIS << ESPACIO << icono << ESPACIO << COLOR_NEGRO << ESPACIO << this->nombre_material;
}
std::string Material::obtener_nombre()
{
    return this->nombre_material;
}

int Material::obtener_cantidad()
{
    return this->cantidad;
}

void Material::fijar_nombre(std::string nombre)
{
    this->nombre_material = nombre;
}

void Material::fijar_cantidad(int cantidad)
{
    this->cantidad = cantidad;
}
void Material::reducir_cantidad(int decremento)
{
    this->cantidad -= this->cantidad - decremento;
}