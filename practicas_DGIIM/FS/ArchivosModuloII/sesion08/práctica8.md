## Prácticas 8
## Blanca Cano Camarero
### Ejercicio 8.1. Pruebe a comentar en el archivo fuente main.cpp la directiva de procesamiento “#include ”functions.h”. La línea quedaría así: //include ”functions.h”. Pruebe a generar ahora el módulo objeto con la orden de compilación mostrada anteriormente. ¿Qué ha ocurrido?
```
blanca@debian:~/cultutrilla/practicas_DGIIM/FS/ArchivosModuloII/sesion08$ g++ -c main.cpp
main.cpp: In function ‘int main()’:
main.cpp:7:17: error: ‘print_hello’ was not declared in this scope
     print_hello();
                 ^
main.cpp:9:52: error: ‘factorial’ was not declared in this scope
     cout << "The factorial of 7 is " << factorial(7) << endl;
                                                    ^
```
Como podemos apreciar nos indica que la funcione declarada en `functions.h` no las detecta.
### Ejercicio 8.2. Explique por qué el enlazador no ha podido generar el programa archivo ejecutable programa2 del ejemplo anterior y, sin embargo, ¿por qué sí hemos podido generar el módulo main2.o?

Porque g++ -c no resuelve las referencias externas al programa.

### Ejercicio 8.3. Explique por qué la orden g++ previa ha fallado. Explique los tipos de errores que ha encontrado.

Para generar el programa ejecutable hay que especificar explícitamente la(s) biblioteca(s) que se utilizan, en nuestro caso no ha encontrado la biblioteca `funcions.h`

### Ejercicio 8.4. Copie el contenido del makefile previo a un archivo llamado makefileE ubicado en el mismo directorio en el que están los archivos de código fuente .cpp. Pruebe a modificar distintos archivos .cpp (puede hacerlo usando la orden touch sobre uno o varios de esos archivos) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden make. ¿Se genera siempre la misma secuencia de órdenes cuando los archivos han sido modificados que cuando no? ¿A qué cree puede deberse tal comportamiento?

Contenido a copiar:

```
# Nombre archivo: makefileE
# Uso: make –f makefileE
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca que utiliza el programa2.

programa2: main2.o factorial.o hello.o libmates.a
       g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
main2.o: main2.cpp
       g++ -I./includes -c main2.cpp
factorial.o: factorial.cpp
       g++ -I./includes -c factorial.cpp
hello.o: hello.cpp
       g++ -I./includes -c hello.cpp
libmates.a: sin.o cos.o tan.o
       ar -rvs libmates.a sin.o cos.o tan.o
sin.o: sin.cpp
       g++ -I./includes -c sin.cpp
cos.o: cos.cpp
       g++ -I./includes -c cos.cpp
tan.o: tan.cpp
       g++ -I./includes -c tan.cpp
```

Tras ejecutarlo por primera vez, en terminal me aparece
```
g++ -c main2.cpp
g++ -c factorial.cpp
g++ -c hello.cpp
g++ -c sin.cpp
g++ -c cos.cpp
g++ -c tan.cpp
ar -rvs libmates.a sin.o cos.o tan.o
ar: creando libmates.a
a - sin.o
a - cos.o
a - tan.o
g++ -L./ -o programa2 main2.o factorial.o hello.o libmates.a

```
La segunda vez `make: 'programa2' is up to date.`

Si escribo un comentario en cos.cpp  y vuelvo a ejecutarlo:
```
g++ -c cos.cpp
ar -rvs libmates.a sin.o cos.o tan.o
r - sin.o
r - cos.o
r - tan.o
g++ -L./ -o programa2 main2.o factorial.o hello.o libmates.a
```

Como podemos comprobar no se genera siempre las misma secuencias de órdenes, se busca los archivos que han sido modificados y esas son las dependencias que se generan.


### Ejercicio 8.5. Obtener un nuevo makefileF a partir del makefile del ejercicio anterior que incluya además las dependencias sobre los archivos de cabecera. Pruebe a modificar cualquier archivo de cabecera (usando la orden touch) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden make.

Tedría que añadir funcions.h a los programas que lo utilicen

Ejercicio 8.5. Obtener un nuevo makefileF a partir del makefile del ejercicio anterior que incluya además las dependencias sobre los archivos de cabecera. Pruebe a modificar cualquier archivo de cabecera (usando la orden touch) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden make.

```

# Nombre archivo: makefile
# Uso: make 
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

LIB_DIR=./

programa2: main2.o factorial.o hello.o libmates.a
	g++ -L$(LIB_DIR) -o $@ $^

main2.o: main2.cpp functions.h mates.h 
	g++ -c main2.cpp

factorial.o: factorial.cpp functions.h
	g++ -c factorial.cpp

hello.o: hello.cpp functions.h
	g++ -c hello.cpp

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o

sin.o: sin.cpp mates.h
	g++ -c sin.cpp

cos.o: cos.cpp mates.h
	g++ -c cos.cpp

tan.o: tan.cpp mates.h
	g++ -c tan.cpp

cleanAll: cleanObj cleanLib
	rm programa2

cleanObj:
	rm main2.o factorial.o hello.o

cleanLib:
	rm sin.o cos.o tan.o libmates.a
```

