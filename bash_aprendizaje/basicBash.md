 > Aquí encontrarás lo suficiente para que con un man seas la reina del mambo

## Instrucciones que utilizo en mi día a día
` find . -type f -name '*~' -delete `
Precioso comando que elimina las copias de seguridad de manera recursiva de la carperta en que estés.

## Comandillos útiles para utilizar en terminal  
- ` C-l` Desplazar la línea, por defecto hace que te aparezca al principio, depués medio y final.  
- `clear` Limpiar terminal.
- Para cerrar al termial `C-alt-w`
- Cerrar una ventana que no sea la terminal `C-quit` y que no se haya abierto por medio de esa.
-`./ <programa> & ` lo ejecuta en "backgraund", dejando disponible la terminal.
- `xdg-open <archivo>` abre ese archivo con el programa predeterminado.
- `source <nombre_guión> ` ejecuta órdenes de un fichero en el shell actual, de esta manera se guardarían las variables dentro del shell.  

 
## Comados relacionados con archivos y direcctorios

 COMANDOS                        | FUNCIONES
 ---		 		 | ---
 tr[option].., SET1 		 | Traduce o borra caracteres :)
 awk	   		 	 | Escanea patrones y procesa lenguajes
 ls	 	    		 | Lee los directorios
 cd 	     			 | Cambia de directorio
 ln			 	 | Crea enlaces simbólicos
 pwd      		 	 | Imprime el camino absulo del direcctorio actual   
 mkdir 	rmdir	  	 	 | rmdir -r borra si tienes también archivos dentro  
 cat     			 | Lee el condtenido de un archivo  
 mv  /<archivo1> <archivo2>	 | Mueve un archivo    
 file 	   		 	 | Muestra el tipo de archivo.  
 more pager  pg  	 	 | Visualiza un archivo fraccionándolo en la pantalla cada vez.  
 rm   	     		         | Borra DEFINITIVAMENTE un archivo/directorio
 touch				 | Modifica fecha y hora de un archivo, si no existe lo crea  
 clear	 			 | Borra el contenido de la terminal actual
 tail -<entero> <archivo> 	 | Muestra las líneas finales de un fichero  
 head -/<entero>/ <archivo>  	 | muestras las x numero de líneas iniciales de un fichero.  
  sort <archivo>   		 | Ordena bajo un critero elegido las líneas de un archivo.  
 wc    				 | Cuenta el número de algo de un fichero, el algo depende de los argumentos. 
 chmod [ugoa][+-=][rwx]dir/file  | Cambio a los permisos de un archivo o direcctorio	 
  echo				 | Escribe un mensaje en terminal  
 `alias <nombre>='<ódener>' `	 | Definir comportamiento de una orden. Si se ejecuta sin argumentos ves los alias creados
 `unalias 		    	 | Borrar un alias
 `\alias`			 | Para ignorar un alias y ejecutar la orden original
 printf  			 | Muestra en el bash lo que se especifique 
 sleep <segundos>		 | Produce una pausa de los segundos introducidos como argumentos
  date  			 | Para saber la fecha en que estamos 
 --- 	  			 | ---
 lpr 				 | Manda ficheros a imprimir a la impresora configurada por defecto 

- Código de formato para print 
``` 
  - %d número con signo.  
  - %f  número en coma flotante.  
  - %q entrecomilla una cadena.  
  - %s muestra una cadena sin entrecomillar.  
  - %x núemero en hexadecimal.  
  - %o número en octal.
