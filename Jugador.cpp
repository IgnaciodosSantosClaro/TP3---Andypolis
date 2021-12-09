#include "Jugador.h"
#include "Configuracion.h"

using namespace std;

Jugador::Jugador()
{
    this->energia = ENERGIA_INICIAL;
    this->edificios = new Diccionario;
}

int Jugador::obtener_energia()
{
    return energia;
}

void Jugador::desplazarse(int pos_x, int pos_y)
{
    this->posicion.fijar_coordenadas(pos_x, pos_y);
}

void Jugador::modificar_energia(int energia)
{
    if (this->energia += energia >= ENERGIA_MAXIMA)
    {
        this->energia = ENERGIA_MAXIMA;
    }
    else if (this->energia += energia <= ENERGIA_MINIMA)
    {
        this->energia = ENERGIA_MINIMA;
    }
    else
    {
        this->energia += energia;
    }
}

void Jugador::agregar_consumible_inventario(string nombre, int cantidad, char icono)
{
    this->inventario.agregar_material_consumible_al_final(nombre, cantidad, icono);
}

void Jugador::agregar_material_inventario(string nombre, int cantidad)
{
    this->inventario.agregar_material_al_final(nombre, cantidad);
}

void Jugador::modificar_cantidad_bomba(int cantidad)
{
    bombas.modificar_cantidad(cantidad);
}

void Jugador::mostrar_inventario()
{
    for (int i = 0; i < inventario.obtener_largo(); i++)
    {
        cout << inventario.obtener_valor(i)->obtener_nombre() << " " << inventario.obtener_valor(i)->obtener_cantidad() << endl;
    }
    cout << "Bombas: " << bombas.obtener_cantidad() << endl;
}

void Jugador::asignar_edificios(Diccionario *diccionario)
{
    this->edificios = diccionario;
}

Diccionario *Jugador::obtener_edificios()
{
    return this->edificios;
}

void Jugador::agregar_edificio(Edificio edificio)
{
    this->edificios->alta(edificio);
}

Jugador::~Jugador()
{
    delete this->edificios;
    cout << "Mori jugador" << endl;
    this->edificios = nullptr;
}