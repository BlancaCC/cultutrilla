# Practica 1  

Recordamos esta útil orden:  ` man -t orden_terminal | ps2pdfwr - nombre_archivo.pdf ` para poder leer en pdf las órdenes hechas
## Creación de cuentas de un usuario. 

### newusers  

Parametros importantes: 
`<Username>:<Password>:<UID>:<GID>:<User Info>:<Home Dir>:<Default Shell> `
```
[root@localhost ~]# echo "Maria:contrasena:502:502::/home/no_soyMaria:/bin/bash"> Maria
[root@localhost ~]# newusers Maria 
```

### userdel  
Para borrar un usuario, su rastro desaparece de 

### Cambie de usuario intente hacer pruebe a visualizar la carpeta principal  

En un principio no se nos permite, para ello deberemos de añadir a nuestro ususario en usoer: 
`visudo` 

y añadimos su nombre de usuario `Maria ALL=(ALL) ALL` 
Finalemte nos cambiamos a su usuario Maria y ya podremso hacer un `ls`

## Archivo /etc/passwd  
Para ver a quién pertenece
```
[root@localhost ~]# ls -l /etc/passwd
-rw-r--r-- 1 root root 924 Dec 10 11:12 /etc/passwd

```
Como vemso pertenece al root 
El formato es de la siguiente manera: 
```
smmsp:x:51:51::/var/spool/mqueue:/sbin/nologin
paco:x:500:500::/home/paco:/bin/bash
Maria:x:502:502::/home/no_soyMaria:/bin/bash
```

## Acceder al archivo /etc/shadow desde otro usuario   
Esto se puede hacer usando su y tras a ver añadido el usuario a visudo



## group   
Grupo de usuarios que comparten recursos y archivos del sistema. 

## Contenido temporal  
Un programa temporal podría guardar su contenido en tmp


## Archivos fstab y mtab

El archivo /etc/fstab es usado para definir cómo las particiones, distintos dispositivos de bloques o sistemas de archivos remotos deben ser montados e integrados en el sistema. 

Al hacer un cat muestra   
```
#
# /etc/fstab
#
LABEL=ROOT					/		auto	noatime1 1
tmpfs						/dev/shm	tmpfs	defaults0 0
tmp						/tmp		tmpfs	rw,mode=1777,fscontext=system_u:object_r:tmp_t:s0	0 0
devpts						/dev/pts	devpts	gid=5,mode=620	0 0
sysfs						/sys		sysfs	defaults0 0
proc						/proc		proc	defaults0 0

```

/etc/mtab muestaa una lista de los procesos actuales montados  
```
[root@localhost ~]# cat /etc/mtab  
LABEL=ROOT / auto rw,noatime 0 0
proc /proc proc rw 0 0
sysfs /sys sysfs rw 0 0
devpts /dev/pts devpts rw,gid=5,mode=620 0 0
tmpfs /dev/shm tmpfs rw 0 0
/tmp /tmp tmpfs rw,mode=1777 0 0
none /proc/sys/fs/binfmt_misc binfmt_misc rw 0 0

```





