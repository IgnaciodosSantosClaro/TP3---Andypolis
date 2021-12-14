#include "utiles.h"
#include <climits>
// int obtener_opcion_ingresada()
//{
//     Input input;
//     string entrada_usuario;
//     cin >> entrada_usuario;
//     int opcion_elegida;
////    try
////    {
////        opcion_elegida = std::stoi(entrada_usuario);
////    }
////    catch (std::invalid_argument &)
////    {
////        cout << MENSAJE_OPCION_INVALIDA << endl;
////        opcion_elegida = obtener_opcion_ingresada();
////    }
////    return opcion_elegida;
//    confirmar_opcion_valida(entrada_usuario, input, );
//    opcion_elegida = input.obtener_input();
//    return opcion_elegida;
//}
void obtener_coordenadas(int &coord_x, int &coord_y, int max_x, int max_y)
{
    pedir_coordenada(coord_x, coord_y);
    if ((coord_x > max_x) || (coord_y > max_y))
    {
        cout << COLOR_TEXTO_ROJO << COORDENADA_INALCANZABLE << COLOR_TEXTO_BLANCO << endl;
        obtener_coordenadas(coord_x, coord_y, max_x, max_y);
    }
}
void pedir_coordenada(int &coord_x, int &coord_y)
{
    Input input;
    string entrada_usuario;

    cout << INGRESE_COORD_X;
    cin >> entrada_usuario;
    confirmar_opcion_valida(entrada_usuario, input, 0, INT_MAX);
    coord_x = input.obtener_input();

    cout << INGRESE_COORD_Y;
    cin >> entrada_usuario;
    confirmar_opcion_valida(entrada_usuario, input, 0, INT_MAX);
    coord_y = input.obtener_input();
};
string separar_hasta(string cadena_a_separar, char caracter)
{
    char cursor;
    string cadena_procesada;
    int indice = 0;
    cursor = cadena_a_separar.at(indice);
    while (cursor != caracter)
    {
        cadena_procesada.push_back(cursor);
        indice++;
        cursor = cadena_a_separar.at(indice);
    }
    return cadena_procesada;
};
bool es_edificio(string nombre)
{
    bool edificio_detectado = false;
    if (nombre.compare(NOMBRE_EDIFICIO_MINA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_MINA_ORO))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ASERRADERO))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_FABRICA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_PLANTA_ELECTRICA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ESCUELA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_OBELISCO))
    {
        edificio_detectado = true;
    }
    return edificio_detectado;
};
bool es_jugador(string nombre)
{
    bool jugador_detectado = false;
    if (nombre.compare(NOMBRE_JUGADOR_1_UBICACIONES) == 0)
    {
        jugador_detectado = true;
    }
    else if (nombre.compare(NOMBRE_JUGADOR_2_UBICACIONES) == 0)
    {
        jugador_detectado = true;
    }
    return jugador_detectado;
}

string pedir_nombre()
{
    string nombre;
    cout << INGRESAR_NOMBRE_EDIFICIO;
    cin >> nombre;
    return nombre;
}
int elegir_jugador_inicial(int max_jugadores)
{
    cout << MENSAJE_ELEGIR_JUGADOR << max_jugadores << SEPARADOR_IZQUIERDO_UBICACIONES << endl;
    Input input;
    string entrada_usuario;
    cin >> entrada_usuario;
    confirmar_opcion_valida(entrada_usuario, input, 1, max_jugadores);
    int entrada = input.obtener_input();
    //    int entrada = obtener_opcion_ingresada();
    //    if (entrada <= 0 || entrada > max_jugadores)
    //    {
    //        cout << MENSAJE_OPCION_INVALIDA << endl;
    //        elegir_jugador_inicial(max_jugadores);
    //    }
    return entrada;
}
bool confirmar_decision()
{
    char opcion = '0'; // Valor default
    bool confirmar;

    while (opcion != 's' && opcion != 'n')
    {
        cin >> opcion;
        switch (opcion)
        {
        case 's':
            confirmar = true;
            break;
        case 'n':
            confirmar = false;
            break;
        default:
            cout << COLOR_TEXTO_ROJO << MENSAJE_OPCION_INVALIDA << COLOR_TEXTO_BLANCO << endl;
            break;
        }
    }
    return confirmar;
}

