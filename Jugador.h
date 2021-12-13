#ifndef JUGADOR_H
#define JUGADOR_H
#include "Coordenada.h"
#include "Objetivo.h"
#include "Vector_material.h"
#include "Bomba.h"
#include "Diccionario.h"
#include "configuracion.h"
#include "Vector_objetivo.h"
class Jugador
{
private:
    string nombre;
    int energia;
    tipo_jugador identidad_jugador;
    Coordenada posicion;
    Vector_objetivo *objetivos_secundarios;
    Objetivo_simple *objetivo_principal;
    Vector_material *inventario;
    Bomba bombas;
    Diccionario *edificios;

public:
    // Constructor
    // PRE: -
    // POS: Construye objeto jugador con energia = 50.
    Jugador(const Jugador &jugador_copiar);
    Jugador operator=(const Jugador &jugador_copiar);
    Jugador();
    Jugador(string nombre, tipo_jugador identidad);

    // PRE: -
    // POS: Devuelve la energia del jugador
    int obtener_energia();

    string obtener_nombre();

    Bomba obtener_bombas();
    tipo_jugador obtener_identidad();
    void fijar_bombas(Bomba bombas);

    // PRE: Recibe una energia que es un numero entero.
    // POS: La energia del jugador se suma a la energia pasada por parametro.
    void modificar_energia(int energia);

    // PRE: Las posiciones pos_x, pos_y son enteras y validas.
    // POS: La posicion actual del jugador pasa a ser pos_x, pos_y.
    void desplazarse(int pos_x, int pos_y);

    // PRE:
    // POS:
    bool es_ganador();

    // PRE:
    // POS:
    void asignar_objetivo_principal(Objetivo *objetivo);

    // PRE:
    // POS:
    void asignar_objetivo_secundario(Objetivo *objetivo);

    // PRE: EL diccionario esta bien cargado.
    // POS: Asigna el diccionario al diccionario del jugador.
    void asignar_edificios(Diccionario *diccionario);

    // PRE: -
    // POS: Devuelve el puntero a diccionario edificios.
    Diccionario *obtener_edificios();
    void mostrar_objetivos_restantes();
    estado_objetivo actualizar_objetivos(string nombre, int cant_incremento);
    // PRE: -
    // POS: Devuelve el inventario del jugador.
    Vector_material *obtener_inventario();

    // PRE:
    // POS:
    bool objetivo_principal_completado(Objetivo *objetivo_principal);

    // PRE:
    // POS:
    bool objetivo_secundario_completado(Objetivo *objetivo_secundario);

    // PRE:
    // POS:
    void agregar_consumible_inventario(string nombre, int cantidad, char icono);

    // PRE:
    // POS:
    void agregar_material_inventario(string nombre, int cantidad);

    // PRE: Cantidad es un numero entero.
    // POS: Modifica la cantidad de bombas que tiene el jugador.
    void modificar_cantidad_bomba(int cantidad);

    // PRE:
    // POS:
    //    void mostrar_inventario();

    // PRE:
    // POS:
    void agregar_edificio(Edificio edificio);

    ~Jugador();
};
#endif // JUGADOR_H