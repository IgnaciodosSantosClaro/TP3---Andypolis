#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include "Material.h"
#include <iostream>
#include "Material_consumible.h"
#include "configuracion.h"

#include "mensajes.h"
using namespace std;
enum tipo_jugador
{
    JUGADOR_1 = 1,
    JUGADOR_2,
    NO_ASIGNADO
};
enum estado_edificio
{
    EDIFICIO_DESTRUIDO = 0,
    EDIFICIO_LASTIMADO,
    EDIFICIO_SANO,
};
enum posicion_materiales
{
    POSICION_PIEDRA = 0,
    POSICION_MADERA,
    POSICION_METAL,
};
class Edificio
{
private:
    std::string nombre_edificio;
    tipo_jugador jugador_dueno = NO_ASIGNADO;
    int cant_max;
    int cant_construidos;
    int salud;
    Material_consumible materiales_construccion[MAX_MATERIALES_CONSTRUIBLES];
    Material_consumible recursos_producidos;

public:
    // Constructor por defecto
    // PRE: -
    // POS: Construye un objeto Edificio de nombre default, cantidad maxima nula, recursos producidos nulos y materiales nulos.
    Edificio();

    // Constructor por parametros
    // PRE:
    // POS:
    Edificio(string nombre_edificio, int puntos_salud);

    // Constructor por parametros
    // PRE: -
    // POS: Construye edificio de nombre nombre_edificio, cantidad maxima cant_max cantidad construida cant_construidos
    // y salud puntos_salud.
    Edificio(string nombre_Edificio, int cant_max, int cantidad_contruidos, int puntos_salud);

    // Constructor por parametros
    // PRE:
    // POS:
    Edificio(string nombre_edificio, int cant_max, Material_consumible materiales_construccion[MAX_MATERIALES_CONSTRUIBLES]);
    void fijar_nombre(string nombre_edificio);
    // PRE: cant_construidos debe ser mayor o igual que cero.
    // POS: Actualiza el atributo cant_construidos.
    void modificar_cant_construidos(int cant_construidos);

    // PRE:
    // POS:
    void mostrar_leyenda(char icono);

    // PRE:
    // POS:
    void fijar_dueno(tipo_jugador jugador_dueno);
    tipo_jugador obtener_dueno();

    // PRE: salud >= 0
    // POS: Fija la salud del edificio.
    void fijar_puntos_de_salud(int salud);

    // PRE: -
    // POS:
    estado_edificio atacar_edificio();

    // PRE: -
    // POS: Devuelve el nombre del edificio.
    string obtener_nombre();

    // PRE: -
    // POS: Devuelve la cantidad maxima permitida de edificios.
    int obtener_cant_max();

    // PRE: -
    // POS: Devuelve la cantidad de edificios contruidos.
    int obtener_cant_construidos();

    // PRE: -
    // POS: Devuelve la salud del edificio.
    int obtener_salud();

    // PRE: La posicion esta entre 0 y 2.
    // POS: Devuelve el objeto material ubicado en la posicion pasada como paramentro del vector materiales.
    Material_consumible obtener_material(int posicion);

    // PRE: -
    // POS: Devuelve el objeto correspondiente a los materiales que otorga el edificio.
    Material_consumible obtener_materiales_otorgados();

    // PRE:
    // POS:
    void fijar_material_constuible(int cantidad, int posicion);

    // PRE: -
    // POS: Incrementa en una unidad la cantidad de construcciones de un edificio.
    void incrementar_construcciones();

    // PRE: -
    // POS: Decrementa en una unidad la cantidad de construcciones de un edificio.
    void decrementar_construcciones();

    // PRE: -
    // POS: Imprime por pantalla la informacion del Edificio.
    void mostrar_edificio();

    // PRE: La cantidad es un entero positivo.
    // POS: Asigna el nombre y la cantidad a recursos_producidos
    void fijar_recurso_producido(string nombre, int cantidad);
};

#endif // EDIFICIO_H
