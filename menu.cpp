#include "menu.h"

using namespace std;

void iniciar_juego()
{
    bool es_partida_nueva = true;
    Matriz_casillero mapa;
    procesar_mapa(mapa);
    Diccionario dicc_edificios;
    Jugador jugador1 = Jugador("jugador1", JUGADOR_1);
    Jugador jugador2 = Jugador("jugador2", JUGADOR_2);
    Grafo grafo1;
    Grafo grafo2;

    cargar_materiales(jugador1, jugador2);
    procesar_edificios(dicc_edificios, jugador1, jugador2);
    cargar_grafo(grafo1, mapa, 1);
    cargar_grafo(grafo2, mapa, 2);
    procesar_ubicaciones(mapa, jugador1, jugador2, grafo1, grafo2, es_partida_nueva);
    menu_inicial(mapa, dicc_edificios, jugador1, jugador2, grafo1, grafo2, es_partida_nueva);
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

void menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2, Grafo &grafo1, Grafo &grafo2, bool es_partida_nueva)
{

    bool salir = false;
    while (salir != true)
    {

        mostrar_menu_inicio();
        salir = procesar_menu_inicial(mapa, dicc_edificios, jugador1, jugador2, grafo1, grafo2, es_partida_nueva);
    }
};

void menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2, Grafo &grafo1, Grafo &grafo2, bool es_partida_nueva)
{
    bool salir = false;
    Jugador jugador_vec[MAXIMO_JUGADORES];
    Grafo grafo_vec[MAXIMO_JUGADORES];
    Vector_objetivo objetivos_generales;
    cargar_objetivos(objetivos_generales, dicc_edificios.consulta(NOMBRE_EDIFICIO_ESCUELA)->obtener_cant_max());
    asignar_objetivos(objetivos_generales, jugador1, 2);
    asignar_objetivos(objetivos_generales, jugador2, 2);
    jugador_vec[POSICION_JUGADOR_1] = jugador1;
    jugador_vec[POSICION_JUGADOR_2] = jugador2;
    grafo_vec[POSICION_JUGADOR_1] = grafo1;
    grafo_vec[POSICION_JUGADOR_2] = grafo2;
    int jugador_actual = elegir_jugador_inicial(MAXIMO_JUGADORES);
    jugador_actual -= 1; // Paso a indice
    if(es_partida_nueva)
    {
        inicializar_posicion_jugador(mapa, jugador_vec[POSICION_JUGADOR_1]);
        inicializar_posicion_jugador(mapa, jugador_vec[POSICION_JUGADOR_2]);
    }
    lluvia_recursos(mapa);
    bool jugo_1 = false;
    bool jugo_2 = false;
    while (salir != true)
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
        salir = procesar_menu_juego(mapa, dicc_edificios, jugador_actual, jugador_vec, grafo_vec, jugo_1, jugo_2, es_partida_nueva);
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

bool procesar_menu_inicial(Matriz_casillero &mapa, Diccionario &dicc_edificios, Jugador &jugador1, Jugador &jugador2, Grafo &grafo1, Grafo &grafo2, bool es_partida_nueva)
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
        opcion_elegida = INICIO_LISTAR_TODOS_EDIFICIOS;
         if(!es_partida_nueva)
        {
            cout << TABULACION << "Edificios Jugador 1" << endl;
            listar_todos_edificios(*jugador1.obtener_edificios());
            cout << endl;
            cout << TABULACION << "Edificios Jugador 2" << endl;
            listar_todos_edificios(*jugador2.obtener_edificios());
        }
        else
        {
             listar_todos_edificios(dicc_edificios);
        }
        break;
    case INICIO_MOSTRAR_MAPA:
        mostrar_mapa(mapa, 5, 3);
        break;
    case INICIO_COMENZAR_PARTIDA:
        menu_juego(mapa, dicc_edificios, jugador1, jugador2, grafo1, grafo2, es_partida_nueva);
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

bool procesar_menu_juego(Matriz_casillero &mapa, Diccionario &dicc_edificios, int &indice_jugador_actual, Jugador *jugador_vec, Grafo *grafo_vec, bool &jugo_1, bool &jugo_2, bool es_partida_nueva)
{
    bool salir = false; // Verificar e imprimir energia

    cout << jugador_vec[indice_jugador_actual].obtener_nombre() << ESPACIO;
    cout << INGRESE_ACCION << endl;
    Input input;
    string entrada_usuario;
    cin >> entrada_usuario;
    confirmar_opcion_valida(entrada_usuario, input, CONSTRUIR_EDIFICIO_POR_NOMBRE, GUARDAR_Y_SALIR);
    int opcion_elegida = input.obtener_input();
    system(CLR_SCREEN);
    mostrar_menu_juego();
    if(es_turno_valido(jugador_vec[indice_jugador_actual]))
    {
        opcion_elegida = FINALIZAR_TURNO;
    }
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO_POR_NOMBRE:
        construir_edificio(mapa, grafo_vec[indice_jugador_actual], jugador_vec[indice_jugador_actual]);
        break;
    case LISTAR_EDIFICIOS_CONSTRUIDOS:
        listar_edificios_construidos(mapa, jugador_vec[indice_jugador_actual]);
        break;
    case DEMOLER_EDIFICIO_POR_COORDENADA:
        demoler_edificio(mapa, grafo_vec[indice_jugador_actual], jugador_vec[indice_jugador_actual], indice_jugador_actual + 1);
        break;
    case ATACAR_EDIFICIO_POR_COORDENADA:

        if (tiene_energia(jugador_vec[indice_jugador_actual], ENERGIA_ATACAR))
        {
            atacar(mapa, jugador_vec[indice_jugador_actual]);
        }
        else
        {
            imprimir_con_retardo("Energia insuficiente", 2000);
        }
        break;
    case REPARAR_EDIFICIO_POR_COORDENADA:
        if (tiene_energia(jugador_vec[indice_jugador_actual], ENERGIA_REPARAR))
        {
            reparar(mapa, jugador_vec[indice_jugador_actual]);
        }
        else
        {
            imprimir_con_retardo("Energia insuficiente", 2000);
        }
        break;
    case COMPRAR_BOMBAS:
        comprar_bombas(jugador_vec[indice_jugador_actual]);
        break;
    case CONSULTAR_COORDENADA:
        consultar_coordenada(mapa);
        break;
    case MOSTRAR_INVENTARIO:
        mostrar_inventario(jugador_vec[indice_jugador_actual]);
        break;
    case MOSTRAR_OBJETIVOS:
        jugador_vec[indice_jugador_actual].mostrar_objetivos_restantes();
        retardo(2500);
        break;
    case RECOLECTAR_RECURSOS_PRODUCIDOS:
        recolectar_recursos_producidos(jugador_vec[indice_jugador_actual]);
        break;
    case MOVERSE_A_UNA_COORDENADA:
        // opcion_elegida = MOVERSE_A_UNA_COORDENADA;
        break;
    case FINALIZAR_TURNO:
        // opcion_elegida = FINALIZAR_TURNO;
        jugador_vec[indice_jugador_actual].modificar_energia(ENERGIA_FIN_TURNO);
        if (indice_jugador_actual == JUGADOR_1)
        {
            cout << "Jugo 1" << endl;
            jugo_1 = true;
            indice_jugador_actual = JUGADOR_2;
        }
        else
        {
            cout << "Jugo 2" << endl;
            jugo_2 = true;
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