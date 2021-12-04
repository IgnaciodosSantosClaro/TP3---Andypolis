#include "Floyd.h"

int ** Floyd::crear_matriz_caminos(){

    int ** caminos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        caminos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crear_matriz_costos(int ** matriz_adyacencia){

    int ** costos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        costos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            costos[i][j] = matriz_adyacencia[i][j];
        }
    }
    return costos;
}

void Floyd::mostrar_matrices(){
    cout << "Matriz de costos:      ||           Matriz de caminos:" << endl;
    string filaCostos;
    string filaCaminos;
    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices * 2; j++) {
            if(j == cantidad_vertices * 2 - 1){
                filaCostos += "            ||           ";
                filaCaminos += "\n";
            } else if(j % 2 == 0){
                if(matriz_costos[i][j/2] == INFINITO){
                    filaCostos += "∞";
                } else {
                    filaCostos += to_string(matriz_costos[i][j/2]);
                }

                if(matriz_caminos[i][j/2] == POSICION_NO_ENCONTRADA){
                    filaCaminos += "-";
                } else {
                    filaCaminos += to_string(matriz_caminos[i][j/2]);
                }
            } else{
                filaCaminos += "|";
                filaCostos += "|";
            }
        }
        cout << filaCostos << filaCaminos;
        filaCostos = "";
        filaCaminos = "";
    }
    cout << endl;
}

void Floyd::calcular_matrices() {

    cantidad_vertices = vertices -> obtener_cantidad_de_elementos();
    matriz_costos = crear_matriz_costos(matriz_adyacencia);
    matriz_caminos = crear_matriz_caminos();
    for (int vertice_intermedio = 0; vertice_intermedio < cantidad_vertices; vertice_intermedio++) {

        for (int origen = 0; origen < cantidad_vertices; origen++){

            for (int destino = 0; destino < cantidad_vertices; destino++) {

                int costo = matriz_costos[origen][vertice_intermedio] + matriz_costos[vertice_intermedio][destino];

                if (matriz_costos[origen][destino] > costo) {
                    matriz_costos[origen][destino] = costo;
                    matriz_caminos[origen][destino] = matriz_caminos[origen][vertice_intermedio];
                } else if (matriz_costos[origen][destino] == INFINITO){
                    matriz_caminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }

            }

        }
//        cout << endl << "Iteracion numero: " << vertice_intermedio << endl;
//        mostrar_matrices();
    }

    cout << endl;

}

Vector<string>* Floyd::camino_minimo(int origen, int destino) {
//    if(matriz_caminos[origen][destino] == POSICION_NO_ENCONTRADA){
//        cout << "No hay un camino que conecte " <<  vertices->obtener_nombre(origen + 1) << " con " << vertices->obtener_nombre(destino + 1);
//    } else {
//        cout << "El camino minimo que une " <<  vertices->obtener_nombre(origen + 1) << " con " << vertices->obtener_nombre(destino + 1);
//        cout << " tiene un costo de: " << matriz_costos[origen][destino] << " y es el siguiente: ";
//        cout << vertices->obtener_nombre(origen + 1);
//        do {
//            origen = matriz_caminos[origen][destino];
//            cout << " -> " << vertices->obtener_nombre(origen + 1);
//        } while(origen != destino);
//    }
//    cout << endl;
    if(matriz_caminos[origen][destino] == POSICION_NO_ENCONTRADA) {
        camino_recorrido->agregar_al_final("∞");
    }
    else {
        do {
            origen = matriz_caminos[origen][destino];
            camino_recorrido->agregar_al_final(vertices->obtener_nombre(origen + 1));
        } while (origen != destino);
    }

    return camino_recorrido;

}

int Floyd::obtener_arista(int origen, int destino) {
    return matriz_costos[origen][destino];
}

void Floyd::liberar_matrices() {
    if(matriz_costos != nullptr && matriz_caminos != nullptr){
        for(int i = 0; i < cantidad_vertices; i++){
            delete[] matriz_costos[i];
            delete[] matriz_caminos[i];
        }
        delete[] matriz_costos;
        delete[] matriz_caminos;

        matriz_costos = nullptr;
        matriz_caminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberar_matrices();
    camino_recorrido->liberar_vector();
    delete camino_recorrido;

}

Floyd::Floyd(Lista<Vertice> *vertices, int ** matriz_adyacencia) : Camino_minimo(vertices, matriz_adyacencia){
    calcular_matrices();
}




