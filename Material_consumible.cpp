#include "Material_consumible.h"
using namespace std;
Material_consumible::Material_consumible()
{
    this->nombre_material = NOMBRE_RECURSO_POR_DEFECTO;
    this->cantidad = 0;
    this->icono_en_mapa = ICONO_RECURSO_POR_DEFECTO;
}
Material_consumible::Material_consumible(std::string nombre_material, int cantidad, char icono)
{
    this->nombre_material = nombre_material;
    this->cantidad = cantidad;
    this->icono_en_mapa = icono;
}
void Material_consumible::mostrar_material()
{
    std::cout << "Soy un/a " << this->nombre_material << CASILLERO_CONSULTADO << std::endl;
}
char Material_consumible::obtener_icono()
{
    return this->icono_en_mapa;
}
void Material_consumible::fijar_icono(char icono)
{
    this->icono_en_mapa = icono;
}
