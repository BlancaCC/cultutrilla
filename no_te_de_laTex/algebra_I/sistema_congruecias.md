# Resolución de un sistema de congruencias  
Explicación del método de Newton y Lagrange  de resolución de congruencias y resolución de uno dado por  uno de los métodos expuestos.

Blanca Cano Camarero
 Granada 22 de noviembre del 2018
2 º DGIIM


## Descripción de cada una de los métodos   
### Resolución de un sistema de congruencias a lo Newton.

A grandes rasgos, este método se basa  en resolver dos de las congruencias del sistema obteniendo así una congruencia nueva, solución de ambas y repetir el proceso con las congruencias del sistema no utilizadas con anterioridad, hasta llegar a una congruencia final, la solución.

La demostración de que existe una solución para dicho sistema es constructiva, lleguemos a ella y además analicemos que de:
Se tienen el siguiente sistema de $ n+1 $ congruencias
$x \equiv a_0 \quad mod \quad b_0$
$x \equiv a_1\quad mod \quad b_1$
...
$x \equiv a_n\quad mod \quad b_n$

1. Buscamos una congruencia equivalente a las dos primeras, para ello en base a la definición de módulo:  
$x \equiv a_0 \quad mod \quad b_0$ equivale a $x = a_0 + b_0 \cdot t  $ con $t$ pertenciente a  $\mathbb{Z}$ , por tanto veamos si la segunda congruencia respeta tal condición y  si es así, cuáles son las soluciones. Para ello sustituyamos los valores posibles ($x$) de la primera en la segunda congruencia:
$$a_0 + b_0 \cdot t  \equiv a_1 \quad mod \quad b_1$$
Volviendo a aplicar la definición de congruencia se tiene
$$a_0 + b_0 \cdot t =  a_1 + b_1 \cdot k$$  con t y k enteros.

En virtud del teorema de Bezout sabemos que este sistema tiene solución si y sólo si $mcd(b_0, b_1) | (a_1 - a_0)$ y si es así sabemos que tiene infinitas soluciones de la forma $t = t_0 + \frac{b_1}{ (b_0, b_1)} \cdot k$ con $k$ un entero cualquiera y $t_0$ la solución particular al sistema.

Con esto hemos encontrado los coeficientes $t$ y $k$ para los que esa ecuación tiene solución es decir, los valores que son  congruentes con la segunda y la primera congruencia, veamos la  ecuación resultante para los coeficientes $t$ obtenidos, sustituyéndolos en la primera ecuación:

$$x = a_0 + b_0 \cdot (t_0 + \frac{b_1}{ (b_0, b_1)} \cdot k)$$   

Desarrollamos  $x = ( a_0 + b_0 \cdot t_0 ) +  \frac{b_0 \cdot b_1}{ (b_0, b_1)} \cdot k \quad$  Teniendo ahora en cuenta que $ \frac{b_0 \cdot b_1}{ (b_0, b_1)} = [b_0,b_1]$ y volviendo a aplicar la definición de módulo llegamos a la congruencia solución del sistema de la primera con la segunda.  

$$x \equiv  a_0 + b_0 \cdot t_0 \quad mod \quad [b_0, b_1]$$

Ahora repetiremos el proceso tomando a la resultante y la siguiente del sistema (la tercera en este caso), dando lugar mediante este proceso a una congruencia con soluciones de la primera, segunda y tercera. Repitiendo este proceso n veces siempre y cuando cumplan la condición de Bezout, se encontrará el resultado buscado.

### Resolución de un sistema de congruencias a lo Lagrange  
En el caso de que los módulos de las congruencias sean primos relativos  (Como en el sistema que se expone más adelante). Podremos utilizar el siguiente método que nos da una solución única al siguiente sistema de congruencias:

$x \equiv a_0 \quad mod \quad b_0$
$x \equiv a_1\quad mod \quad b_1$
...
$x \equiv a_n\quad mod \quad b_n$

