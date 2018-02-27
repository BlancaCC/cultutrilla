# Máxima comandos básicos  
He aquí un pequeño resumen de las funciones y operaciones de máxima, introducida en la asignatura de métodos numéricos del segundo cuatrimestre de primero del grado de ingeniería informática y matemáticas  
## Representación símbolica de números  
- % para indicar que es una representación simbólica, puede haber un número especial (%e por ejemplo) o una casilla ya calculada  

### Números irracionales hasta el momento vistos: 
e 
pi

## Definición y borrado de variables
- `nombre:valor`
ejemplo: ` x: 20`

- Para borrar una variable ` kill ( nombre) ` `kill ( x) `
- Para borrarlas todas `kill( all )`


## Funciones básicas 
### Para trabajar con Maxima 

Funciones básicas  | Descripción  
--- | ---
print ()  | -   
float () | genera redondeo decimal real de un número  
fpprec | variar el núemro de decimales  
bflaot() | para ver con el número de decimales modificados    

### Funciones básicas matemáticas 
--- 
sin   
cos  
tan  
asin  
acos  
atan  
sqrt  
log   -- neperiano simpre  
exp   
abs   
### Definición de funciones, derivadas, integrales y gráficas   

#### Definción de ecuación 
`f(x):= x^2 + %e^x +9 ` Donde f puede ser cualquier nombre y x variable o grupo de variables   

Función     | Descripción  
--- | ---   | ---
diff( f(x) , x ) | Derivada de orden 1  
diff (f(x , x , n)) | Derivada de orenden n   
integrate ( f(x) , x , a , b)  | Integra definida en un intervalo de [a,b]  
integrate(f(x) , x)  | Integrar general, sabemos que le hace falta una cte  


## Dibujar gráfica  
La mejor forma es mediante línea de comandos







