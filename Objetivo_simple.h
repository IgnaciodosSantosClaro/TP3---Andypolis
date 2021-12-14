#ifndef OBJETIVO_SIMPLE_H
#define OBJETIVO_SIMPLE_H
#include "Objetivo.h"
#include "mensajes.h"
#include "configuracion.h"
class Objetivo_simple : public Objetivo
{
private:
    string nombre_elemento_objetivo;

public:
    //Sobrecarga operador =
    Objetivo_simple operator=(const Objetivo_simple &objetivo_a_copiar);

    //Constructor por copia
    //PRE: objetivo_a_copiar fue creado.
    //POS: Crea objeto objetivo_simple con los mismos parametros que objetivo_a_copiar.
    Objetivo_simple(const Objetivo_simple &objetivo_a_copiar);

    //Constructor por defecto
    //PRE: -
    //POS: Construye objeto Objetivo_simple.
    Objetivo_simple();

    //PRE: -
    //POS: Devuelve atributo nombre_elemento_objetivo.
    string obtener_elemento();

    //Constructor por parametro
    //PRE: -
    //POS: Crea objeto Objetivo_simple con nombre, descripcion y nombre_elemento_objetivo correspondientes a los pasados por parametro.
    Objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo);

    //Constructor por parametro
    //PRE: cant_objetivo > 0.
    //POS: Crea objeto Objetivo_simple con nombre, descripcion, nombre_elemento_objetivo y cantidad_objetivo
    // correspondientes a los pasados por parametro.
    Objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);

    //PRE: -
    //POS: Devulve la posicion en la que se encuentra el objetivo.
    int obtener_cantidad_objetivo();

    //PRE: -
    //POS: Devuelve el estado del objetivo
    estado_objetivo actualizar_objetivo(int cantidad_incremento);

    //PRE: -
    //POS: Imprime por pantalla requisitos restantes para completar el objetivo.
    void mostrar_restante();
};
#endif