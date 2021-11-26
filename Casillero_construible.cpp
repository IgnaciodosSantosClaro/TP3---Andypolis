#include "Casillero_construible.h"
using namespace std;

Casillero_construible::Casillero_construible(int posicion_x, int posicion_y, bool esta_ocupado) : Casillero(posicion_x, posicion_y, esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
};
Casillero_construible::Casillero_construible() : Casillero()
{
    this->posicion.fijar_coordenadas(0, 0);
    this->esta_ocupado = esta_ocupado;
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
    this->edificio = edificio;
}
void Casillero_construible::mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima) // Hacer virtual puro
{
    char separador = SEPARADOR_GRILLA_MEDIA;
    cout << COLOR_VERDE;
    if (es_ultima)
    {
        separador = SEPARADOR_GRILLA_INFERIOR;
    };
    if (this->esta_ocupado && es_medio)
    {
        char primera_letra_edificio = this->obtener_edificio().obtener_nombre()[0];
        int mitad = (int)ancho / 2;
        cout << setfill(ESPACIO) << std::setw(mitad - 1) << ESPACIO;
        cout << COLOR_TEXTO_VERDE << (char)toupper(primera_letra_edificio) << COLOR_TEXTO_BLANCO << setfill(ESPACIO) << std::setw(mitad + 1);
    }
    else
    {
        std::cout << std::setfill(separador) << std::setw(ancho);
    }
    cout << SEPARADOR_GRILLA_DERECHA;
    cout << COLOR_NEGRO;
};
Edificio Casillero_construible::obtener_edificio()
{
    return this->edificio;
};
void Casillero_construible::ocupar_casillero(Edificio edificio)
{
    this->edificio = edificio;
    this->esta_ocupado = true;
};