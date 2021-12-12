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
const int CONSUMO_ENERGIA_COMPRAR_BOMBAS = 5;
const int CONSUMO_ENERGIA_RECOLECTAR_RECURSOS = 20;
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
// Acciones
const int ENERGIA_REPARAR = 25;
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
// Objetivo_principal
const string NOMBRE_OBJETIVO_PRINCIPAL = "Mas alto que las nubes";
const string DESCRIPCION_OBJETIVO_PRINCIPAL = "Construir 1 obelisco";
const string ELEMENTO_OBJETIVO_PRINCIPAL = "obelisco";
const int CANTIDAD_OBJETIVO_PRINCIPAL = 1;
// Objetivos_secundarios
const string NOMBRE_COMPRAR_ANDYPOLIS = "Comprar Andypolis";
const string DESCRIPCION_COMPRAR_ANDYPOLIS = "Haber utilizado 100000 Andycoins";
const string ELEMENTO_COMPRAR_ANDYPOLIS = "andycoins";
const int CANTIDAD_COMPRAR_ANDYPOLIS = 100000;

const string NOMBRE_EDAD_PIEDRA = "Edad de piedra";
const string DESCRIPCION_EDAD_PIEDRA = "Tener 50000 de piedra en el inventario";
const string ELEMENTO_EDAD_PIEDRA = "piedra";
const int CANTIDAD_EDAD_PIEDRA = 50000;

const string NOMBRE_BOMBARDERO = "Bombardero";
const string DESCRIPCION_BOMBARDERO = "Haber utilizado 5 bombas";
const string ELEMENTO_BOMBARDERO = "bomba";
const int CANTIDAD_BOMBARDERO = 5;

const string NOMBRE_ENERGETICO = "Energetico";
const string DESCRIPCION_ENERGETICO = "Haber terminado un turno con 100 de energia";
const string ELEMENTO_ENERGETICO = "energia";
const int CANTIDAD_ENERGETICO = 100;

const string NOMBRE_LETRADO = "Letrado";
const string DESCRIPCION_LETRADO = "Haber construido el maximo de escuelas";
const string ELEMENTO_LETRADO = "escuelas"; // Fijar cantidad en tiempo de ejecucion

const string NOMBRE_MINERO = "Minero";
const string DESCRIPCION_MINERO = "Construir una mina de cada tipo";
const string ELEMENTO_1_MINERO = "mina oro";
const string DESCRIPCION_ELEMENTO_1_MINERO = "Construir una mina de oro";
const string ELEMENTO_2_MINERO = "mina";
const string DESCRIPCION_ELEMENTO_2_MINERO = "Construir una mina";

const int CANTIDAD_MINERO = 1;

const string NOMBRE_CANSADO = "Cansado";
const string DESCRIPCION_CANSADO = "Terminar un turno con 0 de energía";
const string ELEMENTO_CANSADO = "energia";
const int CANTIDAD_CANSADO = 0;

const string NOMBRE_CONSTRUCTOR = "Constructor";
const string DESCRIPCION_CONSTRUCTOR = "constuir un edificio de cada tipo";
const string ELEMENTO_CONSTRUCTOR = "todos los edificios";
const string ELEMENTO_1_CONSTRUCTOR = "mina oro";
const string DESCRIPCION_ELEMENTO_1_CONSTRUCTOR = "Construir una mina oro";
const string ELEMENTO_2_CONSTRUCTOR = "mina";
const string DESCRIPCION_ELEMENTO_2_CONSTRUCTOR = "Construir una mina";
const string ELEMENTO_3_CONSTRUCTOR = "aserradero";
const string DESCRIPCION_ELEMENTO_3_CONSTRUCTOR = "Construir un aserradero";
const string ELEMENTO_4_CONSTRUCTOR = "fabrica";
const string DESCRIPCION_ELEMENTO_4_CONSTRUCTOR = "Construir una fabrica";
const string ELEMENTO_5_CONSTRUCTOR = "escuela";
const string DESCRIPCION_ELEMENTO_5_CONSTRUCTOR = "Construir una escuela";
const string ELEMENTO_6_CONSTRUCTOR = "planta electrica";
const string DESCRIPCION_ELEMENTO_6_CONSTRUCTOR = "Construir una planta electrica";
const int CANTIDAD_CONSTRUCTOR = 1;

const string NOMBRE_ARMADO = "Armado";
const string DESCRIPCION_ARMADO = "Tener 10 Bombas en el inventario";
const string ELEMENTO_ARMADO = "bomba";
const int CANTIDAD_ARMADO = 10;

const string NOMBRE_EXTREMISTA = "Extremista";
const string DESCRIPCION_EXTREMISTA = "Haber comprado 500 bombas en una partida";
const string ELEMENTO_EXTREMISTA = "bomba";
const int CANTIDAD_EXTREMISTA = 500;
#endif