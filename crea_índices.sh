#!/bin/bash

############################## README ##############################
# Este script añade un ínicide al archivo.md que le introduzcas
# Por el momento solo funciona bien con los títulos de dos #
# Author: Blanca Cana
# Fecha úlima modificación: 3/11/17

# Para futuras mejoras:
#  1. Reconozca diferentes categorías de títulos y subtítulos
#  2. si existe ya un índice, no lo duplique
#################################################################

LINK=`cat $1 | grep -e ^[##] | cut -d '#' -f3 | tr ' ' '-' | cut -c2- '-' | tr '[:upper:]' '[:lower:]'` #selecciona los textos que nos interesan y los pasa a minúscula
NOMBRE=`cat $1 | grep -e ^[##] |cut -d '#' -f3 | tr '[:upper:]' '[:lower:]'`

echo "## Índice de $1">indice.md
cnti=0 ; cntj=0
for i in $LINK
do
    let cnti=cnti+1
    for j in $NOMBRE
    do
	let cntj=cntj+1
	if [[  $cnti == $cntj ]]
	then
	    
	    echo "($i)[#$i]" >> indice.md
	fi
	
    done
    cntj=0
done
echo "" >> indice.md
cat $1 >> inidce.md

