#include <stdio.h>
#include <stdlib.h>

struct NodoAVL {
    int dato;
    struct NodoAVL* izquierda;
    struct NodoAVL* derecha;
    int altura;
};

int obtenerAltura(struct NodoAVL* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return nodo->altura;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

struct NodoAVL* crearNodo(int dato) {
    struct NodoAVL* nodo = (struct NodoAVL*)malloc(sizeof(struct NodoAVL));
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    nodo->altura = 1; 
    return nodo;
}

struct NodoAVL* rotacionDerecha(struct NodoAVL* y) {
    struct NodoAVL* x = y->izquierda;
    struct NodoAVL* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = maximo(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = maximo(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    return x;
}

struct NodoAVL* rotacionIzquierda(struct NodoAVL* x) {
    struct NodoAVL* y = x->derecha;
    struct NodoAVL* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = maximo(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = maximo(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    return y;
}

int obtenerBalance(struct NodoAVL* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

struct NodoAVL* insertar(struct NodoAVL* nodo, int dato) {

    if (nodo == NULL) {
        return crearNodo(dato);
    }

    if (dato < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, dato);
    } else if (dato > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, dato);
    } else 
	{
        return nodo;
    }

    nodo->altura = 1 + maximo(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && dato < nodo->izquierda->dato) {
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && dato > nodo->derecha->dato) {
        return rotacionIzquierda(nodo);
    }

    if (balance > 1 && dato > nodo->izquierda->dato) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && dato < nodo->derecha->dato) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void inOrden(struct NodoAVL* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierda);
        printf("%d ", raiz->dato);
        inOrden(raiz->derecha);
    }
}

int main() {
    struct NodoAVL* raiz = NULL;

    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    printf("Recorrido Inorden del Árbol AVL:\n");
    inOrden(raiz);

    return 0;
}