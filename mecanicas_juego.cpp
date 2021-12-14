#include "mecanicas_juego.h"

void modificar_edificio(Diccionario &diccionario)
{
    Input input;
    string nombre = pedir_nombre();
    Edificio *edificio_buscado = diccionario.consulta(nombre);
    if (edificio_buscado != NULL)
    {
        if (edificio_buscado->obtener_nombre().compare(NOMBRE_EDIFICIO_OBELISCO) == 0)
        {
            cout << COLOR_TEXTO_ROJO << "El obelisco no puede modificarse" << COLOR_TEXTO_BLANCO << endl;
        }
        else
        {
            for (int i = 0; i < MAX_MATERIALES_CONSTRUIBLES; i++)
            {
                Material_consumible material = edificio_buscado->obtener_material(i);
                cout << "La cantidad de " << material.obtener_nombre() << " necesaria para construir un/a "
                     << edificio_buscado->obtener_nombre() << " es " << material.obtener_cantidad() << endl;
                cout << DESEA_MODIFICAR_MATERIAL << endl;
                if (confirmar_decision())
                {
                    cout << "Ingrese la nueva cantidad de " << material.obtener_nombre() << " que este en el rango (0-50000): " << endl;
                    Input input;
                    string nueva_cantidad;
                    cin >> nueva_cantidad;
                    confirmar_opcion_valida(nueva_cantidad, input, 0 + 1, 50000 - 1);
                    edificio_buscado->fijar_material_constuible(input.obtener_input(), i);
                }
            }
        }
    }
    else
    {
        cout << COLOR_TEXTO_ROJO << EDIFICIO_INEXISTENTE << COLOR_TEXTO_BLANCO << endl;
    }
}

void atacar(Matriz_casillero &mapa, Jugador *jugador)
{
    cout << MENSAJE_ATACAR_EDIFICO << endl;
    int coord_x;
    int coord_y;
    obtener_coordenadas(coord_x, coord_y, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
    Casillero_construible *casillero_elegido;
    if (mapa.obtener_tipo_casillero(coord_x, coord_y) == CASILLERO_CONSTRUIBLE)
    {
        casillero_elegido = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(coord_x, coord_y));
        Bomba bombas_disponibles = jugador->obtener_bombas();
        bombas_disponibles.tirar_bomba(*casillero_elegido);
        jugador->fijar_bombas(bombas_disponibles);
    }
    else
    {
        cout << MENSAJE_CASILLERO_NO_CONSTRUIBLE << endl;
    }
}

void comprar_bombas(Jugador *jugador)
{
    if (jugador->obtener_energia() >= CONSUMO_ENERGIA_COMPRAR_BOMBAS)
    {
        Input input;
        string cantidad;
        cout << "Ingrese la cantidad de bombas que desea comprar: " << endl;
        cin >> cantidad;
        confirmar_opcion_valida(cantidad, input, 1, INT_MAX);
        int pos_buscada = jugador->obtener_inventario()->obtener_pos_material(ANDYCOINS);
        int cantidad_andycoins = jugador->obtener_inventario()->obtener_valor(pos_buscada)->obtener_cantidad();
        if (input.obtener_input() * PRECIO_BOMBAS > cantidad_andycoins)
        {
            cout << COLOR_TEXTO_ROJO << ANDYCOINS_INSUFICIENTES << COLOR_TEXTO_BLANCO << endl;
        }
        else
        {
            cantidad_andycoins -= input.obtener_input() * PRECIO_BOMBAS;
            jugador->obtener_inventario()->obtener_valor(pos_buscada)->fijar_cantidad(cantidad_andycoins);
            jugador->modificar_energia(-CONSUMO_ENERGIA_COMPRAR_BOMBAS);
            jugador->modificar_cantidad_bomba(input.obtener_input());
            cout << "Se han adquirido " << input.obtener_input() << " bombas." << endl;
            cout << "Se tienen " << cantidad_andycoins << " andycoins." << endl;
        }
    }
    else
    {
        cout << COLOR_TEXTO_ROJO << ENERGIA_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
    }
}

