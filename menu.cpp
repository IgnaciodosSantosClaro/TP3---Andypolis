#include "menu.h"

using namespace std;

void iniciar_juego()
{
    bool es_partida_nueva = true;
    Matriz_casillero mapa;
    procesar_mapa(mapa);
    Diccionario dicc_edificios;
    Vector_jugador jugadores;
    Vector_grafo grafos;
    jugadores.agregar_jugador_al_final("Jugador1", JUGADOR_1);
    jugadores.agregar_jugador_al_final("Jugador2", JUGADOR_2);
    grafos.agregar_grafo_al_final();
    grafos.agregar_grafo_al_final();

    cargar_materiales(jugadores.obtener_valor(POSICION_JUGADOR_1), jugadores.obtener_valor(POSICION_JUGADOR_2));
    procesar_edificios(dicc_edificios, jugadores);

    cargar_grafo(grafos.obtener_valor(POSICION_JUGADOR_1), mapa, 1);
    cargar_grafo(grafos.obtener_valor(POSICION_JUGADOR_2), mapa, 2);
    procesar_ubicaciones(mapa, jugadores, grafos, es_partida_nueva);
    menu_inicial(mapa, dicc_edificios, jugadores, grafos, es_partida_nueva);
};

void mostrar_menu_inicio()
{
    cout << TABULACION << endl;
    cout << TABULACION << TABULACION << TABULACION << TITULO_MENU << endl;
    cout << TABULACION << ENCABEZADO_MENU << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_1 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_2 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_3 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_4 << endl;
    cout << TABULACION << MENSAJE_MENU_INICIAL_5 << endl;
    cout << TABULACION << ENCABEZADO_MENU << endl;
    cout << TABULACION << endl;
};

void menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Vector_jugador &jugadores, Vector_grafo &grafos, bool es_partida_nueva)
{

    bool salir = false;
    while (salir != true)
    {

        mostrar_menu_inicio();
        salir = procesar_menu_inicial(mapa, dicc_edificios, jugadores, grafos, es_partida_nueva);
    }
};

void menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, Vector_jugador &jugadores, Vector_grafo &grafos, bool es_partida_nueva)
{
    bool salir = false;

    Vector_objetivo objetivos_generales;

    cargar_objetivos(objetivos_generales, dicc_edificios.consulta(NOMBRE_EDIFICIO_ESCUELA)->obtener_cant_max());
    asignar_objetivos(objetivos_generales, jugadores.obtener_valor(POSICION_JUGADOR_1), 2);
    asignar_objetivos(objetivos_generales, jugadores.obtener_valor(POSICION_JUGADOR_2), 2);

    int jugador_actual = elegir_jugador_inicial(MAXIMO_JUGADORES);
    jugador_actual -= 1; // Paso a indice
    if (es_partida_nueva)
    {

        inicializar_posicion_jugador(mapa, jugadores.obtener_valor(POSICION_JUGADOR_1));
        inicializar_posicion_jugador(mapa, jugadores.obtener_valor(POSICION_JUGADOR_2));
    }
    lluvia_recursos(mapa);
    bool jugo_1 = false;
    bool jugo_2 = false;
    bool gano = false;
    while (salir != true && gano != true)
    {
        retardo(2500);
        if (jugo_1 == true && jugo_2 == true)
        {
            lluvia_recursos(mapa);
            jugo_1 = false;
            jugo_2 = false;
        }
        mostrar_mapa(mapa, 5, 3);
        mostrar_menu_juego();
        salir = procesar_menu_juego(mapa, dicc_edificios, jugador_actual, jugadores, grafos, jugo_1, jugo_2, es_partida_nueva, gano);
    }
    if (gano == true)
    {
        cout << "Gano " << jugadores.obtener_valor(jugador_actual)->obtener_nombre() << endl;
    }
}

void mostrar_menu_juego()
{
    cout << TABULACION << endl;
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
    cout << TABULACION << endl;
}

