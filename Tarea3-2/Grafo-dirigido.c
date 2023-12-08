#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un nodo en el grafo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Estructura para representar el grafo dirigido
typedef struct Grafo {
    int V;                  // Número de vértices
    Nodo** listaDeAdyacencia;   // Lista de adyacencia
} Grafo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para crear un grafo con V vértices
Grafo* crearGrafo(int V) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = V;
    grafo->listaDeAdyacencia = (Nodo**)malloc(V * sizeof(Nodo*));

    // Inicializar la lista de adyacencia
    for (int i = 0; i < V; ++i) {
        grafo->listaDeAdyacencia[i] = NULL;
    }

    return grafo;
}

// Función para agregar un arco al grafo dirigido
void agregarArco(Grafo* grafo, int origen, int destino) {
    // Crear un nuevo nodo en la lista de adyacencia de origen
    Nodo* nuevoNodo = crearNodo(destino);
    nuevoNodo->siguiente = grafo->listaDeAdyacencia[origen];
    grafo->listaDeAdyacencia[origen] = nuevoNodo;
}

// Función para imprimir el grafo dirigido
void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->V; ++i) {
        printf("Lista de adyacencia del vértice %d: ", i);
        Nodo* actual = grafo->listaDeAdyacencia[i];
        while (actual) {
            printf("%d -> ", actual->dato);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
}

// Función principal
int main() {
    int V = 5; // Número de vértices
    Grafo* grafo = crearGrafo(V);

    // Agregar arcos al grafo dirigido
    agregarArco(grafo, 0, 1);
    agregarArco(grafo, 0, 4);
    agregarArco(grafo, 1, 3);
    agregarArco(grafo, 2, 0);
    agregarArco(grafo, 3, 2);
    agregarArco(grafo, 4, 1);

    // Imprimir el grafo dirigido
    imprimirGrafo(grafo);

    return 0;
}