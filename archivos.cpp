#include "archivos.h"

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

void cargar_grafo(Grafo &grafo, Matriz_casillero &mapa)
{
    for(int i = 0; i < mapa.obtener_largo_filas(); i++) {
        for(int j = 0; j < mapa.obtener_largo_columnas(); j++) {
            string vertice = "(" + to_string(i) + "," + " " + to_string(j) + ")";
            grafo.agregar_vertice(vertice);
        }
    }

    for(int i = 0; i < mapa.obtener_largo_filas(); i++) {
        for(int j = 0; j < mapa.obtener_largo_columnas(); j++) {
            Casillero* casillero_actual = mapa.obtener_dato(i, j);
            Casillero* vecino_derecho = mapa.obtener_casillero_vecino(mapa.obtener_dato(i, j), DERECHA);
            Casillero* vecino_abajo = mapa.obtener_casillero_vecino(mapa.obtener_dato(i, j), ABAJO);

            string coord_actual = casillero_actual->obtener_posicion().coordenada_a_string();
            int energia_actual = casillero_actual->obtener_energia_necesaria()[0];

            if(vecino_derecho != nullptr) {
                string coord_derecha = vecino_derecho->obtener_posicion().coordenada_a_string();
                int energia_derecha = vecino_derecho->obtener_energia_necesaria()[0];
                grafo.agregar_camino(coord_actual, coord_derecha, energia_derecha);
                grafo.agregar_camino(coord_derecha, coord_actual, energia_actual);
            }
            if(vecino_abajo != nullptr) {
                string coord_abajo = vecino_abajo->obtener_posicion().coordenada_a_string();
                int energia_abajo = vecino_abajo->obtener_energia_necesaria()[0];
                grafo.agregar_camino(coord_actual, coord_abajo, energia_abajo);
                grafo.agregar_camino(coord_abajo, coord_actual, energia_actual);
            }
        }
    }
}

/* void procesar_edificios(Vector_edificio &edificios)
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
            if (nombre == NOMBRE_EDIFICIO_PLANTA)
            {
                archivo_edificios >> nombre2;
                nombre += " " + nombre2;
            }
            archivo_edificios >> cant_piedra;
            archivo_edificios >> cant_madera;
            archivo_edificios >> cant_metal;
            archivo_edificios >> cant_maxima;

            Material_de_construccion materiales[MAX_MATERIALES_CONSTRUIBLES];
            materiales[0].fijar_nombre(PIEDRA);
            materiales[0].fijar_cantidad(stoi(cant_piedra));
            materiales[1].fijar_nombre(MADERA);
            materiales[1].fijar_cantidad(stoi(cant_madera));
            materiales[2].fijar_nombre(METAL);
            materiales[2].fijar_cantidad(stoi(cant_metal));

            Edificio edificio(nombre, stoi(cant_maxima), materiales);
            edificios.agregar_al_final(edificio);
        }
    }
    archivo_edificios.close();
} */

/* void procesar_ubicaciones(Vector_edificio &edificios, Matriz_casillero &mapa) //Procesar despues de mapa
{
    string nombre;
    string nombre2;
    string saltear;
    string coord_x;
    string coord_y;
    int fila;
    int columna;

    ifstream archivo_ubicaciones(RUTA_UBICACIONES);

    if (!archivo_ubicaciones.is_open())
    {
        cout << COLOR_TEXTO_ROJO << MENSAJE_ARCHIVO_NO_ENCONTRADO << endl;
    }
    else
    {
        while (archivo_ubicaciones >> nombre)
        {
            if (nombre == NOMBRE_EDIFICIO_PLANTA)
            {
                archivo_ubicaciones >> nombre2;
                nombre += " " + nombre2;
            }
            getline(archivo_ubicaciones, saltear, SEPARADOR_DERECHO_UBICACIONES);
            getline(archivo_ubicaciones, coord_x, SEPARADOR_MEDIO_UBICACIONES);
            fila = stoi(coord_x);
            getline(archivo_ubicaciones, saltear, ESPACIO);
            getline(archivo_ubicaciones, coord_y, SEPARADOR_IZQUIERDO_UBICACIONES);
            columna = stoi(coord_y);

            int posicion = edificios.obtener_pos_edificio(nombre);
            Edificio edificio_modificado = edificios.obtener_valor(posicion);
            edificio_modificado.incrementar_construcciones();
            edificios.fijar_valor(edificio_modificado, posicion);
            Casillero_construible *casillero_puntero = dynamic_cast<Casillero_construible *>(mapa.obtener_dato(fila, columna));
            casillero_puntero->ocupar_casillero(edificio_modificado);
        }
    }
}; */
void cargar_materiales(Vector_material &materiales)
{
    string nombre;
    string cantidad;

    ifstream archivo_materiales(RUTA_MATERIALES);

    if (!archivo_materiales.is_open())
    {
        cout << COLOR_TEXTO_ROJO << MENSAJE_ARCHIVO_NO_ENCONTRADO << endl;
    }
    else
    {
        while (archivo_materiales >> nombre)
        {
            archivo_materiales >> cantidad;
            if (nombre.compare(PIEDRA) == 0)
            {
                materiales.agregar_material_consumible_al_final(nombre, stoi(cantidad), ICONO_PIEDRA);
            }
            else if (nombre.compare(MADERA) == 0)
            {
                materiales.agregar_material_consumible_al_final(nombre, stoi(cantidad), ICONO_MADERA);
            }
            else if (nombre.compare(METAL) == 0)
            {
                materiales.agregar_material_consumible_al_final(nombre, stoi(cantidad), ICONO_METAL);
            }
            else
            {
                materiales.agregar_material_al_final(nombre, stoi(cantidad));
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