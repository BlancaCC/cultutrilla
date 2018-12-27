# Cuerpo de nueve elementos  
Blanca Cano Camarero

Se pide encontrar un cuerpo de nueve elementos y construir su tabla de la multiplicación.

## Idea de cómo construir un cuerpo finito de m elementos  
Una idea sencilla para conformar un cuerpo finito es que sus elementos sean los posibles restos de $\mathbb{Z}_n[x]$ en el ideal producido por un irreducible (El motivo por el que debe ser irreducible se explica más adelante).
Supongamos que estamos trabajando con  $\mathbb{Z}_n [x]$ y ahora construimos el ideal con un polinomio irreducible de grado $g$.
Tengamos presente que por el algoritmo de la división euclídea el grado del resto debe ser estrictamente menor que el del "divisor", es decir, debe ser menor que $g$
La cantidad de posibles restos se calcuraría con el número de combinaciones:
Ejemplifico con $\mathbb{Z}_2[x]$ con un irreducible de grado 3:

- Puesto que estamos en $\mathbb{Z}_2$ los coeficientes posibles son 0 o 1.
- El grado de los restos debe ser menor de 3, por tanto llegaremos hasta $x^2$ con coeficientes no nulos.
- La cardinalidad de este conjunto será $2^3$, el número de variaciones con repetición de dos elementos tomados de tres en tres.

$x^0$| $x^1$ | $x^2$ | polinomio
  ---|--- |--- | ---
0 | 0 | 0  | 0  
1| 0| 0 | $1$  
0 | 1 |  0 |$x$
1 | 1 |  0 | $x+1$
0 | 0 | 1 | $x^2$
1| 0|   1|  $ x^2 + 1$
0 | 1 |1 |  $ x^2 + x$  
1 | 1 | 1 | $ x^2 + x+1$


Generalizando un poco más su cardinalidad de obtendrá tomando combinaciones de $n$ elementos tomados de $p$ en $p$, es decir, variaciones con repetición.
Y por tanto el conjunto construido será de $n^p$ elementos.

Como queremos construir un cuerpo de nueve elementos se debe cumplir que  $n^p = 9 $ con n y p pertenecientes a los naturales. Y la única solución sería n = 3 y p = 2.

Por lo tanto  no nos queda más remedio que trabajar con $\mathbb{Z}_3[x]$  en el ideal producido por alguno de sus irreducibles de grado 2, es decir, los posibles cuerpos de nueve elementos son:

$ \frac{ \mathbb{Z}_3[x]}{<x^2+1>}$, $ \frac{ \mathbb{Z}_3[x]}{<x^2+2x+2>}$ y $ \frac{ \mathbb{Z}_3[x]}{<x^2+x+2>}$

## Cuerpo seleccionado   
Sin nigún motivo en concreto, el cuerpo que yo he seleccionado para la construcción de su tabla de multiplicar es:  $ \frac{ \mathbb{Z}_3[x]}{<x^2+1>}$

Cuyas clases de equivalencia son (No se va a hacer uso de la notación de clase):
$ \frac{ \mathbb{Z}_3[x]}{< x^2+1>}$ = { $0 , 1 , 2, x , x+1 , x+2, 2x , 2x+1, 2x+2$}


## Motivos por los que se trata de un cuerpo  

Disponemos de varios motivos por los que ver que se trata de un cuerpo:

