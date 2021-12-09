#include "Menu.h"

using namespace std;
void iniciar_juego()
{
    Matriz_casillero mapa;
    procesar_mapa(mapa);
    // procesar_ubicaciones(mapa); procesar con jugadores
    menu_inicial(mapa);
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
void menu_inicial(Matriz_casillero &mapa)
{
    bool salir = false;
    while (salir != true)
    {
        mostrar_menu_inicio();
        salir = procesar_menu_inicial(mapa);
    }
};
void menu_juego(Matriz_casillero &mapa)
{
    bool salir = false;
    while (salir != true)
    {
        mostrar_mapa(mapa, 5, 3);
        mostrar_menu_juego();
        salir = procesar_menu_juego();
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
bool procesar_menu_inicial(Matriz_casillero &mapa)
{
    bool salir = false;
    int opcion_elegida = obtener_opcion_ingresada();
    switch (opcion_elegida)
    {
    case INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE:
        opcion_elegida = INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE;
        break;
    case INICIO_LISTAR_TODOS_EDIFICIOS:
        opcion_elegida = INICIO_LISTAR_TODOS_EDIFICIOS;
        break;
    case INICIO_MOSTRAR_MAPA:
        mostrar_mapa(mapa, 5, 3);
        break;
    case INICIO_COMENZAR_PARTIDA:
        menu_juego(mapa);
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
bool procesar_menu_juego()
{
    bool salir = false;
    int opcion_elegida = obtener_opcion_ingresada();
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO_POR_NOMBRE:
        opcion_elegida = CONSTRUIR_EDIFICIO_POR_NOMBRE;
        break;
    case LISTAR_EDIFICIOS_CONSTRUIDOS:
        opcion_elegida = LISTAR_EDIFICIOS_CONSTRUIDOS;
        break;
    case DEMOLER_EDIFICIO_POR_COORDENADA:
        opcion_elegida = DEMOLER_EDIFICIO_POR_COORDENADA;
        break;
    case ATACAR_EDIFICIO_POR_COORDENADA:
        opcion_elegida = ATACAR_EDIFICIO_POR_COORDENADA;
        break;
    case COMPRAR_BOMBAS:
        opcion_elegida = COMPRAR_BOMBAS;
        break;
    case CONSULTAR_COORDENADA:
        opcion_elegida = CONSULTAR_COORDENADA;
        break;
    case MOSTRAR_INVENTARIO:
        opcion_elegida = MOSTRAR_INVENTARIO;
        break;
    case MOSTRAR_OBJETIVOS:
        opcion_elegida = MOSTRAR_OBJETIVOS;
        break;
    case RECOLECTAR_RECURSOS_PRODUCIDOS:
        opcion_elegida = RECOLECTAR_RECURSOS_PRODUCIDOS;
        break;
    case MOVERSE_A_UNA_COORDENADA:
        opcion_elegida = MOVERSE_A_UNA_COORDENADA;
        break;
    case FINALIZAR_TURNO:
        opcion_elegida = FINALIZAR_TURNO;
        break;
    case GUARDAR_Y_SALIR:
        opcion_elegida = GUARDAR_Y_SALIR;
        break;
    default:
        opcion_elegida = OPCION_JUEGO_INVALIDA;
        salir = true;
        break;
    }
    return salir;
}
