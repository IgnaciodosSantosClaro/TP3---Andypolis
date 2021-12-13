#include "Vector_objetivo.h"
Vector_objetivo::~Vector_objetivo()
{
    for (int posicion = 0; posicion < this->obtener_largo(); posicion++)
    {

        delete obtener_valor(posicion);
    }
};
Vector_objetivo::Vector_objetivo(){};
Vector_objetivo::Vector_objetivo(const Vector_objetivo &vector_a_copiar)
{
    for (int posicion = 0; posicion < vector_a_copiar.largo_actual; posicion++)
    {
        if (Objetivo_simple *objetivo_ptr = dynamic_cast<Objetivo_simple *>(vector_a_copiar.datos[posicion]))
        {
            this->agregar_al_final(new Objetivo_simple(*(objetivo_ptr)));
        }
        else
        {
            Objetivo_multiple *objetivo_multiple_ptr = dynamic_cast<Objetivo_multiple *>(vector_a_copiar.datos[posicion]);
            this->agregar_al_final(new Objetivo_multiple(*(objetivo_multiple_ptr)));
        }
    }
};

Vector_objetivo Vector_objetivo::operator=(const Vector_objetivo &vector_a_copiar)
{
    for (int posicion = 0; posicion < vector_a_copiar.largo_actual; posicion++)
    {
        if (Objetivo_simple *objetivo_ptr = dynamic_cast<Objetivo_simple *>(vector_a_copiar.datos[posicion]))
        {
            this->agregar_al_final(new Objetivo_simple(*(objetivo_ptr)));
        }
        else
        {
            Objetivo_multiple *objetivo_multiple_ptr = dynamic_cast<Objetivo_multiple *>(vector_a_copiar.datos[posicion]);
            this->agregar_al_final(new Objetivo_multiple(*(objetivo_multiple_ptr)));
        }
    }
    return *this;
};
void Vector_objetivo::agregar_objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo)
{

    this->agregar_al_final(new Objetivo_simple(nombre, descripcion, nombre_elemento_objetivo, cantidad_objetivo));
};
void Vector_objetivo::agregar_objetivo_multiple(Objetivo_multiple &objetivo)
{

    Objetivo_multiple *objetivo_nuevo = new Objetivo_multiple();
    *objetivo_nuevo = objetivo;
    this->agregar_al_final(objetivo_nuevo);
};
// Si el nombre coincide objetivo lo actualiza
estado_objetivo Vector_objetivo::actualizar_por_nombre(string nombre, int cant_incremento)
{
    int largo_vector = this->obtener_largo();
    bool encontrado = false;
    int i = 0;
    estado_objetivo estado = OBJETIVO_INCOMPLETO;
    estado_objetivo estado_vector_objetivo = OBJETIVO_INCOMPLETO;
    while (encontrado == false && i < largo_vector)
    {

        switch (obtener_tipo_objetivo(this->obtener_valor(i)))
        {
        case OBJETIVO_SIMPLE:
        {
            if (this->obtener_valor(i)->obtener_nombre().compare(nombre) == 0)
            {
                cout << i << endl;
                Objetivo_simple *objetivo_ptr = dynamic_cast<Objetivo_simple *>(this->obtener_valor(i));
                estado = objetivo_ptr->actualizar_objetivo(cant_incremento);
                encontrado = true;
            };
            break;
        }
        case OBJETIVO_MULTIPLE:
        {
            cout << i << endl;
            Objetivo_multiple *objetivo_ptr = dynamic_cast<Objetivo_multiple *>(this->obtener_valor(i));
            if (objetivo_ptr->buscar_por_nombre(nombre) != POSICION_INVALIDA)
            {
                estado = objetivo_ptr->actualizar_objetivo(nombre, cant_incremento);
                encontrado = true;
            }
            break;
        }

        case OBJETIVO_NO_RECONOCIDO:
            cout << "No reconoci objetivo" << endl;
            break;
        }
        i++;
    }
    if (estado == OBJETIVO_COMPLETO)
    {
        this->cantidad_completos++;
        if (this->cantidad_completos == this->obtener_largo())
        {
            estado_vector_objetivo = OBJETIVO_COMPLETO;
        }
    }
    return estado_vector_objetivo;
};
tipo_objetivo Vector_objetivo::obtener_tipo_objetivo(Objetivo *objetivo)
{
    tipo_objetivo objetivo_ingresado = OBJETIVO_NO_RECONOCIDO;
    if (dynamic_cast<Objetivo_simple *>(objetivo) != NULL)
    {
        objetivo_ingresado = OBJETIVO_SIMPLE;
    }
    else if (dynamic_cast<Objetivo_multiple *>(objetivo) != NULL)
    {
        objetivo_ingresado = OBJETIVO_MULTIPLE;
    }
    return objetivo_ingresado;
}
void Vector_objetivo::mostrar_restante()
{
    int largo_vector = this->obtener_largo();
    for (int i = 0; i < largo_vector; i++)
    {
        this->obtener_valor(i)->mostrar_restante();
    }
}