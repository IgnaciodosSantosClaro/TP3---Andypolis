#ifndef OBJETIVO_EDIFICIO_MULTIPLE_H
#define OBJETIVO_EDIFICIO_MULTIPLE_H
#include "Objetivo.h"
#include "Objetivo_edificio.h"
#include "Vector.h"

class Objetivo_edificio_multiple : public Objetivo
{
private:
    Vector<Objetivo_edificio> vector_objetivos;
    bool es_de_inventario;

public:
    Objetivo_edificio_multiple(string nombre, string descripcion, Objetivo_edificio objetivo);
    Objetivo_edificio_multiple(string nombre, string descripcion);
    void agregar_objetivo_edificio(Objetivo_edificio &edificio);
    void agregar_objetivo_edificio(string nombre_objetivo, string descripcion, string nombre_edificio, int cantidad_objetivo);
    int buscar_por_nombre(string nombre);
    int obtener_cantidad_objetivo(string nombre);
    estado_objetivo actualizar_objetivo(string nombre_edificio, int cantidad_incremento);
    estado_objetivo actualizar_objetivo_multiple();
    void mostrar_restante();
};
#endif