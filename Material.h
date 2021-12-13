#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <iostream>
#include "configuracion.h"
#include "mensajes.h"
class Material
{
protected:
    std::string nombre_material;
    int cantidad;

public:
    // Constructor por defecto
    // PRE: -
    // POS: Construye un material por defecto.
    Material();

    // Constructor con parametros
    // PRE:
    // POS: Construye un material de nombre nombre_material con una cantidad total cantidad.
    Material(std::string nombre_material, int cantidad);

    // PRE: -
    // POS: Devuelve el nombre del material.
    std::string obtener_nombre();
    void mostrar_leyenda(char icono);
    // PRE: -
    // POS: Devuelve la cantidad de material.
    int obtener_cantidad();

    // PRE: -
    // POS: Fija el nombre del material.
    void fijar_nombre(std::string nombre);

    // PRE: cantidad >= 0.
    // POS: Fija la cantidad del material.
    void fijar_cantidad(int cantidad);

    //PRE: cantidad actual <= decremento <= 0
    //POS: Decrementa la cantidad del material.
    void reducir_cantidad(int decremento);

    //PRE: incremento >= 0.
    //POS: Aumenta la cantidad de material.
    void aumentar_cantidad(int incremento);

    // Destructor virtual
    // PRE: -
    // POS: Destruye el objeto Material.
    virtual ~Material() = default;
};

#endif // MATERIAL_H
