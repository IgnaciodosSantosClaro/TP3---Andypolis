#include "Vector_material.h"

using namespace std;

Vector_material::Vector_material(){};
Vector_material::~Vector_material()
{
    cout << "Mori material" << endl;
    for (int posicion = 0; posicion < this->obtener_largo(); posicion++)
    {
        delete obtener_valor(posicion);
    }
};
void Vector_material::agregar_material_consumible_al_final(std::string nombre_material, int cantidad, char icono)
{

    Material_consumible *puntero = new Material_consumible(nombre_material, cantidad, icono);
    this->agregar_al_final(puntero);
}
void Vector_material::agregar_material_al_final(std::string nombre_material, int cantidad)
{
    Material *puntero = new Material(nombre_material, cantidad);
    this->agregar_al_final(puntero);
}
int Vector_material::obtener_pos_material(string nombre)
{
    int posicion = ERROR_NOMBRE_MATERIAL;

    for (int i = 0; i < largo_actual; i++)
    {
        if (datos[i]->obtener_nombre().compare(nombre) == 0)
        {
            posicion = i;
        }
    };
    return posicion;
};
Material* Vector_material::obtener_por_nombre(string nombre)
{
    return this->obtener_valor(this->obtener_pos_material(nombre));
}