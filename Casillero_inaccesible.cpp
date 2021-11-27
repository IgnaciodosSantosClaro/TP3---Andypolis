#include "Casillero_inaccesible.h"
using namespace std;
Casillero_inaccesible::Casillero_inaccesible() : Casillero()
{
    this->color_fondo = COLOR_CELESTE;
    this->color_texto = COLOR_TEXTO_NEGRO;
    this->icono = ICONO_POR_DEFECTO;
}
Casillero_inaccesible::Casillero_inaccesible(int posicion_x, int posicion_y, bool esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->color_fondo = COLOR_CELESTE;
    this->color_texto = COLOR_TEXTO_NEGRO;
    this->icono = ICONO_POR_DEFECTO;
}

void Casillero_inaccesible::mostrar()
{
    cout << CASILLERO_INACCESIBLE_MENSAJE;
    if (!this->esta_ocupado)
    {
        cout << CASILLERO_NO_OCUPADO_MENSAJE << endl;
    }
    else
    {
        cout << CASILLERO_OCUPADO_MENSAJE << endl;
    }
}
