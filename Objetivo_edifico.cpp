#include "Objetivo_edificio.h"
Objetivo_edificio::Objetivo_edificio()
{
    this->nombre_objetivo = "";
    this->descripcion = "";
};
Objetivo_edificio::Objetivo_edificio(string nombre, string descripcion, Edificio &edificio)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
    this->edificio_objetivo = edificio;
}
Objetivo_edificio::Objetivo_edificio(string nombre, string descripcion, string nombre_edificio, int cantidad_objetivo)
{
    this->nombre_objetivo = nombre;
    this->descripcion = descripcion;
    this->edificio_objetivo.fijar_nombre(nombre_edificio);
    this->edificio_objetivo.modificar_cant_construidos(cantidad_objetivo);
}
void Objetivo_edificio::fijar_edificio_objetivo(Edificio &edificio)
{
    this->edificio_objetivo = edificio;
}
int Objetivo_edificio::obtener_cantidad_objetivo()
{
    return this->edificio_objetivo.obtener_cant_construidos();
}
Edificio Objetivo_edificio::obtener_edificio_objetivo()
{
    return this->edificio_objetivo;
}
estado_objetivo Objetivo_edificio::actualizar_objetivo(int cantidad_incremento)
{
    this->cantidad_actual = this->cantidad_actual + cantidad_incremento;
    estado_objetivo estado = OBJETIVO_INCOMPLETO;
    if (this->cantidad_actual >= this->edificio_objetivo.obtener_cant_construidos())
    {
        this->esta_completo = true;
        estado = OBJETIVO_COMPLETO;
    }
    return estado;
}
void Objetivo_edificio::mostrar_restante()
{
    int cantidad_restante = this->edificio_objetivo.obtener_cant_construidos() - this->cantidad_actual;
    if (cantidad_restante <= 0)
    {
        cout << this->nombre_objetivo << MENSAJE_OBJETIVO_COMPLETO << endl;
    }
    else
    {
        cout << MENSAJE_OBJETIVO_EDIFICIO_RESTANTES_P1 << cantidad_restante << ESPACIO;
        cout << this->edificio_objetivo.obtener_nombre() << MENSAJE_OBJETIVO_EDIFICIO_RESTANTES_P2 << this->nombre_objetivo << endl;
    }
}