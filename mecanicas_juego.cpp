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

void atacar(Matriz_casillero &mapa, Jugador &jugador)
{
    cout << MENSAJE_ATACAR_EDIFICO << endl;
    int coord_x;
    int coord_y;
    obtener_coordenadas(coord_x, coord_y, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());
    Casillero_construible *casillero_elegido;
    if (mapa.obtener_tipo_casillero(coord_x, coord_y) == CASILLERO_CONSTRUIBLE)
    {
        casillero_elegido = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(coord_x, coord_y));
        Bomba bombas_disponibles = jugador.obtener_bombas();
        bombas_disponibles.tirar_bomba(*casillero_elegido);
        jugador.fijar_bombas(bombas_disponibles);
    }
    else
    {
        cout << MENSAJE_CASILLERO_NO_CONSTRUIBLE << endl;
    }
}

void comprar_bombas(Jugador &jugador)
{
    if (jugador.obtener_energia() >= CONSUMO_ENERGIA_COMPRAR_BOMBAS)
    {
        Input input;
        string cantidad;
        cout << "Ingrese la cantidad de bombas que desea comprar: " << endl;
        cin >> cantidad;
        confirmar_opcion_valida(cantidad, input, 1, INT_MAX);
        int pos_buscada = jugador.obtener_inventario()->obtener_pos_material(ANDYCOINS);
        int cantidad_andycoins = jugador.obtener_inventario()->obtener_valor(pos_buscada)->obtener_cantidad();
        if (input.obtener_input() * PRECIO_BOMBAS > cantidad_andycoins)
        {
            cout << COLOR_TEXTO_ROJO << "La cantidad de andycoins es insuficiente." << COLOR_TEXTO_BLANCO << endl;
        }
        else
        {
            cantidad_andycoins -= input.obtener_input() * PRECIO_BOMBAS;
            jugador.obtener_inventario()->obtener_valor(pos_buscada)->fijar_cantidad(cantidad_andycoins);
            jugador.modificar_energia(-CONSUMO_ENERGIA_COMPRAR_BOMBAS);
            jugador.modificar_cantidad_bomba(input.obtener_input());
            cout << "Se han adquirido " << input.obtener_input() << " bombas." << endl;
            cout << "Se tienen " << cantidad_andycoins << " andycoins." << endl;
        }
    }
    else
    {
        cout << COLOR_TEXTO_ROJO << "La cantidad de energia es insuficiente." << COLOR_TEXTO_BLANCO << endl;
    }
}

