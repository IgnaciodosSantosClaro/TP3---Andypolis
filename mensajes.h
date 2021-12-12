#ifndef MENSAJES_H
#define MENSAJES_H
#include <string>
using namespace std;
const string MENSAJE_ARCHIVO_NO_ENCONTRADO = "Archivo no encontrado";
// Interfaz
const string NOMBRE_CASILLERO_INACCESIBLE = "Lago";
const string NOMBRE_CASILLERO_TRANSITABLE = "Camino";
const string NOMBRE_CASILLERO_BETUN = "Betun";
const string NOMBRE_CASILLERO_MUELLE = "Muelle";
const string NOMBRE_CASILLERO_CONSTRUIBLE = "Terreno construible";
// Bomba
const string MENSAJE_INICIO_BOMBA = "Se planto una bomba en ";
const string MENSAJE_BOMBA_DESTRUYO = "La bomba destruyo el edificio ";
const string MENSAJE_BOMBA_DANO = "La bomba debilito el edificio ";
const string MENSAJE_BOMBA_INSUFICIENTES = "No tienes suficentes bombas";
const string MENSAJE_BOMBA_CASILLERO_VACIO = "No hay un edificio para bombardear en la posicion ";
// Casillero_inaccesible
const string CASILLERO_OCUPADO_MENSAJE = " y estoy ocupado.";
const string CASILLERO_NO_OCUPADO_MENSAJE = " y no estoy ocupado.";
const string CASILLERO_CONSULTADO = " y me encuentro en el casillero consultado.";
const string CASILLERO_INACCESIBLE_MENSAJE = "Soy un casillero inaccesible";
const string CASILLERO_CONSTRUIBLE_MENSAJE = "Soy un casillero construible";
const string CASILLERO_TRANSITABLE_MENSAJE = "Soy un casillero transitable";
// menu
const std::string ENCABEZADO_MENU = "═════════════════════════════════════";
const std::string TITULO_MENU = "MENU";
const std::string MENSAJE_OPCION_INVALIDA = "La opcion elegida es invalida. Intente nuevamente.";
const std::string MENSAJE_DESPEDIDA = "Adios!";
const std::string ERROR_GUARDAR = "ERROR guardando"; // integrar a error.h
const std::string INGRESE_ACCION = "Ingrese el numero de la accion que desea realizar.";
// menu inicial
const std::string MENSAJE_MENU_INICIAL_1 = " 1. Modificiar edificio por nombre.";
const std::string MENSAJE_MENU_INICIAL_2 = " 2. Listar edificios construidos.";
const std::string MENSAJE_MENU_INICIAL_3 = " 3. Mostrar mapa.";
const std::string MENSAJE_MENU_INICIAL_4 = " 4. Comenzar partida.";
const std::string MENSAJE_MENU_INICIAL_5 = " 5. Guardar y salir.";
// menu juego
const std::string MENSAJE_MENU_JUEGO_OPCION_1 = " 1. Construir edificio por nombre.";
const std::string MENSAJE_MENU_JUEGO_OPCION_2 = " 2. Listar mis edificios construidos.";
const std::string MENSAJE_MENU_JUEGO_OPCION_3 = " 3. Demoler edificio por coordenada.";
const std::string MENSAJE_MENU_JUEGO_OPCION_4 = " 4. Atacar un edificio por coordenada.";
const std::string MENSAJE_MENU_JUEGO_OPCION_5 = " 5. Reparar un edificio por coordenada.";
const std::string MENSAJE_MENU_JUEGO_OPCION_6 = " 6. Comprar bombas.";
const std::string MENSAJE_MENU_JUEGO_OPCION_7 = " 7. Consultar coordenada.";
const std::string MENSAJE_MENU_JUEGO_OPCION_8 = " 8. Mostrar inventario.";
const std::string MENSAJE_MENU_JUEGO_OPCION_9 = " 9. Mostrar objetivos.";
const std::string MENSAJE_MENU_JUEGO_OPCION_10 = " 10. Recolectar recursos producidos.";
const std::string MENSAJE_MENU_JUEGO_OPCION_11 = " 11. Moverse una coordenada.";
const std::string MENSAJE_MENU_JUEGO_OPCION_12 = " 12. Finalizar turno.";
const std::string MENSAJE_MENU_JUEGO_OPCION_13 = " 13. Guardar y salir.";

const std::string MENSAJE_ELEGIR_JUGADOR = "Elija el numero del jugador inicial (1-";
// utiles.h
const int ANCHO_DE_INVENTARIO = 11;
const std::string ENCABEZADO_LISTADO_MATERIALES = "══════════════════════════════════════════";
const string TITULO_LISTADO_MATERIALES = "\t Listado de materiales        ";
const string TITULO_COLUMNA_MATERIAL = "Material";
const string TITULO_COLUMNA_CANTIDAD = "Cantidad";
const string TITULO_LISTADO_EDIFICIOS = "\t Listado de edificios        ";
const string TITULO_COLUMNA_EDIFICIOS = "Edificios";
const string PIEDRA_MAYUS = "Piedra";
const string MADERA_MAYUS = "Madera";
const string METAL_MAYUS = "Metal";
const string ANDYCOINS_MAYUS = "Andycoins";
const string ENERGIA_MAYUS = "Energia";
const string TITULO_COLUMNA_CANT_CONSTRUIDA = "Cantidad construida";
const string TITULO_COLUMNA_CANT_PERMITIDA = "Cantidad maxima";
const string TITULO_COLUMNA_RECURSO_ENTREGADO = "Recurso otorgado";
const string TITULO_COLUMNA_TIPO = "Tipo";
const string TITULO_LISTADO_EDIFICIOS_CONSTRUIDOS = "\t Listado de edificios construidos"; //
const char TABULACION = '\t';
const string TITULO_COLUMNA_EDIFICIO = "Edificio";
const string TITULO_COLUMNA_COORDENADAS = "Coordenadas";
const string TITULO_ESTADO_SALUD = "Necesita Reparacion";

