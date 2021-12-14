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
    //Constructor por defecto
    //PRE: -
    //POS: Construye vector_objetivo
    Vector_objetivo();

    //Sobrecarga operador =
    Vector_objetivo operator=(const Vector_objetivo &vector_a_copiar);

    //Constructor por copia
    //PRE: -
    //POS: Construye vector_objetivo con los mismos atributos que vector_a_copiar.
    Vector_objetivo(const Vector_objetivo &vector_a_copiar);

    //PRE: cantidad_objetivos > 0
    //POS: Agrega un objetivo
    void agregar_objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo);

    //PRE: -
    //POS: Agrega objetivo multiple
    void agregar_objetivo_multiple(Objetivo_multiple &objetivo);

    //PRE: -
    //POS: Devuelve estado del objetivo
    estado_objetivo actualizar_por_elemento(string elemento, int cant_incremento);

    //PRE: -
    //POS: Devuelve estado del objetivo
    estado_objetivo actualizar_por_nombre(string nombre, int cant_incremento);

    //PRE: -
    //POS: Devuelve estado del objetivo
    tipo_objetivo obtener_tipo_objetivo(Objetivo *objetivo);

    //PRE: -
    //POS: Devuelve la cantidad de objetivos completados.
    int obtener_cantidad_completos();

    //PRE: -
    //POS: Actualiza objetivo
    void actualizar_multiple(string nombre);

    //PRE: -
    //POS: Imprime por pantalla requisitos restantes para completar objetivo.
    void mostrar_restante();

    //PRE: objetivo no es nullptr
    //POS: Agrega un objetivo al final del arreglo.
    void agregar_objetivo_al_final(Objetivo *objetivo);

    //Destructor
    ~Vector_objetivo();
};

#endif