void recolectar_recursos_producidos(Jugador &jugador)
{
    if (jugador.obtener_energia() >= CONSUMO_ENERGIA_RECOLECTAR_RECURSOS)
    {
        int cant_piedra = 0;
        int cant_madera = 0;
        int cant_metal = 0;
        int cant_andycoins = 0;
        int cant_energia = 0;
        Vector<Edificio *> vector_edificios = jugador.obtener_edificios()->arbol_a_vector();

        for (int i = 0; i < vector_edificios.obtener_largo(); i++)
        {
            Edificio *edificio_actual = vector_edificios.obtener_valor(i);
            Material_consumible recurso = edificio_actual->obtener_materiales_otorgados();
            string nombre_recurso = recurso.obtener_nombre();
            int cant_construcciones = edificio_actual->obtener_cant_construidos();

            if (nombre_recurso.compare(PIEDRA) == 0 && cant_construcciones > 0)
            {
                cant_piedra = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_piedra = jugador.obtener_inventario()->obtener_pos_material(PIEDRA);
                int cant_piedra_actual = jugador.obtener_inventario()->obtener_valor(pos_piedra)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_piedra)->fijar_cantidad(cant_piedra + cant_piedra_actual);
            }
            else if (nombre_recurso.compare(MADERA) == 0 && cant_construcciones > 0)
            {
                cant_madera = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_madera = jugador.obtener_inventario()->obtener_pos_material(MADERA);
                int cant_madera_actual = jugador.obtener_inventario()->obtener_valor(pos_madera)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_madera)->fijar_cantidad(cant_madera + cant_madera_actual);
            }
            else if (nombre_recurso.compare(METAL) == 0 && cant_construcciones > 0)
            {
                cant_metal = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_metal = jugador.obtener_inventario()->obtener_pos_material(METAL);
                int cant_metal_actual = jugador.obtener_inventario()->obtener_valor(pos_metal)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_metal)->fijar_cantidad(cant_metal + cant_metal_actual);
            }
            else if (nombre_recurso.compare(ANDYCOINS) == 0 && cant_construcciones > 0)
            {
                cant_andycoins = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_andycoins = jugador.obtener_inventario()->obtener_pos_material(ANDYCOINS);
                int cant_andycoins_actual = jugador.obtener_inventario()->obtener_valor(pos_andycoins)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_andycoins)->fijar_cantidad(cant_andycoins + cant_andycoins_actual);
            }
            else if (nombre_recurso.compare(ENERGIA) == 0 && cant_construcciones > 0)
            {
                cant_energia = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_energia = jugador.obtener_inventario()->obtener_pos_material(ENERGIA);
                int cant_energia_actual = jugador.obtener_inventario()->obtener_valor(pos_energia)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_energia)->fijar_cantidad(cant_energia + cant_energia_actual);
            }
        }
        jugador.modificar_energia(-CONSUMO_ENERGIA_RECOLECTAR_RECURSOS);
        cout << MENSAJE_RECOLECCION << endl;
        cout << PIEDRA_MAYUS << " : " << cant_piedra << endl;
        cout << MADERA_MAYUS << " : " << cant_madera << endl;
        cout << METAL_MAYUS << " : " << cant_metal << endl;
        cout << ANDYCOINS_MAYUS << " : " << cant_andycoins << endl;
        cout << ENERGIA_MAYUS << " : " << cant_energia << endl;
    }
    else
    {
        cout << COLOR_TEXTO_ROJO << "La cantidad de energia es insuficiente." << COLOR_TEXTO_BLANCO << endl;
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
void reparar(Matriz_casillero &mapa, Jugador &jugador)
{

    cout << MENSAJE_ATACAR_EDIFICO << endl;
    int coord_x;
    int coord_y;
    obtener_coordenadas(coord_x, coord_y, mapa.obtener_largo_filas(), mapa.obtener_largo_columnas());

    if (puede_reparar(mapa.obtener_dato(coord_x, coord_y), jugador) == true)
    {
        Casillero_construible *casillero_seleccionado = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(coord_x, coord_y));
        Edificio edificio_seleccionado = casillero_seleccionado->obtener_edificio();
        Edificio *edificio_modelo = jugador.obtener_edificios()->consulta(casillero_seleccionado->obtener_edificio().obtener_nombre());
        int madera_necesaria = (int)(edificio_modelo->obtener_material(POSICION_MADERA).obtener_cantidad() * 0.25);
        int metal_necesaria = (int)(edificio_modelo->obtener_material(POSICION_METAL).obtener_cantidad() * 0.25);
        int piedra_necesaria = (int)(edificio_modelo->obtener_material(POSICION_PIEDRA).obtener_cantidad() * 0.25);
        jugador.obtener_inventario()->obtener_por_nombre(MADERA).reducir_cantidad(madera_necesaria);
        jugador.obtener_inventario()->obtener_por_nombre(METAL).reducir_cantidad(metal_necesaria);
        jugador.obtener_inventario()->obtener_por_nombre(PIEDRA).reducir_cantidad(piedra_necesaria);
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
        jugador.modificar_energia(-ENERGIA_REPARAR);
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
    generar_cantidades_de_recursos(cantidad_metal_a_generar, cantidad_piedra_a_generar, cantidad_madera_a_generar);
    int cantidad_casilleros = cantidad_madera_a_generar + cantidad_piedra_a_generar + cantidad_metal_a_generar;
    bool generacion_completa = false;
    int cantidad_metal_generada = 0;
    int cantidad_piedra_generada = 0;
    int cantidad_madera_generada = 0;
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
                    puntero_a_casillero->ocupar_casillero(Material_consumible(METAL, 1, ICONO_METAL));
                    cantidad_metal_generada++;
                }
                else if (cantidad_piedra_generada < cantidad_piedra_a_generar)
                {
                    puntero_a_casillero->ocupar_casillero(Material_consumible(PIEDRA, 1, ICONO_PIEDRA));
                    cantidad_piedra_generada++;
                }
                else if (cantidad_madera_generada < cantidad_madera_a_generar)
                {
                    puntero_a_casillero->ocupar_casillero(Material_consumible(MADERA, 1, ICONO_MADERA));
                    cantidad_madera_generada++;
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
    }
}