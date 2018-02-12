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
cd $1 #me muevo a esa carpeta para crear los archivo allí

for (( i=0 ; i<$2 ; i++ ))
do
    touch  $3$i" :) "
done;


    
