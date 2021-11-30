#include "Bomba.h"

Bomba::Bomba() {
    this->cantidad = 0;
}

void Bomba::tirar_bomba() {
    this->cantidad--;
}

int Bomba::obtener_cantidad() {
    return this->cantidad;
}

void Bomba::fijar_cantidad(int cantidad) {
    this->cantidad = cantidad;
}

