#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura del nodo de la lista
struct nodo {
    int valor;
    struct nodo *siguiente;
};

struct lista {
    struct nodo *cabeza;
};

int main() {
    // Creamos los nodos de la lista
    struct nodo *nodo1 = (struct nodo*) malloc(sizeof(struct nodo));
    struct nodo *nodo2 = (struct nodo*) malloc(sizeof(struct nodo));
    struct nodo *nodo3 = (struct nodo*) malloc(sizeof(struct nodo));

    // Asignamos los valores a cada nodo
    nodo1->valor = 1;
    nodo2->valor = 2;
    nodo3->valor = 3;

    // Conectamos los nodos en la lista
    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;
    nodo3->siguiente = NULL; // El último nodo apunta a NULL para indicar el final de la lista

    // Recorremos la lista e imprimimos los valores
    struct nodo *actual = nodo1;
    while (actual != NULL) {
        printf("%d\n", actual->valor);
        actual = actual->siguiente;
    }

    // Liberamos la memoria asignada a los nodos
    free(nodo1);
    free(nodo2);
    free(nodo3);

    return 0;
}

