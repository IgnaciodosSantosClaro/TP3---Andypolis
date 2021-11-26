#include "Casillero_inaccesible.h"
using namespace std;
Casillero_inaccesible::Casillero_inaccesible() : Casillero()
{
}
Casillero_inaccesible::Casillero_inaccesible(int posicion_x, int posicion_y, bool esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
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
void Casillero_inaccesible::mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima) // Hacer virtual puro
{
    char separador = SEPARADOR_GRILLA_MEDIA;
    cout << COLOR_CELESTE;
    if (es_ultima)
    {
        separador = SEPARADOR_GRILLA_INFERIOR;
    }
    std::cout << std::setfill(separador) << std::setw(ancho) << SEPARADOR_GRILLA_DERECHA;
    cout << COLOR_NEGRO;
};