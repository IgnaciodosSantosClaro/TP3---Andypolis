#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include "Vector.h"
#include "mensajes.h"
using namespace std;
//Constante de incremento de memoria
//const int TAMANO_MEMORIA_AGREGADA = 1;

//Template clase Vector
//Los índices se recorren de 0 a N-1
//Se almacena un largo de 1 a N
// NO DETECTA NI CORRIGE COLISIONES
template <typename tipo>
class Matriz
{
protected:
    int filas;
    int columnas;
    int espacio_reservado_filas;
    int espacio_reservado_columnas;
    tipo **datos; //Template
public:
    //Constructores
    //PRE:
    //POS:crea una matriz de tamaño 1x1.
    //No inicializa datos con ningun valor
    Matriz() //
    {
        int espacio_columnas = 1;
        int espacio_filas = 1;
        datos = new tipo *[espacio_filas];
        *datos = new tipo[espacio_columnas];
        filas = 0;
        columnas = 0;
        espacio_reservado_columnas = espacio_filas;
        espacio_reservado_filas = espacio_columnas;
    };

    //PRE:
    //POS: Destructor, libera los datos en memoria e incializa
    // atributos en cero o vector nulo .
    ~Matriz()
    {
        for (int i = 0; i < espacio_reservado_filas; i++)
        {
            delete[] datos[i];
            datos[i] = nullptr;
        }

        delete[] datos;
        datos = nullptr;
        filas = 0;
        columnas = 0;
        espacio_reservado_filas = 0;
        espacio_reservado_columnas = 0;
    };
    //PRE:
    //POS: Devuelve el largo de la fila
    int obtener_largo_filas()
    {
        return filas;
    }
    //PRE:
    //POS: Devuelve el largo de las columnas
    int obtener_largo_columnas()
    {
        return columnas;
    }
    //PRE: Toma una posicion válida (dentro del espacio reservado) y un dato a insertar.
    //POS: Fija valor en la posición posicion del puntero datos.
    void insertar_dato(tipo valor, int posicion_filas, int posicion_columnas)
    {

        if (this->espacio_reservado_filas >= posicion_filas + 1 && this->espacio_reservado_columnas >= posicion_columnas + 1)
        {
            if (this->columnas <= posicion_columnas + 1)
            {
                this->columnas = posicion_columnas + 1;
            }
            if (this->filas <= posicion_filas + 1)
            {
                this->filas = posicion_filas + 1;
            }
            this->datos[posicion_filas][posicion_columnas] = valor;
        }
        else
        {
            cout << MENSAJE_POSICION_INACCESIBLE << endl;
        }
    };

    //PRE: Recibe un puntero doble datos a copiar con espacio de al menos filasXcolumnas y
    // otro puntero doble datos_copiados con espacio mayor o igual a filasXcolumnas.
    //POS: Copia de datos_a_copiar un espacio de tamaño filasXcolumnas en datos_copiados.
    void copiar_datos(int filas, int columnas, tipo **datos_a_copiar, tipo **&datos_copiados) //Protegido
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                datos_copiados[i][j] = datos_a_copiar[i][j];
            }
        }
    };
    //PRE: Recibe el espacio_reservado_para las columnas y un puntero doble con los datos a eliminar.
    //POS: Libera las posiciones de memoria del puntero doble.
    void eliminar_datos(int espacio_reservado_columnas, tipo **&datos_a_eliminar)
    {
        for (int i = 0; i < espacio_reservado_columnas; i++)
        {
            delete[] datos_a_eliminar[i];
            datos_a_eliminar[i] = nullptr;
        }

        delete[] datos_a_eliminar;
        datos_a_eliminar = nullptr;
    }
    //PRE: Recibe el nuevo tamaño de las filas y el nuevo tamaño de columnas.
    //POS: Aumenta el espacio reservado en memoria.
    void agrandar_matriz(int nuevo_largo_filas, int nuevo_largo_columnas)
    {
        tipo **aux;
        aux = new tipo *[nuevo_largo_filas];

        for (int i = 0; i < nuevo_largo_filas; i++)
        {
            aux[i] = new tipo[nuevo_largo_columnas];
        }

        copiar_datos(this->filas, this->columnas, this->datos, aux);
        eliminar_datos(this->espacio_reservado_columnas, this->datos);
        this->datos = aux;
        this->espacio_reservado_columnas = nuevo_largo_columnas;
        this->espacio_reservado_filas = nuevo_largo_filas;
    }
    //PRE: Toma una posicion válida (dentro del espacio reservado) y un dato a insertar.
    //POS: Fija valor en la posición (posicion_filas, posicion_columnas) del puntero datos.
    tipo obtener_dato(int posicion_filas, int posicion_columnas)
    {

        if (this->espacio_reservado_filas >= posicion_filas + 1 && this->espacio_reservado_columnas >= posicion_columnas + 1)
        {
            //
        }
        else
        {
            cout << MENSAJE_POSICION_INACCESIBLE << endl;
        }
        return this->datos[posicion_filas][posicion_columnas];
    };
};

#endif