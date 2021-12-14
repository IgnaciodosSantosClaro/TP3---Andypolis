#include "interfaz.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

void mostrar_leyenda_tipo_terreno(string color, string nombre)
{
    cout << color << ESPACIO << ESPACIO << COLOR_NEGRO << ESPACIO << nombre;
}
void mostrar_leyenda_casillero(string color_fondo, string color_letra, char icono, string nombre)
{
    cout << color_fondo << ESPACIO << color_letra << icono << ESPACIO << COLOR_NEGRO << ESPACIO << COLOR_TEXTO_BLANCO << nombre;
}

void mostrar_encabezado(int margen, int ancho_grilla, int columnas)
{
    string margen_cadena;
    int ancho_total = margen + (ancho_grilla) * (columnas + 1);
    string numeracion;
    numeracion.resize(ancho_total, ESPACIO);
    for (int i = 0; i <= columnas; i++)
    {
        numeracion[margen + int(ancho_grilla / 2 - 1) + i * ancho_grilla] = to_string(i)[0];
    }
    cout << numeracion << endl;
    margen_cadena.resize(margen, ESPACIO);
    margen_cadena.resize(ancho_total, SEPARADOR_GRILLA_INFERIOR);
    cout << margen_cadena << endl;
}
void mostrar_fila(Matriz_casillero &mapa, int fila, int ancho_grilla, int largo_grilla)
{
    int limite_columna = mapa.obtener_largo_columnas();
    int medio = (int)largo_grilla / 2;
    for (int i = 0; i < largo_grilla; i++)
    {
        if (i == medio)
        {
            cout << fila;
        }
        else
        {
            cout << ESPACIO;
        }
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
        if (i != largo_grilla - 1)
        {
            cout << endl;
        }
    }
}
void mostrar_referencia_casilleros()
{
    Casillero_construible casillero_construible;
    cout << ESPACIO;
    casillero_construible.mostrar_leyenda(NOMBRE_CASILLERO_CONSTRUIBLE);

    Casillero_transitable casillero_camino = Casillero_transitable(TERRENO_TRANSITABLE, 0, 0, false);
    cout << ESPACIO;
    casillero_camino.mostrar_leyenda(NOMBRE_CASILLERO_TRANSITABLE);

    Casillero_transitable casillero_betun = Casillero_transitable(TERRENO_BETUN, 0, 0, false);
    cout << ESPACIO;
    casillero_betun.mostrar_leyenda(NOMBRE_CASILLERO_BETUN);

    Casillero_transitable casillero_muelle = Casillero_transitable(TERRENO_MUELLE, 0, 0, false);
    cout << ESPACIO;
    casillero_muelle.mostrar_leyenda(NOMBRE_CASILLERO_MUELLE);

    Casillero_inaccesible casillero_inaccesible = Casillero_inaccesible();
    cout << ESPACIO;
    casillero_inaccesible.mostrar_leyenda(NOMBRE_CASILLERO_INACCESIBLE);
}
void mostrar_referencia_edificios() // PENSAR EN IMPLEMENTARLO CON metodos de la clase
{
    // Recorrer Edificios y mostrar referencia
    cout << TABULACION << "Referencias edificios";
};
void mostrar_referencias_salud_edificios()
{
    cout << ESPACIO << COLOR_VERDE << ESPACIO << COLOR_EDIFICIO_SANO_JUG_1 << NOMBRE_EDIFICIO_ASERRADERO[0] << ESPACIO << COLOR_NEGRO << COLOR_TEXTO_BLANCO << ESPACIO << "Edificio de Jugador 1 sano";
    cout << ESPACIO << COLOR_VERDE << ESPACIO << COLOR_EDIFICIO_SANO_JUG_2 << NOMBRE_EDIFICIO_ASERRADERO[0] << ESPACIO << COLOR_NEGRO << COLOR_TEXTO_BLANCO << ESPACIO << "Edificio de Jugador 2 sano";
}
void mostrar_referencias_salud_edificios_danados()
{
    cout << ESPACIO << COLOR_VERDE << ESPACIO << COLOR_EDIFICIO_HERIDO_JUG_1 << NOMBRE_EDIFICIO_ASERRADERO[0] << ESPACIO << COLOR_NEGRO << COLOR_TEXTO_BLANCO << ESPACIO << "Edificio de Jugador 1 herido";
    cout << ESPACIO << COLOR_VERDE << ESPACIO << COLOR_EDIFICIO_HERIDO_JUG_2 << NOMBRE_EDIFICIO_ASERRADERO[0] << ESPACIO << COLOR_NEGRO << COLOR_TEXTO_BLANCO << ESPACIO << "Edificio de Jugador 2 herido";
}
void mostrar_referencia_materiales()
{
    Material piedra = Material(PIEDRA, 1);
    piedra.mostrar_leyenda(ICONO_PIEDRA);
    Material madera = Material(MADERA, 1);
    madera.mostrar_leyenda(ICONO_MADERA);
    Material metal = Material(METAL, 1);
    metal.mostrar_leyenda(ICONO_METAL);
    Material andycoins = Material(ANDYCOINS, 1);
    metal.mostrar_leyenda(ICONO_ANDYCOINS);
}

