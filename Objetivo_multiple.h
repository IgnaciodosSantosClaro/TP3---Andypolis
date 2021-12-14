#ifndef OBJETIVO_MULTIPLE_H
#define OBJETIVO_MULTIPLE_H
#include "Objetivo.h"
#include "Objetivo_simple.h"
#include "Vector.h"
#include "mensajes.h"
class Objetivo_multiple : public Objetivo
{
private:
    Vector<Objetivo_simple> vector_objetivos;

public:
    //Constructor por parametros
    //PRE: objetivo_a_copiar fue creado.
    //POS: Crea objeto objetivo_multiple con los mismos parametros que objetivo_a_copiar.
    Objetivo_multiple(const Objetivo_multiple &objetivo_a_copiar);

    //Sobrecarga operador =
    Objetivo_multiple operator=(const Objetivo_multiple &objetivo_a_copiar);

    //Constructor por defecto
    //PRE: -
    //POS: Construye objeto Objetivo_multiple
    Objetivo_multiple();

    //Constructor por parametros
    //PRE: -
    //POS: Crea objetivo_multiple de nombre nombre_objetivo_multiple, con una descripcion y un objetivo simple.
    Objetivo_multiple(string nombre_objetivo_multiple, string descripcion, Objetivo_simple &objetivo);

    //Constructor por parametros
    //PRE: -
    //POS: Crea objetivo_multiple de nombre nombre_objetivo_multiple y con una descripcion.
    Objetivo_multiple(string nombre_objetivo_multiple, string descripcion);

    //PRE: objetivo_nuevo no esta vacio.
    //POS: Agrega objetivo simple.
    void agregar_objetivo_simple(Objetivo_simple &objetivo_nuevo);

    //PRE: -
    //POS: agrega objetivo simple con los elementos recibidos por parametro.
    void agregar_objetivo_simple(string nombre_objetivo_simple, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);

    //PRE: -
    //POS: Devulve la posicion en la que se encuentra el objetivo.
    int obtener_cantidad_objetivo(string nombre);

    //PRE: -
    //POS: Devuelve la posicion en la que se encuentra el objetivo con nombre pasado por parametro.
    int buscar_por_nombre(string nombre);

    //PRE: cant_incremento > 0
    //POS: Devuelve el estado del objetivo.
    estado_objetivo actualizar_por_elemento(string elemento, int cant_incremento);

    //PRE: cant_incremento > 0
    //POS: Devuelve el estado del objetivo.
    estado_objetivo actualizar_objetivo(string nombre_objetivo_simple, int cantidad_incremento);

    //PRE: -
    //POS: Devuelve el estado del objetivo.
    estado_objetivo actualizar_objetivo_multiple();

    //PRE: -
    //POS: Imprime por pantalla requisitos restantes para completar el objetivo.
    void mostrar_restante();
};
#endif