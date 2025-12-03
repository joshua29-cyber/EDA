# Memoria inicial
memoria = {1: 0, 2: 1, 3: 1} # Se inicializa con los primeros tres términos F(1), F(2), F(3)

def fibonacci_top_down(numero):
    # Si el número ya se encuentra calculado, se regresa el valor y ya no se hacen más cálculos
    if numero in memoria:
        return memoria[numero]
    
    # Llamada recursiva estándar para calcular el valor
    f = fibonacci_top_down(numero - 1) + fibonacci_top_down(numero - 2)
    
    # Guardar el resultado en la memoria
    memoria[numero] = f
    
    return memoria[numero]
    
    termino = 12
    resultado = fibonacci_top_down(termino)
    
    print(f"El término F({termino}) de Fibonacci es: {resultado}")
    print(f"Memoria final: {memoria}")
