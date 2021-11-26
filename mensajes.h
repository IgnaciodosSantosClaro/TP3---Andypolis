#ifndef MENSAJES_H
#define MENSAJES_H
#include <string>
using namespace std;
const string MENSAJE_ARCHIVO_NO_ENCONTRADO = "Archivo no encontrado";
//Interfaz
const string NOMBRE_CASILLERO_INACCESIBLE = "Lago";
const string NOMBRE_CASILLERO_TRANSITABLE = "Camino";
const string NOMBRE_CASILLERO_CONSTRUIBLE = "Terreno construible";

//Casillero_inaccesible
const string CASILLERO_OCUPADO_MENSAJE = " y estoy ocupado.";
const string CASILLERO_NO_OCUPADO_MENSAJE = " y no estoy ocupado.";
const string CASILLERO_CONSULTADO = " y me encuentro en el casillero consultado.";
const string CASILLERO_INACCESIBLE_MENSAJE = "Soy un casillero inaccesible";
const string CASILLERO_CONSTRUIBLE_MENSAJE = "Soy un casillero construible";
const string CASILLERO_TRANSITABLE_MENSAJE = "Soy un casillero transitable";
//menu
const std::string ENCABEZADO_MENU = "═════════════════════════════════════";
const std::string TITULO_MENU = "MENU";
const std::string MENSAJE_OPCION_1 = " 1. Construir edificio por nombre.";
const std::string MENSAJE_OPCION_2 = " 2. Listar edificios construidos.";
const std::string MENSAJE_OPCION_3 = " 3. Listar todos los edificios.";
const std::string MENSAJE_OPCION_4 = " 4. Demoler edificio por coordenada.";
const std::string MENSAJE_OPCION_5 = " 5. Mostrar mapa.";
const std::string MENSAJE_OPCION_6 = " 6. Consultar coordenada.";
const std::string MENSAJE_OPCION_7 = " 7. Mostrar inventario.";
const std::string MENSAJE_OPCION_8 = " 8. Recolectar recursos producidos.";
const std::string MENSAJE_OPCION_9 = " 9. LLuvia de recursos.";
const std::string MENSAJE_OPCION_10 = " 10. Guardar y salir.";
const std::string INGRESE_ACCION = "Ingrese el numero de la accion que desea realizar.";
const std::string MENSAJE_DESPEDIDA = "Adios!";
const std::string ERROR_GUARDAR = "ERROR guardando"; //integrar a error.h
const std::string MENSAJE_OPCION_INVALIDA = "La opcion elegida es invalida. Intente nuevamente.";
//utiles.h
const int ANCHO_DE_INVENTARIO = 11;
const std::string ENCABEZADO_LISTADO_MATERIALES = "══════════════════════════════════════════";
const string TITULO_LISTADO_MATERIALES = "\t Listado de materiales        ";
const string TITULO_COLUMNA_MATERIAL = "Material";
const string TITULO_COLUMNA_CANTIDAD = "Cantidad";
const string TITULO_LISTADO_EDIFICIOS = "\t Listado de edificios        ";
const string TITULO_COLUMNA_EDIFICIOS = "Edificios";
const std::string PIEDRA_MAYUS = "Piedra";
const std::string MADERA_MAYUS = "Madera";
const std::string METAL_MAYUS = "Metal";
const string TITULO_COLUMNA_CANT_CONSTRUIDA = "Cantidad construida";
const string TITULO_COLUMNA_CANT_PERMITIDA = "Cantidad maxima";
const string TITULO_COLUMNA_MATERIAL_ENTREGADO = "Material otorgado";
const string TITULO_COLUMNA_TIPO = "Tipo";
const string TITULO_LISTADO_EDIFICIOS_CONSTRUIDOS = "\t Listado de edificios construidos"; //
const char TABULACION = '\t';
const string TITULO_COLUMNA_EDIFICIO = "Edificio";
const string TITULO_COLUMNA_COORDENADAS = "Coordenadas";

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

//Matriz.h
const string TIPO_CASILLERO_DESCONOCIDO = "Formato de ubicaciones.txt desconocido";
const string MENSAJE_POSICION_INACCESIBLE = "La posicion es inaccesible";
const string ERROR_AGRANDAR_MATRIZ = "No fue posible agrandar matriz";

const string ERROR_ACHICAR_MATRIZ = "No fue posible achicar matriz";
//mecanica_juego.h
const string INGRESE_COORDENADAS_CONSTRUIR = "Ingrese las coordenadas en las que desea construir el edificio.";
const string INGRESE_COORDENADAS_DESTRUIR = "Ingrese las coordenadas en las que desea destruir el edificio.";
const string INGRESE_COORDENADAS_CONSULTAR = "Ingrese las coordenadas del casillero que desea consultaro.";
const string MENSAJE_DESTRUCCION_EXITOSA = "Edificio destruido exitosamente!";
const string MENSAJE_CONSTRUCCION_EXITOSA = "Construccion existosa!";
const string MENSAJE_CONSTRUCCION_FALLIDA = "Construccion cancelada";
const string MENSAJE_TRANSITABLES_COMPLETO = "Se despejaron las nubes : No hay casilleros transitables libres para lluevan materiales.";
const string MENSAJE_LLUVIA_INICIO = "Esta empezando a llover sobre el mapa....";
const string MENSAJE_LLUVIA_COMPLETA = "Termino la lluvia, se generaron los siguientes recursos: ";
#endif