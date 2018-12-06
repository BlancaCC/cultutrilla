en la sobrecarga del operador de salida de flujo si lo dejo como indica el profesor aparece este error: 
```shell
./usodiccionario.out < data.txt
con el elemento: 0

Programa
 informacion asociada:
m. Plan,proyecto o declaracion de lo que se piensa realizar.
Sistema de distribucion de las materias de un curso o asignatura.
Anuncio de las partes,reparto y cuadro técnico de ciertos actos o espectáculos.
**************************************
con el elemento: 1

Sentencia
 informacion asociada:
f. Frase o dicho que implica un juicio,una enseñanza
Dictamen o resolución de un juez,un tribunal o un jurado.
**************************************
con el elemento: 2

Segmentation fault (core dumped)
makefile:12: recipe for target 'test' failed
make: *** [test] Error 139

```

Lo he solucionando haciendo esa clase friend y accediendo directamente a los datos 

```
  //for (it=D.begin(); it!=D.end(); it++)
  //for (it=D.cbegin(); it!=D.cend(); it++)
  for (it=D.datos.begin(); it!=D.datos.end(); it++)
```

Pero no entiendo porqué no va bien :(
