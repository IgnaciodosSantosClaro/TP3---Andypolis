#include "interfaz.h"
void mostrar_leyenda_tipo_terreno(string color, string nombre)
{
    cout << color << ESPACIO << ESPACIO << COLOR_NEGRO << ESPACIO << nombre;
}
void mostrar_leyenda_casillero(string color_fondo, string color_letra, char icono, string nombre)
{
    cout << color_fondo << ESPACIO << color_letra << icono << ESPACIO << COLOR_NEGRO << ESPACIO << COLOR_TEXTO_BLANCO << nombre;
}
/* void mostrar_encabezado_mapa(Vector_edificio &edificios)
{
    mostrar_leyenda_tipo_terreno(COLOR_VERDE, NOMBRE_CASILLERO_CONSTRUIBLE);
    mostrar_leyenda_tipo_terreno(COLOR_GRIS, NOMBRE_CASILLERO_TRANSITABLE);
    mostrar_leyenda_tipo_terreno(COLOR_CELESTE, NOMBRE_CASILLERO_INACCESIBLE);
    cout << endl;
    mostrar_leyenda_casillero(COLOR_GRIS, COLOR_TEXTO_NEGRO, ICONO_PIEDRA, PIEDRA_MAYUS);
    mostrar_leyenda_casillero(COLOR_GRIS, COLOR_TEXTO_NEGRO, ICONO_MADERA, MADERA_MAYUS);
    mostrar_leyenda_casillero(COLOR_GRIS, COLOR_TEXTO_NEGRO, ICONO_METAL, METAL_MAYUS);
    cout << endl;
    int cantidad_edificios = edificios.obtener_largo();
    string todos_los_iconos = obtener_iconos(edificios);
    for (int i = 0; i < cantidad_edificios; i++)
    {
        string nombre_edificio = edificios.obtener_valor(i).obtener_nombre();
        mostrar_leyenda_casillero(COLOR_VERDE, COLOR_TEXTO_VERDE, (char)toupper(todos_los_iconos[i]), nombre_edificio);
    }
    cout << endl;
} */
void mostrar_fila(Matriz_casillero &mapa, int fila, int ancho_grilla, int largo_grilla)
{
    int limite_columna = mapa.obtener_largo_columnas();
    int medio = (int)largo_grilla / 2;
    for (int i = 0; i < largo_grilla; i++)
    {
        cout << SEPARADOR_GRILLA_DERECHA;
        for (int columna = 0; columna < limite_columna; columna++)
        {
            if (i == medio)
            {
                mapa.obtener_dato(fila, columna)->mostrar_en_mapa(ancho_grilla, true, false);
            }
            else if (i == largo_grilla - 1)
            {

                mapa.obtener_dato(fila, columna)->mostrar_en_mapa(ancho_grilla, false, true);
            }
            else
            {

                mapa.obtener_dato(fila, columna)->mostrar_en_mapa(ancho_grilla, false, false);
            }
        };
        cout << endl;
    }
}
void mostrar_mapa(Matriz_casillero &mapa, int ancho_grilla, int largo_grilla)
{
    int limite_fila = mapa.obtener_largo_filas();
    int limite_columna = mapa.obtener_largo_columnas();
    cout << endl;
    cout.width((ancho_grilla)*limite_columna + 1);
    cout << cout.fill(SEPARADOR_GRILLA_INFERIOR) << endl;
    for (int fila = 0; fila < limite_fila; fila++)
    {
        mostrar_fila(mapa, fila, ancho_grilla, largo_grilla);
    }
}