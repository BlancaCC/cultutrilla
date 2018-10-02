# Haskell básico
He aquí un esquema de lo que debería saber de Haskell a modo de recordatorio. :)

## Índice de contenidos  
- [Conceptos básicos](#i1)  
- [Funciones](#i2)  
- [Datos](#i3)  
  -[Bool](#i3_0)  
  -[Int y Integer](#i3_1)  
  -[Float y Double](#i3_2)  
  -[Char](#i3_3)  
  -[tuplas](#i3_4)  
  - [Listas](#i3_5)  
-[Operadores](#i4)  
-[Patrones para funciones](#i5)  
  -[Patrones constantes](#5_1)  
  -[Patrones para listas](#5_2)  
-[Input and output](#i99)  
- [Instrucciones interesantes para ahorrar tiempo](#6)

## Conceptos básico <a name="i1"></a>

- Programación funcional
- Haskell lenguaje perezoso: cálculos cuando son necesarios
- Lenguaje no tipado
- Archivo .hs
- Abrir módulos desde intérprete ghci :l nombre_del_archivo.hs_sin_el.sh
- Compilar y ejecutar desde terminal:
  - Crear archivo .hs
  - Deberá contener una función main
  - ` ghc --make nombre.sh `

- Comentarios cortos `-- esto es un comentario corto`
- Comentario largo:
```
{- Esto es un comentario
de más de
una línea-}
```

## Funciones <a name="i2"></a>

- Para llamar a una función: ` nombre variables `
- de forma infija ` variable_1 \`nombre\` variable_2 `

### Funciones básicas predefinidas

Función | Descripción | ejemplo
--- 	| ---	      | ---
succ 	| siguiente   | ` succ 'a' `
max 	| máximo dos elementos | `max 2 8 `
min 	| mínimo dos elementos | `min 'a' 'o' `

### Declaración de funciones

sintaxis:

` nombre variables = operaciones `

ejemplo:
```
Prelude> doblame x = x*x
Prelude> sumanos x y = doblame x + doblame y
Prelude> sumanos 1 2
5

```

## Datos <a name="i3"></a>

Para definir un nombre el la GHCi `let nombre = algo`  
### Tipos simples predefinidos

#### Bool <a name="i3_0"></a>  

Operador o función | Descripción  
--- | ---
` && ` | Conjunción lógica    
`\|\| ` | Disyunción lógica  
` not `| Negación lógica   
` otherwise ` | Función constante que devuelve el valor true    

#### Int <a name="i3_1"></a>
Exprsiones para determinar rango de valores:
- `minBound :: Int`
- `maxBound :: Int `  

##### Funciones básicas y operadores definidos para el tipo entero  

Operador o función | Descripción  
--- | ---
` + - * ^ `   | Suma, resta, producto de enteros, potencia exponente entero  
`div mod `    | Cociente y resto de dividir dos enteros  
` abs `       | Valor absoluto  
`signum`      | 1 positivo -1 negativo 0 0  
`negate` `- ` | invierte signo del argumento   
`even ` `odd` | bool comprueba si es par o impar     
`min` `max`   | devuelve mínimo, máximo

#### Integer  
- Valores de tipo Int con precisión ilimitada,  utilizan los mismo oeradores y funciones
- Los cálculos son menos eficientes.

#### Float <a name="i3_2"></a>  
- Valores que representan los números reales.
- Notación habitual `2.718281828` con punto entre la parte entera y decimal  
- Notación científica `6.022e23`  

##### Funciones y operadores  

Operador o función | Descripción  
--- | ---   
` + - * ` | -   
` ^ ` | Potencia de base real, pero exponente natural   
`**` | Potencia de base y exponente real   
`abs`| -   
`signum` | -   
`negate - ` | -   
` sin asin cos acos tan atan ` | funciones trigonométricas, trabajan con radianes    
`atan2 :: Float -> Float -> Float`| `atan2 x y` devuelve el arcotangente de x/y  
`log exp` | -   
`logBase` | `logBase ( base , numero_a_calcular )`
`sqrt` | -   
`pi` | -    
`truncate round floor ceiling ` | Funciones de redondeo, respectivamente: elimina parte decimal, redondea al entero más próximo, entero inferior, entero superior. ¿Cual es la diferencia entre truncate y floor ?   
`fromInt` | convierte a Int    
` min max 	`| -
### Double  
Real con más precisión  

### Char <a name="i3_3"></a>  
- Representa un carácter
- Se escriben con comillas simples `'a' `

- Representación de caracteres especiales:

Carácter | Descripción  
--- | ---
`'\n' `| Salto de linea  
`'\t' `| Tabulador  
`'\''` | Comilla simple  
`'\"' ` | Comilla doble  
`' \\'` | Barra inclinada hacia la izquierda    

#### Funciones  
Operador o función | Descripción  
--- | ---   
ord | Código ASCII del carácter  
chr | Función inversa a ord  
is Upper, isLower, isDigit, isAlpha | Si el (resp) mayúscula, minúscula, dígito o letra  
toUpper , toLower | -  
< > >= <= == /= | La última quiere decir diferente  
min max | -

#### Tuplas <a name="i3_4"></a>  

Dato compuesto donde el tipo de cada componente puede ser distinto, ejemplo:
```
('e' , 2.718281828459045 , False)::(Char, Double , Bool)
```


#### Listas (no tontas) <a name="i3_5"></a>
- No combinan distintos tipos
ejemplo `let notas = [ 0 ,1 , 0 , 1 , 1 ,1 ]`
- Las cadenas de caracteres son listas (no tienen inteligencia propia)
- ` !! ` Hacer referencia a un elemento conociendo índice  

##### Contatenadores
- `++` concatena al fina *ojo con las listas largas* `Prelude> [1,2,3] ++ [2,3,4]       [1,2,3,2,3,4]`  
- ` : ` operador cons, concatena ALGO al principio  `Prelude> 'm' : "niño"		"mni\241o"`
- Ejemplo interesante` Prelude> 2:1:3:[]						[2,1,3]`

##### Funciones básicas trabajo con listas
función 	| Descripción 	    | Ejemplo
--- 		| --- 		    | ---
head 		| Devuelve primer elemento de la lista | ` head [1,2,3]` 1
tail 		| La lista sin el primero     	       | ` tail [ 0 , 1 , 2] ` [ 2 , 3]
last 		| Devuelve último elemento 	       | `last [ 1 ,2]` 2
init 		| La lista sin el último elemento      | ` init [ 1 , 2 , 9999999999999999999999999]` [1,2]
leght 		| Tamaño       	  	 	       | ...
null 		| Comprueba si la lista es vacía        | `null []` true
reverse 	| Lista del revés      	  	       | ...
take 		| Coge n elementos primeros de la lista | ` take 1 [0,1,2]` [0]
drop 		| Quita n elementos primeros   	  	| `drop 1 [ 0] ` []
maximum 	| Develve el elemento mayor de una lista ordenable | ...
minimum 	| Devuleve el elemento menor de una lista ordenable | ...
sum 		| Devuelve la suma de una lista de números 	    | `sum [ 1 , 1] `2
product 	| Producto elementos de una lista  		    | ...
elem 		| Si un elemento está e una lesta 		    | `elem '0' [ 'e'] ` false
[ .. ]		| Para crear lista entre esos números s		    | `[0 .. 999]` [ 0,1,2,3,4,5 .. vale, ya sé porqué existe
[ , .. ]	| igual pero definiendo función succ		    | `[ 7 , 0 ..49

#### Constructor de tipo (->) <a name="i3_6"></a>  
Asigna el tipo correspondiente a cada función.  
```
ant :: Integer -> Integer
ant x = x -1

componer :: (Integer-> Integer ) -> (Integer -> Integer ) -> Integer -> Integer
componer g f x = g( f x )

MAIN> componer ant ant 1
-1 :: Integer
```

## Operadores <a name="i4"></a>
A parte de definir funciones, podemos definir operadores con la siguiente estructura:  
` claúsula prioridad identificador `

claúsulas infix | Descripción
--- | ---
infix | Operador no asociativo  
infixl | propiedad asociativa izquierda
infixr | " derecha

Ejemplo:
```
infix 4 ~=
(~=) :: Float -> Float -> Bool
x ~= y = abs( y - x ) < 0.001
```

### Patrones para funciones <a name="i5"></a>  
Tengamos presentes que estos patrones se pueden anidar

#### Patrones constantes  <a name="i5_1"></a>  
Patrón unifica (concuerda) por una constante:
```
binario :: Integer -> Bool
binario 1 = True
binario 0 = False
```

```
factorial :: Integer -> Integer  
factotial 0 = 1
factorial n = n * factorial (n-1) -- esperemos que n no sea negativo
```
#### Patrones para listas <a name="i5_2"></a>  
```
producto  :: [Integer]-> Integer
producto 1 = 1  -- caso base
produnto [x:xs] = x * producto xs -- caso recursivo
```
#### Patrones para tuplas  
```
simetrico :: (Integer , Integer) -> ( Integer , Integer )
simetrico (x , y) = ( y , -x )  

```
#### Patrones nombrados o seudónimos  <a name="i5_3"></a>  
Para ahorrarse escribir un patrón, cuando este aparece en la izquierda y en la derecha, esto se soluciona con el operador ` @ `
```
-- no copies este código
module Main where
factorial :: Integer -> Integer
factorial 0 = 1
factorial m@(n+1) = m * factorial n -- AQUÍ ESTA LO IMPORTANTE DEL EJEMPLO
```
#### Patrones aritméticos  
** Este patrón está anticuado a partir de la versión 7.0.3, por considerarse poco ortodoxo, [fuente](https://wildunix.es/posts/el-patron-nk-en-haskell-a-partir-de-la-version-703/). **

Para incluirlo, añadir biblioteca: `module Main where`
y compilarlo con `ghc  -XNPlusKPatterns .... factorial.hs`

Es un patrón de la forma (n+k) donde k pertenece a los números naturales (sin el cero), solo se unifica si el argumento n , es mayor o igual que k, esto es útil por ejemplo en la función factorial, para evitar que sea infinita.
```
module Main where
factorial :: Integer -> Integer
factorial 0 = 1
factorial (n+1) = (n+1) * factorial n
```

#### Patrón subrayado  <a name="i5_3"></a>  
El patrón subrayado (_) unifica con cualquier argumento, pero no estable ninguna ligadura.
```
decapitar :: [Integer]-> [Integer]
decapitar [] = []
decapitar (_:xs) = xs
```
## Input and output <a name="i99"></a>

Función		| Descripción				| Ejemplo
--- 		| --- 					| ---
putStrLn	| Imprime en terminal 			| putStrLn "I love Haskell"  

## Instrucciones interesantes que ahorran tiempo <a name i6></a>

Instrucción | Utilidad | Ejemplo
--- | --- | ---  
take | Coge los n últimos elementos de una lista   


# Ampliación de listas   


Comando | Descripción | Ejemplillo si me aptece  
--- | --- | ---   
`++ ` | Concatena dos listas | ` [1]++[0]`  
concat | Para lista de listas | `concat[ [1..2], [9,9],[111]] -> [1,2,9,9,111]`  
head tail | primer elemento y último | aaa  
take | coge los n primeros | `take 7 [1..898989] -> [1,2,3,4,5,6,7]`  
drop | deshecha los n primeros  | ...  
splitAt | combina take y drop | `splitAt 3 [0..10] -> ([0,1,2],[3,4,5,6,7,8,9,10]) `  
`!!` | selección de elemento dentro de una lista | `[1..10] !! 0 ->1 `   
zipWith | aplica cierta función a los elementos de una lista, tomándolos de dos en dos | `zipWith (*)[1..3][5..] -> [5,12,21]`  
zip | igual sin operación | `zip [0..3]['a'..] -> [(0,'a'),(1,'b'),(2,'c'),(3,'d')]`  
unzip | proceso inverso | ooo   
map | aplicar _ a todos lo elemento de la lista | `map  (+1) [1..2] ->[2,3]`  
filter | aplica un filtro  | ...  
takeWhile | filtro hasta que se encuentra un elemento que no debería estar dentro  | ` takeWhile (<3) [-1..3] ->[-1,0,1,2] `  
dropWhile | elimina mientras que se de la condición | ...  