const string MENSAJE_RECOLECCION = "Has recolectado: ";
const string INGRESAR_NOMBRE_EDIFICIO = "Ingrese el nombre del edificio: ";
const string EDIFICIO_INEXISTENTE = "El edificio no existe.";
const string MADERA_INSUFICIENTE = "No se puede construir el edificio. La cantidad de madera es insuficiente.";
const string PIEDRA_INSUFICIENTE = "No se puede construir el edificio. La cantidad de piedra es insuficiente.";
const string METAL_INSUFICIENTE = "No se puede construir el edificio. La cantidad de metal es insuficiente.";
const string MAXIMO_ALCANZADO = "No se puede construir el edificio. Cantidad maxima alcanzada.";
const string COORDENADA_INVALIDA = "La coordenada ingresada no es valida.";
const string COORDENADA_INALCANZABLE = "La coordenada ingresada no se encuentra en el mapa.";
const string COORDENADA_INACCESIBLE = "La coordenada ingresada no corresponde a un casillero construible.";
const string COORDENADA_OCUPADA = "El casillero seleccionado se encuentra ocupado.";
const string COORDENADA_LIBRE = "El casillero no tiene ningun edificio construido.";
const string INGRESE_COORD_X = "Coordenada fila: ";
const string INGRESE_COORD_Y = "Coordenada columna: ";
const string DESEA_CONSTRUIR = "Desea construir el edificio? (s/n)";
const string DESEA_MODIFICAR_MATERIAL = "Desea modificar la cantidad de material necesaria? (s/n)";
const string MENSAJE_CASILLERO_NO_CONSTRUIBLE = "El casillero seleccionado no es construible, por favor seleccione un casillero construible";
const string MENSAJE_COORDENADAS_INVALIDAS = "Las coordenadas ingresadas son inválidas";
// Matriz.h
const string TIPO_CASILLERO_DESCONOCIDO = "Formato de ubicaciones.txt desconocido";
const string MENSAJE_POSICION_INACCESIBLE = "La posicion es inaccesible";
const string ERROR_AGRANDAR_MATRIZ = "No fue posible agrandar matriz";

const string ERROR_ACHICAR_MATRIZ = "No fue posible achicar matriz";
// mecanica_juego.h
const string INGRESE_COORDENADAS_CONSTRUIR = "Ingrese las coordenadas en las que desea construir el edificio.";
const string INGRESE_COORDENADAS_DESTRUIR = "Ingrese las coordenadas en las que desea destruir el edificio.";
const string INGRESE_COORDENADAS_CONSULTAR = "Ingrese las coordenadas del casillero que desea consultaro.";
const string MENSAJE_DESTRUCCION_EXITOSA = "Edificio destruido exitosamente!";
const string MENSAJE_CONSTRUCCION_EXITOSA = "Construccion existosa!";
const string MENSAJE_CONSTRUCCION_FALLIDA = "Construccion cancelada";
const string MENSAJE_TRANSITABLES_COMPLETO = "Se despejaron las nubes : No hay casilleros transitables libres para lluevan materiales.";
const string MENSAJE_LLUVIA_INICIO = "Esta empezando a llover sobre el mapa....";
const string MENSAJE_LLUVIA_COMPLETA = "Termino la lluvia, se generaron los siguientes recursos: ";
const string MENSAJE_ATACAR_EDIFICO = "Ingrese la posición (fila,columna) a bombardear";
const string MENSAJE_REPARAR_EDIFICIO = "Ingrese la posición (fila,columna) a reparar";
const string MENSAJE_CASILLERO_NO_REPARABLE = "No se puede reparar, revise las coordenadas";
const string MENSAJE_REPARACION_EXITOSA = "Reparacion exitosa!";
// Objetivo_material.h
const string MENSAJE_OBJETIVO_COMPLETO = " ->Completo";

const string MENSAJE_OBJETIVO_INVENTARIO_RESTANTES_P1 = "Faltan ";
const string MENSAJE_OBJETIVO_INVENTARIO_RESTANTES_P2 = " de ";
const string MENSAJE_OBJETIVO_INVENTARIO_RESTANTES_P3 = "Para completar el objetivo ";
const string MENSAJE_OBJETIVO_SIMPLE_RESTANTES_P1 = "Faltan construir/obtener ";
const string MENSAJE_OBJETIVO_SIMPLE_RESTANTES_P2 = " para completar el objetivo ";
const string COMPLETAR_OBJETIVO_MULTIPLE_INICIO = "Faltan cumplir los siguientes objetivos ";
const string COMPLETAR_OBJETIVO_MULTIPLE_FIN = " para completar el objetivo ";

#endif