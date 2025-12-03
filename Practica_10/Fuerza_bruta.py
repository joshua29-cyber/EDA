from string import ascii_letters, digits
from itertools import product
from time import time

# Concatenar letras y dígitos en una sola cadena
caracteres = ascii_letters + digits

# La contraseña a buscar (ejemplo)
con = "l0n2" 
t0 = time()

def buscador(con):
    # Abrimos el archivo para escribir las combinaciones generadas
    # range(1, 11) -> prueba longitudes i=1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    # Para longitudes 8 y 10, el tiempo de ejecución es muy largo
    # El conjunto de caracteres es: 52 letras + 10 dígitos = 62 caracteres.
    longitudes_a_probar = [4, 8, 10] 

    for i in longitudes_a_probar: 
        print(f"\n Probando contraseñas de longitud {i} ")
        
        # Generar todas las combinaciones de 'caracteres', repetidas 'i' veces
        for comb in product(caracteres, repeat=i):
            prueba = "".join(comb)
            
            # archivo.write(prueba + "\n") 
            if prueba == con:
                print(f" Tu contraseña es : {prueba}")
                # Cerramos el archivo y detenemos la búsqueda
                # archivo.close() 
                return True # Se encontró

buscador(con)
# Calcular y mostrar el tiempo total de ejecución
t_final = time()
print(f"\n Tiempo de ejecución: {round(t_final - t0, 6)} segundos")
