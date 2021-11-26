#include "Matriz_casillero.h"

void Matriz_casillero::agregar_casillero(tipos_casillero casillero_elegido, int fila, int columna, bool esta_ocupado)
{
    switch (casillero_elegido)
    {
    case CASILLERO_TRANSITABLE:
    {
        Casillero_transitable *transitable_ptr = new Casillero_transitable(fila, columna, esta_ocupado);
        this->insertar_dato(transitable_ptr, fila, columna);
        this->cantidad_transitables++;
        break;
    }

    case CASILLERO_CONSTRUIBLE:
    {
        Casillero_construible *construible_ptr = new Casillero_construible(fila, columna, esta_ocupado);
        this->insertar_dato(construible_ptr, fila, columna);
        this->cantidad_construibles++;
        break;
    }

    case CASILLERO_INACCESIBLE:
    {
        Casillero_inaccesible *inaccesible_ptr = new Casillero_inaccesible(fila, columna, esta_ocupado);
        this->insertar_dato(inaccesible_ptr, fila, columna);
        this->cantidad_inaccesibles++;
        break;
    }
    default:
        cout << TIPO_CASILLERO_DESCONOCIDO << endl;
        break;
    }
}
void Matriz_casillero::agregar_casillero(const char tipo_terreno, int fila, int columna, bool esta_ocupado)
{
    switch (tipo_terreno)
    {
    case TERRENO_TRANSITABLE:
    {
        Casillero_transitable *transitable_ptr = new Casillero_transitable(fila, columna, esta_ocupado);
        this->insertar_dato(transitable_ptr, fila, columna);
        this->cantidad_transitables++;
        break;
    }

    case TERRENO_CONSTRUIBLE:
    {
        Casillero_construible *construible_ptr = new Casillero_construible(fila, columna, esta_ocupado);
        this->insertar_dato(construible_ptr, fila, columna);
        this->cantidad_construibles++;
        break;
    }

    case TERRENO_INTRANSITABLE:
    {
        Casillero_inaccesible *inaccesible_ptr = new Casillero_inaccesible(fila, columna, esta_ocupado);
        this->insertar_dato(inaccesible_ptr, fila, columna);
        this->cantidad_inaccesibles++;
        break;
    }
    default:
        cout << TIPO_CASILLERO_DESCONOCIDO << endl;
        break;
    }
}
Matriz_casillero::Matriz_casillero()
{
    this->cantidad_transitables = 0;
    this->cantidad_construibles = 0;
    this->cantidad_inaccesibles = 0;
};
Matriz_casillero::~Matriz_casillero()
{
    int max_filas = this->obtener_largo_filas();
    int max_columnas = this->obtener_largo_columnas();
    for (int filas = 0; filas < max_filas; filas++)
    {
        for (int columnas = 0; columnas < max_columnas; columnas++)
        {
            delete this->obtener_dato(filas, columnas);
        }
    }
}
int Matriz_casillero::obtener_cant_construibles()
{
    return this->cantidad_construibles;
}
int Matriz_casillero::obtener_cant_transitables()
{
    return this->cantidad_transitables;
}
int Matriz_casillero::obtener_cant_inaccesibles()
{
    return this->cantidad_inaccesibles;
}
void Matriz_casillero::fijar_cant_construibles(int cantidad)
{
    this->cantidad_construibles = cantidad;
}
void Matriz_casillero::fijar_cant_transitables(int cantidad)
{
    this->cantidad_construibles = cantidad;
};
void Matriz_casillero::fijar_cant_inaccesibles(int cantidad)
{
    this->cantidad_construibles = cantidad;
};
tipos_casillero Matriz_casillero::obtener_tipo_casillero(int fila, int columna)
{
    tipos_casillero tipo_de_casillero;
    if (dynamic_cast<Casillero_transitable *>(this->obtener_dato(fila, columna)))
    {
        tipo_de_casillero = CASILLERO_TRANSITABLE;
    }
    else if (dynamic_cast<Casillero_inaccesible *>(this->obtener_dato(fila, columna)))
    {
        tipo_de_casillero = CASILLERO_INACCESIBLE;
    }
    else
    {
        tipo_de_casillero = CASILLERO_CONSTRUIBLE;
    }
    return tipo_de_casillero;
};