#include "Casillero_construible.h"
using namespace std;

Casillero_construible::Casillero_construible(int posicion_x, int posicion_y, bool esta_ocupado) : Casillero(posicion_x, posicion_y, esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
    this->color_fondo = COLOR_VERDE;
    this->color_texto = COLOR_TEXTO_NEGRO;
};
Casillero_construible::Casillero_construible() : Casillero()
{
    this->posicion.fijar_coordenadas(0, 0);
    this->esta_ocupado = esta_ocupado;
    this->color_fondo = COLOR_VERDE;
    this->color_texto = COLOR_TEXTO_NEGRO;
};
void Casillero_construible::mostrar()
{
    cout << CASILLERO_CONSTRUIBLE_MENSAJE;
    if (!this->esta_ocupado)
    {
        cout << CASILLERO_NO_OCUPADO_MENSAJE << endl;
    }
    else
    {
        cout << CASILLERO_OCUPADO_MENSAJE << endl;
        edificio.mostrar_edificio();
    }
};

void Casillero_construible::fijar_edificio(Edificio edificio)
{
    this->icono = edificio.obtener_nombre()[0];
    this->edificio = edificio;
}

Edificio Casillero_construible::obtener_edificio()
{
    return this->edificio;
};
void Casillero_construible::ocupar_casillero(Edificio edificio)
{
    this->edificio = edificio;
    this->esta_ocupado = true;
    this->icono = edificio.obtener_nombre()[0];
};