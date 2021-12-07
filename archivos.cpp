#include "archivos.h"
#include <cctype>
using namespace std;

Errores abrir_archivo(std::ifstream &archivo, std::string path)
{
    Errores estado;
    (archivo).open(path);
    if (!(archivo))
    {
        estado = ERROR_ABRIENDO_ARCHIVO;
    }
    estado = EXITO;
    return estado;
}

Errores abrir_archivo_de_salida(std::ofstream &archivo, std::string path)
{
    Errores estado;
    (archivo).open(path);
    if (!(archivo))
    {
        estado = ERROR_ABRIENDO_ARCHIVO;
    }
    estado = EXITO;
    return estado;
}
void procesar_mapa(Matriz_casillero &mapa)
{
    string filas;
    string columnas;
    char tipo_terreno;
    bool esta_ocupado = false;

    ifstream archivo_mapa(RUTA_MAPA);

    if (!archivo_mapa.is_open())
    {
        cout << COLOR_TEXTO_ROJO << MENSAJE_ARCHIVO_NO_ENCONTRADO << COLOR_TEXTO_BLANCO << endl;
    }
    else
    {
        archivo_mapa >> filas;
        archivo_mapa >> columnas;
        int cant_filas = stoi(filas);
        int cant_columnas = stoi(columnas);
        mapa.agrandar_matriz(cant_filas, cant_columnas);

        Coordenada coordenadas;

        for (int fila = 0; fila < cant_filas; fila++)
        {
            for (int columna = 0; columna < cant_columnas; columna++)
            {
                coordenadas.fijar_coordenadas(fila, columna);
                archivo_mapa >> tipo_terreno;
                mapa.agregar_casillero(tipo_terreno, fila, columna, esta_ocupado);
            }
        }
    }
}

void cargar_grafo(Grafo &grafo, Matriz_casillero &mapa, int num_jugador)
{
    for (int i = 0; i < mapa.obtener_largo_filas(); i++)
    {
        for (int j = 0; j < mapa.obtener_largo_columnas(); j++)
        {
            string vertice = "(" + to_string(i) + "," + " " + to_string(j) + ")";
            grafo.agregar_vertice(vertice);
        }
    }

    for (int i = 0; i < mapa.obtener_largo_filas(); i++)
    {
        for (int j = 0; j < mapa.obtener_largo_columnas(); j++)
        {
            Casillero *casillero_actual = mapa.obtener_dato(i, j);
            Casillero *vecino_derecho = mapa.obtener_casillero_vecino(mapa.obtener_dato(i, j), DERECHA);
            Casillero *vecino_abajo = mapa.obtener_casillero_vecino(mapa.obtener_dato(i, j), ABAJO);

            string coord_actual = casillero_actual->obtener_posicion().coordenada_a_string();
            int energia_actual = casillero_actual->obtener_energia_necesaria()[num_jugador - 1];

            if (vecino_derecho != nullptr)
            {
                string coord_derecha = vecino_derecho->obtener_posicion().coordenada_a_string();
                int energia_derecha = vecino_derecho->obtener_energia_necesaria()[num_jugador - 1];
                grafo.agregar_camino(coord_actual, coord_derecha, energia_derecha);
                grafo.agregar_camino(coord_derecha, coord_actual, energia_actual);
            }
            if (vecino_abajo != nullptr)
            {
                string coord_abajo = vecino_abajo->obtener_posicion().coordenada_a_string();
                int energia_abajo = vecino_abajo->obtener_energia_necesaria()[num_jugador - 1];
                grafo.agregar_camino(coord_actual, coord_abajo, energia_abajo);
                grafo.agregar_camino(coord_abajo, coord_actual, energia_actual);
            }
        }
    }
}

void procesar_edificios(Diccionario &dicc)
{
    string nombre;
    string nombre2;
    string cant_piedra;
    string cant_madera;
    string cant_metal;
    string cant_maxima;

    ifstream archivo_edificios(RUTA_EDIFICIOS);

    if (!archivo_edificios.is_open())
    {
        cout << COLOR_TEXTO_ROJO << MENSAJE_ARCHIVO_NO_ENCONTRADO << COLOR_TEXTO_BLANCO << endl;
    }
    else
    {
        while (archivo_edificios >> nombre)
        {
            if (nombre == "planta")
            {
                archivo_edificios >> nombre2;
                nombre += " " + nombre2;
                archivo_edificios >> cant_piedra;
                archivo_edificios >> cant_madera;
                archivo_edificios >> cant_metal;
                archivo_edificios >> cant_maxima;
            }
            else if(nombre == "mina")
            {
                archivo_edificios >> nombre2;
                if(!isdigit(nombre2[0])) {
                    nombre += " " + nombre2;
                    archivo_edificios >> cant_piedra;
                    archivo_edificios >> cant_madera;
                    archivo_edificios >> cant_metal;
                    archivo_edificios >> cant_maxima;
                }
                else {
                    cant_piedra = nombre2;
                    archivo_edificios >> cant_madera;
                    archivo_edificios >> cant_metal;
                    archivo_edificios >> cant_maxima;
                }
            }
            else {
                archivo_edificios >> cant_piedra;
                archivo_edificios >> cant_madera;
                archivo_edificios >> cant_metal;
                archivo_edificios >> cant_maxima;
            }

            Material_consumible materiales[MAX_MATERIALES_CONSTRUIBLES];
            materiales[0].fijar_nombre(PIEDRA);
            materiales[0].fijar_cantidad(stoi(cant_piedra));
            materiales[1].fijar_nombre(MADERA);
            materiales[1].fijar_cantidad(stoi(cant_madera));
            materiales[2].fijar_nombre(METAL);
            materiales[2].fijar_cantidad(stoi(cant_metal));

            Edificio edificio(nombre, stoi(cant_maxima), materiales);
            dicc.alta(edificio);
        }
    }
    archivo_edificios.close();
}

