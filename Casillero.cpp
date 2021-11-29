#include "Casillero.h"
Casillero::Casillero()
{
    this->esta_ocupado = false;
}
Casillero::Casillero(int posicion_x, int posicion_y, bool esta_ocupado)
{
    this->esta_ocupado = esta_ocupado;
    this->posicion.fijar_coordenadas(posicion_x, posicion_y);
}
Casillero::~Casillero()
{
}
//void Casillero::()
void Casillero::ocupar_casillero()
{
    this->esta_ocupado = true;
    this->icono = ICONO_OCUPADO_POR_DEFECTO;
    //this->energia_necesaria = MAX_ENERGIA + 1;
};
void Casillero::habitar_casillero()
{
    this->esta_habitado = true;
    this->esta_ocupado = true;
    this->icono = ICONO_JUGADOR;
};
void Casillero::deshabitar_casillero()
{
    this->esta_habitado = false;
    this->esta_habitado = false;
    this->icono = ICONO_POR_DEFECTO;
};
void Casillero::desocupar_casillero()
{
    this->esta_ocupado = false;
    //this->energia_necesaria = volver a valores viejos;
};
void Casillero::fijar_color_fondo(string color)
{
    this->color_fondo = color;
};
void Casillero::fijar_color_texto(string color)
{
    this->color_texto = color;
};
void Casillero::fijar_icono(char icono)
{
    this->icono = icono;
};
void Casillero::mostrar_en_mapa(int ancho, bool es_medio, bool es_ultima)
{
    char separador = SEPARADOR_GRILLA_MEDIA;
    cout << this->color_fondo;
    if (es_ultima)
    {
        separador = SEPARADOR_GRILLA_INFERIOR;
    };
    if (this->esta_ocupado && es_medio)
    {
        int mitad = (int)ancho / 2;
        cout << setfill(ESPACIO) << std::setw(mitad - 1) << ESPACIO;
        cout << this->color_texto << icono << COLOR_TEXTO_BLANCO << setfill(ESPACIO) << std::setw(mitad + 1);
    }
    else
    {
        std::cout << std::setfill(separador) << std::setw(ancho);
    }
    cout << SEPARADOR_GRILLA_DERECHA;
    cout << COLOR_NEGRO;
};
bool Casillero ::casillero_ocupado()
{
    return this->esta_ocupado;
};
bool Casillero ::casillero_habitado()
{
    return this->esta_habitado;
};
void Casillero::fijar_energia_necesaria(int energia_jugador_1, int energia_jugador_2)
{
    this->energia_necesaria[0] = energia_jugador_1;
    this->energia_necesaria[1] = energia_jugador_2;
};
int *Casillero::obtener_energia_necesaria()
{
    return this->energia_necesaria;
};
Coordenada Casillero::obtener_posicion()
{
    return this->posicion;
};
