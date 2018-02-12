## Haskell básico
He aquí un esquema de lo que sé en de Haskell a modo de recordatorio

### Conceptos básico

- Programación funcional
- Haskell lenguaje perezoso: cálculos cuando son necesarios
- Lenguaje no tipado
- Archivo .hs
- Abrir módulos desde intérprete ghci :l nombre_del_archivo.hs_sin_el.sh
- Compilar y ejecutar desde terminal:
  - crear archivo .hs
  - deberá contener una función main
  - ` ghc --make nombre.sh `

### Funciones

- Para llamar a una función: ` nombre variables `
- de forma infija ` variable_1 \`nmbre\` variable_2 `

####Funciones básica predefinidas

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

### Datos

Para defininir un nombre el la GHCi `let nombre = algo`

#### Listas (no tontas) 
- no combinan distintos tipos
ejemplo `let notas = [ 0 ,1 , 0 , 1 , 1 ,1 ]`
- las cadenas de caracteres son listas (no tienen inteligencia propia)
- ` !! ` Hacer referencia a un elemento conociendo índice  

##### contatenadores
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


### Input and output

función		| Descripción				| Ejemplo
--- 		| --- 					| ---
putStrLn	| Imprime en terminal 			| putStrLn "I love Haskell"
