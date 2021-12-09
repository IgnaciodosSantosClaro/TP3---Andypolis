#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "Configuracion.h"
#include "Mensajes.h"
using namespace std;
//Constante de incremento de memoria

//Template clase Vector
//Los índices se recorren de 0 a N-1
//Se almacena un largo de 1 a N
template <typename tipo>
class Vector
{
private:
    //PRE: -
    //POS: Devuelve la cantidad de memoria reservada del vector
    int obtener_memoria_reservada()
    {
        return this->espacio_reservado;
    }

protected:
    int largo_actual;
    int espacio_reservado;
    tipo *datos;

public:
    //Constructores
    //PRE: -
    //Pos:crea un objeto vector de con espacio en memoria 1
    //No inicializa datos con ningun valor
    Vector()
    {
        datos = new tipo[1];
        largo_actual = 0;
        espacio_reservado = 1;
    }
    //PRE: El largo debe ser un numero entero positivo.
    //Pos: Crea un objeto vector con espacio en memoria largo
    //No inicializa datos con ningun valor
    Vector(int largo)
    {
        datos = new tipo[largo];
        largo_actual = 0;
        espacio_reservado = largo;
    }
    //PRE: -
    //POS: Destructor, libera los datos en memoria e incializa
    // atributos en cero o vector nulo .
    ~Vector()
    {
        delete[] datos;
        datos = nullptr;
        largo_actual = 0;
        espacio_reservado = 0;
    }
    //PRE: Toma un objeto tipo vector
    //POS: Copia el objeto en otro objeto vector independiente
    // en términos de memoria.
    Vector(const Vector &vector_objetivo)
    {
        datos = new tipo[vector_objetivo.espacio_reservado];
        for (int i = 0; i < vector_objetivo.largo_actual; i++)
        {
            this->datos[i] = vector_objetivo.datos[i];
        }
        this->largo_actual = vector_objetivo.largo_actual;
        this->espacio_reservado = vector_objetivo.espacio_reservado;
    }
    //PRE: toma una posicion válida (dentro del espacio reservado)
    //POS:Fija valor en la posición posicion del puntero datos
    void fijar_valor(tipo valor, int posicion)
    {

        if (this->espacio_reservado >= posicion + 1)
        {
            if (this->largo_actual <= posicion)
            {
                this->largo_actual = posicion + 1;
            };
            this->datos[posicion] = valor;
        }
        else
        {
            cout << MENSAJE_POSICION_INACCESIBLE << endl;
        }
    }
    //PRE: Toma un vector que apunta a una posicion suficiente en memoria (datos_copia)
    // para copiar largo entradas del vector datos.
    //POS: copia largo entradas consecutivas de datos en datos_copia
    void copiar_datos(tipo *datos_copia, const tipo *datos, int largo) //Tambien protegido, otro nombre
    {

        for (int i = 0; i < largo; i++)
        {
            datos_copia[i] = datos[i];
        }
    }
    //PRE: Toma un entro con la cantida de espacio a agregar al vector
    //POS: Aumenta espacio_reservado y reserva más memoria para el puntero datos.
    void extender_vector(int espacio_a_agregar)
    {
        tipo *aux;
        int espacio_anterior = this->espacio_reservado;
        int espacio_nuevo = this->espacio_reservado + espacio_a_agregar;
        if (espacio_anterior < espacio_nuevo)
        {
            aux = new tipo[espacio_nuevo];
            copiar_datos(aux, this->datos, this->largo_actual);
            delete[] this->datos;
            this->espacio_reservado = espacio_nuevo;
            this->datos = aux;
        }
        else
        {
            cout << ERROR_AGRANDAR_MATRIZ << endl;
        }
    }
    //PRE: Toma un entro con la cantida de espacio a eliminar del vector
    //POS: Libera espacio_a_eliminar de memoria a derecha del puntero datos
    // reduce espacio_reservado.
    void contraer_vector(int espacio_a_eliminar)
    {
        tipo *aux;
        int espacio_nuevo = this->espacio_reservado - espacio_a_eliminar;
        int espacio_anterior = this->espacio_reservado;
        if (espacio_anterior > espacio_nuevo)
        {

            aux = new tipo[espacio_nuevo];
            copiar_datos(aux, this->datos, espacio_nuevo);
            delete[] this->datos;
            this->espacio_reservado = espacio_nuevo;
            this->datos = aux;
        }
        else
        {
            cout << ERROR_AGRANDAR_MATRIZ << endl;
        }
    }
    //PRE: Recibe un dato a agregar al vector
    //POS: Agrega el dato al final del vector, si no hay memoria para
    // hacerlo, llama a extender_vector, incrementa el largo actual.
    void agregar_al_final(tipo dato)
    {

        //ultimo_ocupado = this->datos[this->largo_actual];
        if (this->largo_actual == this->espacio_reservado)
        {
            this->extender_vector(TAMANO_MEMORIA_AGREGADA);
        }

        this->fijar_valor(dato, largo_actual);
    }
    //PRE: -
    //POS: Agrega el dato al final del vector, llama a contraer vector y
    // decrementa el largo actual;
    void eliminar_ultimo()
    {
        int nuevo_largo = this->largo_actual - 1;
        int memoria_a_liberar = this->espacio_reservado - nuevo_largo;
        this->contraer_vector(memoria_a_liberar);
        this->largo_actual -= 1;
    }
    //PRE: Recibe una posicion válida del vector (menor a largo actual)
    //POS: Devuelve el dato en esa posición
    tipo obtener_valor(int posicion)
    {
        if (this->largo_actual >= posicion + 1)
        {
                }
        else
        {
            throw std::invalid_argument(MENSAJE_POSICION_INACCESIBLE);
        }
        return this->datos[posicion];
    }
    //PRE: -
    //POS: Devuelve el largo del vector
    int obtener_largo()
    {
        return this->largo_actual;
    }

    void liberar_vector()
    {
        delete[] datos;
        datos = nullptr;
        largo_actual = 0;
        espacio_reservado = 0;
    }
};

#endif