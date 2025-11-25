#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

// Estructura de la Cola Doble (Deque)
typedef struct {
    int datos[MAX];
    int frente; 
    int size;   
} Deque;

void inicializarDeque(Deque *d) {
    d->frente = 0;
    d->size = 0;
    printf(" Cola Doble (Deque) inicializada (frente = 0, size = 0) \n");
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

int isFull(Deque *d) {
    return d->size == MAX;
}

// Calcular la posición del último elemento
int getRearIndex(Deque *d) {
    if (isEmpty(d)) {
        return -1; 
    }
    return (d->frente + d->size - 1) % MAX;
}

// Operaciones de Inserción y Eliminación (Paso B2)
// Insertar por el frente (insert_front)
void insert_front(Deque *d, int valor) {
    if (isFull(d)) {
        printf(" Deque llena (OVERFLOW). No se insertó %d.\n", valor);
        return;
    }

    // 1. Mover el índice 'frente' a la posición anterior de forma circular
    d->frente = (d->frente - 1 + MAX) % MAX;
    d->datos[d->frente] = valor;
    d->size++;
    printf(" INSERT_FRONT: %d insertado. (Size: %d)\n", valor, d->size);
}

// Insertar por el final (insert_rear)
void insert_rear(Deque *d, int valor) {
    if (isFull(d)) {
        printf(" Deque llena (OVERFLOW). No se insertó %d.\n", valor);
        return;
    }

    // 1. Calcular la posición donde se insertará 
    int rear_insert_index = (d->frente + d->size) % MAX;
    d->datos[rear_insert_index] = valor;
    d->size++;
    printf(" INSERT_REAR: %d insertado. (Size: %d)\n", valor, d->size);
}

// Eliminar por el frente (delete_front)
int delete_front(Deque *d) {
    if (isEmpty(d)) {
        printf(" Deque vacía (UNDERFLOW) \n");
        return -1;
    }

    // 1. Obtener el valor del frente
    int valor = d->datos[d->frente];
    
    // 2. Mover el índice 'frente' a la siguiente posición de forma circular
    d->frente = (d->frente + 1) % MAX;
    d->size--;
    return valor;
}

// Eliminar por el final (delete_rear)
int delete_rear(Deque *d) {
    if (isEmpty(d)) {
        printf(" Deque vacía (UNDERFLOW) \n");
        return -1;
    }

    // 1. Calcular el índice del último elemento
    int rear_index = getRearIndex(d);
    int valor = d->datos[rear_index];
    d->size--;
    return valor;
}

// Elemento del frente sin sacarlo (peek_front)
int peek_front(Deque *d) {
    if (isEmpty(d)) {
        printf(" Deque vacía \n");
        return -1;
    }
    return d->datos[d->frente];
}

// Elemento del final sin sacarlo (peek_rear)
int peek_rear(Deque *d) {
    if (isEmpty(d)) {
        printf(" Deque vacía \n");
        return -1;
    }
    return d->datos[getRearIndex(d)];
}

// Estado actual de la Deque
void printDeque(Deque d) {
    int rear_idx = getRearIndex(&d);
    printf("   [Estado Deque] F(%d) | R(%d) | Size(%d) -> [ ", d.frente, rear_idx, d.size);
    if (isEmpty(&d)) {
        printf("Vacía ]\n");
        return;
    }
    
    int i = d.frente;
    int count = 0;
    while (count < d.size) {
        printf("%d ", d.datos[i]);
        i = (i + 1) % MAX;
        count++;
    }
    printf("]\n");
}


int main() {
    Deque miDeque;
    
    printf("=== B) PRUEBAS DE COLA DOBLE (DEQUE) ===\n");
    
    inicializarDeque(&miDeque);
    printDeque(miDeque);

    printf("\n Paso B3.1 - B3.4: Inserciones \n");
    
    // 1. insert_front(10)
    insert_front(&miDeque, 10);
    printDeque(miDeque);
    
    // 2. insert_rear(15), insert_rear(20)
    insert_rear(&miDeque, 15);
    insert_rear(&miDeque, 20);
    printDeque(miDeque);

    // 3. insert_front(30)
    insert_front(&miDeque, 30); 
    printDeque(miDeque);
    
    // 4. insert_rear(40) 
    insert_rear(&miDeque, 40); 
    printf(" La Deque está llena \n");
    printDeque(miDeque); 

    printf("\n Paso B3.5: Eliminaciones \n");
    
    // delete_front()
    int val_f = delete_front(&miDeque);
    printf("DELETE_FRONT: Salió %d. Frente se mueve de %d a %d.\n", val_f, (miDeque.frente - 1 + MAX) % MAX, miDeque.frente);
    printDeque(miDeque); 
    
    // delete_rear()
    int val_r = delete_rear(&miDeque);
    printf("DELETE_REAR: Salió %d. El nuevo Rear (último) es %d.\n", val_r, getRearIndex(&miDeque));
    printDeque(miDeque); 

    printf("\n Paso B3.6: Reciclaje y movimientos \n");
    
    // Insertar por el frente 
    insert_front(&miDeque, 5); 
    printDeque(miDeque); 
    
    // Insertar por el final
    insert_rear(&miDeque, 50);
    printDeque(miDeque); 
    
    printf("\nPeek Front: %d\n", peek_front(&miDeque));
    printf("Peek Rear: %d\n", peek_rear(&miDeque));

    return 0;
}
