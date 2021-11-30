#include "Material.h"
#include <iostream>
#include "configuracion.h"
#include "mensajes.h"

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
