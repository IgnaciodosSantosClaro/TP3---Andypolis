#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include "Material.h"
#include <iostream>
#include "Material_consumible.h"
#include "configuracion.h"
using namespace std;
enum estado_edificio
{
    EDIFICIO_SANO,
    EDIFICIO_LASTIMADO,
    EDIFICIO_DESTRUIDO,
};
class Edificio
{
private:
    std::string nombre_edificio;
    int cant_max;
    int cant_construidos;
    int salud;
    //Material_de_construccion materiales[MAX_MATERIALES_CONSTRUIBLES];
    Material_consumible recursos_producidos;

public:
    //Constructor por defecto
    //PRE: -
    //POS: Construye un objeto Edificio de nombre default, cantidad maxima nula, recursos producidos nulos y materiales nulos.
    Edificio();

    //Constructor por parametros
    //PRE: -
    //POS: Construye edificio de nombre nombre_edificio, cantidad maxima cant_max y materiales de construccion materiales.
    Edificio(string nombre_Edificio, int cant_max, int cant_contruidos, int puntos_salud);
    //Edificio(std::string nombre_edificio, int cant_max, Material_de_construccion *materiales);

    //PRE: cant_construidos debe ser mayor o igual que cero.
    //POS: Actualiza el atributo cant_construidos.
    void modificar_cant_construidos(int cant_construidos);

    void fijar_puntos_de_salud(int salud);
    estado_edificio atacar_edificio();
    //PRE: -
    //POS: Devuelve el nombre del edificio.
    std::string obtener_nombre();

    //PRE: -
    //POS: Devuelve la cantidad maxima permitida de edificios.
    int obtener_cant_max();

    //PRE: -
    //POS: Devuelve la cantidad de edificios contruidos.
    int obtener_cant_construidos();

    //PRE: La posicion esta entre 0 y 2.
    //POS: Devuelve el objeto material ubicado en la posicion pasada como paramentro del vector materiales.
    //Material_de_construccion obtener_material(int posicion);

    //PRE: -
    //POS: Devuelve el objeto correspondiente a los materiales que otorga el edificio.
    Material_consumible obtener_materiales_otorgados();

    //PRE: -
    //POS: Incrementa en una unidad la cantidad de construcciones de un edificio.
    void incrementar_construcciones();

    //PRE: -
    //POS: Decrementa en una unidad la cantidad de construcciones de un edificio.
    void decrementar_construcciones();

    //PRE: -
    //POS: Imprime por pantalla la informacion del Edificio.
    void mostrar_edificio();
};

#endif //EDIFICIO_H
