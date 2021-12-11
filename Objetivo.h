#ifndef OBJETIVO_H
#define OBJETIVO_H
#include <iostream>
using namespace std;
enum estado_objetivo
{
    OBJETIVO_COMPLETO,
    OBJETIVO_INCOMPLETO,
};

class Objetivo
{
protected:
    string nombre_objetivo;
    string descripcion;
    int cantidad_actual = 0;
    int cantidad_objetivo = 0;
    int cantidad_restante = 0;
    bool esta_completo = false;

public:
    string obtener_nombre();
    void fijar_descripcion(string descripcion);
    string obtener_descripcion();
    void mostrar();
    virtual void mostrar_restante() = 0;
    bool objetivo_completo();
    // virtual void fijar_objetivo();
    // virtual estado_objetivo actualizar_objetivo() = 0;
    // Destructor virtual
    // PRE: -
    // POS: Destruye el objeto Objetivo.
    virtual ~Objetivo() = default;
};
#endif // OBJETIVO_H