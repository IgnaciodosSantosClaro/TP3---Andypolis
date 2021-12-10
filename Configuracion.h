#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#include <string>

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

// Archivos
using namespace std;
const string RUTA_MATERIALES = "materiales/materiales.txt";
const string RUTA_EDIFICIOS = "edificios/edificios.txt";
const string RUTA_UBICACIONES = "ubicaciones/ubicaciones.txt";
const string RUTA_MAPA = "mapa/mapa.txt";
const int LARGO_HASTA_COLUMNA = 4;
const char SEPARADOR_DERECHO_UBICACIONES = '(';
const char SEPARADOR_IZQUIERDO_UBICACIONES = ')';
const char SEPARADOR_MEDIO_UBICACIONES = ',';
const char ESPACIO = ' ';
const char ICONO_PIEDRA = 'S';
const char ICONO_MADERA = 'W';
const char ICONO_METAL = 'I';
const char ICONO_ANDYCOINS = 'C';
const char CONSUMO_ENERGIA_MUELLE_JUGADOR_1 = 5;
const char CONSUMO_ENERGIA_MUELLE_JUGADOR_2 = 2;
const char CONSUMO_ENERGIA_CAMINO_JUGADOR_1 = 4;
const char CONSUMO_ENERGIA_CAMINO_JUGADOR_2 = 4;
const char CONSUMO_ENERGIA_BETUN_JUGADOR_1 = 0;
const char CONSUMO_ENERGIA_BETUN_JUGADOR_2 = 0;
const char CONSUMO_ENERGIA_INACCESIBLE_JUGADOR_1 = 2;
const char CONSUMO_ENERGIA_INACCESIBLE_JUGADOR_2 = 5;
const char CONSUMO_ENERGIA_CONSTRUIBLE_JUGADOR_1 = 25;
const char CONSUMO_ENERGIA_CONSTRUIBLE_JUGADOR_2 = 25;
// Casillero.h
const char TERRENO_CONSTRUIBLE = 'T';
const char TERRENO_INTRANSITABLE = 'L';
const char TERRENO_TRANSITABLE = 'C';
const char TERRENO_BETUN = 'B';
const char TERRENO_MUELLE = 'M';
const int MAX_ENERGIA = 100;
const char ICONO_POR_DEFECTO = ' ';
const char ICONO_JUGADOR = 'J';
const char ICONO_OCUPADO_POR_DEFECTO = 'X';
// Jugador
const string ENERGIA = "energia";
const int ENERGIA_INICIAL = 50;
const int ENERGIA_MAXIMA = 100;
const int ENERGIA_MINIMA = 0;
const string NOMBRE_JUGADOR_1_UBICACIONES = "1";
const string NOMBRE_JUGADOR_2_UBICACIONES = "2";
// Casillero_contruible
const string COLOR_BLANCO = "\033[48;5;15m";
const string COLOR_MARRON = "\033[48;5;136m";
const string COLOR_GRIS_OSCURO = "\033[48;5;59m";
const string COLOR_GRIS = "\033[48;5;246m";
const string COLOR_NEGRO = "\033[48;5;16m";
const string COLOR_CELESTE = "\033[48;5;6m";
const string COLOR_VERDE = "\033[48;5;112m";
const string COLOR_ROJO_OSCURO = "\033[48;5;52m";
const string COLOR_ROJO = "\033[48;5;124m";
const string COLOR_AMARILLO_OSCURO = "\033[48;5;3m";
const string COLOR_AMARILLO = "\033[48;5;149m";
const string COLOR_TEXTO_VERDE = "\033[38;5;28m";
const string COLOR_TEXTO_NEGRO = "\033[38;5;16m";
const string COLOR_TEXTO_BLANCO = "\033[38;5;15m";
const string COLOR_TEXTO_ROJO = "\033[38;5;124m";

const char SEPARADOR_GRILLA_INFERIOR = '_';
const char SEPARADOR_GRILLA_MEDIA = ' ';
const char SEPARADOR_GRILLA_DERECHA = '|';

