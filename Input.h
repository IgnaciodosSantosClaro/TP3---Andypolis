#ifndef INPUT_H
#define INPUT_H

#include "Matriz_casillero.h"
#include "errores.h"
#include "mensajes.h"

class Input {
private:
    int input;

public:
    //Constructor
    //PRE: -
    //POS: Construye un objeto Input.
    Input();

    //PRE: -
    //POS: Devuelve true si la opcion esta en el rango valido, false en caso contrario.
    bool es_rango_valido(int min, int max);

    //PRE: input es un entero valido
    //POS: Se fija el atributo input.
    void fijar_opcion(int input);

    //PRE: -
    //POS: Devuelve true si todos los elementos de input son numeros, false en caso contrario.
    bool es_opcion_numero(string input);

    //PRE: Todos los elementos de input son numeros.
    //POS: Castea input de string a int.
    int castear_string_a_int(string input);

    //PRE: -
    //POS: Imprime por pantalla el pedido de input al usuario.
    void pedir_input();

    //PRE: -
    //POS: Devuelve el input
    int obtener_input();

};

#endif //INPUT_H
