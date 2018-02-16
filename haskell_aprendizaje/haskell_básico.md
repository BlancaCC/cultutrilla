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
-[operadores](#i4)  
-[Patrones para funciones](#i5)  
  -[Patrones constantes](#5_1)  
  -[Patrones para listas](#5_2)  
-[Input and output](#i99)  

## Conceptos básico <a name="i1"></a>

- Programación funcional
- Haskell lenguaje perezoso: cálculos cuando son necesarios
- Lenguaje no tipado
- Archivo .hs
- Abrir módulos desde intérprete ghci :l nombre_del_archivo.hs_sin_el.sh
- Compilar y ejecutar desde terminal:
  - crear archivo .hs
  - deberá contener una función main
  - ` ghc --make nombre.sh `
  
- Comentarios cortos `-- esto es un comentario corto`
- Comenttario largo:
```
{- Esto es un comentario
de más de 
una línea-}
```

## Funciones <a name="i2"></a>

- Para llamar a una función: ` nombre variables `
- de forma infija ` variable_1 \`nmbre\` variable_2 `

### Funciones básica predefinidas

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

Para defininir un nombre el la GHCi `let nombre = algo`  
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
`truncate round floor ceiling ` | Fnciones de redondeo, respectivamente: elimina parte decimal, redondea al entero más proximos, entero inferior, entero superior ¿Cual es la diferencia entre truncate y floor ?   
`fromInt` | convierte a Int    
` min max 	`| - 
### Double  
Real con más precisión  

### Char <a name="i3_3"></a>  
- Representa un caracter 
- Se escrien con comillas simples `'a' `

- Representación de caracteres especiales: 

Carácter | Descripción  
--- | ---
`'\n' `| salto de linea  
`'\t' `| tabulador  
`'\''` | comilla simple  
`'\"' ` | comilla doble  
`' \\'` | barra inclinada hacia la izquierda    

#### Funciones  
Operador o función | Descripción  
--- | ---   
ord | código ASCII del carácter  
chr | función inversa a ord  
is Upper, isLower, isDigit, isAlpha | si el (resp) mayúscula, minúscula, dígito o letra  
toUpper , toLower | -  
< > >= <= == /= | la última quiere decir diferente  
min max | -

#### Tuplas <a name="i3_4"></a>  

Dato compuesto donde el tipo de cada componente puede ser distinto, ejemplo:
```
('e' , 2.718281828459045 , False)::(Char, Double , Bool)
```


#### Listas (no tontas) <a name="i3_5"></a>
- no combinan distintos tipos
ejemplo `let notas = [ 0 ,1 , 0 , 1 , 1 ,1 ]`
- las cadenas de caracteres son listas (no tienen inteligencia propia)
- ` !! ` Hacer referencia a un elemento conociendo índice  

##### Contatenadores
- `++` concatena al fina *ojo con las listas largas* `Prelude> [1,2,3] ++ [2,3,4]       [1,2,3,2,3,4]`  
- ` : ` operador cons, concatena ALGO al principio  `Prelude> 'm' : "niño"		"mni\241o"`
- Ejemplo interesante` Prelude> 2:1:3:[]						[2,1,3]`

##### Funciones básicas trabajo con listas
función 	| Descripción 	    | Ejemplo
--- 		| --- 		    | ---
head 		| devuelve primer elemento de la lista | ` head [1,2,3]` 1
tail 		| la lista sin el primero     	       | ` tail [ 0 , 1 , 2] ` [ 2 , 3]
last 		| devuelve último elemento 	       | `last [ 1 ,2]` 2
init 		| la lista sin el último elemento      | ` init [ 1 , 2 , 9999999999999999999999999]` [1,2]
leght 		| tamaño       	  	 	       | ...
null 		|comprueba si la lista es vacía        | `null []` true
reverse 	| lista del revés      	  	       | ...
take 		| coge n elementos primeros de la lista | ` take 1 [0,1,2]` [0]
drop 		| quita n elementos primeros   	  	| `drop 1 [ 0] ` []
maximum 	| develve el elemento mayor de una lista ordenable | ...
minimum 	| devuleve el elemnteo menor de una lista ordenable | ...
sum 		| devuelve la suma de una lista de números 	    | `sum [ 1 , 1] `2
product 	| producto elementos de una lista  		    | ...
elem 		| si un elemento está e una lesta 		    | `elem '0' [ 'e'] ` false
[ .. ]		| para crear lista estre esos nuemro s		    | `[0 .. 999]` [ 0,1,2,3,4,5 .. vale, ya sé porqué existe
[ , .. ]	| igual pero definientos función succ		    | `[ 7 , 0 ..49

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
Para ahorrarse escribir un patron, cuando este aparece en la izquierda y en la derecha, esto se soluciona con el operador ` @ `
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

Es un patron de la forma (n+k) donde k pertenece a los números naturales (sin el cero), solo se unifica si el argumento n , es mayor o igual que k, esto es útil por ejemplo en la función factorial, para evitar que sea infinita. 
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

función		| Descripción				| Ejemplo
--- 		| --- 					| ---
putStrLn	| Imprime en terminal 			| putStrLn "I love Haskell"
