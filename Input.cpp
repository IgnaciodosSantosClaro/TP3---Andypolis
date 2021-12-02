#include "Input.h"

Input::Input() {
    this->input = 0;
}

bool Input::es_rango_valido(int min, int max) {
    return this->input <= max && this->input >= min;
}

void Input::fijar_opcion(int input) {
    this->input = input;
}

bool Input::es_opcion_numero(string input) {
    int largo_input = (int)input.length();
    bool numero = true;
    for(int i = 0; i < largo_input; i++) {
        if(!isdigit(input[i])) {
            numero = false;
        }
    }
    return numero;
}

int Input::castear_string_a_int(string input) {
    return stoi(input);
}

void Input::pedir_input() {
    cout << INGRESE_ACCION << endl;

}