void mostrar_mapa(Matriz_casillero &mapa, int ancho_grilla, int largo_grilla)
{
    int limite_fila = mapa.obtener_largo_filas();
    int limite_columna = mapa.obtener_largo_columnas();
    cout << endl;
    cout << TEXTO_NEGRITA;
    mostrar_encabezado(2, ancho_grilla, limite_columna - 1);
    for (int fila = 0; fila < limite_fila; fila++)
    {
        mostrar_fila(mapa, fila, ancho_grilla, largo_grilla);
        switch (fila)
        {
        case PRIMERA_FILA:
            mostrar_referencia_casilleros();
            cout << endl;
            break;
        case SEGUNDA_FILA:
            mostrar_referencia_edificios();
            cout << endl;
            break;
        case TERCERA_FILA:
            mostrar_referencia_materiales();
            cout << endl;
            break;
        case CUARTA_FILA:
            mostrar_referencias_salud_edificios();
            cout << endl;
            break;
        case QUINTA_FILA:
            mostrar_referencias_salud_edificios_danados();
            cout << endl;
            break;
        default:
            cout << endl;
            break;
        }
    }
}

void listar_todos_edificios(Diccionario &diccionario)
{
    int ancho_nombre = 18;
    int ancho_general = 11;
    cout << TABULACION << ENCABEZADO_LISTADO_MATERIALES << endl;
    cout << TABULACION << TITULO_LISTADO_EDIFICIOS << endl;
    cout << TABULACION << ENCABEZADO_LISTADO_MATERIALES << endl;
    cout << left << TABULACION << setfill(' ') << setw(ancho_nombre) << TITULO_COLUMNA_EDIFICIOS;
    cout << setw(1) << setfill(' ') << SEPARADOR_GRILLA_DERECHA << setfill(' ') << setw(ancho_general) << PIEDRA_MAYUS << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA << setfill(' ') << setw(ancho_general) << MADERA_MAYUS << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << METAL_MAYUS << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(2 * ancho_general) << TITULO_COLUMNA_CANT_CONSTRUIDA << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(2 * ancho_general) << TITULO_COLUMNA_CANT_PERMITIDA << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << TITULO_COLUMNA_RECURSO_ENTREGADO << setfill(' ') << setw(1) << endl;
    cout << left << TABULACION;
    cout << setfill(' ') << setw(ancho_nombre) << "        " << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << "      " << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << "      " << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << "     " << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(2 * ancho_general) << "                   " << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(2 * ancho_general) << "                   " << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << TITULO_COLUMNA_TIPO << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general / 2) << TITULO_COLUMNA_CANTIDAD << setfill(' ') << setw(1) << endl;

    Vector<Edificio *> vector_edificio = diccionario.arbol_a_vector();
    for (int i = 0; i < vector_edificio.obtener_largo(); i++)
    {
        cout << left << TABULACION;
        cout << setfill(' ') << setw(ancho_nombre) << vector_edificio.obtener_valor(i)->obtener_nombre() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(ancho_general) << vector_edificio.obtener_valor(i)->obtener_material(0).obtener_cantidad() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(ancho_general) << vector_edificio.obtener_valor(i)->obtener_material(1).obtener_cantidad() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(ancho_general) << vector_edificio.obtener_valor(i)->obtener_material(2).obtener_cantidad() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(2 * ancho_general) << vector_edificio.obtener_valor(i)->obtener_cant_construidos() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(2 * ancho_general) << vector_edificio.obtener_valor(i)->obtener_cant_max() - vector_edificio.obtener_valor(i)->obtener_cant_construidos() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(ancho_general) << vector_edificio.obtener_valor(i)->obtener_materiales_otorgados().obtener_nombre() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(ancho_general / 2) << vector_edificio.obtener_valor(i)->obtener_materiales_otorgados().obtener_cantidad() << setfill(' ') << setw(1) << endl;
    }
}

