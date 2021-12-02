#include "Bomba.h"

Bomba::Bomba()
{
    this->cantidad = 0;
    this->nombre_material = "Bomba";
};

void Bomba::tirar_bomba(Casillero_construible &casillero_objetivo, string color_texto_edificio_herido)
{
    if (this->cantidad > 0)
    {
        bool esta_ocupado = casillero_objetivo.casillero_ocupado();
        if (esta_ocupado == true)
        {
            this->cantidad--;
            Edificio edificio_objetivo = casillero_objetivo.obtener_edificio();
            if (edificio_objetivo.atacar_edificio() == EDIFICIO_DESTRUIDO)
            {
                cout << MENSAJE_BOMBA_DESTRUYO << edificio_objetivo.obtener_nombre() << endl;
                casillero_objetivo.desocupar_casillero();
            }
            else
            {
                cout << MENSAJE_BOMBA_DANO << edificio_objetivo.obtener_nombre() << endl;
                casillero_objetivo.fijar_color_texto(color_texto_edificio_herido);
                casillero_objetivo.fijar_edificio(edificio_objetivo);
            }
        }
        else
        {
            cout << MENSAJE_BOMBA_CASILLERO_VACIO;
            casillero_objetivo.obtener_posicion().mostrar();
        }
    }
    else
    {
        cout << MENSAJE_BOMBA_INSUFICIENTES << endl;
    }
};

void Bomba::modificar_cantidad(int cantidad) {
    this->cantidad += cantidad;
}

int Bomba::obtener_cantidad() {
    return this->cantidad;
}
