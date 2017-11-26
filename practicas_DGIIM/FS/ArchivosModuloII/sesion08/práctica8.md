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
