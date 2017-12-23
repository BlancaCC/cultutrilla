Blanca Cano Camarero
Práctica 9

### Ejercicio 9.1. Compile los archivos main.cpp factorial.cpp hello.cpp y genere un ejecutable con el nombre ejemplo1. Lance gdb con dicho ejemplo y ejecútelo dentro del depurador. Describa la información que ofrece.

blanca@debian:~/campo_batalla/ArchivosModuloII/sesion09$ gbd ejemplo1
bash: gbd: no se encontró la orden
blanca@debian:~/campo_batalla/ArchivosModuloII/sesion09$ gdb ejemplo1 
GNU gdb (Debian 7.7.1+dfsg-5) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ejemplo1...done.
(gdb)  
(gdb) 


### Ejercicio 9.2. Usando la orden list muestre el código del programa principal y el de la función factorial utilizados en el ejercicio 1 (para ello utilice la orden help list).

Programa princial:
```
(gdb) l
1	#include <iostream>
2	#include "functions.h"
3	
4	using namespace std;
5	
6	int main(){
7	    print_hello();
8	    cout << endl;
9	    cout << "The factorial of 7 is " << factorial(7) << endl;
10	    return 0;

```
Programa factorial
```
(gdb) list factorial(int) 
1	#include "functions.h"
2	
3	int factorial(int n){
4	    if(n!=1){
5		return(n * factorial(n-1));
6	    }
7	    else return 1;
8	}
```

### Ejercicio 9.3. Ponga un punto de ruptura asociado a cada línea del programa fuente mainsesion09.cpp donde aparezca el comentario /* break */. Muestre información de todas las variables que se estén usando cada vez que en la depuración se detenga la ejecución. Muestre la información del contador de programa mediante $pc y el de la pila con $sp.
```
Breakpoint 1, main () at mainsesion09a.cpp:48
48	      final2 = cuenta(i);
(gdb) p/x $pc
$1 = 0x40081f
```

Breakpoint 1, main () at mainsesion09a.cpp:48
48	      final2 = cuenta(i);
(gdb) p/x $pc
$1 = 0x40081f


### Ejercicio 9.4. Indique las órdenes necesarias para ver el valor de las variables final1 y final2 del programa generado en el ejercicio anterior en los puntos de ruptura correspondientes tras un par de iteraciones en el bucle for. Indique la orden para obtener el código ensamblador de la zona depurada.

```
Breakpoint 1 at 0x400804: file mainsesion09a.cpp, line 42.
(gdb) b 15
Breakpoint 2 at 0x4007c6: file mainsesion09a.cpp, line 15.
(gdb) b 29
Breakpoint 3 at 0x4007e5: file mainsesion09a.cpp, line 29.
(gdb) b 42
Note: breakpoint 1 also set at pc 0x400804.
Breakpoint 4 at 0x400804: file mainsesion09a.cpp, line 42.
(gdb) b 47
Breakpoint 5 at 0x40081f: file mainsesion09a.cpp, line 47.
(gdb) r

Breakpoint 1, main () at mainsesion09a.cpp:43
43	   final1 = multiplica(3, 2);
(gdb) p/x $PC
$1 = Value can't be converted to integer.
(gdb) p/x $pc
$2 = 0x400804
(gdb) p/x $pc
$3 = 0x400804
(gdb) p/x $pc
$4 = 0x400804
(gdb) info locals 
final1 = 0
final2 = 32767
i = 0
```

### Ejercicio 9.4. Indique las órdenes necesarias para ver el valor de las variables final1 y final2 del programa generado en el ejercicio anterior en los puntos de ruptura correspondientes tras un par de iteraciones en el bucle for. Indique la orden para obtener el código ensamblador de la zona depurada.


info locals  para ver las  variables
disassemble para ver el código ensamblador

### Ejercicio 9.5. Considerando la depuración de los ejercicios anteriores, elimine todos los puntos de ruptura salvo el primero.

`(gdb) delete breakpoints 2 3 4 `
