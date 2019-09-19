# Práctica final

Creación de un scrabble contra el que jugar

## Desarrollo del proyecto

El programa se ha diseñado con los siguientes módulos:
- diccionario
- letras  
- ia 

Procedemos a comentarlos.

### Diccionario

Puede encontrar el código fuente en:
- include/diccionario.h
- src/diccioanario.cpp

Así como un test en src/testdiccionario.cpp

Este módulo es utilizado como estructura para guardar las combinaciones válidas de nuestro juego.
Para ver en profundizad sus miembros ver la docuemntación gnerada con doxigen.  


### Letras  
Emancipándonos un tanto de la estructura propuesta en el guión final, he decido agrupar cantidad de letras y bolsa de letras en un mismo módulo con el objetivo de aprovechar la frecuencia para con un algoritmo generar de esta dorma las puntaciones. Por lo demás he respetado la funcionalidades que se le pide a cada uno e incluso completado. 


### ia  
El módulo ia, es el de inteligencia artificial, 
- Cada letra válida tiene asociado un primo. 
- Se analiza el diccionario de la IA, construyendo de esta manera la tabla hash  
- Al pasarle las letras 

su diseño se compone de una tabla hash, donde cada letra de las válidas tiene un primo asociado, se empiezan ahora se prueban las combinaciones sin repetición de todos los  elementos 
