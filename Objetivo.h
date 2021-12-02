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
    bool esta_completo;

public:
    void fijar_descripcion(string descripcion);
    string obtener_descripcion();
    virtual void mostrar() = 0;
    //virtual void fijar_objetivo();
    //virtual estado_objetivo actualizar_objetivo() = 0;
};
#endif //OBJETIVO_H