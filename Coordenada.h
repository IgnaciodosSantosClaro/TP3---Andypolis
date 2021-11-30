#ifndef COORDENADA_H
#define COORDENADA_H
struct ubicacion
{
    int coordenada_x;
    int coordenada_y;
};
class Coordenada
{
private:
    ubicacion posicion_actual;

public:
    //Constructor
    //PRE: -
    //POS: Construye objeto Coordenada con ubicacion (0, 0).
    Coordenada();

    //PRE: Recibe dos enteros con las coordenadas en x e y.
    //POS: Llena el struct posicion con los valores recibidos.
    void fijar_coordenadas(int x, int y);

    //PRE: -
    //POS: Devuelve un struct tipo ubicación con las coordenadas del objeto.
    ubicacion obtener_coordenadas();

    //PRE: -
    //POS: Imprime por pantalla las coordenadas.
    void mostrar();
};
#endif