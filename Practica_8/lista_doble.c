#include <stdio.h>
#include <stdlib.h> 

// Estructura base del nodo
struct Nodo {
    int dato;
    struct Nodo *anterior; 
    struct Nodo *siguiente; 
};

// Paso 2: Funciones de Inserción 
// Nuevo nodo al inicio de la lista
void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    if (nuevo == NULL) {
        printf(" Falló la reserva de memoria \n");
        return;
    }
    
    nuevo->dato = valor;
    nuevo->anterior = NULL; 
    nuevo->siguiente = *inicio;
    
    // El nodo original ahora tiene un nodo anterior
    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }
    
    *inicio = nuevo; 
    printf(" Insertado %d al inicio \n", valor);
}

// Insertar un nuevo nodo al final de la lista
void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    if (nuevo == NULL) {
        printf(" Falló la reserva de memoria \n");
        return;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = NULL; 

    // 1. Si la lista está vacía, el nuevo nodo es el inicio
    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        printf(" Insertado %d al final (lista vacía) \n", valor);
        return;
    }
    
    // 2. Recorrer hasta el final
    struct Nodo *ultimo = *inicio;
    while (ultimo->siguiente != NULL) {
        ultimo = ultimo->siguiente;
    }
    
    // 3. Conectar el nodo 'ultimo' con el 'nuevo'
    ultimo->siguiente = nuevo;
    
    // 4. Conectar el nodo 'nuevo' con el 'ultimo' 
    nuevo->anterior = ultimo;
    printf(" Insertado %d al final \n", valor);
}

// Paso 3: Funciones de Recorrido 
// Recorre la lista de inicio a fin 
void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("Recorrido Adelante: NULL - ");
    
    if (actual == NULL) {
        printf("Vacía - NULL\n");
        return;
    }
    
    while (actual != NULL) {
        printf("%d - ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Recorre la lista de fin a inicio 
void recorrerAtras(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    
    if (actual == NULL) {
        printf("Recorrido Atrás: NULL - Vacía - NULL\n");
        return;
    }
    
    // 1. Encontrar el último nodo
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    
    // 2. Recorrer hacia atrás
    printf("Recorrido Atrás: NULL - ");
    while (actual != NULL) {
        printf("%d - ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

// Paso 4: Función de Eliminación 
// Eliminar la primera aparición de un valor de la lista
void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;

    // 1. Buscar el nodo a eliminar
    while (temp != NULL && temp->dato != valor) {
        temp = temp->siguiente;
    }
    
    // Caso 1: No se encontró
    if (temp == NULL) {
        printf(" El valor %d no se encontró para eliminar \n", valor);
        return;
    }

    // Caso 2: El nodo a eliminar NO es la cabeza 
    if (temp->anterior != NULL) {
        temp->anterior->siguiente = temp->siguiente;
    } else {
        // Caso 2a: Eliminar el nodo cabeza
        *inicio = temp->siguiente; 
    }
    
    // Caso 3: El nodo a eliminar no es el final 
    if (temp->siguiente != NULL) {
        temp->siguiente->anterior = temp->anterior;
    }
    
    // 4. Liberar la memoria
    printf(" Eliminado %d correctamente \n", valor);
    free(temp);
}

// Libera toda la memoria de la lista dinámicamente.
void liberar(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    struct Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente; 
        free(actual);                  
        actual = siguiente;            
    }
}

int main() {
    struct Nodo *inicio = NULL; 
    int numValores, valorAEliminar, i, valor;
    
    printf(" LISTA DOBLEMENTE LIGADA \n");

    // PASO 2: INSERCIÓN 
    printf("\n INSERCIÓN AL INICIO \n");
    printf("¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &numValores);

    // Inserción al inicio
    for (i = 0; i < numValores; i++) {
        printf("Ingrese valor inicial %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }
    recorrerAdelante(inicio);
    
    printf("\n INSERCIÓN AL FINAL \n");
    printf("¿Cuántos valores desea insertar al final? ");
    scanf("%d", &numValores);

    // Inserción al final
    for (i = 0; i < numValores; i++) {
        printf(" Ingrese valor final %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }
    recorrerAdelante(inicio);

    // PASO 3: RECORRIDO BIDIRECCIONAL 
    printf("\n RECORRIDO EN AMBOS SENTIDOS \n");
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    // PASO 4: ELIMINACIÓN 
    printf("¿Qué valor desea eliminar de la lista? ");
    scanf("%d", &valorAEliminar);

    eliminar(&inicio, valorAEliminar);

    // 4. Mostrar lista actualizada
    printf("\n Lista después de la eliminación: \n");
    recorrerAdelante(inicio); 
    recorrerAtras(inicio); 
    
    // PASO 5: LIBERACIÓN DE MEMORIA 
    printf("\n LIBERACIÓN DE MEMORIA \n");
    liberar(inicio);
    printf(" Memoria liberada correctamente \n");

    return 0;
}
