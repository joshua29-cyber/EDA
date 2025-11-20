#include <stdio.h>
#include <stdlib.h> 

int main() {
    int *arr = NULL;   // Puntero malloc
    int *arr2 = NULL;  // Puntero calloc y realloc
    int n, m, i;

    // Paso 1. Reservar memoria con malloc
    printf(" Paso 1: Reservar memoria con malloc \n");
    printf("¿Cuántos enteros quieres almacenar? ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    // 1.2 Verificar si la memoria se asignó correctamente
    if (arr == NULL) {
        printf("Error: No se pudo reservar memoria con malloc.\n");
        return 1; 
    }

    // 1.3 Mostrar los valores iniciales (basura)
    printf("Valores iniciales en el bloque 'arr' (malloc):\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); 
    }

    // Paso 2. Reservar memoria con calloc
    printf("\n Paso 2: Reservar memoria con calloc \n");
    printf("Reservando espacio para %d enteros con calloc \n", n);
    arr2 = (int *)calloc(n, sizeof(int));

    // 2.2 Verificar si la memoria se asignó
    if (arr2 == NULL) {
        printf("No se pudo reservar memoria con calloc\n");
        free(arr); 
        return 1; 
    }

    // 2.3 Mostrar los valores iniciales (ceros)
    printf("Valores iniciales en el bloque 'arr2' (calloc):\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 3. Llenar el arreglo
    printf("\n Paso 3: Llenar el arreglo 'arr2' \n");
    for (i = 0; i < n; i++) {
        printf("Introduce el valor para arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }

    // Paso 4. Redimensionar con realloc
    printf("\n Paso 4: Redimensionar 'arr2' con realloc \n");
    printf("Introduce el nuevo tamaño (m) para 'arr2': ");
    scanf("%d", &m);
    int *temp_arr2 = (int *)realloc(arr2, m * sizeof(int));

    // 4.2 Verificar si realloc tuvo éxito
    if (temp_arr2 == NULL) {
        printf("No se pudo redimensionar la memoria con realloc\n");
        free(arr);
        free(arr2);
        return 1;
    }

    // 4.3 Si tuvo éxito, actualizamos nuestro puntero principal
    arr2 = temp_arr2;

    // 4.4 En caso de que el arreglo sea de mayor tamaño (m > n)
    if (m > n) {
        printf("El arreglo creció, introduce los %d valores que faltan:\n", m - n);
        for (i = n; i < m; i++) {
            printf("Introduce el valor para arr2[%d]: ", i);
            scanf("%d", &arr2[i]);
        }
    }    // Si m < n, los datos extra se pierden

    // 4.5 Imprimir todos los valores del arreglo redimensionado
    printf("\nValores finales en 'arr2' (tamaño %d):\n", m);
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 5. Liberar memoria
    printf("\n Paso 5: Liberar memoria \n");
    
    free(arr);
    free(arr2);

    arr = NULL;
    arr2 = NULL; 

    printf("\nMemoria liberada correctamente.\n");
    return 0; 
}
