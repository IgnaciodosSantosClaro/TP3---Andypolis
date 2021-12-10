#include "menu.h"

using namespace std;
void iniciar_juego()
{
    Matriz_casillero mapa;
    procesar_mapa(mapa);
    Diccionario dicc_edificios;
    Jugador jugador1 = Jugador("jugador1");
    Jugador jugador2 = Jugador("jugador2");
    procesar_edificios(dicc_edificios, jugador1, jugador2);
    procesar_ubicaciones(mapa, jugador1, jugador2);
    menu_inicial(mapa, dicc_edificios, jugador1, jugador2);
};
void mostrar_menu_inicio()
{
    cout << TABULACION << TABULACION << TABULACION << TITULO_MENU << endl;
    cout << TABULACION << ENCABEZADO_MENU << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_1 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_2 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_3 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_4 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_5 << endl;
    cout << TABULACION << ENCABEZADO_MENU << endl;
};
void menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2)
{
    bool salir = false;
    while (salir != true)
    {
        mostrar_menu_inicio();
        salir = procesar_menu_inicial(mapa, dicc_edificios, jugador1, jugador2);
    }
};
void menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2)
{
    bool salir = false;
    Jugador jugador_vec[2];
    jugador_vec[0] = jugador1;
    jugador_vec[1] = jugador2;

    int jugador_actual = elegir_jugador_inicial(2); // Parametrizar
    jugador_actual -= 1;                            // Convierto a indice
    while (salir != true)
    {
        mostrar_mapa(mapa, 3, 3);
        mostrar_menu_juego();
        salir = procesar_menu_juego(mapa, dicc_edificios, jugador_actual, jugador_vec);
    }
}
void mostrar_menu_juego()
{
    cout << TABULACION << TABULACION << TABULACION << TITULO_MENU << endl;
    cout << TABULACION << ENCABEZADO_MENU << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_1 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_2 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_3 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_4 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_5 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_6 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_7 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_8 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_9 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_10 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_11 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_12 << endl;
    cout << TABULACION << MENSAJE_MENU_JUEGO_OPCION_13 << endl;
    cout << TABULACION << ENCABEZADO_MENU << endl;
}
bool procesar_menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2)
{
    bool salir = false;
    int opcion_elegida = obtener_opcion_ingresada();
    switch (opcion_elegida)
    {
    case INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE:
        opcion_elegida = INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE;
        modificar_edificio(dicc_edificios);
        break;
    case INICIO_LISTAR_TODOS_EDIFICIOS:
        opcion_elegida = INICIO_LISTAR_TODOS_EDIFICIOS;
        cout << "Edificios Jugador 1" << endl;
        listar_edificios_construidos(mapa, jugador1);
        cout << "Edificios Jugador 2" << endl;
        listar_edificios_construidos(mapa, jugador2); // Hacer una función que diga de quien es cada edificio
        break;
    case INICIO_MOSTRAR_MAPA:
        mostrar_mapa(mapa, 5, 3);
        break;
    case INICIO_COMENZAR_PARTIDA:
        menu_juego(mapa, dicc_edificios, jugador1, jugador2);
        break;
    case INICIO_GUARDAR_Y_SALIR_INICIAL:
        opcion_elegida = INICIO_GUARDAR_Y_SALIR_INICIAL;
        salir = true;
        break;

    default:
        opcion_elegida = OPCION_INICIAL_INVALIDA;

        break;
    }
    return salir;
}
bool procesar_menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, int &indice_jugador_actual, Jugador *jugador_vec)
{
    bool salir = false; // Verificar e imprimir energia
    cout << jugador_vec[indice_jugador_actual].obtener_nombre() << ESPACIO;
    int opcion_elegida = obtener_opcion_ingresada();
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO_POR_NOMBRE:
        // opcion_elegida = CONSTRUIR_EDIFICIO_POR_NOMBRE;

        break;
    case LISTAR_EDIFICIOS_CONSTRUIDOS:
        listar_edificios_construidos(mapa, jugador_vec[indice_jugador_actual]);
        break;
    case DEMOLER_EDIFICIO_POR_COORDENADA:
        // opcion_elegida = DEMOLER_EDIFICIO_POR_COORDENADA;
        break;
    case ATACAR_EDIFICIO_POR_COORDENADA:
        // opcion_elegida = ATACAR_EDIFICIO_POR_COORDENADA;
        atacar(mapa, jugador_vec[indice_jugador_actual]);
        break;
    case REPARAR_EDIFICIO_POR_COORDENADA:
        // opcion_elegida = REPARAR_EDIFICIO_POR_COORDENADA;
        break;
    case COMPRAR_BOMBAS:
        // opcion_elegida = COMPRAR_BOMBAS;
        // comprar_bombas(jugador_vec[indice_jugador_actual]); Falta implementar
        break;
    case CONSULTAR_COORDENADA:
        // opcion_elegida = CONSULTAR_COORDENADA;
        break;
    case MOSTRAR_INVENTARIO:
        // opcion_elegida = MOSTRAR_INVENTARIO;
        break;
    case MOSTRAR_OBJETIVOS:
        // opcion_elegida = MOSTRAR_OBJETIVOS;
        break;
    case RECOLECTAR_RECURSOS_PRODUCIDOS:
        // opcion_elegida = RECOLECTAR_RECURSOS_PRODUCIDOS;
        break;
    case MOVERSE_A_UNA_COORDENADA:
        // opcion_elegida = MOVERSE_A_UNA_COORDENADA;
        break;
    case FINALIZAR_TURNO:
        // opcion_elegida = FINALIZAR_TURNO;
        if (indice_jugador_actual == JUGADOR_1)
        {
            indice_jugador_actual = JUGADOR_2;
        }
        else
        {
            indice_jugador_actual = JUGADOR_1;
        }

        break;
    case GUARDAR_Y_SALIR:
        // opcion_elegida = GUARDAR_Y_SALIR;
        salir = true;
        break;
    default:
        cout << "no entendi" << endl;
        break;
    }

    return salir;
}
