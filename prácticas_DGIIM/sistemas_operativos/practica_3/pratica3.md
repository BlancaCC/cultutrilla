# Práctica 3
Blanca Cano Camarero

## Consulta estadísticas del sistema  

Utilizando la orden uptime 
```
[root@localhost ~]# uptime
 02:42:23 up 5 min,  1 user,  load average: 0.00, 0.00, 0.00
```

Nota : load average significa la carga de CPU media en los últimaos 1, 5 y 15 minutos
- Tiempo de marcha del sistema : 5 min  
- Usuarios trabajando: 1 
- Carga media en estos 15 min es 15


## Cambios de prioridad entre procesos  

1. Creo escript que tener ejecutando en background 
Su nombre es prueba_procesos.sh
```bash 
#!/bin/bash

lim=100

for (( c=1; c<lim; c++ ))
do
    for (( d=1; d<lim; d++ ))
    do
	a=$(($lim+$d))
    done
done

echo fin $0 con pid $$, a vale $a
```

Ejemplo de cambio y modificación de permisos
```
yo:~/SO/modulo_i/practica_3$ ./prueba_procesos.sh &
[5] 9481
[4]   Terminado               ./prueba_procesos.sh
yo:~/SO/modulo_i/practica_3$ ./prueba_procesos.sh &
[6] 9487
yo:~/SO/modulo_i/practica_3$ renice 20 9481
9481 (process ID) prioridad anterior 0, nueva prioridad 19
yo:~/SO/modulo_i/practica_3$ sudo renice -5 9487
9487 (process ID) prioridad anterior 0, nueva prioridad -5
```

Para obtener los tiempos ejecutar con time.

```
yp_~time ./prueba_procesos.sh &
yo:~/SO/modulo_i/practica_3$ fin ./prueba_procesos.sh con pid 9943, a vale 19

real	0m0,003s
user	0m0,003s
sys	0m0,000s

```

## ps y pstree  
Para mostar el proceso con su padre 

```
[root@localhost ~]# ps -f      
UID        PID  PPID  C STIME TTY          TIME CMD
root      1189  1187  0 03:38 tty0     00:00:00 -bash
root      1216  1189  0 03:44 tty0     00:00:00 ps -f

```

## tty  
Proviene de  [*Teletype printer*](https://en.wikipedia.org/wiki/Teleprinter)  

En unix hacer referencia a el nombre de la termianl conectada a cada a la salida standar de cada proceso 

## Porcentaje de CPU ...
-  Eln interrupciones de software: he de fijarmen en el registro %soft
- Para las interrrucciones de hardware: %irq 


