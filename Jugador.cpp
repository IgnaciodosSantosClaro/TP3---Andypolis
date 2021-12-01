#include "Jugador.h"
#include "configuracion.h"

using namespace std;

Jugador::Jugador() {
    this->energia = ENERGIA_INICIAL;
}

int Jugador::obtener_energia() {
    return energia;
}

void Jugador::desplazarse(int pos_x, int pos_y) {
    this->posicion.fijar_coordenadas(pos_x, pos_y);
}

void Jugador::modificar_energia(int energia) {
    if(this->energia += energia >= ENERGIA_MAXIMA) {
        this->energia = ENERGIA_MAXIMA;
    }
    else if(this->energia += energia <= ENERGIA_MINIMA) {
        this->energia = ENERGIA_MINIMA;
    }
    else {
        this->energia += energia;
    }
}

