from string import ascii_letters, digits
from itertools import product
from time import time

caracteres = ascii_letters + digits

# Contraseña a buscar
con = "Q6h7" 

t0 = time()

def buscador(con):
    # Definimos las longitudes específicas a probar
    longitudes_a_probar = [4, 8, 10] 

    for i in longitudes_a_probar: # Itera sobre 4, luego 8, luego 10
        print(f"\n Probando contraseñas de longitud {i} ")
        
        # Generar todas las combinaciones de 'caracteres', repetidas 'i' veces
        for comb in product(caracteres, repeat=i):
            
            # Unir los caracteres generados para formar la contraseña
            prueba = "".join(comb)
            
            if prueba == con:
                print(f" Tu contraseña es: {prueba}")
                return True 

    print("\nNo se encontró la contraseña ")
    return False

buscador(con)
# Calcular y mostrar el tiempo total de ejecución
t_final = time()
print(f"\n Tiempo de ejecución: {round(t_final - t0, 6)} segundos")
