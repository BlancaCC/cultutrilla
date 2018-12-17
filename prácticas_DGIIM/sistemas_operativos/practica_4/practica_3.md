# Práctica 4 automaticación de procesos


# at  
orden at para crear procesos <3

ejemplo de uso 
```
blanca@blanca-HP-Pavilion-Laptop-14-bk0xx:~$ at 11:44
warning: commands will be executed using /bin/sh
at> echo "Holaaa cariño" >saludo  	
at> <EOT>
job 1 at Sat Dec 15 11:44:00 2018

```

## Ejemplo de ejecución de at  
-  a media noche `at 12pm`
- un minuto después de la media noche de hoy `at 12pm + 1 minutes`
-  el uno de enero del mes que viene `at 00:00 Jan 1`


### cuestioenes sobre at  
- El directorio de trabajo que tiene actualmente es aquel desde el que se lanza la orden at  
- Hereda la máscara de permisos del padre  
- No hereda las variable que se definan para la terminal que lo lance  
- Su proceso padre es el demonio ( visto con el script de clase)

```
daemon    7559   902  0 21:03 ?        00:00:00 /usr/sbin/atd -f
blanca    7560  7559  0 21:03 ?        00:00:00 sh
```

Una buena constumbre a seguir es redirigir la salidas estandar y la de error 
```
salida standar 1>> fichero
salida de error 2> /dev/null 
```

Por defecto el fichero /dev/null lo que hace es ir al vacío

## Escribir script que devuelva los archivos modifiaos del día anterios 
órden en consola: 
```
at now + 1 days -f ultimas_24_horas.sh
```
Script escrito 
```
dia=`date +%d`
dia=$((dia--))

archivo=modificados_`date +%Y-%d-%T`
find ~/ -mtime 0 > $archivo} 2>> /dev/null
```


## Ejemplo de fichero crontab  
```
# minutes horas dia_mes mes di_semana comanddo
1 	  * 	* 	*   *	      ~/practica_4/saca_padre.sh
```

sintaxis molona: 
- crontab file para cargar el fichero de cron del ususario  
- crontab -r para borrar el actual  
- crontab -l para ver la tabla del cronta actual  
- cronta -e para editar 