bool validar_opcion(string opcion, Input &input, int min, int max)
{
    bool opcion_valida = false;
    if (!input.es_opcion_numero(opcion))
    {
        opcion_valida = false;
    }
    else
    {
        input.fijar_opcion(input.castear_string_a_int(opcion));
        if (input.es_rango_valido(min, max))
        {
            opcion_valida = true;
        }
    }
    return opcion_valida;
}

void confirmar_opcion_valida(string &opcion, Input &input, int min, int max)
{
    while (!validar_opcion(opcion, input, min, max))
    {
        cout << MENSAJE_OPCION_INVALIDA << endl;
        cin >> opcion;
    }
}

void asignar_recursos_otorgados(string nombre, Edificio &edificio)
{
    if (nombre.compare(NOMBRE_EDIFICIO_MINA) == 0)
    {
        edificio.fijar_recurso_producido(PIEDRA, CANT_RECURSOS_MINA);
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ASERRADERO) == 0)
    {
        edificio.fijar_recurso_producido(MADERA, CANT_RECURSOS_ASERRADERO);
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_FABRICA) == 0)
    {
        edificio.fijar_recurso_producido(METAL, CANT_RECURSOS_FABRICA);
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ESCUELA) == 0)
    {
        edificio.fijar_recurso_producido(ANDYCOINS, CANT_RECURSOS_ESCUELA);
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_MINA_ORO) == 0)
    {
        edificio.fijar_recurso_producido(ANDYCOINS, CANT_RECURSOS_MINA_ORO);
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_PLANTA_ELECTRICA) == 0)
    {
        edificio.fijar_recurso_producido(ENERGIA, CANT_RECURSOS_PLANTA_ELECTRICA);
    }
}

void asignar_materiales(string nombre, Material_consumible &material)
{
    if (nombre.compare(PIEDRA) == 0)
    {
        material.fijar_nombre(PIEDRA);
        material.fijar_cantidad(CANT_CONJUNTO_PIEDRA);
        material.fijar_icono(ICONO_PIEDRA);
    }
    else if (nombre.compare(MADERA) == 0)
    {
        material.fijar_nombre(MADERA);
        material.fijar_cantidad(CANT_CONJUNTO_MADERA);
        material.fijar_icono(ICONO_MADERA);
    }
    else if (nombre.compare(METAL) == 0)
    {
        material.fijar_nombre(METAL);
        material.fijar_cantidad(CANT_CONJUNTO_METAL);
        material.fijar_icono(ICONO_METAL);
    }
    else if (nombre.compare(ANDYCOINS) == 0)
    {
        material.fijar_nombre(ANDYCOINS);
        material.fijar_cantidad(CANT_CONJUNTO_ANDYCOINS);
        material.fijar_icono(ICONO_ANDYCOINS);
    }
}

