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
    bool es_de_inventario;

public:
    Objetivo_multiple();
    Objetivo_multiple(string nombre_objetivo_multiple, string descripcion, Objetivo_simple &objetivo);
    Objetivo_multiple(string nombre_objetivo_multiple, string descripcion);
    void agregar_objetivo_simple(Objetivo_simple &objetivo_nuevo);
    void agregar_objetivo_simple(string nombre_objetivo_simple, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);
    int buscar_por_nombre(string nombre);
    int obtener_cantidad_objetivo(string nombre);
    estado_objetivo actualizar_objetivo(string nombre_objetivo_simple, int cantidad_incremento);
    estado_objetivo actualizar_objetivo_multiple();
    void mostrar_restante();
};
#endif