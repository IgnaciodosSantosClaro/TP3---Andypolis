#include "Objetivo.h"
string Objetivo::obtener_nombre()
{
    return this->nombre_objetivo;
}
void Objetivo::fijar_descripcion(string descripcion)
{
    this->descripcion = descripcion;
};
string Objetivo::obtener_descripcion()
{
    return this->descripcion;
};
void Objetivo::mostrar()
{
    cout << this->nombre_objetivo << " : " << this->descripcion << endl;
};
bool Objetivo::objetivo_completo()
{
    return this->esta_completo;
};