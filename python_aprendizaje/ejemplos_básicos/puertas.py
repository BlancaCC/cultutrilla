#!/bin/python3.5

# Programa obtenido de hacker run, se le pasa lista con 0 y 1, que simbolizan puertas, 0 la puerta abierta 1 la puerta cerrada.
# Nuestro objetivo es abrir todas las puertas
# si se abre y las subyacentes se abrirán si no están abiertas
# el programa devuelve para una lista de 0 y 1 le mínimo de puertas a abrir y el máximo siguiendo este patrón

import sys

def puertas( doors ):
    min = 0
    max = 0
    i = 1
    
    while i < len( doors) -2 :

        # Casos en los que hay reducción
        
        if(doors[i]) == 1:
            if doors[ i-1 : i+2] == [1,1,1]:
                min += 1
                max += 2
                i += 2
            elif doors[ i] == 1:
                min += 1
                max += 1
                i += 1
            else:
                min += 1
                max += 1
                
            i += 1
    return [ min , max]

def prueba ( ):
    for i in range (10):
        print (i )
        i += i
        

if __name__ == "__main__":
    doors = list ( map( int, input().strip().split(' ')))
    print ("La puerta creada: " , doors)
    result = puertas (doors)
    print( " ".join( map(str , result )))
    prueba();