void listar_edificios_construidos(Matriz_casillero &mapa, Jugador *jugador)
{
    int ancho_nombre = 19;
    int ancho_general = 11;
    cout << TABULACION << ENCABEZADO_LISTADO_MATERIALES << endl;
    cout << TABULACION << TITULO_LISTADO_EDIFICIOS_CONSTRUIDOS << endl;
    cout << TABULACION << ENCABEZADO_LISTADO_MATERIALES << endl;
    cout << left << TABULACION;
    cout << setfill(' ') << setw(ancho_nombre) << TITULO_COLUMNA_EDIFICIO << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << TITULO_COLUMNA_CANTIDAD << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_general) << TITULO_ESTADO_SALUD << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho_nombre) << TITULO_COLUMNA_COORDENADAS << setfill(' ') << setw(1) << endl;

    Vector<Edificio *> vector_construidos = jugador->obtener_edificios()->arbol_a_vector();
    for (int i = 0; i < vector_construidos.obtener_largo(); i++)
    {
        if (vector_construidos.obtener_valor(i)->obtener_cant_construidos() > 0)
        {
            string nombre = vector_construidos.obtener_valor(i)->obtener_nombre();
            string reparacion = "si";
            if (vector_construidos.obtener_valor(i)->obtener_salud() == SALUD_MAXIMA)
            {
                reparacion = "no";
            }
            cout << left << TABULACION;
            cout << setfill(' ') << setw(ancho_nombre) << nombre << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
            cout << setfill(' ') << setw(ancho_general) << vector_construidos.obtener_valor(i)->obtener_cant_construidos() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
            cout << setfill(' ') << setw(ancho_nombre) << reparacion << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
            mostrar_coordenadas(mapa, nombre);
            cout << endl;
        }
    }
}

void mostrar_coordenadas(Matriz_casillero &mapa, string nombre_edificio)
{
    for (int fila = 0; fila < mapa.obtener_largo_filas(); fila++)
    {
        for (int columna = 0; columna < mapa.obtener_largo_columnas(); columna++)
        {
            if (mapa.obtener_tipo_casillero(fila, columna) == CASILLERO_CONSTRUIBLE)
            {
                Casillero_construible *puntero_a_casillero = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila, columna));
                if (puntero_a_casillero->obtener_edificio().obtener_nombre() == nombre_edificio)
                {
                    puntero_a_casillero->obtener_posicion().mostrar();
                }
            }
        }
    }
}

void mostrar_inventario(Jugador *jugador)
{
    int ancho = ANCHO_DE_INVENTARIO;

    cout << TABULACION << ENCABEZADO_LISTADO_MATERIALES << endl;
    cout << TABULACION << TITULO_LISTADO_MATERIALES << endl;
    cout << TABULACION << ENCABEZADO_LISTADO_MATERIALES << endl;
    cout << left << TABULACION << setfill(' ') << setw(ancho) << TITULO_COLUMNA_MATERIAL << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA << setfill(' ') << setw(ancho) << TITULO_COLUMNA_CANTIDAD << setfill(' ') << setw(1) << endl;

    Vector_material *ptr_inventario = jugador->obtener_inventario();
    for (int i = 0; i < ptr_inventario->obtener_largo(); i++)
    {
        cout << left << TABULACION;
        cout << setfill(' ') << setw(ancho) << ptr_inventario->obtener_valor(i)->obtener_nombre() << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
        cout << setfill(' ') << setw(ancho) << ptr_inventario->obtener_valor(i)->obtener_cantidad() << setfill(' ') << setw(1) << endl;
    }
    cout << left << TABULACION;
    cout << setfill(' ') << setw(ancho) << BOMBAS << setfill(' ') << setw(1) << SEPARADOR_GRILLA_DERECHA;
    cout << setfill(' ') << setw(ancho) << jugador->obtener_bombas().obtener_cantidad() << setfill(' ') << setw(1) << endl;
}
void imprimir_con_retardo(string mensaje, int retardo_milisegundos)
{
    cout << mensaje << endl;
    sleep_for(milliseconds(retardo_milisegundos));
}
void retardo(int retardo_milisegundos)
{
    sleep_for(milliseconds(retardo_milisegundos));
}
