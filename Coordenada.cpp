#include "Coordenada.h"
#include "configuracion.h"
#include <iostream>

using namespace std;

Coordenada::Coordenada() {
    this -> posicion_actual.coordenada_x = 0;
    this -> posicion_actual.coordenada_y = 0;
}

void Coordenada::fijar_coordenadas(int x, int y)
{
    this->posicion_actual.coordenada_x = x;
    this->posicion_actual.coordenada_y = y;
}; //llamar a es_coordenada_valida?

ubicacion Coordenada::obtener_coordenadas()
{
    ubicacion coordenadas;
    coordenadas.coordenada_x = this->posicion_actual.coordenada_x;
    coordenadas.coordenada_y = this->posicion_actual.coordenada_y;
    return coordenadas;
}

void Coordenada::mostrar() {
    cout << SEPARADOR_DERECHO_UBICACIONES << this->posicion_actual.coordenada_x << SEPARADOR_MEDIO_UBICACIONES << " " << this->posicion_actual.coordenada_y <<SEPARADOR_IZQUIERDO_UBICACIONES << " ";
}

string Coordenada::coordenada_a_string() {
    return "(" + to_string(this->posicion_actual.coordenada_x) + "," + " " + to_string(this->posicion_actual.coordenada_y) + ")";
}
