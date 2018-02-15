# Haskell básico
He aquí un esquema de lo que sé de Haskell a modo de recordatorio. :)

## Índice de contenidos  
- [Conceptos básicos](#i1)  
- [Funciones](#i2)  
- [Datos](#i3)  
  -[Bool](#i3_0)  
  -[Int y Integer](#i3_1)  
  -[Float y Double](#i3_2)  
  - [Listas](#i3_)  
-[Input and output](#i4)  

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
`sqrt` | -   
`pi` | -    
`truncate round floor ceiling ` | Fnciones de redondeo, respectivamente: elimina parte decimal, redondea al entero más proximos, entero inferior, entero superior ¿Cual es la diferencia entre truncate y floor ?   
`fromInt` | convierte a Int    
	
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





#### Listas (no tontas) <a name="i3_"></a>
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
[ , .. ]	| igual pero definientos función succ		    | `[ 7 , 0 ..49]


## Input and output <a name="i4">

función		| Descripción				| Ejemplo
--- 		| --- 					| ---
putStrLn	| Imprime en terminal 			| putStrLn "I love Haskell"