void recolectar_recursos_producidos(Jugador *jugador)
{
    if (jugador->obtener_energia() >= CONSUMO_ENERGIA_RECOLECTAR_RECURSOS)
    {
        int cant_piedra = 0;
        int cant_madera = 0;
        int cant_metal = 0;
        int cant_andycoins = 0;
        int cant_energia = 0;
        Vector<Edificio *> vector_edificios = jugador->obtener_edificios()->arbol_a_vector();

        for (int i = 0; i < vector_edificios.obtener_largo(); i++)
        {
            Edificio *edificio_actual = vector_edificios.obtener_valor(i);
            Material_consumible recurso = edificio_actual->obtener_materiales_otorgados();
            string nombre_recurso = recurso.obtener_nombre();
            int cant_construcciones = edificio_actual->obtener_cant_construidos();

            if (nombre_recurso.compare(PIEDRA) == 0 && cant_construcciones > 0)
            {
                cant_piedra = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_piedra = jugador->obtener_inventario()->obtener_pos_material(PIEDRA);
                int cant_piedra_actual = jugador->obtener_inventario()->obtener_valor(pos_piedra)->obtener_cantidad();
                jugador->obtener_inventario()->obtener_valor(pos_piedra)->fijar_cantidad(cant_piedra + cant_piedra_actual);
            }
            else if (nombre_recurso.compare(MADERA) == 0 && cant_construcciones > 0)
            {
                cant_madera = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_madera = jugador->obtener_inventario()->obtener_pos_material(MADERA);
                int cant_madera_actual = jugador->obtener_inventario()->obtener_valor(pos_madera)->obtener_cantidad();
                jugador->obtener_inventario()->obtener_valor(pos_madera)->fijar_cantidad(cant_madera + cant_madera_actual);
            }
            else if (nombre_recurso.compare(METAL) == 0 && cant_construcciones > 0)
            {
                cant_metal = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_metal = jugador->obtener_inventario()->obtener_pos_material(METAL);
                int cant_metal_actual = jugador->obtener_inventario()->obtener_valor(pos_metal)->obtener_cantidad();
                jugador->obtener_inventario()->obtener_valor(pos_metal)->fijar_cantidad(cant_metal + cant_metal_actual);
            }
            else if (nombre_recurso.compare(ANDYCOINS) == 0 && cant_construcciones > 0)
            {
                cant_andycoins = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_andycoins = jugador->obtener_inventario()->obtener_pos_material(ANDYCOINS);
                int cant_andycoins_actual = jugador->obtener_inventario()->obtener_valor(pos_andycoins)->obtener_cantidad();
                jugador->obtener_inventario()->obtener_valor(pos_andycoins)->fijar_cantidad(cant_andycoins + cant_andycoins_actual);
            }
            else if (nombre_recurso.compare(ENERGIA) == 0 && cant_construcciones > 0)
            {
                cant_energia = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_energia = jugador->obtener_inventario()->obtener_pos_material(ENERGIA);
                int cant_energia_actual = jugador->obtener_inventario()->obtener_valor(pos_energia)->obtener_cantidad();
                jugador->obtener_inventario()->obtener_valor(pos_energia)->fijar_cantidad(cant_energia + cant_energia_actual);
            }
        }
        jugador->modificar_energia(-CONSUMO_ENERGIA_RECOLECTAR_RECURSOS);
        cout << MENSAJE_RECOLECCION << endl;
        cout << PIEDRA_MAYUS << " : " << cant_piedra << endl;
        cout << MADERA_MAYUS << " : " << cant_madera << endl;
        cout << METAL_MAYUS << " : " << cant_metal << endl;
        cout << ANDYCOINS_MAYUS << " : " << cant_andycoins << endl;
        cout << ENERGIA_MAYUS << " : " << cant_energia << endl;
    }
    else
    {
        cout << COLOR_TEXTO_ROJO << ENERGIA_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
    }
}

