#include "mecanicas_juego.h"
#include <climits>

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
        bombas_disponibles.fijar_cantidad(10); // Prueba
        bombas_disponibles.tirar_bomba(*casillero_elegido);


        jugador.fijar_bombas(bombas_disponibles);
    }
    else
    {
        cout << MENSAJE_CASILLERO_NO_CONSTRUIBLE << endl;
    }
}

void comprar_bombas(Jugador &jugador) {
    if (jugador.obtener_energia() >= CONSUMO_ENERGIA_COMPRAR_BOMBAS) {
        Input input;
        string cantidad;
        cout << "Ingrese la cantidad de bombas que desea comprar: " << endl;
        cin >> cantidad;
        confirmar_opcion_valida(cantidad, input, 1, INT_MAX);
        int pos_buscada = jugador.obtener_inventario()->obtener_pos_material(ANDYCOINS);
        int cantidad_andycoins = jugador.obtener_inventario()->obtener_valor(pos_buscada)->obtener_cantidad();
        if (input.obtener_input() * PRECIO_BOMBAS > cantidad_andycoins) {
            cout << COLOR_TEXTO_ROJO << "La cantidad de andycoins es insuficiente." << COLOR_TEXTO_BLANCO << endl;
        } else {
            cantidad_andycoins -= input.obtener_input() * PRECIO_BOMBAS;
            jugador.obtener_inventario()->obtener_valor(pos_buscada)->fijar_cantidad(cantidad_andycoins);
            jugador.modificar_energia(-CONSUMO_ENERGIA_COMPRAR_BOMBAS);
            jugador.modificar_cantidad_bomba(input.obtener_input());
            cout << "Se han adquirido " << input.obtener_input() << " bombas." << endl;
            cout << "Se tienen " << cantidad_andycoins << " andycoins." << endl;
        }
    } else {
        cout << COLOR_TEXTO_ROJO << "La cantidad de energia es insuficiente." << COLOR_TEXTO_BLANCO << endl;
    }
}

void recolectar_recursos_producidos(Jugador &jugador)
{
    if(jugador.obtener_energia() >= CONSUMO_ENERGIA_RECOLECTAR_RECURSOS) {
        int cant_piedra = 0;
        int cant_madera = 0;
        int cant_metal = 0;
        int cant_andycoins = 0;
        int cant_energia = 0;
        Vector<Edificio *> vector_edificios = jugador.obtener_edificios()->arbol_a_vector();

        for (int i = 0; i < vector_edificios.obtener_largo(); i++) {
            Edificio *edificio_actual = vector_edificios.obtener_valor(i);
            Material_consumible recurso = edificio_actual->obtener_materiales_otorgados();
            string nombre_recurso = recurso.obtener_nombre();
            int cant_construcciones = edificio_actual->obtener_cant_construidos();

            if (nombre_recurso.compare(PIEDRA) == 0 && cant_construcciones > 0) {
                cant_piedra = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_piedra = jugador.obtener_inventario()->obtener_pos_material(PIEDRA);
                int cant_piedra_actual = jugador.obtener_inventario()->obtener_valor(pos_piedra)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_piedra)->fijar_cantidad(cant_piedra + cant_piedra_actual);

            } else if (nombre_recurso.compare(MADERA) == 0 && cant_construcciones > 0) {
                cant_madera = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_madera = jugador.obtener_inventario()->obtener_pos_material(MADERA);
                int cant_madera_actual = jugador.obtener_inventario()->obtener_valor(pos_madera)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_madera)->fijar_cantidad(cant_madera + cant_madera_actual);

            } else if (nombre_recurso.compare(METAL) == 0 && cant_construcciones > 0) {
                cant_metal = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_metal = jugador.obtener_inventario()->obtener_pos_material(METAL);
                int cant_metal_actual = jugador.obtener_inventario()->obtener_valor(pos_metal)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_metal)->fijar_cantidad(cant_metal + cant_metal_actual);

            } else if (nombre_recurso.compare(ANDYCOINS) == 0 && cant_construcciones > 0) {
                cant_andycoins = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_andycoins = jugador.obtener_inventario()->obtener_pos_material(ANDYCOINS);
                int cant_andycoins_actual = jugador.obtener_inventario()->obtener_valor(pos_andycoins)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_andycoins)->fijar_cantidad(cant_andycoins + cant_andycoins_actual);

            } else if (nombre_recurso.compare(ENERGIA) == 0 && cant_construcciones > 0) {
                cant_energia = edificio_actual->obtener_materiales_otorgados().obtener_cantidad() * cant_construcciones;
                int pos_energia = jugador.obtener_inventario()->obtener_pos_material(ENERGIA);
                int cant_energia_actual = jugador.obtener_inventario()->obtener_valor(pos_energia)->obtener_cantidad();
                jugador.obtener_inventario()->obtener_valor(pos_energia)->fijar_cantidad(cant_energia + cant_energia_actual);
            }
        }
        cout << MENSAJE_RECOLECCION << endl;
        cout << PIEDRA_MAYUS << " : " << cant_piedra << endl;
        cout << MADERA_MAYUS << " : " << cant_madera << endl;
        cout << METAL_MAYUS << " : " << cant_metal << endl;
        cout << ANDYCOINS_MAYUS << " : " << cant_andycoins << endl;
        cout << ENERGIA_MAYUS << " : " << cant_energia << endl;
    }
    else {
        cout << COLOR_TEXTO_ROJO << "La cantidad de energia es insuficiente." << COLOR_TEXTO_BLANCO << endl;
    }
}
