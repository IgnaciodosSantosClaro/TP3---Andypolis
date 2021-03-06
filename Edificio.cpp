#include "Edificio.h"

Edificio::Edificio()
{
    this->nombre_edificio = NOMBRE_EDIFICIO_POR_DEFECTO;
    this->cant_max = 0;
    this->cant_construidos = 0;
    this->salud = SALUD_MAXIMA;
}
Edificio::Edificio(string nombre_edificio, int puntos_salud)
{
    this->cant_max = 0;
    this->cant_construidos = 0;
    this->nombre_edificio = nombre_edificio;
    this->salud = puntos_salud;
}
Edificio::Edificio(string nombre_edificio, int cant_max, int cantidad_construidos, int puntos_salud)
{
    this->nombre_edificio = nombre_edificio;
    this->cant_max = cant_max;
    this->cant_construidos = cantidad_construidos;
    this->salud = puntos_salud;
}

Edificio::Edificio(string nombre_edificio, int cant_max, Material_consumible materiales_construccion[MAX_MATERIALES_CONSTRUIBLES])
{
    this->nombre_edificio = nombre_edificio;
    this->cant_max = cant_max;
    this->cant_construidos = 0;
    this->salud = SALUD_MAXIMA;
    this->materiales_construccion[0] = materiales_construccion[0];
    this->materiales_construccion[1] = materiales_construccion[1];
    this->materiales_construccion[2] = materiales_construccion[2];
}

void Edificio::fijar_nombre(string nombre_edificio)
{
    this->nombre_edificio = nombre_edificio;
};
void Edificio::mostrar_leyenda(char icono)
{
    cout << COLOR_VERDE << ESPACIO << icono << ESPACIO << COLOR_NEGRO << ESPACIO << COLOR_TEXTO_BLANCO << this->nombre_edificio;
};
void Edificio::fijar_dueno(tipo_jugador jugador_dueno)
{
    this->jugador_dueno = jugador_dueno;
};
tipo_jugador Edificio::obtener_dueno()
{
    return this->jugador_dueno;
};
void Edificio::fijar_puntos_de_salud(int salud)
{
    this->salud = salud;
};
void Edificio::modificar_cant_construidos(int cant_construidos)
{
    this->cant_construidos = cant_construidos;
}
estado_edificio Edificio::atacar_edificio()
{
    this->salud--;
    if (this->salud == 0)
    {
        return EDIFICIO_DESTRUIDO;
    }
    return EDIFICIO_LASTIMADO;
};
std::string Edificio::obtener_nombre()
{
    return this->nombre_edificio;
}

int Edificio::obtener_cant_max()
{
    return this->cant_max;
}

int Edificio::obtener_cant_construidos()
{
    return this->cant_construidos;
}

Material_consumible Edificio::obtener_materiales_otorgados()
{
    return this->recursos_producidos;
}

void Edificio::incrementar_construcciones()
{
    this->cant_construidos++;
}

void Edificio::decrementar_construcciones()
{
    this->cant_construidos--;
}

void Edificio::mostrar_edificio()
{
    std::cout << "Soy un/a " << this->nombre_edificio << CASILLERO_CONSULTADO << std::endl;
}

Material_consumible Edificio::obtener_material(int posicion)
{
    return this->materiales_construccion[posicion];
}

void Edificio::fijar_material_constuible(int cantidad, int posicion)
{
    this->materiales_construccion[posicion].fijar_cantidad(cantidad);
}

void Edificio::fijar_recurso_producido(string nombre, int cantidad)
{
    this->recursos_producidos.fijar_nombre(nombre);
    this->recursos_producidos.fijar_cantidad(cantidad);
}

int Edificio::obtener_salud()
{
    return this->salud;
}
