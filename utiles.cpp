#include "utiles.h"
#include "mensajes.h"

string separar_hasta(string cadena_a_separar, char caracter)
{
    char cursor;
    string cadena_procesada;
    int indice = 0;
    cursor = cadena_a_separar.at(indice);
    while (cursor != caracter)
    {
        cadena_procesada.push_back(cursor);
        indice++;
        cursor = cadena_a_separar.at(indice);
    }
    return cadena_procesada;
};
bool es_edificio(string nombre)
{
    bool edificio_detectado = false;
    if (nombre.compare(NOMBRE_EDIFICIO_MINA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_MINA_ORO))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ASERRADERO))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_FABRICA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_PLANTA_ELECTRICA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_ESCUELA))
    {
        edificio_detectado = true;
    }
    else if (nombre.compare(NOMBRE_EDIFICIO_OBELISCO))
    {
        edificio_detectado = true;
    }
    return edificio_detectado;
};
bool es_jugador(string nombre)
{
    bool jugador_detectado = false;
    if (nombre.compare(NOMBRE_JUGADOR_1_UBICACIONES) == 0)
    {
        jugador_detectado = true;
    }
    else if (nombre.compare(NOMBRE_JUGADOR_2_UBICACIONES) == 0)
    {
        jugador_detectado = true;
    }
    if (jugador_detectado)
    {
        cout << nombre << " es jugador" << endl;
    }
    if (!jugador_detectado)
    {
        cout << nombre << " no es jugador" << endl;
    }
    return jugador_detectado;
}

string pedir_nombre()
{
    string nombre;
    cout << INGRESAR_NOMBRE_EDIFICIO;
//    cin.ignore();
    getline(cin, nombre);
    return nombre;
}

bool confirmar_decision()
{
    char opcion = '0'; //Valor default
    bool confirmar;

    while (opcion != 's' && opcion != 'n')
    {
        cin >> opcion;
        switch (opcion)
        {
            case 's':
                confirmar = true;
                break;
            case 'n':
                confirmar = false;
                break;
            default:
                cout << COLOR_TEXTO_ROJO << MENSAJE_OPCION_INVALIDA << COLOR_TEXTO_BLANCO << endl;
                break;
        }
    }
    return confirmar;
}

bool validar_opcion(string opcion, Input &input, int min, int max) {
    bool opcion_valida = false;
    if(!input.es_opcion_numero(opcion)) {
        opcion_valida = false;
    }
    else {
        input.fijar_opcion(input.castear_string_a_int(opcion));
        if(input.es_rango_valido(min, max)) {
            opcion_valida = true;
        }
    }
    return opcion_valida;
}

void confirmar_opcion_valida(string &opcion, Input &input, int min, int max) {
    while(!validar_opcion(opcion, input, min, max)) {
        cout << MENSAJE_OPCION_INVALIDA << endl;
        cin >> opcion;
    }
}