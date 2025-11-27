#include <stdio.h>
#include <stdlib.h> 

// Estructura base del nodo
struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Inserta un nuevo nodo al final de la lista circular.
void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    if (nuevo == NULL) {
        printf(" Falló la reserva de memoria \n");
        return;
    }
    
    nuevo->dato = valor;

    // Caso 1: La lista está vacía
    if (*inicio == NULL) {
        *inicio = nuevo;
        nuevo->anterior = nuevo; 
        nuevo->siguiente = nuevo; 
        printf(" Insertado %d (Primer nodo) \n", valor);
        return;
    }

    // Caso 2: La lista no está vacía
    struct Nodo *ultimo = (*inicio)->anterior;
    
    // 1. Conectar el nuevo nodo
    nuevo->siguiente = *inicio; 
    nuevo->anterior = ultimo;   
    
    // 2. Actualizar los enlaces del inicio y último nodo
    ultimo->siguiente = nuevo;    
    (*inicio)->anterior = nuevo; 
    
    printf(" Insertado %d al final \n", valor);
}

// Recorre la lista desde el inicio hasta que vuelve al inicio
void recorrerAdelanteCircular(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf(" Recorrido Circular: ");
    
    if (inicio == NULL) {
        printf(" Vacía \n");
        return;
    }

    do {
        printf("%d - ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    
    printf(" Vuelve al inicio (%d)\n", inicio->dato);
}

// Elimina la primera aparición de un valor de la lista circular.
void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf(" No se puede eliminar, la lista está vacía \n");
        return;
    }

    struct Nodo *temp = *inicio;
    
    do {
        if (temp->dato == valor) {
            break;
        }
        temp = temp->siguiente;
    } while (temp != *inicio);

    // Caso 1: El valor no se encontró
    if (temp->dato != valor && temp == *inicio) {
        printf(" El valor %d no se encontró en la lista \n", valor);
        return;
    }

    // Caso 2: Se encontró el valor 
    // Caso 2a: Único nodo en la lista
    if (temp == *inicio && temp->siguiente == *inicio) {
        free(temp);
        *inicio = NULL;
        printf(" Eliminado %d (Único nodo). La lista está vacía \n", valor);
        return;
    }
    
    // Caso 2b: Más de un nodo
    struct Nodo *anterior = temp->anterior;
    struct Nodo *siguiente = temp->siguiente;
    
    // Conexión del anterior y el siguiente
    anterior->siguiente = siguiente;
    siguiente->anterior = anterior;
    
    // Actualizar el inicio si se eliminó el primer nodo
    if (temp == *inicio) {
        *inicio = siguiente; 
    }
    
    printf(" Eliminado %d correctamente \n", valor);
    free(temp);
}

// Libera toda la memoria de la lista circular
void liberarCircular(struct Nodo **inicio) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;
    struct Nodo *ultimo = (*inicio)->anterior;

    // Romper el ciclo antes de liberar
    ultimo->siguiente = NULL; 
    
    struct Nodo *temp;
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *inicio = NULL;
}

int main() {
    struct Nodo *inicio = NULL; 
    int numValores, valorAEliminar, i, valor;
    
    printf("\n LISTA DOBLEMENTE LIGADA CIRCULAR \n");

    // PASO 2: INSERCIÓN CIRCULAR 
    printf("\n INSERCIÓN AL FINAL \n");
    printf("¿Cuántos valores desea insertar al final? ");
    scanf("%d", &numValores);

    for (i = 0; i < numValores; i++) {
        printf(" Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
        recorrerAdelanteCircular(inicio);
    }
    
    // PASO 3: RECORRIDO CIRCULAR 
    printf("\n RECORRIDO CIRCULAR \n");
    recorrerAdelanteCircular(inicio);
    
    // Comprobación de la doble ligadura circular
    if (inicio != NULL) {
        struct Nodo *ultimo = inicio->anterior;
        printf(" Comprobación: El inicio (%d) apunta hacia atrás al último (%d) \n", 
               inicio->dato, ultimo->dato);
    }
    
    // PASO 4: ELIMINACIÓN CIRCULAR 
    printf("\n ELIMINACIÓN \n");
    
    printf("¿Qué valor desea eliminar de la lista? ");
    scanf("%d", &valorAEliminar);

    eliminarCircular(&inicio, valorAEliminar);
    
    // Mostrar lista actualizada
    if (inicio != NULL) {
        recorrerAdelanteCircular(inicio); 
    } else {
        printf(" Lista vacía después de eliminar ");
    }

    // Paso 5: LIBERACIÓN DE MEMORIA 
    printf("\n LIBERACIÓN DE MEMORIA \n");
    liberarCircular(&inicio);
    printf("Memoria liberada correctamente\n");

    return 0;
}
