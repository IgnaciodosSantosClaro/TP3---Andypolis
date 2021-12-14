#include "Objetivo_simple.h"
Objetivo_simple::Objetivo_simple(const Objetivo_simple &objetivo_a_copiar)
{
    this->nombre_objetivo = objetivo_a_copiar.nombre_objetivo;
    this->esta_completo = objetivo_a_copiar.esta_completo;
    this->descripcion = objetivo_a_copiar.descripcion;
    this->cantidad_actual = objetivo_a_copiar.cantidad_actual;
    this->cantidad_objetivo = objetivo_a_copiar.cantidad_objetivo;
    this->cantidad_restante = objetivo_a_copiar.cantidad_restante;
};
Objetivo_simple Objetivo_simple::operator=(const Objetivo_simple &objetivo_a_copiar)
{
    this->nombre_objetivo = objetivo_a_copiar.nombre_objetivo;
    this->esta_completo = objetivo_a_copiar.esta_completo;
    this->descripcion = objetivo_a_copiar.descripcion;
    this->cantidad_actual = objetivo_a_copiar.cantidad_actual;
    this->cantidad_objetivo = objetivo_a_copiar.cantidad_objetivo;
    this->cantidad_restante = objetivo_a_copiar.cantidad_restante;
    return *this;
}
Objetivo_simple::Objetivo_simple()
{
    this->nombre_objetivo = "";
    this->descripcion = "";
};
Objetivo_simple::Objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
    this->nombre_elemento_objetivo = nombre_elemento_objetivo;
}
Objetivo_simple::Objetivo_simple(string nombre, string descripcion, string nombre_elemento_objetivo, int cantidad_objetivo)
{
    this->nombre_objetivo = nombre;
    this->cantidad_restante = cantidad_objetivo;
    this->descripcion = descripcion;
    this->nombre_elemento_objetivo = nombre_elemento_objetivo;
    this->cantidad_objetivo = cantidad_objetivo;
}
int Objetivo_simple::obtener_cantidad_objetivo()
{
    return this->cantidad_objetivo;
}
string Objetivo_simple::obtener_elemento()
{
    return this->nombre_elemento_objetivo;
}
estado_objetivo Objetivo_simple::actualizar_objetivo(int cantidad_incremento)
{
    this->cantidad_actual = this->cantidad_actual + cantidad_incremento;
    estado_objetivo estado = OBJETIVO_INCOMPLETO;
    this->cantidad_restante = this->cantidad_objetivo - this->cantidad_actual;
    if (this->cantidad_actual >= this->cantidad_objetivo)
    {
        this->esta_completo = true;
        estado = OBJETIVO_COMPLETO;
    }
    return estado;
}
void Objetivo_simple::mostrar_restante()
{
    if (this->cantidad_restante <= 0)
    {
        cout << this->nombre_objetivo << MENSAJE_OBJETIVO_COMPLETO << endl;
    }
    else
    {
        cout << MENSAJE_OBJETIVO_SIMPLE_RESTANTES_P1 << this->cantidad_restante << ESPACIO;
        cout << this->nombre_elemento_objetivo << MENSAJE_OBJETIVO_SIMPLE_RESTANTES_P2 << this->nombre_objetivo << endl;
    }
}