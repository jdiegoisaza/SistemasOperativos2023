#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura del nodo de la lista
struct nodo {
    int number;
    char city[50];
    char gender[10];
    int age;
    float income;
    char illness[10];
    struct nodo *siguiente;
};

int main() {
    FILE *archivo;
    char linea[100];
    char *token;
    struct nodo *inicio = NULL;
    struct nodo *nuevo;
    struct nodo *actual;

    archivo = fopen("toy_dataset.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Leemos cada línea del archivo
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Creamos un nuevo nodo para cada línea
        nuevo = (struct nodo*) malloc(sizeof(struct nodo));
        nuevo->siguiente = NULL;
        // Separamos los campos de la línea utilizando la coma como delimitador
        token = strtok(linea, ",");
        nuevo->number = atoi(token);
	printf("%d\n", atoi(token));

        token = strtok(NULL, ",");
        strcpy(nuevo->city, token);

        token = strtok(NULL, ",");
        strcpy(nuevo->gender, token);

        token = strtok(NULL, ",");
        nuevo->age = atoi(token);

        token = strtok(NULL, ",");
        nuevo->income = atof(token);

        token = strtok(NULL, ",");
        strcpy(nuevo->illness, token);

        // Agregamos el nuevo nodo a la lista enlazada
        if (inicio == NULL) {
            inicio = nuevo;
        } else {
            actual = inicio;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }

    fclose(archivo);

    // Recorremos la lista e imprimimos los datos de cada nodo
    actual = inicio;
    while (actual != NULL) {
        printf("%d, %s, %s, %d, %.2f, %s\n", actual->number, actual->city, actual->gender, actual->age, actual->income, actual->illness);
        actual = actual->siguiente;
    }

    // Liberamos la memoria asignada a los nodos
    actual = inicio;
    while (actual != NULL) {
        nuevo = actual->siguiente;
        free(actual);
        actual = nuevo;
    }

    return 0;
}

