#include "Objetivo.h"

void Objetivo::fijar_descripcion(string descripcion)
{
    this->descripcion = descripcion;
};
string Objetivo::obtener_descripcion()
{
    return this->descripcion;
};