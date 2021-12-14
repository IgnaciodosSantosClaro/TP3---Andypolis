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
    //PRE:
    //POS:
    string obtener_nombre();

    //PRE: -
    //POS: Fija la descripcion del objetivo.
    void fijar_descripcion(string descripcion);

    //PRE: -
    //POS: Devuelve la descripcion del objetivo.
    string obtener_descripcion();

    //PRE: -
    //POS: Muestra el objetivo.
    void mostrar();

    virtual void mostrar_restante() = 0;

    //PRE:
    //POS:
    bool objetivo_completo();

    // Destructor virtual
    // PRE: -
    // POS: Destruye el objeto Objetivo.
    virtual ~Objetivo() = default;
};
#endif // OBJETIVO_H