Se define $M = \prod_{i=0}^{n} b_i$
Y se calcula  $c_i = (\frac{M}{b_i})^{-1}$ en $\mathbb{Z}_{b_i}$

Se tienen que una solución particular es $x_0 = \sum_{i=0}^{n} a_i \cdot  c_i \cdot  \frac{M}{b_i}$

Por tanto la congruencia solución sería:
$$x \equiv x_0 \quad mod \quad [b_0, ... , b_n]$$

## Números de partida

Sea d = 75 57 73 92  
Sea u = d mod 100 = 92 mod 100  = 92
Sea v = $\frac{d-u}{100}$ mod 100  = 73 mod 100  = 73   
sea w = $\frac{d-100v-u}{10000}$ mod 100 = 77 mod 100 = 57  

## Resuelve el siguiente sistema de ecuaciones

 x $\equiv$ 92 mod 101  $\quad$  (1)
 x $\equiv$ 73 mod 102  $\quad$  (2)
 x $\equiv$ 57 mod 103  $\quad$  (3)

### Mediante el teorema de los restos chinos a lo Newtom

1. Comprobamos que tiene solución, esto es si y sólo si se cumple que $ a \equiv b $ mod c donde a,b $\in$ {92,73,57} y c es el mcd de los respectivos módulos.
 Esto se dará siempre, ya que 101, 102 y 103 son primos relativos, es decir, que su mcd es 1.

2. Sin pérdida de generalidad procedo a calcular el sistema formado por la congruencias (2) y (3):

Por la definición de congruencia, x $\equiv$ 57 mod 103  equivale a x = 57 + 103 t  (4), donde t $\in  \mathbb{Z}$ . Sustituimos tal igualdad en (2), resultando:
57 + 103 t $\equiv$ 73 mod 102, restamos 57 en ambos miembros y como 1 $\equiv$ 103 mod 102la ecuación resultante es:
$$ t = 16 \quad mod \quad 102$$
 De donde deducimos que t = 16.
 Sustituyendo en (4) obtenemos como solución particular  que  x = 1705.
Y la congruencia solución es:

$$x \equiv 1705 \quad mod \quad 10506 \quad \quad (5)$$  

Continuemos ahora para resolver el sistema con las congruencias (5) y (1).

Por la definición de módulo en (5) x = 1705 + 10506 t donde t es cualquier entero.

Sustituimos tal valor de la x en (1): $1705 + 10506 t \equiv 92 \quad mod \quad 101$   
Además tenemos que por ser primos relativos el [102, 103] = (101+1)(101+2) que en módulo 101 es 2.
$2 \cdot t \equiv -1705 + 92 \quad mod \quad 101; \quad -1705+92 = -1613; \quad
-1613 + 16 \cdot 101 = 3$

Por consiguiente la congruencia simplificada resulta:
$2t \equiv 3 \quad mod \quad 101$

Que da lugar a la ecuación $2t_0 + 101 k_0 = 3$ (6), nos interesa ver la solución general de t. Calculamos los coeficiente de Bezout ya que tiene solución:
Cociente | Resto | $k$ | $t$  
--- | --- | --- |---
  ~ |101   | 1 | 0  
  ~ | 2 | 0 | 1
  50 | 1 | 1 | -50    


  El (101, 2) es 1, y Bezout nos dice que $2t + 101k = (2,101) = 1$ ,donde por los cálculos anteriores t = -50 , multiplicamos por 3 para calcular una solución particular a la ecuación (6), de donde deducimos que $t_0 = 3t = -150$

  Por el desarrollo teórico explicado al principio, determinamos que las soluciones al sistema son de la forma:  $x \equiv -1574195 \quad mod \quad [101,102,103] \quad$, que tras simplificar queda:
  $$x \equiv 548017 \quad mod \quad 1061106$$

  ### Confirmación de los resultados mediante Gap
  Para cerciorarnos de no haber cometido ningún error de cálculo utilizaremos gap:
  ```Gap
  gap> Lcm(101,102,103);
  1061106
  gap> ChineseRem([101,102,103],[92,73,57]);
  548017
  ```