void cargar_objetivos(Vector_objetivo &objetivos_totales, int cant_maxima_escuela)
{
    objetivos_totales.agregar_objetivo_simple(NOMBRE_OBJETIVO_PRINCIPAL, DESCRIPCION_OBJETIVO_PRINCIPAL, ELEMENTO_OBJETIVO_PRINCIPAL, CANTIDAD_OBJETIVO_PRINCIPAL);

    objetivos_totales.agregar_objetivo_simple(NOMBRE_COMPRAR_ANDYPOLIS, DESCRIPCION_COMPRAR_ANDYPOLIS, ELEMENTO_COMPRAR_ANDYPOLIS, CANTIDAD_COMPRAR_ANDYPOLIS);
    objetivos_totales.agregar_objetivo_simple(NOMBRE_EDAD_PIEDRA, DESCRIPCION_EDAD_PIEDRA, ELEMENTO_EDAD_PIEDRA, CANTIDAD_EDAD_PIEDRA);
    objetivos_totales.agregar_objetivo_simple(NOMBRE_BOMBARDERO, DESCRIPCION_BOMBARDERO, ELEMENTO_BOMBARDERO, CANTIDAD_BOMBARDERO);
    objetivos_totales.agregar_objetivo_simple(NOMBRE_ENERGETICO, DESCRIPCION_ENERGETICO, ELEMENTO_ENERGETICO, CANTIDAD_ENERGETICO);
    objetivos_totales.agregar_objetivo_simple(NOMBRE_LETRADO, DESCRIPCION_LETRADO, ELEMENTO_LETRADO, cant_maxima_escuela);

    Objetivo_multiple objetivo_minero = Objetivo_multiple(NOMBRE_MINERO, DESCRIPCION_MINERO);
    objetivo_minero.agregar_objetivo_simple(ELEMENTO_1_MINERO, DESCRIPCION_ELEMENTO_1_MINERO, ELEMENTO_1_MINERO, CANTIDAD_MINERO);
    objetivo_minero.agregar_objetivo_simple(ELEMENTO_2_MINERO, DESCRIPCION_ELEMENTO_2_MINERO, ELEMENTO_2_MINERO, CANTIDAD_MINERO);
    objetivos_totales.agregar_objetivo_multiple(objetivo_minero);

    Objetivo_multiple objetivo_constructor = Objetivo_multiple(NOMBRE_CONSTRUCTOR, DESCRIPCION_CONSTRUCTOR);
    objetivo_constructor.agregar_objetivo_simple(ELEMENTO_1_CONSTRUCTOR, DESCRIPCION_ELEMENTO_1_CONSTRUCTOR, ELEMENTO_1_CONSTRUCTOR, CANTIDAD_CONSTRUCTOR);
    objetivo_constructor.agregar_objetivo_simple(ELEMENTO_2_CONSTRUCTOR, DESCRIPCION_ELEMENTO_2_CONSTRUCTOR, ELEMENTO_2_CONSTRUCTOR, CANTIDAD_CONSTRUCTOR);
    objetivo_constructor.agregar_objetivo_simple(ELEMENTO_3_CONSTRUCTOR, DESCRIPCION_ELEMENTO_3_CONSTRUCTOR, ELEMENTO_3_CONSTRUCTOR, CANTIDAD_CONSTRUCTOR);
    objetivo_constructor.agregar_objetivo_simple(ELEMENTO_4_CONSTRUCTOR, DESCRIPCION_ELEMENTO_4_CONSTRUCTOR, ELEMENTO_4_CONSTRUCTOR, CANTIDAD_CONSTRUCTOR);
    objetivo_constructor.agregar_objetivo_simple(ELEMENTO_5_CONSTRUCTOR, DESCRIPCION_ELEMENTO_5_CONSTRUCTOR, ELEMENTO_5_CONSTRUCTOR, CANTIDAD_CONSTRUCTOR);
    objetivo_constructor.agregar_objetivo_simple(ELEMENTO_6_CONSTRUCTOR, DESCRIPCION_ELEMENTO_6_CONSTRUCTOR, ELEMENTO_6_CONSTRUCTOR, CANTIDAD_CONSTRUCTOR);
    objetivos_totales.agregar_objetivo_multiple(objetivo_constructor);

    objetivos_totales.agregar_objetivo_simple(NOMBRE_ARMADO, DESCRIPCION_ARMADO, ELEMENTO_ARMADO, CANTIDAD_MINERO);
    objetivos_totales.agregar_objetivo_simple(NOMBRE_EXTREMISTA, DESCRIPCION_EXTREMISTA, ELEMENTO_EXTREMISTA, CANTIDAD_EXTREMISTA);
}
bool puede_reparar(Casillero *casillero_elegido, Jugador *jugador)
{
    Casillero_construible *construible_ptr;
    bool reparar = false;
    if ((construible_ptr = dynamic_cast<Casillero_construible *>(casillero_elegido)) && casillero_elegido->casillero_ocupado() == true)
    {
        if (construible_ptr->obtener_edificio().obtener_dueno() == jugador->obtener_identidad())
        {
            Edificio *edificio_modelo = jugador->obtener_edificios()->consulta(construible_ptr->obtener_edificio().obtener_nombre());
            int madera_necesaria = (int)(edificio_modelo->obtener_material(POSICION_MADERA).obtener_cantidad() * 0.25);
            int metal_necesaria = (int)(edificio_modelo->obtener_material(POSICION_METAL).obtener_cantidad() * 0.25);
            int piedra_necesaria = (int)(edificio_modelo->obtener_material(POSICION_PIEDRA).obtener_cantidad() * 0.25);
            int madera_jugador = (int)(jugador->obtener_inventario()->obtener_por_nombre(MADERA)->obtener_cantidad());
            int metal_jugador = (int)(jugador->obtener_inventario()->obtener_por_nombre(METAL)->obtener_cantidad());
            int piedra_jugador = (int)(jugador->obtener_inventario()->obtener_por_nombre(PIEDRA)->obtener_cantidad());
            if ((madera_necesaria <= madera_jugador) && (metal_necesaria <= metal_jugador) && (piedra_necesaria <= piedra_jugador))
            {
                reparar = true;
            }
        }
    }
    return reparar;
}
bool tiene_energia(Jugador *jugador, int energia_necesaria)
{
    return (jugador->obtener_energia() >= energia_necesaria);
}

