#include "Casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable() : Casillero()
{

    this->posicion.fijar_coordenadas(0, 0);
    this->esta_ocupado = false;
    this->color_fondo = COLOR_GRIS;
    this->color_texto = COLOR_TEXTO_NEGRO;
    this->icono = ICONO_POR_DEFECTO;
};

Casillero_transitable::Casillero_transitable(int posicion_x, int posicion_y, bool esta_ocupado) : Casillero(posicion_x, posicion_y, esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
    this->color_fondo = COLOR_GRIS;
    this->color_texto = COLOR_TEXTO_NEGRO;
    this->icono = ICONO_POR_DEFECTO;
};

void Casillero_transitable::mostrar()
{
    cout << CASILLERO_TRANSITABLE_MENSAJE;
    if (!this->esta_ocupado)
    {
        cout << CASILLERO_NO_OCUPADO_MENSAJE << endl;
    }
    else
    {
        cout << CASILLERO_OCUPADO_MENSAJE << endl;
        material.mostrar_material();
    }
};

void Casillero_transitable::fijar_material(Material_consumible material)
{
    this->material = material;
    this->icono = material.obtener_nombre()[0];
};
void Casillero_transitable::ocupar_casillero(Material_consumible material)
{
    this->esta_ocupado = true;
    this->material = material;
    this->icono = material.obtener_nombre()[0];
};
Material_consumible Casillero_transitable::obtener_material()
{
    return this->material;
}