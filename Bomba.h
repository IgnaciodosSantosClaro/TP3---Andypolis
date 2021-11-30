#ifndef BOMBA_H
#define BOMBA_H

class Bomba
{
private:
    int cantidad;

public:
    //PRE: -
    //POS: Construye un objeto bomba con cantidad 0.
    Bomba();

    //PRE: -
    //POS: Devuelve la cantidad de bombas.
    int obtener_cantidad();

    //PRE: La cantidad es un numero positivo y entero.
    //POS: Fija la cantidad de bombas.
    void fijar_cantidad(int cantidad);

    //PRE:
    //POS:
    void tirar_bomba();
};

#endif //BOMBA_H
