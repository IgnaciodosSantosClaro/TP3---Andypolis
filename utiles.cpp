#include "utiles.h"
string separar_hasta(string cadena_a_separar, char caracter)
{
    char cursor;
    string cadena_procesada;
    int indice = 0;
    cursor = cadena_a_separar.at(indice);
    while (cursor != caracter)
    {
        cadena_procesada.push_back(cursor);
        indice++;
        cursor = cadena_a_separar.at(indice);
    }
    return cadena_procesada;
};
bool es_edificio(string nombre)
{
    bool edificio_detectado = false;
    if (nombre.compare(NOMBRE_EDIFICIO_MINA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_MINA_ORO))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ASERRADERO))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_FABRICA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_PLANTA_ELECTRICA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ESCUELA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_OBELISCO))
    {
        edificio_detectado = true;
    }
    return edificio_detectado;
};
bool es_jugador(string nombre)
{
    bool jugador_detectado = false;
    if (nombre.compare(NOMBRE_JUGADOR_1_UBICACIONES) == 0)
    {
        jugador_detectado = true;
    }
    else if (nombre.compare(NOMBRE_JUGADOR_2_UBICACIONES) == 0)
    {
        jugador_detectado = true;
    }
    if (jugador_detectado)
    {
        cout << nombre << " es jugador" << endl;
    }
    if (!jugador_detectado)
    {
        cout << nombre << " no es jugador" << endl;
    }
    return jugador_detectado;
}