bool procesar_menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Vector_jugador &jugadores, Vector_grafo &grafos, bool es_partida_nueva)
{
    bool salir = false;
    cout << INGRESE_ACCION << endl;
    Input input;
    string entrada_usuario;
    cin >> entrada_usuario;
    confirmar_opcion_valida(entrada_usuario, input, INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE, INICIO_GUARDAR_Y_SALIR_INICIAL);
    int opcion_elegida = input.obtener_input();
    system(CLR_SCREEN);
    switch (opcion_elegida)
    {
    case INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE:
        opcion_elegida = INICIO_MODIFICAR_EDIFICIO_POR_NOMBRE;
        modificar_edificio(dicc_edificios);
        break;
    case INICIO_LISTAR_TODOS_EDIFICIOS:
        listar_todos_edificios(dicc_edificios);
        break;
    case INICIO_MOSTRAR_MAPA:
        mostrar_mapa(mapa, 5, 3);
        break;
    case INICIO_COMENZAR_PARTIDA:
        menu_juego(mapa, dicc_edificios, jugadores, grafos, es_partida_nueva);
        salir = true;
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

bool procesar_menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, int &indice, Vector_jugador &jugadores, Vector_grafo &grafos, bool &jugo_1, bool &jugo_2, bool es_partida_nueva, bool &gano)
{
    bool salir = false;
    gano = verificar_objetivos_inventario(jugadores.obtener_valor(indice));
    cout << jugadores.obtener_valor(indice)->obtener_nombre() << ESPACIO;
    cout << INGRESE_ACCION << endl;
    Input input;
    string entrada_usuario;
    cin >> entrada_usuario;
    confirmar_opcion_valida(entrada_usuario, input, CONSTRUIR_EDIFICIO_POR_NOMBRE, GUARDAR_Y_SALIR);
    int opcion_elegida = input.obtener_input();
    system(CLR_SCREEN);
    mostrar_menu_juego();
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO_POR_NOMBRE:
        construir_edificio(mapa, grafos.obtener_valor(indice), jugadores.obtener_valor(indice), gano);
        break;
    case LISTAR_EDIFICIOS_CONSTRUIDOS:
        listar_edificios_construidos(mapa, jugadores.obtener_valor(indice));
        break;
    case DEMOLER_EDIFICIO_POR_COORDENADA:
        demoler_edificio(mapa, grafos.obtener_valor(indice), jugadores.obtener_valor(indice), indice + 1);
        break;
    case ATACAR_EDIFICIO_POR_COORDENADA:
        if (tiene_energia(jugadores.obtener_valor(indice), ENERGIA_ATACAR))
        {
            atacar(mapa, jugadores.obtener_valor(indice));
        }
        else
        {
            imprimir_con_retardo(MENSAJE_ENERGIA_INSUFICIENTE, 2000);
        }
        break;
    case REPARAR_EDIFICIO_POR_COORDENADA:
        if (tiene_energia(jugadores.obtener_valor(indice), ENERGIA_REPARAR))
        {
            reparar(mapa, jugadores.obtener_valor(indice));
        }
        else
        {
            imprimir_con_retardo(MENSAJE_ENERGIA_INSUFICIENTE, 2000);
        }
        if (tiene_energia(jugadores.obtener_valor(indice), ENERGIA_ATACAR))
        {
            reparar(mapa, jugadores.obtener_valor(indice));
        }
        else
        {
            imprimir_con_retardo("Energia insuficiente", 2000);
        }
        break;
    case COMPRAR_BOMBAS:
        comprar_bombas(jugadores.obtener_valor(indice), gano);

        break;
    case CONSULTAR_COORDENADA:
        consultar_coordenada(mapa);
        break;
    case MOSTRAR_INVENTARIO:
        mostrar_inventario(jugadores.obtener_valor(indice));
        break;
    case MOSTRAR_OBJETIVOS:
        jugadores.obtener_valor(indice)->mostrar_objetivos_restantes();
        retardo(2500);
        break;
    case RECOLECTAR_RECURSOS_PRODUCIDOS:
        recolectar_recursos_producidos(jugadores.obtener_valor(indice));
        break;
    case MOVERSE_A_UNA_COORDENADA:
        desplazarse(mapa, grafos.obtener_valor(indice), jugadores.obtener_valor(indice), indice + 1);
        break;
    case FINALIZAR_TURNO:
        if (indice == POSICION_JUGADOR_1)
        {
            jugo_1 = true;
            indice = POSICION_JUGADOR_2;
        }
        else
        {
            jugo_2 = true;
            indice = POSICION_JUGADOR_1;
        }

        break;
    case GUARDAR_Y_SALIR:
        salir = true;
        guardar_y_salir(mapa, jugadores, dicc_edificios);
        break;
    default:
        cout << "no entendi" << endl;
        break;
    }

    return salir;
}