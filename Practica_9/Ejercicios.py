#CADENAS 

#Inicializando cadenas
cadena1 = ' Hola '
cadena2 = " Mundo "
print(cadena1)
print(cadena2)
concat_cadenas = cadena1 + cadena2  #Concatenación de cadenas
print(concat_cadenas)



#OPERADORES

#Para el exponente se puede utilizar asterisco
print(  1 + 5  )
print(  6 * 3  )
print(  10 - 4  )
print(  100 / 50  )
print(  10 % 2  )
print(  ((20 * 3) + (10 + 1))  / 10  )
print(  2**2  )



#LISTAS

#Declaracion de una lista simple
lista_diasDelMes=[ 31,28,31,30,31,30,31,31,30,31,30,31 ]

print (lista_diasDelMes)                #imprimir la lista completa
print (lista_diasDelMes[0])             #imprimir elemento 1
print (lista_diasDelMes [6])            #imprimir elemento 7
print (lista_diasDelMes [11])         #imprimir elemento 12



#TUPLA CON NOMBRE

#Se debe importar la librería para hacer uso de namedtuple 
from collections import namedtuple

#Se crea la tupla con nombre
#El primer argumento es el nombre de la tupla, mientras que el segundo argumento son los campos 
#p es la referencia a la tupla
planeta = namedtuple( ' planeta ', [ ' nombre ', ' numero ' ])

#Se crea el planeta 1 y se agregan a la tupla los valores correspondientes a los campos
planeta1 = planeta( ' Mercurio ', 1)
print(planeta1)

#Se crea el planeta 2
planeta2 = planeta( ' Venus ', 2)
#Se imprimen los valores de los campos
#Usando la referencia se llama a cada uno de sus campos
print ( planeta1.nombre, planeta1.numero)
#Se obtienen los valores por el orden de los campos
print (planeta2[0], planeta2[1])
print ( ' Campos de la tupla: {} ' .format(planeta1._fields))



#DICCIONARIOS

#Creando un nuevo diccionario
elementos2 = {}
elementos2[ ' H ' ] = { ' name ' : ' Hydrogen ', ' number ' : 1, ' weight ' : 1.00794}
elementos2[ ' He ' ] = { ' name ' : ' Helium ', ' number ' : 2, ' weight ': 4.002602}
print (elementos2)



#FUNCIONES

#Definiendo una función que regresa el cuadrado de un número
def cuadrado(x) :
      return x ** 2
x = 5
#La función format() sirve para convertir los parámetros que recibe, en cadenas; éstos valores
#por las llaves de la cadena. 
print( "El cuadrado de {} es {} ".format(x, cuadrado(x)))   #La función cuadrado() regresa un valor 



#ESTRUCTURAS DE CONTROL SELECTIVAS

def obtenerMayorV2(param1, param2):
    if param1 < param2:
        return param2
    else:
        return param1
print("El mayor es {}".format(obtenerMayorV2(4, 20)))
print("El mayor es {}".format(obtenerMayorV2(11, 6)))



#ESTRUCTURAS DE CONTROL REPETITIVAS

# Ejemplo 1
def cuenta(limite):
    i = limite
    while True:
        print(i)
        i = i - 1
        if i == 0:
            break # Rompiendo el ciclo

cuenta(10)




#BIBLIOTECAS

# Para utilizar una biblioteca, ésta se debe de importar
import math
x = math.cos(math.pi)
print(x)