1. Puesto que en la tabla (ver epígrafe siguiente) no se encuentra ninguna ocurrencia del 0 hemos demostrado por exhaución que se trata de un dominio euclídeo.
 En virtud de que  todo dominio de integridad finito es un cuerpo, hemos probado lo que queríamos, que $ \frac{ \mathbb{Z}_3[x]}{<x^2+1>}$ es un cuerpo.

 2. Sin embargo, aunque útil el método anterior, podríamos valernos de otro más general utilizando la igualdad de Bezout:
 Preguntémonos por la existencia del inverso de $a$ dentro del ideal producido por un irreducible.

 $aa^{-1} \equiv 1 \quad mod  \quad irreducible$
 Por Bezout sabemos que esto tendrá solución si y sólo si el máximo común de $a$ y  el *irreducible* es divisor de 1, pero por tratarse de un irreducible esto ya lo tenemos asegurado, ya que el máximo común de ambos será 1. El coeficiente que acompañe como solución de tal ecuación a  $a$ será su inverso.

 Nota: La ecuación de Bezout nos da infinitas soluciones, pero todas ellas pertenecen a la misma clase del ideal.


## Su tabla de la multiplicación   

Nota:
  - Entre paréntesis se encuentra la explicación de qué razonamientos se ha seguido para calcular tal casilla, algunos se han omitido y que la idea ya era explicada en otros apartados.

 $\cdot$ | $0$ | $1$ | $2$|$ x $|$ x+1 $|$ x+2$|$2x$|$ 2x+1$|$ 2x+2$
---|---|---|---|---|---|---|---|---|---  
$0$| $0$ |$0$| $0$| $0$| $0$| $0$| $0$ |$0$ | $0$
$1$|$0$ | $1$| $2$ | $ x $|$ x+1 $|$ x+2$|$2x$|$ 2x+1$|$ 2x+2$
$2$|$0$ |$2$|$1$ (0)|$2x$|$2x+2$|$2x+1$ (0)| $x$ (1)|$x+2$|$x+1$   
$x$| $0$ | $x$| $2x $|$2$ (2)|$x+2$(3)|$2x+2$ (5)|$1$|$x+1$ (6)|$2x+1$     
$x+1$|$0$ | $x+1$|$2x+2$|$x+1$|$2x$|$1$ (4)|$2x+1$| $2$|$x$  
$x+2$|$0$ |$x+2$|$2x+1$|$2x+2$|$1$|$x$|$x+1$|$2x$|$2$  
$2x$|$0$ | $2x$|$x$|$1$|$2x+1$|$x+1$|$2$|$2x+2$|$x+2$
$2x+1$|$0$ | $x+1$| $x+2$|$x+1$|$2$|$2x$|$2x+2$|$x$|$1$
$2x+2$|$0$ |$2x+1$|$x+1$|$2x+1$|$x$|$2$|$x+2$|$1$|$2x$ (7)  

## Explicación de cómo se han obtenido las casillas de la tabla  

Algunas de las casillas se han omitido pro considerarse ya explicadas con razonamientos similares en otros apartados.
0. Con la reglas de toda la vida 2*2 es 4 = 3+1 y como el 3 pertenece a la clase del 0 obtenemos que 4 = 1
1. $2x \cdot 2 = 4x = (3+1)x = 3x + x = 0x + x = x $ Hemos utilizado el 3 pertece a la clase del 0 por estar en $\mathbb{Z}_3[x]$  

2. $x \cdot x = x^2$ Puesto que el grado debe ser menor que el del irreducible sobre el que se construye el ideal por el algoritmo general de la división:  $ x^2 - (x^2 + 1) = -1 = 2$
3. $x \cdot (x+1) = (x^2 +x) =  (x^2 + x)- (x^2+1) = x-1 = x+2  $  
4. $(x+1)(x+2)= x^2+3x+2 = (x^2+1)+ 1$ que por tratarse de un ideal es 1.
5. $x(x+2) =  x^2 + 2x = (x^2 +1)-1 + 2x = 2x + 2 $
6. $x(2x+1) = 2x^2 + x = 2(x^2 +1)+ x -2  = x+1$
7. $(2x^2+2)^2 = (4x^4)$

A partir de este los razonamientos similares serán omitidos.



### Observaciones interesantes  
La tabla de las multiplicaciones es simétrica, esto es producido ya que al ser un cuerpo la suma es conmutativa.
