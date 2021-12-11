#ifndef OBJETIVO_SIMPLE_H
#define OBJETIVO_SIMPLE_H
#include "Objetivo.h"
#include "Mensajes.h"
#include "Configuracion.h"
class Objetivo_simple : public Objetivo
{
private:
    string nombre_elemento_objetivo;
    bool es_de_inventario;

public:
    Objetivo_simple();
    Objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo);
    Objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);
    int obtener_cantidad_objetivo();
    estado_objetivo actualizar_objetivo(int cantidad_incremento);
    void mostrar_restante();
};
#endif