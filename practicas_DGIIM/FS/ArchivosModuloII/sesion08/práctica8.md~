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

