#include <stdio.h>
#include <stdlib.h>

// Estructura base del nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Nuevo nodo al inicio de la lista circular
void insertarInicioCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if (nuevoNodo == NULL) {
        printf(" Falló la reserva de memoria \n");
        return;
    }

    nuevoNodo->dato = valor;

    // Si la lista está vacía
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        *ultimo = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;

    } else {
        // La lista no está vacía:
        nuevoNodo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevoNodo;
        *cabeza = nuevoNodo;
    }

    printf(" Insertado %d al inicio \n", valor);
}

// Recorre la lista circular
void recorrerCircular(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    printf("Lista Circular: ");

    if (cabeza == NULL) {
        printf("Vacía \n");
        return;
    }

    // Nodo de cabeza
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);

    printf("Regresa a %d \n", cabeza->dato);
}

// Elimina la primera aparición de un valor de la lista circular
void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf(" La lista está vacía, no se puede eliminar \n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor) {
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    // Caso 1: El valor no se encontró
    if (actual->dato != valor) {
        printf(" El valor %d no se encontró en la lista \n", valor);
        return;
    }

    // Caso 2: El valor se encontró
    // a: Único nodo en la lista
    if (actual == *cabeza && actual == *ultimo && actual->siguiente == *cabeza) {
        free(actual);
        *cabeza = NULL;
        *ultimo = NULL;
        printf(" Eliminado %d. La lista está vacía \n", valor);
        return;
    }

    // b: Eliminación de la cabeza (pero hay más nodos)
    if (actual == *cabeza) {
        *cabeza = actual->siguiente;
        (*ultimo)->siguiente = *cabeza;

    // c: Eliminación del último nodo
    } else if (actual == *ultimo) {
        *ultimo = anterior;
        (*ultimo)->siguiente = *cabeza;

    // d: Eliminación de nodo intermedio
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf(" Eliminado %d correctamente \n", valor);
}

// Liberar la memoria de la lista dinámicamente.
void liberarCircular(struct Nodo **cabeza, struct Nodo **ultimo) {
    if (*cabeza == NULL) return;
    struct Nodo *actual = *cabeza;
    struct Nodo *temp;

    // Romper el enlace circular del último nodo para detener el bucle
    (*ultimo)->siguiente = NULL;

    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *cabeza = NULL;
    *ultimo = NULL;
}

int main() {
    // Paso 1: Declarar punteros
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int numValores, valorAEliminar, i, valor;

    printf("\n LISTA ENLAZADA CIRCULAR \n");

    // PASO 2: INSERCIÓN CIRCULAR
    printf("\n INSERCIÓN AL INICIO \n");
    printf("¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &numValores);

    for (i = 0; i < numValores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicioCircular(&cabeza, &ultimo, valor);

        // Muestra el contenido después de cada inserción
        recorrerCircular(cabeza);
    }

    // PASO 3: RECORRIDO CIRCULAR
    printf("\n RECORRIDO CIRCULAR \n");
    printf("Recorrido final de la lista:\n");
    recorrerCircular(cabeza);

    // PASO 4: ELIMINACIÓN CIRCULAR
    printf("\n ELIMINACIÓN \n");
    printf("¿Qué valor desea eliminar de la lista? ");
    scanf("%d", &valorAEliminar);

    // 2. Implementar la lógica 3. Mostrar lista actualizada
    eliminarCircular(&cabeza, &ultimo, valorAEliminar);
    recorrerCircular(cabeza);

    // Volver a eliminar para probar otro caso
    if (cabeza != NULL) {
        printf("\nProbando eliminar la cabeza actual (%d) \n", cabeza->dato);
        eliminarCircular(&cabeza, &ultimo, cabeza->dato);
        recorrerCircular(cabeza);
    }

    printf("\n LIBERACIÓN DE MEMORIA \n");
    liberarCircular(&cabeza, &ultimo);
    printf("Memoria liberada correctamente\n");
    return 0;
}
