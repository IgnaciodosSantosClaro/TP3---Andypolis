#ifndef VECTOR_MATERIAL_H
#define VECTOR_MATERIAL_H

#include "Vector.h"
#include "Material.h"
#include "Material_consumible.h"
#include <iostream>
#include <iomanip>
#include "errores.h"

class Vector_material : public Vector<Material *>
{
public:
    //constructor
    //PRE: -
    //POS: Construye un Vector_material.
    Vector_material();

    //Destructor
    //PRE: -
    //POS: Libera los espacios de memoria que contengan a un elemento Material o Material_casillero.
    ~Vector_material();

    //PRE: El nombre del material debe ser valido y pertenecer al vector de materiales.
    //POS: Devuelve el objeto material.
    int obtener_pos_material(std::string nombre);

    //PRE: Recibe el nombre del material, la cantidad y el icono que lo representa
    //POS: Reserva memoria y agrega un objeto Material_construible al vector Vector_material inicializandolo con
    //la cantidad e icono indicada
    void agregar_material_consumible_al_final(std::string nombre_material, int cantidad, char icono);

    //PRE: Recibe el nombre del material y una cantidad entera y positiva.
    //POS: Reserva memoria y agrega un objeto Material al vector Vector_material inicializandolo con la cantidad indicada.
    void agregar_material_al_final(std::string nombre_material, int cantidad);
};

#endif //VECTOR_MATERIAL_H