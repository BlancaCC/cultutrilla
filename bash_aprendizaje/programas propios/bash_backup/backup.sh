#!/bin/bash

##############################################################################################################
# REALIZA COPIAS DE SEGURIDAD de la carpeta pasada por argumento
# Autora : Blanca Cano Camarero
# Última modificación 24 / 12 / 17 versión 1.0
###############################################################################################################


################## archivos de información  ##################################
DIR=.dir
AYUDA=.ayuda
INFO=.info
LAST=.last

################################## variables #######################################################
SOS="Comandos: \n
sin argumentos    ) muestra esta ayuda \n
--help            ) muestra la espeficificación del programa \n
--h               ) muestra esta ayuda corta \n
--info     o --i  ) muestra los últimos cambios \n
--historia o --ti ) muesta el historial de cambios \n
--install         ) crea ficheros de inicio, ejecutarlo siempre la primera vez \n
--unisntall       ) borra los fichero de inicio  \n
--all      o --a  ) actualiza todos los ficheros, que ya se han grabado al menos una ve \n
FICHERO DIRECTORIOS) actualiza estos ficheros o directorios \n "


############################### CÓDIGO #########################################################
# Actualizo carpetas
if [ $# == 0 ]
then
    echo -e $SOS

elif  [ $# == 1 ]
then
    # Muestro ayuda
    if [[  $1 == "--help" ]]
    then
	cat $AYUDA

    elif [[ $1 == "--h"  ]]
    then
	echo -e $SOS

    #INFORMACIÓN
    elif [[ $1 == "--info" || $1 == "--i" ]]
    then
	printf "Última actualización: "
	cat $LAST
    elif [[ $1 == "--historia" || $1 == "--ti" ]]
    then
	cat $INFO

    # ACTUALIZO TODAS LAS CARPETAS 
    elif [[ $1 == "--all" || $1 == "--a" ]]
    then
	for i in `cat $DIR`;
	do
	    cp -rb ~/$i .
	done
	echo -e `date +%D `" a las "`date +%r`"\nArchivos:\n"`cat $DIR`>$LAST # Actualizo fecha de modificación
	cat $LAST >> $INFO
    
	echo "Todas las carpetas actualizadas con éxito";
    # creación carpetas utiles
    elif [ $1 == "--install" ]
    then
	if  test -f $DIR ;
	then
	    echo "Sistema ya instalado"
	else
	    touch $DIR
	    echo "Fecha de creación "`date +%D `" a las "`date +%r`>$LAST # Actualizo fecha de modificación
       
	    cat $LAST > $INFO

	fi
	
    # borro sistema de gestión 
    elif [ $1 == "--unisntall" ]
    then
	
	 
	 test -f $DIR && rm $DIR || echo "No se puede desistalar lo que no está instalado"
	 rm $LAST $INFO
    else
	#AMPLIATT CON CASO DE UNO SOLO 
    fi
else
    for i in $@;
    do
	
    	if test -e ~/$i;
	then
	    cp -b -r  ~/$i .
	    grep -wq $i $DIR || echo $i >> $DIR   # Si es la primera vez que se declara se actualiza
	    printf  "%s actualizado con éxito \n" $i
	else
	    printf "No se encuentra el fichero o directorio, path utilizado ~/%s \n" $i   
	fi
    done
    
   echo "Fecha de creación "`date +%D `" a las "`date +%r`>$LAST # Actualizo fecha de modificación
    cat $LAST >> $INFO

fi

	
    