void procesar_ubicaciones(Matriz_casillero &mapa) // Procesar despues de mapa
{
    string linea;
    string nombre;
    long long unsigned int inicio_posicion;
    int fila;
    int columna;

    ifstream archivo_ubicaciones(RUTA_UBICACIONES);

    if (!archivo_ubicaciones.is_open())
    {
        cout << COLOR_TEXTO_ROJO << MENSAJE_ARCHIVO_NO_ENCONTRADO << COLOR_TEXTO_BLANCO << endl;
    }
    else
    {
        bool procesar_jugador_1 = false;
        bool procesar_jugador_2 = false;
        while (getline(archivo_ubicaciones, linea))
        {
            nombre = separar_hasta(linea, SEPARADOR_DERECHO_UBICACIONES);
            nombre.pop_back();
            inicio_posicion = linea.find(SEPARADOR_DERECHO_UBICACIONES);
            fila = linea[inicio_posicion + 1] - '0'; // Resto offset ASCII
            columna = linea[inicio_posicion + LARGO_HASTA_COLUMNA] - '0';
            if (es_jugador(nombre))
            {
                mapa.obtener_dato(fila, columna)->habitar_casillero();

                if (nombre.compare(NOMBRE_JUGADOR_1_UBICACIONES) == 0)
                {
                    mapa.obtener_dato(fila, columna)->fijar_color_texto(COLOR_JUGADOR_1);
                    procesar_jugador_1 = true;
                    procesar_jugador_2 = false;
                }
                else
                {
                    mapa.obtener_dato(fila, columna)->fijar_color_texto(COLOR_JUGADOR_2);
                    procesar_jugador_1 = false;
                    procesar_jugador_2 = true;
                }
            }
            else if (procesar_jugador_1)
            {
                cout << "Soy un edificio del jugador 1" << endl;
                cout << "mi nombre es: " << nombre << " y estoy en " << fila << ": " << columna << endl;
                Casillero_construible *construible_ptr = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila, columna));
                Edificio edificio_seleccionado = Edificio(nombre, PUNTOS_SALUD_BASE);
                construible_ptr->ocupar_casillero(edificio_seleccionado, COLOR_EDIFICIO_SANO_JUG_1);
            }
            else if (procesar_jugador_2)
            {
                cout << "Soy un edificio del jugador 2" << endl;
                cout << "mi nombre es: " << nombre << " y estoy en " << fila << ": " << columna << endl;
                Casillero_construible *construible_ptr = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila, columna));
                Edificio edificio_seleccionado = Edificio(nombre, PUNTOS_SALUD_BASE);
                construible_ptr->ocupar_casillero(edificio_seleccionado, COLOR_EDIFICIO_SANO_JUG_2);
            }
            else
            {
                // Procesar materiales
                cout << "Soy un material " << endl;
                cout << "mi nombre es:" << nombre << " y estoy en " << fila << ": " << columna << endl;
            }
        }
    }
};
void cargar_materiales(Jugador &jugador1, Jugador &jugador2)
{
    string nombre;
    string cantidad_j1;
    string cantidad_j2;

    ifstream archivo_materiales(RUTA_MATERIALES);

    if (!archivo_materiales.is_open())
    {
        cout << COLOR_TEXTO_ROJO << MENSAJE_ARCHIVO_NO_ENCONTRADO << COLOR_TEXTO_BLANCO << endl;
    }
    else
    {
        while (archivo_materiales >> nombre)
        {
            archivo_materiales >> cantidad_j1;
            archivo_materiales >> cantidad_j2;
            if (nombre.compare(PIEDRA) == 0)
            {
                jugador1.agregar_consumible_inventario(nombre, stoi(cantidad_j1), ICONO_PIEDRA);
                jugador2.agregar_consumible_inventario(nombre, stoi(cantidad_j2), ICONO_PIEDRA);
            }
            else if (nombre.compare(MADERA) == 0)
            {
                jugador1.agregar_consumible_inventario(nombre, stoi(cantidad_j1), ICONO_MADERA);
                jugador2.agregar_consumible_inventario(nombre, stoi(cantidad_j2), ICONO_MADERA);
            }
            else if (nombre.compare(METAL) == 0)
            {
                jugador1.agregar_consumible_inventario(nombre, stoi(cantidad_j1), ICONO_METAL);
                jugador2.agregar_consumible_inventario(nombre, stoi(cantidad_j2), ICONO_METAL);
            }
            else if (nombre.compare(ANDYCOINS) == 0)
            {
                jugador1.agregar_consumible_inventario(nombre, stoi(cantidad_j1), ICONO_PIEDRA);
                jugador2.agregar_consumible_inventario(nombre, stoi(cantidad_j2), ICONO_PIEDRA);
            }
            else if (nombre.compare(BOMBAS) == 0)
            {
                jugador1.modificar_cantidad_bomba(stoi(cantidad_j1));
                jugador2.modificar_cantidad_bomba(stoi(cantidad_j2));
            }
            else
            {
                jugador1.agregar_material_inventario(nombre, stoi(cantidad_j1));
                jugador2.agregar_material_inventario(nombre, stoi(cantidad_j2));
            }
        }
    }
    archivo_materiales.close();
}

