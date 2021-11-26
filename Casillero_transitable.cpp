#include "Casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable() : Casillero()
{

    this->posicion.fijar_coordenadas(0, 0);
    this->esta_ocupado = false;
};

Casillero_transitable::Casillero_transitable(int posicion_x, int posicion_y, bool esta_ocupado) : Casillero(posicion_x, posicion_y, esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
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
void Casillero_transitable::mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima) // Hacer virtual puro
{
    char separador = SEPARADOR_GRILLA_MEDIA;
    cout << COLOR_GRIS;
    if (es_ultima)
    {
        separador = SEPARADOR_GRILLA_INFERIOR;
    };
    if (this->esta_ocupado && es_medio)
    {
        int mitad = (int)ancho / 2;
        cout << setfill(ESPACIO) << std::setw(mitad - 1) << ESPACIO;
        cout << COLOR_TEXTO_NEGRO << this->obtener_material().obtener_icono() << COLOR_TEXTO_BLANCO << setfill(ESPACIO) << std::setw(mitad + 1);
    }
    else
    {
        std::cout << std::setfill(separador) << std::setw(ancho);
    }
    cout << SEPARADOR_GRILLA_DERECHA;
    cout << COLOR_NEGRO;
};

void Casillero_transitable::fijar_material(Material_de_construccion material)
{
    this->material = material;
};
void Casillero_transitable::ocupar_casillero(Material_de_construccion material)
{
    this->esta_ocupado = true;
    this->material = material;
};
Material_de_construccion Casillero_transitable::obtener_material()
{
    return this->material;
}