## Práctica 7. Depuración y control de trabajos
Blanca Cano Camarero
Fecha de entrega 16/11/17

### Ejercicio 7.1. Indique cuál ha sido el error introducido en el guión anterior y cómo se corregiría.
Guión anterior:
``` bash
#!/bin/bash
# Uso: pathmas directorio [after]
if ! echo $PATH | /bin/egrep -q "(^|:)$1($|:)" ; then
if ["$2" = "after" ] ; then
PATH=$PATH:$1
else
PATH=$1:$PATH
fi
else
echo "$1 ya está en el path"
fi
```
El error se encuntra en la línea 4, el fallo es que debería estar escrito así ` if [ "$2" = "after" ] ; then ` nótese que he  dejado un espacio entre `[ ` y ` "$2" ` .


### Ejercicio 7.2. Aplicar las herramientas de depuración vistas en la sección 2 para la detección de errores durante el
desarrollo de los guiones propuestos como ejercicios en la práctica 6.

El guión sobre el que voy a trabajar es el 6.9, a continuación parte de su código:
```bash
if ! test -d $1
then
    echo "El fichero $1 no existe y se procede a crearlo"
    mkdir $1
    
fi;
cd $1 #me muevo a esa carpeta para crear los archivo allí

for (( i=0 ; i<$2 ; i++ ))
do
    touch  $3$i" :) "
done;
```
Las herramientas vistas en la sección dos son:
- bash y set, cuyas funciones son las mismas:

resultado de:
- ` bash -n newdirfiles.sh a 10 aaaaa`
`blanca@debian:~/cultutrilla/practicas_DGIIM$ ` lo cual es normal porque el guión funcionaba correctamente

-` bash -v newdirfiles.sh a 10 aaaaa`
```bash
#!/bin/bash

#Ejercicio 6.9. Hacer un script en Bash denominado newdirfiles con los siguientes tres argumentos:
#<dirname> Nombre del directorio que, en caso de no existir, se debe crear para alojar en él los archivos que se han de crear.
# <num_files> Número de archivos que se han de crear.
#<basefilename> Será una cadena de caracteres que represente el nombre base de los archivos.

#Creo directorio si no existía
if ! test -d $1
then
    echo "El fichero $1 no existe y se procede a crearlo"
    mkdir $1
    
fi;
El fichero a no existe y se procede a crearlo
cd $1 #me muevo a esa carpeta para crear los archivo allí

for (( i=0 ; i<$2 ; i++ ))
do
    touch  $3$i" :) "
done;


    
blanca@debian:~/cultutrilla/practicas_DGIIM$ ls
a  fs_7.txt  fs_7.txt~  Modulo.I.Ordenes.Unix.y.Shell.Bash.pdf  newdirfiles.sh  newdirfiles.sh~

```
Observemos que la carpeta se ha creado.

- `bash -x newdirfiles.sh a 10 aaaaa`
```
+ test -d a
+ cd a
+ (( i=0  ))
+ (( i<10  ))
+ touch 'aaaaa0 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa1 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa2 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa3 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa4 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa5 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa6 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa7 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa8 :) '
+ (( i++  ))
+ (( i<10  ))
+ touch 'aaaaa9 :) '
+ (( i++  ))
+ (( i<10  ))
 ```

## Ejercicio 7.3. Escribir un guion que nos dé el nombre del proceso del sistema que consume más memoria.
 `ps aux --sort %mem | tail -1 | cut -d ":" -f3 | cut -d " " -f2 `

## Ejercicio 7.4. Escribir un guión que escriba números desde el 1 en adelante en intervalos de un segundo ¿Cómo
se podría, desde otro terminal, detener la ejecución de dicho proceso, reanudarlo y terminar definitivamente su
ejecución?

```bash
#!/bin/bash
#duerme.sh
cnt=0

while true
do

    cnt=`expr $cnt + 1 `
    echo $cnt
    sleep 1
    
done
```
Para para, matar o renaudar un proceso, aunque se haya abierto desde otra terminal, se necesita saber su PID, para ello hacemos un `ps aux` buscamos el proceso que queremos cerrar y después ejecutamos el comando
- `kill <PID>` donde `< PID>` es el número de proceso a matar
- `kill -STOP <pid>` para deterner el proceso
- `kill -CONT pid para contuar el proceso

## Ejercicio 7.5. ¿Se puede matar un proceso que se encuentra suspendido? En su caso, ¿cómo?
Sí utilizando el comando `kill -TERM <PID>` o `kill %<número_proceso>`

## Ejercicio 7.6. ¿Qué debemos hacer a la orden top para que nos muestre sólo los procesos nuestros?
`top -u $USER`

