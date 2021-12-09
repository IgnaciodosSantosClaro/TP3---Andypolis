#include "Mecanicas_juego.h"

void modificar_edificio(Diccionario &diccionario) {
    Input input;
    string nombre = pedir_nombre();
    Edificio* edificio_buscado = diccionario.consulta(nombre);
    if(edificio_buscado != NULL) {
        if(edificio_buscado->obtener_nombre().compare(NOMBRE_EDIFICIO_OBELISCO) == 0) {
            cout << COLOR_TEXTO_ROJO << "El obelisco no puede modificarse" << COLOR_TEXTO_BLANCO << endl;
        }
        else {
            for (int i = 0; i < MAX_MATERIALES_CONSTRUIBLES; i++) {
                Material_consumible material = edificio_buscado->obtener_material(i);
                cout << "La cantidad de " << material.obtener_nombre() << " necesaria para construir un/a "
                     << edificio_buscado->obtener_nombre() << " es " << material.obtener_cantidad() << endl;
                cout << DESEA_MODIFICAR_MATERIAL << endl;
                if (confirmar_decision()) {
                    cout << "Ingrese la nueva cantidad de " << material.obtener_nombre() << " que este en el rango (0-50000): " <<endl;
                    Input input;
                    string nueva_cantidad;
                    cin >> nueva_cantidad;
                    confirmar_opcion_valida(nueva_cantidad, input, 0 + 1, 50000 - 1);
                    edificio_buscado->fijar_material_constuible(input.obtener_input(), i);
//                    diccionario.reemplazar(nombre, edificio_buscado);
                }
            }
        }
    }
    else {
        cout << COLOR_TEXTO_ROJO << EDIFICIO_INEXISTENTE << COLOR_TEXTO_BLANCO << endl;
    }

}

