#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

// Estructura de la Cola Circular
typedef struct {
    int datos[MAX];
    int frente; 
    int final;  
    int size;  
} ColaCircular;

// Funciones de Control
// Paso A1. Inicialización
void inicializarColaCircular(ColaCircular *c) {
    c->frente = 0; 
    c->final = 0;  
    c->size = 0;   
    printf(" Cola circular inicializada (frente = 0, final = 0, size = 0) \n");
}

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

// Operaciones (Paso A2)
// Insertar elementos (Enqueue)
void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf(" Cola llena (OVERFLOW). No se insertó %d.\n", valor);
        return;
    }

    // 1. Insertar el valor en la posición 'final'
    c->datos[c->final] = valor;
    
    // 2. Avanzar el índice 'final' de forma circular
    c->final = (c->final + 1) % MAX;
    
    // 3. Incrementar el tamaño
    c->size++;
    printf(" ENQUEUE: Insertado %d. (Size: %d)\n", valor, c->size);
}

// Extraer elementos (Dequeue)
int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf(" Cola vacía (UNDERFLOW) \n");
        return -1;
    }

    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}

// Ver el elemento del frente sin sacarlo (Peek)
int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf(" Cola vacía \n");
        return -1;
    }
    return c->datos[c->frente];
}

// Estado actual de la cola
void printQueue(ColaCircular c) {
    printf(" [Estado] F(%d) | R(%d) | Size(%d) -> [ ", c.frente, c.final, c.size);
    
    if (isEmpty(&c)) {
        printf("Vacía ]\n");
        return;
    }
    
    int i = c.frente;
    int count = 0;
    while (count < c.size) {
        printf("%d ", c.datos[i]);
        i = (i + 1) % MAX;
        count++;
    }
    printf("]\n");
}

int main() {
    ColaCircular miCola;

    // Paso A1. Inicialización
    printf(" Pruebas de cola circular \n");
    inicializarColaCircular(&miCola);
    printQueue(miCola);

    // Paso A3. Pruebas 1: Encolar 5, 10, 15
    printf("\n Prueba A3.1: Primeras inserciones \n");
    enqueue(&miCola, 5);
    enqueue(&miCola, 10);
    enqueue(&miCola, 15);
    printQueue(miCola); 

    // Paso A3.2: Desencolar uno
    printf("\n Prueba A3.2: Extracción (Reciclar un espacio) ---\n");
    int out1 = dequeue(&miCola);
    printf("DEQUEUE: Salió %d. (Frente avanza de 0 a %d)\n", out1, miCola.frente);
    printQueue(miCola); 

    printf("\n Prueba A3.3: Reciclaje de espacios y desbordamiento \n");
    
    enqueue(&miCola, 20); 
    enqueue(&miCola, 25); 
    
    printQueue(miCola); 

    enqueue(&miCola, 30); 
    printQueue(miCola);
    
    // Verificación de Peek
    printf("\nPEEK: El siguiente a salir es %d (Posición %d).\n", peek(&miCola), miCola.frente);
    
    printf("\n Prueba Final: Vaciar la cola \n");
    while(!isEmpty(&miCola)) {
        printf("DEQUEUE final: Salió %d.\n", dequeue(&miCola));
    }
    printQueue(miCola);

    return 0;
}