### Ejercicio 8.6. Usando como base el archivo makefileG, sustituya la línea de orden de la regla cuyo objetivo es programa2 por otra en la que se use alguna de las variables especiales y cuya ejecución sea equivalente.

```
#Nombre archivo: makefile
#Uso: make
#Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
que utiliza el programa2.
# Variable que indica el compilador que se va a utilizar
CC=g++
# Variable que indica las opciones que se van a pasar al compilador
CPPFLAGS= -Wall
# Variable que indica el directorio en donde se encuentran los archivos de
cabecera
INCLUDE_DIR= ./includes
# Variable que indica el directorio en donde se encuentran las bibliotecas
LIB_DIR= ./
programa2: main2.o factorial.o hello.o libmates.a
$(CC) -L$(LIB_DIR) -o programa2 $^
main2.o: main2.cpp
$(CC) -I$(INCLUDE_DIR) -c main2.cpp
factorial.o: factorial.cpp
$(CC) -I$(INCLUDE_DIR) -c factorial.cpp
hello.o: hello.cpp
$(CC) -I$(INCLUDE_DIR) -c hello.cpp
libmates.a: sin.o cos.o tan.o
ar -rvs libmates.a sin.o cos.o tan.o
sin.o: sin.cpp
$(CC) -I$(INCLUDE_DIR) -c sin.cpp
cos.o: cos.cpp
$(CC) -I$(INCLUDE_DIR) -c cos.cpp
tan.o: tan.cpp
$(CC) -I$(INCLUDE_DIR) -c tan.cpp

#
#
#
#
Nombre archivo: makefile
Uso: make
Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
que utiliza el programa2.
# Variable que indica el compilador que se va a utilizar
CC=g++
# Variable que indica las opciones que se van a pasar al compilador
CPPFLAGS= -Wall
# Variable que indica el directorio en donde se encuentran los archivos de
cabecera
INCLUDE_DIR= ./includes
# Variable que indica el directorio en donde se encuentran las bibliotecas
LIB_DIR= ./
programa2: main2.o factorial.o hello.o libmates.a
$(CC) -L$(LIB_DIR) -o programa2 $^
main2.o: main2.cpp
$(CC) -I$(INCLUDE_DIR) -c main2.cpp
factorial.o: factorial.cpp
$(CC) -I$(INCLUDE_DIR) -c factorial.cpp
hello.o: hello.cpp
$(CC) -I$(INCLUDE_DIR) -c hello.cpp
libmates.a: sin.o cos.o tan.o
ar -rvs libmates.a sin.o cos.o tan.o
sin.o: sin.cpp
$(CC) -I$(INCLUDE_DIR) -c sin.cpp
cos.o: cos.cpp
$(CC) -I$(INCLUDE_DIR) -c cos.cpp
tan.o: tan.cpp
$(CC) -I$(INCLUDE_DIR) -c tan.cpp
```

### Ejercicio 8.7. Utilizando como base el archivo makefileG y los archivos fuente asociados, realice los cambios que considere oportunos para que, en la construcción de la biblioteca estática libmates.a, este archivo pase a estar en un subdirectorio denominado libs y se pueda enlazar correctamente con el resto de archivos objeto.

Ya resuelto en el ejercicio anterior.

### Ejercicio 8.8. Busque la variable predefinida de make que almacena la utilidad del sistema que permite construir bibliotecas. Recuerde que la orden para construir una biblioteca estática a partir de una serie de archivos objeto es ar (puede usar la orden grep para filtrar el contenido; no vaya a leer línea a línea toda la salida). Usando el archivo makefileG, sustituya la orden ar por su variable correspondiente.

La orden predefinida es AR

Habría que cambiar solo la linea
```
libmates.a: sin.o cos.o tan.o
$(AR) -rvs libmates.a sin.o cos.o tan.o

```

### Ejercicio 8.9. Dado el siguiente archivo makefile, explique las dependencias que existen y para qué sirve cada una de las líneas del mismo. Enumere las órdenes que se van a ejecutar a consecuencia de invocar la utilidad make sobre este archivo.

```
CC=g++
CPPFLAGS=-Wall –I./includes
SOURCE_MODULES=main.cpp factorial.cpp hello.cpp
OBJECT_MODULES=$(SOURCE_MODULES:.cpp=.o)
EXECUTABLE=programa1
all: $(OBJECT_MODULES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECT_MODULES)
$(CC) $^ -o $@

# Regla para obtener los archivos objeto .o que dependerán de los archivos .cpp
# Aquí, $< y $@ tomarán valores respectivamente main.cpp y main.o y así sucesivamente
.o: .cpp
$(CC) $(CPPFLAGS) $< -o $@
```
 línea							| útil
 ---							| ---
`CC=g++ `						| compilador que usa
`CPPFLAGS=-Wall –I./includes `				| abilita los  warming
`SOURCE_MODULES=main.cpp factorial.cpp hello.cpp ` 	| Dependencias que utiliza
`OBJECT_MODULES=$(SOURCE_MODULES:.cpp=.o)` 	 	| Módulos objeto que utiliza
`EXECUTABLE=programa1 `					| Nombre del porgrama
`all: $(OBJECT_MODULES) $(EXECUTABLE)`			| Todos módulos objetos y dependencias que utilizan
`$(CC) $^ -o $@` 					|