/* void guardar_y_salir(Vector_edificio &edificios, Vector_material &materiales, Matriz_casillero &mapa)
{
    actualizar_archivo_edificios(edificios);
    actualizar_archivo_materiales(materiales);
    actualizar_archivo_ubicaciones(mapa);
} */

/* void actualizar_archivo_edificios(Vector_edificio &edificios)
{
    ofstream archivo_edificios_actualizado(RUTA_EDIFICIOS);
    if (!archivo_edificios_actualizado.is_open())
    {
        cout << "Archivo " << RUTA_EDIFICIOS << " creado." << endl;
    }

    for (int i = 0; i < edificios.obtener_largo(); i++)
    {
        Edificio edificio_actual = edificios.obtener_valor(i);
        archivo_edificios_actualizado << edificio_actual.obtener_nombre() << " ";
        archivo_edificios_actualizado << edificio_actual.obtener_material(0).obtener_cantidad() << " ";
        archivo_edificios_actualizado << edificio_actual.obtener_material(1).obtener_cantidad() << " ";
        archivo_edificios_actualizado << edificio_actual.obtener_material(2).obtener_cantidad() << " ";
        archivo_edificios_actualizado << edificio_actual.obtener_cant_max() << endl;
    }

    archivo_edificios_actualizado.close();
} */

void actualizar_archivo_ubicaciones(Matriz_casillero &mapa)
{
    ofstream archivo_ubicaciones_actualizado(RUTA_UBICACIONES);
    if (!archivo_ubicaciones_actualizado.is_open())
    {
        cout << "Archivo " << RUTA_UBICACIONES << " creado." << endl;
    }

    for (int fila = 0; fila < mapa.obtener_largo_filas(); fila++)
    {
        for (int columna = 0; columna < mapa.obtener_largo_columnas(); columna++)
        {
            if (mapa.obtener_tipo_casillero(fila, columna) == CASILLERO_CONSTRUIBLE)
            {
                Casillero_construible *puntero_a_casillero = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila, columna));
                if (puntero_a_casillero->casillero_ocupado())
                {
                    archivo_ubicaciones_actualizado << puntero_a_casillero->obtener_edificio().obtener_nombre() << " ";
                    archivo_ubicaciones_actualizado << SEPARADOR_DERECHO_UBICACIONES
                                                    << puntero_a_casillero->obtener_posicion().obtener_coordenadas().coordenada_x
                                                    << SEPARADOR_MEDIO_UBICACIONES << " "
                                                    << puntero_a_casillero->obtener_posicion().obtener_coordenadas().coordenada_y
                                                    << SEPARADOR_IZQUIERDO_UBICACIONES << endl;
                }
            }
        }
    }

    archivo_ubicaciones_actualizado.close();
}

void actualizar_archivo_materiales(Vector_material &materiales)
{
    ofstream archivo_materiales_actualizado(RUTA_MATERIALES);
    if (!archivo_materiales_actualizado.is_open())
    {
        cout << "Archivo " << RUTA_MATERIALES << " creado." << endl;
    }

    for (int i = 0; i < materiales.obtener_largo(); i++)
    {
        archivo_materiales_actualizado << materiales.obtener_valor(i)->obtener_nombre() << " ";
        archivo_materiales_actualizado << materiales.obtener_valor(i)->obtener_cantidad() << endl;
    }

    archivo_materiales_actualizado.close();
}