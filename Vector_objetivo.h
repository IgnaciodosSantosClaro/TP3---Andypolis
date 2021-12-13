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
    int cantidad_completos = 0;

public:
    Vector_objetivo();
    Vector_objetivo operator=(const Vector_objetivo &vector_a_copiar);
    Vector_objetivo(const Vector_objetivo &vector_a_copiar);
    void agregar_objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);
    void agregar_objetivo_multiple(Objetivo_multiple &objetivo);
    estado_objetivo actualizar_por_nombre(string nombre, int cant_incremento);
    tipo_objetivo obtener_tipo_objetivo(Objetivo *objetivo);
    void actualizar_multiple(string nombre);
    void mostrar_restante();
    ~Vector_objetivo();
};

#endif