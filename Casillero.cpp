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
void Casillero::ocupar_casillero()
{
    this->esta_ocupado = true;
};
void Casillero::desocupar_casillero()
{
    this->esta_ocupado = false;
};

bool Casillero ::casillero_ocupado()
{
    return this->esta_ocupado;
};
void Casillero::fijar_energia_necesaria(int consumo)
{
    this->energia_consumida = consumo;
};
int Casillero::obtener_energia_necesaria()
{
    return this->energia_consumida;
};
Coordenada Casillero::obtener_posicion()
{
    return this->posicion;
};
