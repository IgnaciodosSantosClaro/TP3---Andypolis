#include "Casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable() : Casillero()
{

    this->posicion.fijar_coordenadas(0, 0);
    this->esta_ocupado = false;
    this->color_fondo = COLOR_GRIS;
    this->color_texto = COLOR_TEXTO_BLANCO;
    this->icono = ICONO_POR_DEFECTO;
};
Casillero_transitable::Casillero_transitable(char tipo_terreno, int posicion_x, int posicion_y, bool esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
    this->color_texto = COLOR_TEXTO_BLANCO;
    switch (tipo_terreno)
    {
    case TERRENO_BETUN:
        this->fijar_energia_necesaria(CONSUMO_ENERGIA_BETUN_JUGADOR_1, CONSUMO_ENERGIA_BETUN_JUGADOR_2);
        this->color_fondo = COLOR_GRIS_OSCURO;
        break;
    case TERRENO_MUELLE:
        this->fijar_energia_necesaria(CONSUMO_ENERGIA_MUELLE_JUGADOR_1, CONSUMO_ENERGIA_MUELLE_JUGADOR_2);
        this->color_fondo = COLOR_MARRON;
        break;
    default:
        this->fijar_energia_necesaria(CONSUMO_ENERGIA_CAMINO_JUGADOR_1, CONSUMO_ENERGIA_CAMINO_JUGADOR_2);
        this->color_fondo = COLOR_GRIS;
        break;
    }
};
/* Casillero_transitable::Casillero_transitable(tipos_casillero casillero, int posicion_x, int posicion_y, bool esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
    switch (casillero)
    {
    case CASILLERO_BETUN:
        this->fijar_energia_necesaria(CONSUMO_ENERGIA_BETUN_JUGADOR_1, CONSUMO_ENERGIA_BETUN_JUGADOR_2);
        this->color_fondo = COLOR_GRIS_OSCURO;
        break;
    case CASILLERO_MUELLE:
        this->fijar_energia_necesaria(CONSUMO_ENERGIA_MUELLE_JUGADOR_1, CONSUMO_ENERGIA_MUELLE_JUGADOR_2);
        this->color_fondo = COLOR_MARRON;
        break;
    default:
        this->fijar_energia_necesaria(CONSUMO_ENERGIA_CAMINO_JUGADOR_1, CONSUMO_ENERGIA_CAMINO_JUGADOR_2);
        this->color_fondo = COLOR_GRIS;
        break;
    }
}; */
Casillero_transitable::Casillero_transitable(int posicion_x, int posicion_y, bool esta_ocupado) : Casillero(posicion_x, posicion_y, esta_ocupado)
{
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
    this->esta_ocupado = esta_ocupado;
    this->color_fondo = COLOR_GRIS;
    this->color_texto = COLOR_TEXTO_BLANCO;
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
    this->icono = material.obtener_icono();
};
void Casillero_transitable::ocupar_casillero(Material_consumible material)
{
    this->esta_ocupado = true;
    this->material = material;
    this->icono = material.obtener_icono();
};
Material_consumible Casillero_transitable::obtener_material()
{
    return this->material;
}