Errores verificar_construccion(Jugador *jugador, string nombre_edificio)
{
    Errores estado = EXITO;
    if (jugador->obtener_edificios()->consulta(nombre_edificio) == nullptr)
    {
        estado = ERROR_NOMBRE_EDIFICIO;
    }
    else
    {
        Edificio *edificio_objetivo = jugador->obtener_edificios()->consulta(nombre_edificio);
        int pos_piedra = jugador->obtener_inventario()->obtener_pos_material(PIEDRA);
        int cant_piedra = jugador->obtener_inventario()->obtener_valor(pos_piedra)->obtener_cantidad();

        int pos_madera = jugador->obtener_inventario()->obtener_pos_material(MADERA);
        int cant_madera = jugador->obtener_inventario()->obtener_valor(pos_madera)->obtener_cantidad();

        int pos_metal = jugador->obtener_inventario()->obtener_pos_material(METAL);
        int cant_metal = jugador->obtener_inventario()->obtener_valor(pos_metal)->obtener_cantidad();

        if (cant_piedra < edificio_objetivo->obtener_material(0).obtener_cantidad())
        {
            estado = ERROR_CANT_PIEDRA;
        }
        else if (cant_madera < edificio_objetivo->obtener_material(1).obtener_cantidad())
        {
            estado = ERROR_CANT_MADERA;
        }
        else if (cant_metal < edificio_objetivo->obtener_material(2).obtener_cantidad())
        {
            estado = ERROR_CANT_METAL;
        }
        else if (edificio_objetivo->obtener_cant_construidos() == edificio_objetivo->obtener_cant_max())
        {
            estado = ERROR_CANT_MAXIMA;
        }
    }
    return estado;
}

void procesar_errores(Errores error)
{
    switch (error)
    {
    case ERROR_NOMBRE_EDIFICIO:
        cout << COLOR_TEXTO_ROJO << EDIFICIO_INEXISTENTE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_CANT_MADERA:
        cout << COLOR_TEXTO_ROJO << MADERA_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_CANT_PIEDRA:
        cout << COLOR_TEXTO_ROJO << PIEDRA_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_CANT_METAL:
        cout << COLOR_TEXTO_ROJO << METAL_INSUFICIENTE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_CANT_MAXIMA:
        cout << COLOR_TEXTO_ROJO << MAXIMO_ALCANZADO << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_INVALIDA:
        cout << COLOR_TEXTO_ROJO << COORDENADA_INVALIDA << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_INALCANZABLE:
        cout << COLOR_TEXTO_ROJO << COORDENADA_INALCANZABLE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_INACCESIBLE:
        cout << COLOR_TEXTO_ROJO << COORDENADA_INACCESIBLE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_OCUPADA:
        cout << COLOR_TEXTO_ROJO << COORDENADA_OCUPADA << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_HABITADA:
        cout << COLOR_TEXTO_ROJO << COORDENADA_HABITADA << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_LIBRE:
        cout << COLOR_TEXTO_ROJO << COORDENADA_LIBRE << COLOR_TEXTO_BLANCO << endl;
        break;
    case ERROR_COORDENADA_PROPIA:
        cout << COLOR_TEXTO_ROJO << COORDENADA_PROPIA << COLOR_TEXTO_BLANCO << endl;
        break;
    default:
        break;
    }
}

