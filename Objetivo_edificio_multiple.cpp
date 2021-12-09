#include "Objetivo_edificio_multiple.h"
Objetivo_edificio_multiple::Objetivo_edificio_multiple(string nombre, string descripcion, Objetivo_edificio objetivo)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
    this->vector_objetivos.agregar_al_final(objetivo);
}
Objetivo_edificio_multiple::Objetivo_edificio_multiple(string nombre, string descripcion)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
}
void Objetivo_edificio_multiple::agregar_objetivo_edificio(Objetivo_edificio &edificio)
{
    this->vector_objetivos.agregar_al_final(edificio);
}
void Objetivo_edificio_multiple::agregar_objetivo_edificio(string nombre_objetivo, string descripcion, string nombre_edificio, int cantidad_objetivo)
{
    Objetivo_edificio objetivo = Objetivo_edificio(nombre_objetivo, descripcion, nombre_edificio, cantidad_objetivo);
    this->vector_objetivos.agregar_al_final(objetivo);
}
int Objetivo_edificio_multiple::buscar_por_nombre(string nombre) // Devuelve posicion invalida si no encuentra
{
    int largo_vector = this->vector_objetivos.obtener_largo();
    int i = 0;
    string nombre_objetivo = this->vector_objetivos.obtener_valor(i).obtener_nombre();
    bool no_existe = false;
    while (nombre_objetivo.compare(nombre) != 0 || no_existe == true)
    {
        i++;
        nombre_objetivo = this->vector_objetivos.obtener_valor(i).obtener_nombre();
        if (i > largo_vector)
        {
            no_existe = true;
            i = POSICION_INVALIDA;
        }
    }
    return i;
}
int Objetivo_edificio_multiple::obtener_cantidad_objetivo(string nombre) // Devuelve posicion invalida si no encuentra
{
    int indice = buscar_por_nombre(nombre);
    int cant_objetivo = indice;
    if (indice == POSICION_INVALIDA)
    {
        cout << "posición de objetivo invalida" << endl;
    }
    else
    {
        Objetivo_edificio objetivo_seleccionado = this->vector_objetivos.obtener_valor(indice);
        objetivo_seleccionado.obtener_cantidad_objetivo();
        this->vector_objetivos.fijar_valor(objetivo_seleccionado, indice);
    }
    return cant_objetivo;
}
estado_objetivo Objetivo_edificio_multiple::actualizar_objetivo(string nombre_objetivo, int cantidad_incremento)
{
    int indice = buscar_por_nombre(nombre_objetivo);
    estado_objetivo estado_secundario;
    estado_objetivo estado = OBJETIVO_INCOMPLETO;
    if (indice == POSICION_INVALIDA)
    {
        cout << "posición de objetivo invalida" << endl;
    }
    else
    {
        Objetivo_edificio objetivo_seleccionado = this->vector_objetivos.obtener_valor(indice);
        estado_secundario = objetivo_seleccionado.actualizar_objetivo(cantidad_incremento);
        this->vector_objetivos.fijar_valor(objetivo_seleccionado, indice);
    }
    if (estado_secundario == OBJETIVO_COMPLETO)
    {
        if (this->actualizar_objetivo_multiple() == OBJETIVO_COMPLETO)
        {
            estado = OBJETIVO_COMPLETO;
        }
    }
    return estado;
}
estado_objetivo Objetivo_edificio_multiple::actualizar_objetivo_multiple()
{
    int cantidad_objetivos = this->vector_objetivos.obtener_largo();
    estado_objetivo estado = OBJETIVO_COMPLETO;
    for (int i = 0; i < cantidad_objetivos; i++)
    {
        if (this->vector_objetivos.obtener_valor(i).objetivo_completo() == false)
        {
            estado = OBJETIVO_INCOMPLETO;
        }
    }
    return estado;
}
void Objetivo_edificio_multiple::mostrar_restante()
{
    cout << COMPLETAR_OBJETIVO_MULTIPLE_INICIO << endl;
    int cantidad_objetivos = this->vector_objetivos.obtener_largo();
    for (int i = 0; i < cantidad_objetivos; i++)
    {
        this->vector_objetivos.obtener_valor(i).mostrar_restante();
    }
    cout << COMPLETAR_OBJETIVO_MULTIPLE_FIN << this->nombre_objetivo << endl;
}