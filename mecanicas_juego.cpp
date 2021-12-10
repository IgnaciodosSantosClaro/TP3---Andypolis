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