#include "Jugador.h"

using namespace std;

Jugador::Jugador()
{
    this->energia = ENERGIA_INICIAL;
    this->edificios = new Diccionario;
    this->inventario = new Vector_material;
}
Jugador::Jugador(string nombre, tipo_jugador identidad)
{
    this->nombre = nombre;
    this->identidad_jugador = identidad;
    this->energia = ENERGIA_INICIAL;
    this->edificios = new Diccionario;
    this->inventario = new Vector_material;
}
tipo_jugador Jugador::obtener_identidad()
{
    return this->identidad_jugador;
}
int Jugador::obtener_energia()
{
    return energia;
}
string Jugador::obtener_nombre()
{
    return nombre;
}
Bomba Jugador::obtener_bombas()
{
    return this->bombas;
}
void Jugador::fijar_bombas(Bomba bombas)
{
    this->bombas = bombas;
}
void Jugador::desplazarse(int pos_x, int pos_y)
{
    this->posicion.fijar_coordenadas(pos_x, pos_y);
}

void Jugador::modificar_energia(int energia)
{
    if (this->energia + energia >= ENERGIA_MAXIMA)
    {
        this->energia = ENERGIA_MAXIMA;
    }
    else if (this->energia - energia <= ENERGIA_MINIMA)
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
    this->inventario->agregar_material_consumible_al_final(nombre, cantidad, icono);
}

void Jugador::agregar_material_inventario(string nombre, int cantidad)
{
    this->inventario->agregar_material_al_final(nombre, cantidad);
}

void Jugador::modificar_cantidad_bomba(int cantidad)
{
    bombas.modificar_cantidad(cantidad);
}

// void Jugador::mostrar_inventario()
//{
//     for (int i = 0; i < inventario->obtener_largo(); i++)
//     {
//         cout << inventario->obtener_valor(i)->obtener_nombre() << " " << inventario->obtener_valor(i)->obtener_cantidad() << endl;
//     }
//     cout << "Bombas: " << bombas.obtener_cantidad() << endl;
// }
void Jugador::asignar_objetivo_principal(Objetivo *objetivo)
{
    Objetivo_simple *objetivo_ptr = dynamic_cast<Objetivo_simple *>(objetivo);
    this->objetivo_principal = *objetivo_ptr;
}
void Jugador::asignar_objetivo_secundario(Objetivo *objetivo)
{
    this->objetivos_secundarios.agregar_al_final(objetivo);
}
void Jugador::asignar_edificios(Diccionario *diccionario)
{
    this->edificios = diccionario;
}
void Jugador::mostrar_objetivos_restantes()
{
    this->objetivo_principal.mostrar_restante();
    this->objetivos_secundarios.mostrar_restante();
}
estado_objetivo Jugador::actualizar_objetivos(string nombre, int cant_incremento)
{
    estado_objetivo objetivos_completos = OBJETIVO_INCOMPLETO;
    if (nombre.compare(NOMBRE_OBJETIVO_PRINCIPAL) == 0)
    {

        objetivos_completos = this->objetivo_principal.actualizar_objetivo(cant_incremento);
    }
    else
    {
        objetivos_completos = this->objetivos_secundarios.actualizar_por_nombre(nombre, cant_incremento);
    }
    return objetivos_completos;
}
Diccionario *Jugador::obtener_edificios()
{
    return this->edificios;
}

void Jugador::agregar_edificio(Edificio edificio)
{
    this->edificios->alta(edificio);
}

Vector_material *Jugador::obtener_inventario()
{
    return this->inventario;
}

Jugador::~Jugador()
{
    delete this->edificios;
    delete this->inventario;
    cout << "Mori jugador" << endl;
    this->edificios = nullptr;
    this->inventario = nullptr;
}
