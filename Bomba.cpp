#include "Bomba.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;
Bomba::Bomba()
{
    this->cantidad = 0;
    this->nombre_material = "Bomba";
};

void Bomba::tirar_bomba(Casillero_construible &casillero_objetivo)
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
                cout << MENSAJE_INICIO_BOMBA << edificio_objetivo.obtener_nombre() << endl;
                sleep_for(milliseconds(1000));
                // bombardeo(250);
                sleep_for(milliseconds(1000));
                cout << MENSAJE_BOMBA_DANO << edificio_objetivo.obtener_nombre() << endl;

                if (casillero_objetivo.obtener_edificio().obtener_dueno() == JUGADOR_1)
                {
                    casillero_objetivo.fijar_color_texto(COLOR_EDIFICIO_HERIDO_JUG_1);
                }
                else
                {
                    casillero_objetivo.fijar_color_texto(COLOR_EDIFICIO_HERIDO_JUG_2);
                }
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

void Bomba::modificar_cantidad(int cantidad)
{
    this->cantidad += cantidad;
}

int Bomba::obtener_cantidad()
{
    return this->cantidad;
}