void consultar_coordenada(Matriz_casillero &mapa)
{
    int coord_x;
    int coord_y;
    cout << INGRESE_COORDENADAS_CONSULTAR << endl;
    obtener_coordenadas(coord_x, coord_y, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
    mapa.obtener_dato(coord_x, coord_y)->mostrar();
}
void reparar(Matriz_casillero &mapa, Jugador *jugador)
{

    cout << MENSAJE_ATACAR_EDIFICO << endl;
    int coord_x;
    int coord_y;
    obtener_coordenadas(coord_x, coord_y, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());

    if (puede_reparar(mapa.obtener_dato(coord_x, coord_y), jugador) == true)
    {
        Casillero_construible *casillero_seleccionado = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(coord_x, coord_y));
        Edificio edificio_seleccionado = casillero_seleccionado->obtener_edificio();
        Edificio *edificio_modelo = jugador->obtener_edificios()->consulta(casillero_seleccionado->obtener_edificio().obtener_nombre());
        int madera_necesaria = (int)(edificio_modelo->obtener_material(POSICION_MADERA).obtener_cantidad() * 0.25);
        int metal_necesaria = (int)(edificio_modelo->obtener_material(POSICION_METAL).obtener_cantidad() * 0.25);
        int piedra_necesaria = (int)(edificio_modelo->obtener_material(POSICION_PIEDRA).obtener_cantidad() * 0.25);
        jugador->obtener_inventario()->obtener_por_nombre(MADERA)->reducir_cantidad(madera_necesaria);
        jugador->obtener_inventario()->obtener_por_nombre(METAL)->reducir_cantidad(metal_necesaria);
        jugador->obtener_inventario()->obtener_por_nombre(PIEDRA)->reducir_cantidad(piedra_necesaria);
        Edificio edificio_aux = casillero_seleccionado->obtener_edificio();
        edificio_aux.fijar_puntos_de_salud(PUNTOS_SALUD_BASE);
        casillero_seleccionado->fijar_edificio(edificio_aux);
        if (casillero_seleccionado->obtener_edificio().obtener_dueno() == JUGADOR_1)
        {
            casillero_seleccionado->fijar_color_texto(COLOR_EDIFICIO_SANO_JUG_1);
        }
        else
        {
            casillero_seleccionado->fijar_color_texto(COLOR_EDIFICIO_SANO_JUG_2);
        }
        imprimir_con_retardo(MENSAJE_REPARACION_EXITOSA, 2000);
        jugador->modificar_energia(-ENERGIA_REPARAR);
    }
    else
    {
        imprimir_con_retardo(MENSAJE_CASILLERO_NO_REPARABLE, 2000);
    }
}
void lluvia_recursos(Matriz_casillero &mapa)
{
    imprimir_con_retardo(MENSAJE_LLUVIA_INICIO, 2000);
    int limite_filas = mapa.obtener_largo_filas();
    int limite_columnas = mapa.obtener_largo_columnas();

    int cantidad_metal_a_generar;
    int cantidad_piedra_a_generar;
    int cantidad_madera_a_generar;
    int cantidad_andycoins_a_generar;
    generar_cantidades_de_recursos(cantidad_metal_a_generar, cantidad_piedra_a_generar, cantidad_madera_a_generar, cantidad_andycoins_a_generar);
    int cantidad_casilleros = cantidad_madera_a_generar + cantidad_piedra_a_generar + cantidad_metal_a_generar + cantidad_andycoins_a_generar;
    bool generacion_completa = false;
    int cantidad_metal_generada = 0;
    int cantidad_piedra_generada = 0;
    int cantidad_madera_generada = 0;
    int cantidad_andycoins_generada = 0;
    int cantidad_casilleros_completados = 0;
    int cantidad_casilleros_ocupados = 0;
    bool mapa_completo = false;
    while (!generacion_completa)
    {
        int fila;
        int columna;
        coordenadas_aleatorias(limite_filas, limite_columnas, fila, columna);

        if (mapa.obtener_tipo_casillero(fila, columna) == CASILLERO_TRANSITABLE)
        {
            Casillero_transitable *puntero_a_casillero = dynamic_cast<Casillero_transitable *>(mapa.obtener_dato(fila, columna));
            if (!puntero_a_casillero->casillero_ocupado())
            {

                if (cantidad_metal_generada < cantidad_metal_a_generar)
                {
                    puntero_a_casillero->ocupar_casillero(Material_consumible(METAL, CANT_METAL_EN_BOLSA, ICONO_METAL));
                    cantidad_metal_generada++;
                }
                else if (cantidad_piedra_generada < cantidad_piedra_a_generar)
                {
                    puntero_a_casillero->ocupar_casillero(Material_consumible(PIEDRA, CANT_PIEDRA_EN_BOLSA, ICONO_PIEDRA));
                    cantidad_piedra_generada++;
                }
                else if (cantidad_madera_generada < cantidad_madera_a_generar)
                {
                    puntero_a_casillero->ocupar_casillero(Material_consumible(MADERA, CANT_MADERA_EN_BOLSA, ICONO_MADERA));
                    cantidad_madera_generada++;
                }
                else if (cantidad_andycoins_generada < cantidad_andycoins_a_generar)
                {
                    puntero_a_casillero->ocupar_casillero(Material_consumible(ANDYCOINS, CANT_ANDYCOINS_EN_BOLSA, ICONO_ANDYCOINS));
                    cantidad_andycoins_generada++;
                }
                cantidad_casilleros_completados++;
            }
            else
            {
                cantidad_casilleros_ocupados++;
            }
        }
        if (cantidad_casilleros_completados == cantidad_casilleros)
        {
            generacion_completa = true;
        }
        else if (cantidad_casilleros_ocupados == mapa.obtener_cant_transitables())
        {
            generacion_completa = true;
            mapa_completo = true;
        }
    }
    if (mapa_completo)
    {
        cout << MENSAJE_TRANSITABLES_COMPLETO << endl;
    }
    else
    {
        tormenta(1);
        cout << MENSAJE_LLUVIA_COMPLETA << endl;
        cout << PIEDRA << ESPACIO << cantidad_piedra_generada << endl;
        cout << METAL << ESPACIO << cantidad_metal_generada << endl;
        cout << MADERA << ESPACIO << cantidad_madera_generada << endl;
        cout << ANDYCOINS << ESPACIO << cantidad_madera_generada << endl;
    }
}
// Espera dos Vectores objetivos y dos jugadores
void asignar_objetivos(Vector_objetivo &vector, Jugador *jugador, int cantidad_secundarios)
{
    jugador->asignar_objetivo_principal(vector.obtener_valor(POSICION_OBJETIVO_PRINCIPAL));
    Vector<int> indices_jug;
    int indice;
    for (int i = 0; i < cantidad_secundarios; i++)
    {
        indice = numero_aleatorio(CANTIDAD_TOTAL_OBJETIVOS_SECUNDARIOS, CANTIDAD_OBJETIVO_PRINCIPAL);
        while (indice_repetido(indice, indices_jug) == true)
        {
            indice = numero_aleatorio(CANTIDAD_TOTAL_OBJETIVOS_SECUNDARIOS, CANTIDAD_OBJETIVO_PRINCIPAL);
        }
        indices_jug.agregar_al_final(indice);
        jugador->asignar_objetivo_secundario(vector.obtener_valor(indice));
    }
}
bool verificar_objetivos_inventario(Jugador *jugador)
{
    int energia = jugador->obtener_energia();
    int cantidad_piedra = jugador->obtener_inventario()->obtener_por_nombre(PIEDRA)->obtener_cantidad();
    int cantidad_bombas = jugador->obtener_bombas().obtener_cantidad();
    if (jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_EDAD_PIEDRA, cantidad_piedra) != OBJETIVO_COMPLETO)
    {
        jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_EDAD_PIEDRA, cantidad_piedra);
    }
    if (jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_ENERGETICO, -energia) != OBJETIVO_COMPLETO)
    {
        jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_ENERGETICO, -energia);
    }
    if (jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_CANSADO, energia) != OBJETIVO_COMPLETO)
    {
        jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_CANSADO, -energia);
    }
    if (jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_ARMADO, cantidad_bombas) != OBJETIVO_COMPLETO)
    {
        jugador->obtener_objetivos()->actualizar_por_nombre(NOMBRE_CANSADO, -cantidad_bombas);
    }
    return jugador->cumplio_objetivos();
}
bool indice_repetido(int indice_a_revisar, Vector<int> indices)
{
    bool esta_duplicado = false;
    for (int i = 0; i < indices.obtener_largo(); i++)
    {
        if (indice_a_revisar == indices.obtener_valor(i))
        {
            esta_duplicado = true;
        }
    }
    return esta_duplicado;
}
void construir_edificio(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, bool &gano)
{
    if (tiene_energia(jugador, CONSUMO_ENERGIA_CONSTRUIR_EDIFICIO))
    {
        string nombre_edificio = pedir_nombre();
        Errores estado = verificar_construccion(jugador, nombre_edificio);
        if (estado != EXITO)
        {
            procesar_errores(estado);
        }
        else
        {
            cout << DESEA_CONSTRUIR << endl;
            if (confirmar_decision())
            {
                int fila = 0;
                int columna = 0;
                obtener_coordenadas(fila, columna, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
                Errores estado_coordenadas = validar_coordenadas_construccion(fila, columna, mapa);
                if (estado_coordenadas != EXITO)
                {
                    procesar_errores(estado_coordenadas);
                }
                else
                {
                    Casillero_construible *ptr_casillero = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila, columna));
                    Edificio *edificio_objetivo = jugador->obtener_edificios()->consulta(nombre_edificio);
                    jugador->obtener_inventario()->obtener_por_nombre(PIEDRA)->reducir_cantidad(edificio_objetivo->obtener_material(POSICION_PIEDRA).obtener_cantidad());
                    jugador->obtener_inventario()->obtener_por_nombre(MADERA)->reducir_cantidad(edificio_objetivo->obtener_material(POSICION_MADERA).obtener_cantidad());
                    jugador->obtener_inventario()->obtener_por_nombre(METAL)->reducir_cantidad(edificio_objetivo->obtener_material(POSICION_METAL).obtener_cantidad());
                    jugador->modificar_energia(-CONSUMO_ENERGIA_CONSTRUIR_EDIFICIO);
                    string color_edificio = asignar_color_edificio_sano(jugador);
                    edificio_objetivo->incrementar_construcciones();
                    ptr_casillero->ocupar_casillero(*edificio_objetivo, color_edificio);
                    Coordenada coordenada;
                    coordenada.fijar_coordenadas(fila, columna);
                    actualizar_aristas_grafo(mapa, grafo, coordenada, INFINITO);
                    cout << COLOR_TEXTO_VERDE << MENSAJE_CONSTRUCCION_EXITOSA << COLOR_TEXTO_BLANCO << endl;
                    if (jugador->actualizar_objetivos(edificio_objetivo->obtener_nombre(), 1) == OBJETIVO_COMPLETO)
                    {
                        gano = true;
                    }
                }
            }
            else
            {
                cout << COLOR_TEXTO_ROJO << MENSAJE_CONSTRUCCION_CANCELADA << COLOR_TEXTO_BLANCO << endl;
            }
        }
    }
    else
    {
        imprimir_con_retardo(MENSAJE_ENERGIA_INSUFICIENTE, 2500);
    }
}