// Edificio
const int PUNTOS_SALUD_BASE = 2;
const string NOMBRE_EDIFICIO_POR_DEFECTO = "edificio vacío";
const string NOMBRE_EDIFICIO_MINA = "mina";
const string NOMBRE_EDIFICIO_MINA_ORO = "mina oro";
const string NOMBRE_EDIFICIO_ASERRADERO = "aserradero";
const string NOMBRE_EDIFICIO_FABRICA = "fabrica";
const string NOMBRE_EDIFICIO_PLANTA_ELECTRICA = "planta electrica";
const string NOMBRE_EDIFICIO_ESCUELA = "escuela";
const string NOMBRE_EDIFICIO_OBELISCO = "obelisco";
const string NOMBRE_RECURSO_POR_DEFECTO = "-";
const string COLOR_EDIFICIO_SANO_JUG_1 = "\033[38;5;16m";    // NEGRO
const string COLOR_EDIFICIO_SANO_JUG_2 = "\033[38;5;63m";    // BLANCO
const string COLOR_EDIFICIO_HERIDO_JUG_1 = "\033[38;5;9m";   // ROJO
const string COLOR_EDIFICIO_HERIDO_JUG_2 = "\033[38;5;130m"; // VIOLETA
const string COLOR_JUGADOR_1 = "\033[38;5;161m";             // ROSA
const string COLOR_JUGADOR_2 = "\033[38;5;7m";               // BLANCO
const char ICONO_RECURSO_POR_DEFECTO = '-';
const int MAX_MATERIALES_CONSTRUIBLES = 3;
const int SALUD_MAXIMA = 2;
// ERRORES
const int POSICION_INVALIDA = -1;
//
const int CANT_MAXIMA_METAL = 4;
const int CANT_MAXIMA_PIEDRA = 2;
const int CANT_MAXIMA_MADERA = 1;
const int CANT_MINIMA_METAL = 2;
const int CANT_MINIMA_PIEDRA = 1;
const int CANT_MINIMA_MADERA = 0;
// interfaz
const int DURACION_TRUENO_PRINCIPAL = 750;
const int DURACION_TRUENO_INTERMEDIO = 100;
const int DURACION_ALEATORIA_MAXIMO_TRUENO_PRINCIPAL = 400;
const int DURACION_ALEATORIA_MAXIMO_TRUENO_INTERMEDIO = 25;
const int ANCHO_TRUENO = 270;
const int LARGO_TRUENO = 120;
const string TEXTO_NEGRITA = "\033[1m";
// Material
const string NOMBRE_MATERIAL_POR_DEFECTO = "default";
const std::string PIEDRA = "piedra";
const std::string MADERA = "madera";
const std::string METAL = "metal";
const std::string ANDYCOINS = "andycoins";
const std::string BOMBAS = "bombas";
const int CANT_RECURSOS_MINA = 15;
const int CANT_RECURSOS_ASERRADERO = 25;
const int CANT_RECURSOS_FABRICA = 40;
const int CANT_RECURSOS_ESCUELA = 25;
const int CANT_RECURSOS_MINA_ORO = 50;
const int CANT_RECURSOS_PLANTA_ELECTRICA = 15;
const int CANT_CONJUNTO_PIEDRA = 100;
const int CANT_CONJUNTO_MADERA = 50;
const int CANT_CONJUNTO_METAL = 50;
const int CANT_CONJUNTO_ANDYCOINS = 250;
const int PRECIO_BOMBAS = 100;
// Menu
const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;
const int OPCION_CONSTRUIR_EDIFICIO = 1;
const int OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int OPCION_LISTAR_TODOS_EDIFICIOS = 3;
const int OPCION_DEMOLER_EDIFICIO_COORDENADA = 4;
const int OPCION_MOSTRAR_MAPA = 5;
const int OPCION_CONSULTAR_COORDENADA = 6;
const int OPCION_MOSTRAR_INVENTARIO = 7;
const int OPCION_RECOLECTAR_RECURSOS_PRODUCIDOS = 8;
const int OPCION_LLUVIA_RECURSOS = 9;
const int OPCION_GUARDAR_Y_SALIR = 10;

const int TAMANO_MEMORIA_AGREGADA = 1;
// UTILES.H

#endif