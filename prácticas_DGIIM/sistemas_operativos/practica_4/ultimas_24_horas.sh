# Escrpt que devuelve lo archivos modificados desde hace 24 horas

#nombre del archivo con fecha de un día menos
dia=`date +%d`
dia=$((dia--))

archivo=modificados_`date +%Y-%d-%T`
find ~/ -mtime 0 > $archivo} 2>> /dev/null
			     # hemos redireccionado la salid ade error a la nula
			     #no queremeo stener constancia de los archivo que no se pueden leer por falta de permisos
