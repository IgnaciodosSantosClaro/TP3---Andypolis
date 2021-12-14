#include "Vector_jugador.h"

using namespace std;

Vector_jugador::Vector_jugador() {};
Vector_jugador::~Vector_jugador()
{
    for (int posicion = 0; posicion < this->obtener_largo(); posicion++)
    {
        cout << posicion << endl;
        delete obtener_valor(posicion);
    }
};
void Vector_jugador::agregar_jugador_al_final(std::string nombre_jugador, tipo_jugador identidad)
{
    Jugador *puntero = new Jugador(nombre_jugador, identidad);
    this->agregar_al_final(puntero);
}
int Vector_jugador::obtener_pos_jugador(string nombre)
{
    int posicion = ERROR_NOMBRE_MATERIAL;

    for (int i = 0; i < largo_actual; i++)
    {
        if (datos[i]->obtener_nombre().compare(nombre) == 0)
        {
            posicion = i;
        }
    };
    return posicion;
};
Jugador Vector_jugador::obtener_por_nombre(std::string nombre)
{
    return *(this->obtener_valor(this->obtener_pos_jugador(nombre)));
}