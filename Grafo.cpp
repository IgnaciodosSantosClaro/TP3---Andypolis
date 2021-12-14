#include "Grafo.h"

Grafo::Grafo()
{
    matriz_de_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(string nuevo_vertice)
{
    agrandar_matriz_de_adyacencia();
    vertices->agregar(nuevo_vertice);
}

void Grafo::mostrar_grafo()
{
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

void Grafo::agregar_camino(string origen, string destino, int peso)
{
    int posicion_origen = vertices->obtener_posicion(origen);
    int posicion_destino = vertices->obtener_posicion(destino);

    if (posicion_origen == POSICION_NO_ENCONTRADA)
    {
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if (posicion_destino == POSICION_NO_ENCONTRADA)
    {
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if (!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA))
    {
        matriz_de_adyacencia[posicion_origen][posicion_destino] = peso;
    }
}

void Grafo::actualizar_camino(string origen, string destino, int peso)
{
    int posicion_origen = vertices->obtener_posicion(origen);
    int posicion_destino = vertices->obtener_posicion(destino);

    matriz_de_adyacencia[posicion_origen][posicion_destino] = peso;
}

Vector<string> *Grafo::camino_minimo(string origen, string destino)
{
    int posicion_origen = vertices->obtener_posicion(origen);
    int posicion_destino = vertices->obtener_posicion(destino);

    return camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_de_adyacencia()
{
    int **matriz_auxiliar;
    int nueva_cantidad_de_vertices = vertices->obtener_cantidad_de_elementos() + 1;

    matriz_auxiliar = new int *[nueva_cantidad_de_vertices];
    for (int i = 0; i < nueva_cantidad_de_vertices; i++)
    {
        matriz_auxiliar[i] = new int[nueva_cantidad_de_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int **nueva_adyacente)
{
    for (int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++)
    {
        for (int j = 0; j < vertices->obtener_cantidad_de_elementos(); j++)
        {
            nueva_adyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int **nueva_adyacente)
{
    for (int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++)
    {
        nueva_adyacente[vertices->obtener_cantidad_de_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices->obtener_cantidad_de_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices->obtener_cantidad_de_elementos()][vertices->obtener_cantidad_de_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia()
{
    for (int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++)
    {
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo()
{
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}

void Grafo::mostrar_vertices()
{
    cout << "Lista de vértices: [";
    for (int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++)
    {
        cout << vertices->obtener_nombre(i + 1);
        if (i + 1 != vertices->obtener_cantidad_de_elementos())
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrar_matriz_adyacencia()
{
    cout << "Matriz de adyacencia:" << endl;
    for (int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++)
    {
        for (int j = 0; j < vertices->obtener_cantidad_de_elementos() * 2; j++)
        {
            if (j == vertices->obtener_cantidad_de_elementos() * 2 - 1)
            {
                cout << endl;
            }
            else if (j % 2 == 0)
            {
                if (matriz_de_adyacencia[i][j / 2] == INFINITO)
                {
                    cout << "∞";
                }
                else
                {
                    cout << matriz_de_adyacencia[i][j / 2];
                }
            }
            else
            {
                cout << "|";
            }
        }
    }
    cout << endl;
}

Vector<string> *Grafo::camino_minimo(int origen, int destino)
{
    return algoritmo_camino_minimo->camino_minimo(origen, destino);
}

void Grafo::usar_floyd()
{
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Floyd(vertices, matriz_de_adyacencia);
}

int Grafo::obtener_arista(string origen, string destino)
{
    int posicion_origen = vertices->obtener_posicion(origen);
    int posicion_destino = vertices->obtener_posicion(destino);

    return obtener_arista(posicion_origen, posicion_destino);
}

int Grafo::obtener_arista(int origen, int destino)
{
    return algoritmo_camino_minimo->obtener_arista(origen, destino);
}
