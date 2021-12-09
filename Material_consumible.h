#ifndef MATERIAL_CONSUMIBLE_H
#define MATERIAL_CONSUMIBLE_H
#include "Material.h"
#include "Mensajes.h"
#include <iostream>
#include "Configuracion.h"
class Material_consumible : public Material
{
private:
    char icono_en_mapa;

public:
    //Constructores
    //PRE:
    //POS: Inicializa el nombre del material con su nombre e icono por defecto con cantidad nula.
    Material_consumible();

    //PRE: Recibe un nombre valido del material, la cantidad entera y positiva, y el ícono que lo representa en el mapa.
    //POS: Inicializa el objeto con las variables recibidas.
    Material_consumible(std::string nombre_material, int cantidad, char icono);
    //PRE:
    //POS: Devuelve el atributo ícono del objeto
    char obtener_icono();

    //PRE: Recibe un carácter.
    //POS: Fija el atributo ícono del objeto que lo representa en el mapa.
    void fijar_icono(char icono);

    //PRE: -
    //POS: Imprime por pantalla la informacion del Material.
    void mostrar_material();
};
#endif //MATERIAL_CONSTRUIBLE_H