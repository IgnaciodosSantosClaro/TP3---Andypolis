#ifndef OBJETIVO_EDIFICIO_H
#define OBJETIVO_EDIFICIO_H
#include "Objetivo.h"
#include "Edificio.h"

class Objetivo_edificio : public Objetivo
{
private:
    Edificio edificio_objetivo;
    bool es_de_inventario;
    int cantidad_actual = 0;

public:
    Objetivo_edificio();
    Objetivo_edificio(string nombre, string descripcion, Edificio &edificio);
    Objetivo_edificio(string nombre, string descripcion, string nombre_edificio, int cantidad_objetivo);
    void fijar_edificio_objetivo(Edificio &edificio);
    int obtener_cantidad_objetivo();
    Edificio obtener_edificio_objetivo();
    estado_objetivo actualizar_objetivo(int cantidad_incremento);
    void mostrar_restante();
};
#endif