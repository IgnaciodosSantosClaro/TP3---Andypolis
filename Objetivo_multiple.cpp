#include "Objetivo_multiple.h"
Objetivo_multiple::Objetivo_multiple(const Objetivo_multiple &objetivo_a_copiar)
{
    this->nombre_objetivo = objetivo_a_copiar.nombre_objetivo;
    this->esta_completo = objetivo_a_copiar.esta_completo;
    this->descripcion = objetivo_a_copiar.descripcion;
    this->cantidad_actual = objetivo_a_copiar.cantidad_actual;
    this->cantidad_objetivo = objetivo_a_copiar.cantidad_objetivo;
    this->cantidad_restante = objetivo_a_copiar.cantidad_restante;
    this->vector_objetivos = objetivo_a_copiar.vector_objetivos;
};
Objetivo_multiple Objetivo_multiple::operator=(const Objetivo_multiple &objetivo_a_copiar)
{
    this->nombre_objetivo = objetivo_a_copiar.nombre_objetivo;
    this->esta_completo = objetivo_a_copiar.esta_completo;
    this->descripcion = objetivo_a_copiar.descripcion;
    this->cantidad_actual = objetivo_a_copiar.cantidad_actual;
    this->cantidad_objetivo = objetivo_a_copiar.cantidad_objetivo;
    this->cantidad_restante = objetivo_a_copiar.cantidad_restante;
    this->vector_objetivos = objetivo_a_copiar.vector_objetivos;
    return *this;
}
Objetivo_multiple::Objetivo_multiple(string nombre_objetivo_multiple, string descripcion, Objetivo_simple &objetivo)
{
    this->nombre_objetivo = nombre_objetivo_multiple;
    this->descripcion = descripcion;
    this->vector_objetivos.agregar_al_final(objetivo);
}
Objetivo_multiple::Objetivo_multiple() {}

Objetivo_multiple::Objetivo_multiple(string nombre, string descripcion)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
}
void Objetivo_multiple::agregar_objetivo_simple(Objetivo_simple &objetivo_nuevo)
{
    this->vector_objetivos.agregar_al_final(objetivo_nuevo);
}
void Objetivo_multiple::agregar_objetivo_simple(string nombre_objetivo, string descripcion, string nombre_simple, int cantidad_objetivo)
{
    this->vector_objetivos.agregar_al_final(Objetivo_simple(nombre_objetivo, descripcion, nombre_simple, cantidad_objetivo));
}
int Objetivo_multiple::buscar_por_nombre(string nombre) // Devuelve posicion invalida si no encuentra
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

int Objetivo_multiple::obtener_cantidad_objetivo(string nombre) // Devuelve posicion invalida si no encuentra
{
    int indice = buscar_por_nombre(nombre);
    int cant_objetivo = indice;
    if (indice == POSICION_INVALIDA)
    {
        cout << "posición de objetivo invalida" << endl;
    }
    else
    {
        Objetivo_simple objetivo_seleccionado = this->vector_objetivos.obtener_valor(indice);
        objetivo_seleccionado.obtener_cantidad_objetivo();
        this->vector_objetivos.fijar_valor(objetivo_seleccionado, indice);
    }
    return cant_objetivo;
}
estado_objetivo Objetivo_multiple::actualizar_objetivo(string nombre_objetivo, int cantidad_incremento)
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
        Objetivo_simple objetivo_seleccionado = this->vector_objetivos.obtener_valor(indice);
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
estado_objetivo Objetivo_multiple::actualizar_objetivo_multiple()
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
estado_objetivo Objetivo_multiple::actualizar_por_elemento(string elemento, int cant_incremento) // Devuelve posicion invalida si no encuentra
{
    int cantidad_objetivos = this->vector_objetivos.obtener_largo();
    for (int i = 0; i < cantidad_objetivos; i++)
    {
        if (this->vector_objetivos.obtener_valor(i).obtener_elemento().compare(elemento))
        {
            this->vector_objetivos.obtener_valor(i).actualizar_objetivo(cant_incremento);
        }
    }
    return this->actualizar_objetivo_multiple();
}
void Objetivo_multiple::mostrar_restante()
{
    cout << COMPLETAR_OBJETIVO_MULTIPLE_INICIO << endl;
    int cantidad_objetivos = this->vector_objetivos.obtener_largo();
    for (int i = 0; i < cantidad_objetivos; i++)
    {
        cout << ESPACIO << ESPACIO;
        this->vector_objetivos.obtener_valor(i).mostrar_restante();
    }
    cout << COMPLETAR_OBJETIVO_MULTIPLE_FIN << this->nombre_objetivo << endl;
}