void demoler_edificio(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, int numero_jugador)
{
    if (tiene_energia(jugador, CONSUMO_ENERGIA_DEMOLER_EDIFICIO))
    {
        cout << INGRESE_COORDENADAS_DESTRUIR << endl;
        int fila = 0;
        int columna = 0;
        obtener_coordenadas(fila, columna, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
        Errores estado_coordenada = validar_coordenadas_destruccion(fila, columna, mapa, numero_jugador);
        if (estado_coordenada != EXITO)
        {
            procesar_errores(estado_coordenada);
        }
        else
        {
            Coordenada coordenada;
            coordenada.fijar_coordenadas(fila, columna);
            Casillero_construible *puntero_casillero = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila,
                                                                                                               columna));
            Edificio edificio_objetivo = puntero_casillero->obtener_edificio();
            Edificio *edificio_a_demoler = jugador->obtener_edificios()->consulta(edificio_objetivo.obtener_nombre());
            jugador->obtener_inventario()->obtener_por_nombre(PIEDRA)->aumentar_cantidad(
                edificio_a_demoler->obtener_material(POSICION_PIEDRA).obtener_cantidad() / 2);
            jugador->obtener_inventario()->obtener_por_nombre(MADERA)->aumentar_cantidad(
                edificio_a_demoler->obtener_material(POSICION_MADERA).obtener_cantidad() / 2);
            jugador->obtener_inventario()->obtener_por_nombre(METAL)->aumentar_cantidad(
                edificio_a_demoler->obtener_material(POSICION_METAL).obtener_cantidad() / 2);
            edificio_a_demoler->decrementar_construcciones();
            puntero_casillero->desocupar_casillero();
            jugador->modificar_energia(-CONSUMO_ENERGIA_DEMOLER_EDIFICIO);

            int peso = puntero_casillero->obtener_energia_necesaria()[numero_jugador - 1];
            actualizar_aristas_grafo(mapa, grafo, coordenada, peso);

            cout << COLOR_TEXTO_VERDE << MENSAJE_DESTRUCCION_EXITOSA << COLOR_TEXTO_BLANCO << endl;
        }
    }
    else
    {
        cout << COLOR_TEXTO_ROJO << ENERGIA_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
    }
}

