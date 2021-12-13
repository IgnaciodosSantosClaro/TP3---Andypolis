#include "animaciones.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;
void bombardeo(int retardo_milisegundos)
{
    sleep_for(milliseconds(retardo_milisegundos));
    trueno(25, COLOR_ROJO_OSCURO);
    trueno(20, COLOR_ROJO);
    trueno(20, COLOR_AMARILLO_OSCURO);
    trueno(30, COLOR_AMARILLO);
    trueno(10, COLOR_ROJO_OSCURO);
    trueno(25, COLOR_ROJO);
    trueno(30, COLOR_AMARILLO);
    trueno(25, COLOR_BLANCO);
    trueno(10, COLOR_NEGRO);
}
void trueno(int milisegundos_duracion, string color)
{

    cout << color;
    for (int i = 0; i < LARGO_TRUENO; i++)
    {

        cout.width(ANCHO_TRUENO);
        cout.fill(ESPACIO);
        cout << endl;
    }
    sleep_for(milliseconds(milisegundos_duracion));
    system(CLR_SCREEN);
};
void tormenta(int cant_truenos)
{
    int duracion_aleatoria = 0;
    int t_duracion = 2;
    int num_gotas = 500;
    int t_espera = 100;
    lluvia(t_duracion, num_gotas, t_espera);
    for (int trueno_generado = 0; trueno_generado < cant_truenos; trueno_generado++)
    {
        duracion_aleatoria = numero_aleatorio(DURACION_ALEATORIA_MAXIMO_TRUENO_PRINCIPAL, 0);
        trueno(DURACION_TRUENO_PRINCIPAL - duracion_aleatoria, COLOR_BLANCO);
        duracion_aleatoria = numero_aleatorio(DURACION_TRUENO_INTERMEDIO, 0);
        trueno(DURACION_TRUENO_INTERMEDIO - duracion_aleatoria, COLOR_GRIS);
        duracion_aleatoria = numero_aleatorio(DURACION_ALEATORIA_MAXIMO_TRUENO_PRINCIPAL, 0);
        trueno(DURACION_TRUENO_PRINCIPAL - duracion_aleatoria, COLOR_NEGRO);
    }
    lluvia(t_duracion, num_gotas, t_espera);
    cout << endl;
    system(CLR_SCREEN);
}
void lluvia(int t_visible, int num_gotas, int t_espera)
{
    char gota = '/';
    for (int i = 0; i < t_visible; i++)
    {
        for (int j = 0; j < num_gotas; j++)
        {
            cout << gota << setfill(' ') << setw(rand() % 100);
        }

        sleep_for(milliseconds(t_espera));
    }
    cout << endl;
}
void coordenadas_aleatorias(int limite_filas, int limite_columnas, int &fila, int &columna)
{
    fila = rand() % limite_filas;
    columna = rand() % limite_columnas;
}
int numero_aleatorio(int limite_sup, int limite_inf)
{
    return (rand() % (limite_sup + 1 - limite_inf)) + limite_inf;
}
void generar_cantidades_de_recursos(int &cantidad_metal, int &cantidad_piedra, int &cantidad_madera)
{
    cantidad_metal = numero_aleatorio(CANT_MAXIMA_METAL, CANT_MINIMA_METAL);
    cantidad_piedra = numero_aleatorio(CANT_MAXIMA_PIEDRA, CANT_MINIMA_PIEDRA);
    cantidad_madera = numero_aleatorio(CANT_MAXIMA_MADERA, CANT_MINIMA_MADERA);
}