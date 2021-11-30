#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>

using namespace std;

class Vertice {

private:
    string nombre;

public:
    Vertice(string nombre);

    //PRE: -
    //POS: obtiene el nombre del vertice
    string obtener_nombre();

    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