void desplazarse(Matriz_casillero &mapa, Grafo *grafo, Jugador *jugador, int numero_jugador)
{
    Coordenada coordenada;
    int fila = 0;
    int columna = 0;
    cout << INGRESE_COORDENADAS_DESPLAZAR << endl;
    obtener_coordenadas(fila, columna, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
    coordenada.fijar_coordenadas(fila, columna);
    string posicion_inicial = jugador->obtener_posicion().coordenada_a_string();
    string posicion_final = coordenada.coordenada_a_string();
    grafo->usar_floyd();
    if (!tiene_energia(jugador, grafo->obtener_arista(posicion_inicial, posicion_final)))
    {
        cout << COLOR_TEXTO_ROJO << ENERGIA_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
    }
    else
    {
        Vector<string> *camino_recorrido = grafo->camino_minimo(posicion_inicial, posicion_final);
        Casillero *casillero_anterior = mapa.obtener_dato(jugador->obtener_posicion().obtener_coordenadas().coordenada_x, jugador->obtener_posicion().obtener_coordenadas().coordenada_y);

        int peso = casillero_anterior->obtener_energia_necesaria()[numero_jugador - 1];
        actualizar_aristas_grafo(mapa, grafo, coordenada, peso);
        system(CLR_SCREEN);
        for (int i = 0; i < camino_recorrido->obtener_largo(); i++)
        {
            casillero_anterior = mapa.obtener_dato(jugador->obtener_posicion().obtener_coordenadas().coordenada_x, jugador->obtener_posicion().obtener_coordenadas().coordenada_y);
            string casillero_destino = camino_recorrido->obtener_valor(i);
            ubicacion posicion = coordenada.string_a_coordenada(casillero_destino);
            coordenada.fijar_coordenadas(posicion.coordenada_x, posicion.coordenada_y);

            if (jugador->obtener_identidad() == JUGADOR_1)
            {
                mapa.obtener_dato(posicion.coordenada_x, posicion.coordenada_y)->fijar_color_texto(COLOR_JUGADOR_1);
            }
            else
            {
                mapa.obtener_dato(posicion.coordenada_x, posicion.coordenada_y)->fijar_color_texto(COLOR_JUGADOR_2);
            }

            jugador->desplazarse(posicion.coordenada_x, posicion.coordenada_y);

            Casillero *casillero_actual = mapa.obtener_dato(posicion.coordenada_x, posicion.coordenada_y);
            casillero_anterior->deshabitar_casillero();

            if (mapa.obtener_tipo_casillero(posicion.coordenada_x, posicion.coordenada_y) == CASILLERO_TRANSITABLE)
            {
                recolectar_material(casillero_actual, jugador);
            }
            casillero_actual->habitar_casillero();

            mostrar_mapa(mapa, 5, 3);
            retardo(1700);
            system(CLR_SCREEN);
        }
        actualizar_aristas_grafo(mapa, grafo, coordenada, INFINITO);
        jugador->modificar_energia(-grafo->obtener_arista(posicion_inicial, posicion_final));
    }
}
