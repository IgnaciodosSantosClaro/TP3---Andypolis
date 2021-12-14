#include "Jugador.h"

using namespace std;

Jugador::Jugador()
{
    cout << "cree jugador " << this->obtener_nombre() << endl;
    this->energia = ENERGIA_INICIAL;
    this->edificios = new Diccionario;
    this->inventario = new Vector_material;
    this->objetivo_principal = new Objetivo_simple;
    this->objetivos_secundarios = new Vector_objetivo;
}

Jugador::Jugador(string nombre, tipo_jugador identidad)
{
    this->nombre = nombre;
    this->identidad_jugador = identidad;
    this->energia = ENERGIA_INICIAL;
    this->edificios = new Diccionario;
    this->inventario = new Vector_material;
    this->objetivo_principal = new Objetivo_simple;
    this->objetivos_secundarios = new Vector_objetivo;
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
Coordenada Jugador::obtener_posicion()
{
    return this->posicion;
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

void Jugador::asignar_objetivo_principal(Objetivo *objetivo)
{
    Objetivo_simple *objetivo_ptr = dynamic_cast<Objetivo_simple *>(objetivo);
    *this->objetivo_principal = *objetivo_ptr;
}
void Jugador::asignar_objetivo_secundario(Objetivo *objetivo)
{
    this->objetivos_secundarios->agregar_objetivo_al_final(objetivo);
}
void Jugador::asignar_edificios(Diccionario *diccionario)
{
    this->edificios = diccionario;
}
void Jugador::mostrar_objetivos_restantes()
{
    this->objetivo_principal->mostrar_restante();
    this->objetivos_secundarios->mostrar_restante();
}
bool Jugador::cumplio_objetivos()
{
    bool completo = false;
    if (this->objetivo_principal->objetivo_completo())
    {
        completo = true;
    }
    else if (this->objetivos_secundarios->obtener_cantidad_completos() == CANTIDAD_OBJETIVOS_SECUNDARIOS_POR_JUGADOR)
    {
        completo = true;
    }
    return completo;
}
bool Jugador::actualizar_objetivos(string elemento, int cant_incremento)
{
    bool gano = false;
    estado_objetivo objetivos_completos = OBJETIVO_INCOMPLETO;
    if (nombre.compare(ELEMENTO_OBJETIVO_PRINCIPAL) == 0)
    {

        objetivos_completos = this->objetivo_principal->actualizar_objetivo(cant_incremento);
    }
    else
    {
        objetivos_completos = this->objetivos_secundarios->actualizar_por_elemento(nombre, cant_incremento);
    }
    if (objetivos_completos == OBJETIVO_COMPLETO)
    {
        gano = true;
    }
    return gano;
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
    delete this->objetivo_principal;
    delete this->objetivos_secundarios;

    this->edificios = nullptr;
    this->inventario = nullptr;
    this->objetivo_principal = nullptr;
    this->objetivos_secundarios = nullptr;
}
Vector_objetivo *Jugador::obtener_objetivos()
{
    return this->objetivos_secundarios;
}