Errores validar_coordenadas_construccion(int coord_x, int coord_y, Matriz_casillero &mapa)
{
    Errores estado_coordenadas = EXITO;

    if (mapa.obtener_tipo_casillero(coord_x, coord_y) != CASILLERO_CONSTRUIBLE)
    {
        estado_coordenadas = ERROR_COORDENADA_INACCESIBLE;
    }
    else if (mapa.obtener_dato(coord_x, coord_y)->casillero_ocupado())
    {
        estado_coordenadas = ERROR_COORDENADA_OCUPADA;
    }
    else if (mapa.obtener_dato(coord_x, coord_y)->casillero_habitado())
    {
        estado_coordenadas = ERROR_COORDENADA_HABITADA;
    }

    return estado_coordenadas;
}

Errores validar_coordenadas_destruccion(int coord_x, int coord_y, Matriz_casillero &mapa, int numero_jugador)
{
    Errores estado_coordenadas = EXITO;
    if (mapa.obtener_tipo_casillero(coord_x, coord_y) != CASILLERO_CONSTRUIBLE)
    {
        estado_coordenadas = ERROR_COORDENADA_INACCESIBLE;
    }
    else if (!mapa.obtener_dato(coord_x, coord_y)->casillero_ocupado())
    {
        estado_coordenadas = ERROR_COORDENADA_LIBRE;
    }
    else if (mapa.obtener_dato(coord_x, coord_y)->casillero_habitado())
    {
        estado_coordenadas = ERROR_COORDENADA_HABITADA;
    }
    else
    {
        Casillero_construible *puntero_casillero = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(coord_x, coord_y));
        Edificio edificio_objetivo = puntero_casillero->obtener_edificio();
        if (numero_jugador != edificio_objetivo.obtener_dueno())
        {
            estado_coordenadas = ERROR_COORDENADA_PROPIA;
        }
    }
    return estado_coordenadas;
}

string asignar_color_edificio_sano(Jugador *jugador)
{
    string color_edificio;
    if (jugador->obtener_identidad() == JUGADOR_1)
    {
        color_edificio = COLOR_EDIFICIO_SANO_JUG_1;
    }
    else
    {
        color_edificio = COLOR_EDIFICIO_SANO_JUG_2;
    }
    return color_edificio;
}

void actualizar_aristas_grafo(Matriz_casillero &mapa, Grafo *grafo, Coordenada coordenada, int peso)
{
    int fila = coordenada.obtener_coordenadas().coordenada_x;
    int columna = coordenada.obtener_coordenadas().coordenada_y;
    string destino = coordenada.coordenada_a_string();
    Casillero *vecino_derecho = mapa.obtener_casillero_vecino(mapa.obtener_dato(fila, columna), DERECHA);
    Casillero *vecino_izquierdo = mapa.obtener_casillero_vecino(mapa.obtener_dato(fila, columna), IZQUIERDA);
    Casillero *vecino_abajo = mapa.obtener_casillero_vecino(mapa.obtener_dato(fila, columna), ABAJO);
    Casillero *vecino_arriba = mapa.obtener_casillero_vecino(mapa.obtener_dato(fila, columna), ARRIBA);

    if (vecino_derecho != nullptr)
    {
        string coord_derecha = vecino_derecho->obtener_posicion().coordenada_a_string();
        grafo->actualizar_camino(coord_derecha, destino, peso);
    }
    if (vecino_izquierdo != nullptr)
    {
        string coord_izquierda = vecino_izquierdo->obtener_posicion().coordenada_a_string();
        grafo->actualizar_camino(coord_izquierda, destino, peso);
    }
    if (vecino_abajo != nullptr)
    {
        string coord_abajo = vecino_abajo->obtener_posicion().coordenada_a_string();
        grafo->actualizar_camino(coord_abajo, destino, peso);
    }
    if (vecino_arriba != nullptr)
    {
        string coord_arriba = vecino_arriba->obtener_posicion().coordenada_a_string();
        grafo->actualizar_camino(coord_arriba, destino, peso);
    }
}

