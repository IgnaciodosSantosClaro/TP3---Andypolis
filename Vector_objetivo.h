#ifndef VECTOR_OBJETIVO_H
#define VECTOR_OBJETIVO_H
#include "Vector.h"
#include "Objetivo.h"
#include "Objetivo_simple.h"
#include "Objetivo_multiple.h"
enum tipo_objetivo
{
    OBJETIVO_SIMPLE,
    OBJETIVO_MULTIPLE,
    OBJETIVO_NO_RECONOCIDO,
};
class Vector_objetivo : public Vector<Objetivo *>
{
    int pos_objetivo_principal;

public:
    void agregar_objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);
    void agregar_objetivo_multiple(Objetivo_multiple &objetivo);
    void actualizar_por_nombre(string nombre, int cant_incremento);
    tipo_objetivo obtener_tipo_objetivo(Objetivo *objetivo);
    void actualizar_multiple(string nombre);
    void mostrar_restante();
    ~Vector_objetivo();
};

#endif