#include <stdio.h>
#include <stdlib.h> 

// Estructura base del nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Inserta un nuevo nodo al inicio de la lista.
void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    if (nuevoNodo == NULL) {
        printf(" Falló la reserva de memoria.\n");
        return;
    }
    
    // 2. Asignar el valor
    nuevoNodo->dato = valor;
    
    // 3. Apuntar el 'siguiente' del nuevo nodo a la cabeza actual
    nuevoNodo->siguiente = *cabeza;
    
    // 4. Mover la cabeza al nuevo nodo
    *cabeza = nuevoNodo;
    
    printf(" Insertado %d al inicio\n", valor);
}

// Recorre la lista desde la cabeza hasta NULL e imprime los valores
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    printf("Lista: ");
    
    if (actual == NULL) {
        printf("Vacía\n");
        return;
    }
    
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Elimina la primera aparición de un valor de la lista.
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *temp = *cabeza;
    struct Nodo *anterior = NULL;

    // Caso 1: El nodo a eliminar es la cabeza (*cabeza)
    if (temp != NULL && temp->dato == valor) {
        *cabeza = temp->siguiente; // Mover la cabeza al siguiente nodo
        free(temp);                
        printf(" Eliminado %d \n", valor);
        return;
    }

    // Caso 2: Buscar el nodo a eliminar (el valor está en medio o al final)
    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf(" El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    anterior->siguiente = temp->siguiente;
    
    // Liberar la memoria del nodo que se va
    free(temp);
    printf(" Eliminado %d (En medio/final)\n", valor);
}

void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    struct Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente; 
        free(actual);                  
        actual = siguiente;          
    }
}

int main() {
    // Paso 1.1 Crear la estructura y puntero
    struct Nodo *cabeza = NULL; 
    int numValores, valorAEliminar, i, valor;
    
    printf(" LISTA ENLAZADA SIMPLE \n");

    // PASO 2: INSERCIÓN 
    printf("\n INSERCIÓN AL INICIO \n");
    printf("¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &numValores);

    for (i = 0; i < numValores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }
    
    // PASO 3: RECORRIDO Y ELIMINACIÓN 
    printf("\n RECORRIDO Y ELIMINACIÓN \n");

    printf("Contenido final de la lista antes de eliminar:\n");
    recorrer(cabeza);

    printf("\n¿Qué valor desea eliminar de la lista? ");
    scanf("%d", &valorAEliminar);

    eliminar(&cabeza, valorAEliminar);
    recorrer(cabeza); 
    
    // PASO 4: LIBERACIÓN DE MEMORIA 
    printf("\n LIBERACIÓN DE MEMORIA \n");
    liberar(cabeza);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
