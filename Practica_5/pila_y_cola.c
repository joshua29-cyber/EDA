#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

// Estructura para la PILA
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

// Estructura para la COLA
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

// Funciones para PILA
void inicializarPila(Pila *p) {
    p->tope = -1; 
    printf(" Pila inicializada vacía (tope = -1) \n");
}

void push(Pila *p, int valor) {
    if (p->tope < MAX - 1) {
        p->tope++;
        p->datos[p->tope] = valor;
        printf(" Elemento %d insertado (PUSH) \n", valor);
    } else {
        printf(" La pila está llena (Desbordamiento/Overflow) \n");
    }
}

int pop(Pila *p) {
    if (p->tope >= 0) {
        int valor = p->datos[p->tope];
        p->tope--;
        return valor;
    } else {
        printf(" La pila está vacía (Subdesbordamiento/Underflow) \n");
        return -1;
    }
}

void mostrarPila(Pila p) {
    printf(" [Estado Pila]: ");
    if (p.tope == -1) {
        printf("Vacía\n");
    } else {
        for (int i = 0; i <= p.tope; i++) {
            printf("%d ", p.datos[i]);
        }
        printf("(Tope es %d)\n", p.datos[p.tope]);
    }
}

// Funciones para COLA
void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf(" Cola inicializada vacía (frente = 0, final = -1) \n");
}

void enqueue(Cola *c, int valor) {
    if (c->final < MAX - 1) {
        c->final++;
        c->datos[c->final] = valor;
        printf(" Elemento %d insertado (ENQUEUE) \n", valor);
    } else {
        printf(" La cola está llena \n");
    }
}

int dequeue(Cola *c) {
    if (c->frente <= c->final) {
        int valor = c->datos[c->frente];
        c->frente++;
        return valor;
    } else {
        printf(" La cola está vacía \n");
        return -1;
    }
}

void mostrarCola(Cola c) {
    printf("   [Estado Cola]: ");
    if (c.frente > c.final) {
        printf("Vacía\n");
    } else {
        for (int i = c.frente; i <= c.final; i++) {
            printf("%d ", c.datos[i]);
        }
        printf("(Frente: %d, Final: %d)\n", c.datos[c.frente], c.datos[c.final]);
    }
}


int main() {
    int i, n, valor;
    
    printf(" PASO 1: CREAR UNA PILA \n");
    Pila miPila;
    inicializarPila(&miPila);

    printf("\n PASO 2: INSERTAR ELEMENTOS (PUSH) \n");
    printf("¿Cuántos elementos quieres apilar? (Max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX; 

    for (i = 0; i < n; i++) {
        printf("Ingresa valor %d: ", i + 1);
        scanf("%d", &valor);
        push(&miPila, valor);
        mostrarPila(miPila);
    }

    printf("\n PASO 3: EXTRAER ELEMENTOS (POP) \n");
    printf("¿Cuántos elementos quieres desapilar? ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        valor = pop(&miPila);
        if (valor != -1) {
            printf(" Salió: %d\n", valor);
            mostrarPila(miPila);
        }
    }

    printf("\n PASO 4: CREAR UNA COLA \n");
    Cola miCola;
    inicializarCola(&miCola);

    printf("\n PASO 5: INSERTAR ELEMENTOS EN LA COLA (ENQUEUE) \n");
    printf("¿Cuántos elementos quieres encolar? (Max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    for (i = 0; i < n; i++) {
        printf("Ingresa valor %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&miCola, valor);
        mostrarCola(miCola);
    }

    printf("\n PASO 6: EXTRAER ELEMENTOS DE LA COLA (DEQUEUE) \n");
    printf("¿Cuántos elementos quieres desencolar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        valor = dequeue(&miCola);
        if (valor != -1) {
            printf(" Salió: %d\n", valor);
            mostrarCola(miCola);
        }
    }

    printf("\n PASO 7: COMPARACIÓN \n");
    printf("Resumen del orden de salida:\n");
    printf("1. PILA (Stack) -> LIFO (Last In, First Out)\n");
    printf("   El ÚLTIMO elemento en entrar fue el PRIMERO en salir.\n");
    
    printf("2. COLA (Queue) -> FIFO (First In, First Out)\n");
    printf("   El PRIMER elemento en entrar fue el PRIMERO en salir.\n");

    return 0;
}