```
- Ejemplo: 
```bash
blanca@debian:$printf "Quedan %i semanas para fin año \n" $( expr $DIFERENCIA / 7)
Quedan 10 semanas para fin año 
```
### Alias permanentes 
Los alias declarados  por terminal son temporales,  se borrarán al cerrarla. Para hacerlos permanentes bastará con abrir ( en caso de no existir crear) el documento `.bashrc` que se encuentra en el direcctorio \home de su usuario y allí escribir el alias.
Al guardar y salir del documento hacer un `. .bashrc` en la terminal  

 
 Comando			    | Utilidad					  | Ejemplo  
 --- 	 			    | --- 	    				  | ---
 `find <directorios> [expresiones]` | Busca según unos criterios y realiza acción | `find / -name "*.c" ` o `find . -atime +100 -ok rm {} \; ` 
 `grep [opciones][patrón]<fichero>` | Busca dentro de ficheros 	   	   	  | ---

## Metacarácteres

 Metacarácter | Función								          | Ejemplo  
 --- 	     	| ---										  | ---
 ?		| Carácter simple en la posición que se indique				  | `tema?.pdf`
 \*	| Cualquier secuencia de 0 o más carácteres  					  | `tema* `
 []		| Designan un carácter o rango de caracteres que representan un carácter simple	  | `tema[1-3].pdf`
 {}		| Sustituyen conjuntos de palabras separadas por comas con  partes comunes	  | npi
 ~		| Abrevia el campo absoluto del directorio home	       	    	   		  | `~\Documento`  
 \< nombre	| redireciciona la entrada de una orden obtenida del ARCHIVO nombre		  | `cat < text.txt`
 \> nombre	| Redirige la salida de una orden para que la escriba en el nuevo archivo nombre  | `echo "aaa" > text.txt `
 &> nombre 	| La salida estándar se combina con la salida de error estándar estritas en nombre| idem
 \>\> nombre	| Igual que *>* añadiendo al final del archivo si existe		    	  | idem
 &\>\> nombre	| Igual que  “&>”, pero añadiendo las dos salidas combinadas al final del archivo | idem
 2> nombre	| Igual que &>	   		      	  	  	     	      	  	  | idem
 `| ` 	| Para crear cauces SÚPER ÚTIL							  | `cat text | grep -e ^[A-B]`
 `|& `	| Cauce con errores 	  							  | similar  
 ;   		| Separador entre órdenes que se ejecutan					  | ` cat archivo ; echo "aaa"`
 ()		| Aislar órdenes, siendo trada como una única					  | --
 &&		| La orden siguiente se ejecuta si la anterior ha tenido éxito			  | aa
 \|\| 		| La orden siguiente se ejecuta sólo si la anterior no ha funcionado	  | `ls -l notas || pwd`  

## Variables  
### Variables de paths
Nombre			| Utilidad
---			| ---  
$BASH       		|  Contiene la ruta de acceso del terminal
$HOME			| Almacena el directorio raíz de la carpeta home
$PATH			| Guarda el camino local de las órdenes
$? 			| Contiene el código de retorno hacia la última orden o guión

### vecotres o estring  
Comando | utilidad | ejemplo 
--- |--- |---
` VECTOR=( ALGO ALGO ... )` | Para declar los paréntesis con elementos separados por espacios |` num=(uno dos tres)`
`$ {VECTOR[*]} ` ` ${VECTOR[@]} `    | Hacer referencia a todo el contenido                   | `echo ${num[*]}; uno dos tres` 
`$ {#VECTOR[*]} ` ` ${#VECTOR[@]} `  | Devuelve la longitud del vector 			      | `echo ${#num[@]} ; 3 `

*Si eres un profano en depuración lee el [apartado de depuración](#depuracion-de-programas)*  

 Variables de  depuración  |  Utilidad  
  --- 			    | ---
  $LINENO   		    | Representa el número de línea que está leyendo de un archivo
  PS4			    | Variable empotrada que ajusta el valor de *xtrace* de la línea<br>`export PS4='+ línea $LINENO: ' `
  $FUNCNAME 		    | Array que contiene el nombre de todas las funciones que se ejecutan en el instante  
  $BASH_ARGV 		    |  Array que contiene todos los parámetros de la ejecucióna ctual en bash, llamado stack.
Info bash y hartate información
  


  Operaciones con varibles	| Utilidad 
  ---		    		| ---
  `declare -[i,s,a] <nombre>`	| Declara variables 
  `declare -p <nombre>	| Ver el contenido de una variable  
  `export <variable>`		| Para que el sistema la reconozca 
  \` orden \`			| Sustitución de orden como si fuera un avariable  
  `$(orden) `			| Sustitución de orden como si fuera una variable  
  `expre <operación>`		| Permite operaciones con variables ```numero=`expr $numero + 1` ```
  ` $(( expresión )) `	| Evalúa expresiones aritméticas y sustituye su valor, LOS ESPACIOS CUÍDAMELOS  
  ` $[ expresión ] ` 		| Evalúa expresiones aritméticas y sustituye su valor
  `operaciones | bc -l `	| Permite operaciones con decimales <3  
  `let varInt=asignación`	| Asigna valor a una variable entera SIN ESPACIO EN BLANCO `let a='a +   4'`  o `let a=a+4`
     
## Guiones 
1. Comenzar con `#!/bin/bash` 
2. Cambiarle los permisos a ejecución ` chmod +x <script>`  
3. Ejecutar indicando directorio en el que se encuentra `./<script.sh>` si se encuentrn en el direcctorio actual 

 Argumento  	   | Descripción 
 --- 	   	   | ---
 `$0 `	  	   | Nombre del scrips que se llama 
 `$1..$9 ${10}..`  | Referencia a distintos argumentos  
 `$@ $* ` 	   | Todos los argumentos que se le han pasado  
 `$#`		   | Número de argumentos que se le han pasado 
 `${arg:-val}`	   | Si el argumento es nulo se le asigna val  
 `${arg:?val }`	   | Si el argumento es no nulo le asigna ese valor  
 `${!#}`     	   | Muestra el último argumento

## Operadores de consulta de archivos  
### test 
  Operador    	      | Función							 | Ejemplo  
  --- 	   	      | ---     						 | ---
  `test <expresión>`  | Comprobación de características de archivos y directorio | `test -x cat && echo “true” || echo “false”`  
  
#### Empresiones útiles  

  orden 	 | funcion  
  --- 		 | --- 
  -d 		 | si existe y es un directorio 
  -e 		 | si existe 
  -f 		 | si existe y es un fichero de texto plano  

> Para más información man test

### Orden if else 
- con un 0 entra, con un 1 no.		 
```bash 
if <condición>
then
	<órdenes>
elif <condicióin>
then 
     <orden>
else
	<orden>
fi
```

### Orden for  
Repite una secuencia, por ejemplo imaginemos que queremos contar del 1 hasta el 10
 `for n in \`seq 1 1 10\` `  es equivalente también `for n in {1..10}` 
Puedes trabajar también con otras órdenes `for i in $(ls)`

O podemos hacer un bucle for al estilo c  
``` bash 
for (( i=0 ; i<$2 ; i++ ))
do
    touch ficherito_del_amor_$i" :) "
done;
```
### Bucle infino con while
```
while:
do 
	echo "Que bonita es la vida"
done
	
```
 
### Depuración de programas  
 - Para activarlo, + para desactivarlo, 

 Comando                  | Función 
 --- 	     		  | --- 
 `bash -n`  `set -n` 	  | Chequea errores sintácticos sin ejecutar una orden  
 `bash -v`  `set -v`	  | Visualiza cada orden antes de ejecutarla
 `bash -x`  `set -x`	  | Igual que -v pero con todas las sustituciones y expansiones realizadas

#### Orden trap 
Traza, especifica una acción a realizar cada vez que recibe una señal (mecanismos de comunicación entre distintos procesos en linux <3) 
colocar después del #!/bin/bash   
`trap <lo que quieras que haga tras cada ejecución de una línea> DEBUG`  
DEBUG  es un tipo de señal, como también lo son EXIT , ERR ,  RETURN  
- EXIT cuando el código que se esté ejecutando finalice   
- ERR cuando una orden devuelve un código de finalización distinto de 0     

#### Función de aserción  
Función que comprueba una variable o función en puntos críticos del guión.	

### Control de trabajo en bash  

- Función ejecutada en primer plano **foreground**  
- Función en segundo plano **background** declarada con `&` al final de su declaración  

Órdenes para hacer referencia a un trabajo y así poder manipularlo: 

Especificador  	     | Trabajo que es denotado con dicho especificador
 --- 		     | ---
%		     | Trabajo actual (%+ y %% son sinónimos de este especificador)
%- 		     | Trabajo previo al actual
%n 		     | Trabajo número n
%<cadena> 	     | Trabajo cuya línea de órdenes comienza por <cadena>
%?<cadena> 	     | Trabajo cuya línea de órdenes contiene <cadena>

 órdenes más frecuentes de control de trabajos:   
 
Órdenes | Descripción
 --- 	| ---
jobs 	| Lista los trabajos activos bajo el control del usuario (help jobs)
fg 	| Trae a primer plano un trabajo que se encuentra suspendido o en segundo plano (help fg)
bg 	| Envía a segundo plano un trabajo (help bg)
%	| Permite cambiar el estado de un trabajo (help %)
wait 	| Espera la finalización de procesos en segundo plano (help wait)
disown	| Suprime un trabajo de la lista de trabajos activos (help disown) `disown -r ` elimina los trabajos en ejecución `disown -a` todos los trabajos	
kill 	| Envía una señal a un/os proceso/s. Por defecto, finaliza la ejecución de un proceso (man kill)
ps 	| Muestra el estado de los procesos actuales en el sistema (man ps)
top	| Muestra los procesos en ejecución con actualización de su información en tiempo real (man top)  


## Compilación de programas  
### Compilación con g++  
#### Procesos de la compilación
1. **Procesador:** Acepta como entrada un archivo con código fuente, elimina los comentarios e interpreta las **directivas de procesamiento**  
2. **Compilador** Analiza el código fuente y lo traduce a un código objeto, **módulo objeto** con la extensión `.o`, en este porceso no se resuelven las referencias externa a variable o funciones.  
`g++ -c archivo.cpp` genera si no hay errores de programación el módulo objeto.  
3. **Enlazador** Resuelve las referencias externas y genera un archivo ejecutable.  

Órdenes de compilación en g++  

 órden				 | Función  
 ---		       	       	 | --- 
 `g++ -o archivo.cpp`  	       	 | Realiza etapa de procesado y compilación generando módulo objeto si no hay error 
 `g++ archivo.o ach.o` 	       	 | Crea el ejutable, a.out 
 `g++ -o nom_ejecuta archivo.o`  | Igual que el anterior pero en vez de nombrar al archivo con a.out, lo nombra nom_ejecuta.out 
 `ar -rvs biblio.a modulo.o mod.o`| Genera una librería <br>genera un archivo .a <br>> r inserta los miembros del archivo, s crea índice, v amplia información en verbose 
`g++ -I ACHIVO.CPP` 	    	 | Permite especificar archivos en los que la orden g++ busca en la cabecera, por defecto busca en *usr/include*<br> esta orden no tiene sentdo si todos los archivos se encuentra en el directorio donde se ejecutan las órdenes
`$ g++ -L ./ -o programa2 main2.o factorial.o hello.o -lmates` | Crea ejecutable especificando las librerias con la raiz mates, esta se debe encontra en el direcorio  
`g++ -I./directorio -L./ -o programa2 main2.cpp factorial.cpp hello.cpp -lmates` | Igual que la anterior pero especificando el directorio  


## Uso de archivos del tipo makefile  

Makefile permite gestionar las depedencias, comprobando que archivos se han modificado desde la última vez que se ejecutó y vuelve a construir el ejecutable cambiando solo lás modificaciones.

 Comando 	  	   | Utilidad 
 --- 		 	   | --- 
`make -f NOMBRE_MAKEFILE`  | Especificación del archivo makefile, si es *makefileGNU*, *makefile* o *Makefile* se puede ejecutar `make` sin argumentos  

### Estructura de un archivo makefile  
Reglas para la estructura de un archivo makefile
```
objetivo: dependecias	
TABULADOR orden1  
TABULADOR orden2
...

```
 Lexema			| Orden  
 --- 			| ---
Objetivo 		| Nombre característico para la acción que ejecutará. Por ejemplo el nombre de un archivo  
Dependencias 		| Archivos u objetos (separadas en líneas en blanco) posteriores de los que depende nuesro programa<br>cuando se ejecuta la orden make se comprueba si estas dependencias han sido modificadas y en tal caso se ejecuta su lista de órdenes asociadas.  
Órdenes 		| Conjunto de líneas de orden de shell que comienzan por tabulador, construyen objetos o realizan otras tareas  

Ejemplo de makefile  
```
programa1: main.o factorial.o hello.o
	   g++ -o programa1 main.o factorial.o hello.o
main.o: main.cpp ./includes/functions.h
	g++ -I./includes -c main.cpp
factorial.o: factorial.cpp ./includes/functions.h
	     g++ -I./includes -c factorial.cpp
hello.o: hello.cpp ./includes/functions.h
	 g++ -I./includes -c hello.cpp
```  
#### Reglas virtuales  
Órdenes dentro de un archivo makefile que no genera ningún objeto pero que genera alguna acción dentro del proyecto de software. 
Para utilizar esta orden es necesario especificarla cuando se llama a la orden makefile.
Ejemplo:
```bash 
...
...
clear:          # nombre de mi regla virtual
       rm *.o   # orden del shell que realiza
```
Para llamarla desde el shell `make -f makefile clean`  

Si existiera en el directorio un objeto que se llamara igual que la orden virtual, make consideraría que el objeto ya está creado y no ejecutaría la orden, para solucionarlo: 
Ejecutar la orde especial `.POTHY: clean` todas las dependencias que contengan esta orden obviarán los ficheros con el mismo nombre y así se ejecutarán los comandos correspondientes

#### Variable predefinidas en el uso de make 

`make -p` nos muestra las variable predefinidas, dejo las más interesantes 
> Hay que echarle un ratillo para leerlo entero y comprenderlo

Variable  | Significado 
--- 	  | --- 
$@	  | Representa el nombre del objetivo de la regla en la que nos encontramos
$<	  | Representa la primera dependencia de la regla en la que nos encontramos
$?	  | Representa las dependencias de la presente regla que hayan sido actualizadas (modificadas) dentro del objetivo de la regla y separadas por un espacio en blanco
$^	  | Representa todas las dependencias separadas por un espacio en blanco  

Ejemplo clarificador:

```  
CC = g++					% Compilador	que vamos a utilizar
CPPFLAGS = -Wall				% Opciones de compilado, -Wall para ver los warning 
SRCS = main.cpp factorial.cpp hello.cpp
OBJS = main.o factorial.o hello.o
HDRS = functions.h  

programa1: $(OBJS) 
        $(CC) -o $@ $(OBJS)  % el valor de $@ se sustituirá por el de programa1  

hello.o: hello.cpp 
        $(CC) -c $(CPPFLAGS) $<  %el valos de $< hará referencia  a hello.cpp, la primera dependencia 

print: $(SRCS)  
        lpr -p $?            % represena las dependencias que hayan sido modificadas hasta la fecha


programa1: $(OBJS)  
        $(CC) -c $@ $^       % $^ representaría la secuencia  main.o factorial.o hello.o  
```  
Además se puede uno ahorrar escribir de la siguiente manera `$(Nombre:TextoActual=TextoNuevo) `   
Ejemplo:  
```
SRCS = main.cpp factorial.cpp hello.cpp  
OBJS = $(SRCS:.cpp=.o)        		 % sería equivalente a main.o factorial.o hello.o 
``` 