void inicializar_posicion_jugador(Matriz_casillero &mapa, Jugador *jugador)
{
    int fila = 0;
    int columna = 0;
    cout << INGRESE_APARICION_JUGADOR << endl;
    obtener_coordenadas(fila, columna, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
}

bool es_turno_valido(Jugador &jugador)
{
    return (jugador.obtener_energia() > ENERGIA_MINIMA);
}
void actualizar_inventario(Jugador *jugador, Material_consumible &material)
{
    jugador->obtener_inventario()->obtener_por_nombre(material.obtener_nombre())->aumentar_cantidad(material.obtener_cantidad());
}
void recolectar_material(Casillero *casillero, Jugador *jugador)
{
    Casillero_transitable *casillero_material = dynamic_cast<Casillero_transitable *>(casillero);
    if (casillero_material->casillero_ocupado())
    {
        Material_consumible material_casillero = casillero_material->obtener_material();
        actualizar_inventario(jugador, material_casillero);
        casillero_material->desocupar_casillero();
        cout << COLOR_TEXTO_VERDE << "Has recolectado " << material_casillero.obtener_cantidad() << " unidades de " << material_casillero.obtener_nombre() << COLOR_TEXTO_BLANCO << endl;
    }
}

Vector<string>* cadena_materiales(Matriz_casillero &mapa)
{
    Vector<string>* coord_materiales = new Vector<string>;
    string cadena_material;
    Coordenada coordenada;
    for(int fila = 0; fila < mapa.obtener_largo_filas(); fila++)
    {
        for(int columna = 0; columna < mapa.obtener_largo_columnas(); columna++)
        {
            if(mapa.obtener_tipo_casillero(fila, columna) == CASILLERO_TRANSITABLE)
            {
                Casillero_transitable* ptr_casillero = dynamic_cast<Casillero_transitable*>(mapa.obtener_dato(fila, columna));
                if(ptr_casillero->casillero_ocupado())
                {
                    coordenada.fijar_coordenadas(fila, columna);
                    cadena_material = ptr_casillero->obtener_material().obtener_nombre() + " " + coordenada.coordenada_a_string();
                    coord_materiales->agregar_al_final(cadena_material);
                }
            }
        }
    }

    return coord_materiales;
}

Vector<string>* cadena_edificios(Matriz_casillero &mapa, int numero_jugador)
{
    Vector<string>* coord_edificios = new Vector<string>;
    string cadena_edificio;
    Coordenada coordenada;
    for(int fila = 0; fila < mapa.obtener_largo_filas(); fila++)
    {
        for(int columna = 0; columna < mapa.obtener_largo_columnas(); columna++)
        {
            if(mapa.obtener_tipo_casillero(fila, columna) == CASILLERO_CONSTRUIBLE)
            {
                Casillero_construible* ptr_casillero = dynamic_cast<Casillero_construible*>(mapa.obtener_dato(fila, columna));
                if(ptr_casillero->casillero_ocupado()) {
                    if(ptr_casillero->obtener_edificio().obtener_dueno() == numero_jugador)
                    {
                        coordenada.fijar_coordenadas(fila, columna);
                        cadena_edificio = ptr_casillero->obtener_edificio().obtener_nombre() + " " + coordenada.coordenada_a_string();
                        coord_edificios->agregar_al_final(cadena_edificio);
                    }
                }
            }
        }
    }

    return coord_edificios;
}