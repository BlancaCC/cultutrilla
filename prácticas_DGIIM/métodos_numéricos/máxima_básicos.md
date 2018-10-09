# Máxima comandos básicos  
He aquí un pequeño resumen de las funciones y operaciones de Máxima, introducida en la asignatura de métodos numéricos del segundo cuatrimestre de primero del doble grado de ingeniería informática y matemáticas.
## Representación simbólica de números  
- % para indicar que es una representación simbólica, puede haber un número especial (%e por ejemplo) o una casilla ya calculada.  

### Números irracionales hasta el momento vistos: 
e (%e)
pi (%PI)

## Definición y borrado de variables
- Para definir: `nombre:valor`
Ejemplo: ` x: 20`

- Para borrar una variable ` kill ( nombre) ` `kill ( x) `
- Para borrarlas todas `kill( all )`


## Funciones básicas 
### Para trabajar con Maxima 

Funciones básicas  | Descripción  
--- | ---
print ()  | Muestra un mensaje   
float () | Genera redondeo decimal real de un número  
fpprec | Variar el número de decimales  
bflaot() | Para ver con el número de decimales modificados    

### Funciones básicas matemáticas 
--- 
- sin   
- cos  
- tan  
- asin  
- acos  
- atan  
- sqrt  
- log   -- neperiano simpre  
- exp   
- abs   
### Definición de funciones, derivadas, integrales y gráficas   

#### Definción de ecuación 
`f(x):= x^2 + %e^x +9 ` Donde f puede ser cualquier nombre y x variable o grupo de variables   

Función     | Descripción  
--- | ---   | ---
diff( f(x) , x ) | Derivada de orden 1  
diff (f(x , x , n)) | Derivada de orden n   
integrate ( f(x) , x , a , b)  | Integral definida en un intervalo de [a,b]  
integrate(f(x) , x)  | Integral primitiva, sabemos que le hace falta una cte  


## Dibujar gráfica  
La mejor forma es mediante línea de comandos o usando las ayudas de la barra de herramientas.




## Estructuras de control de flujo  
### for  
```
for i:1 thru n do
(
     print(i),
    print(n-i)
);

```
```
for i:1 step 2 thru n do
(
	print(i)
	print(n-i)
);
```

### if   

```
if 1 = n then 1 else n
```
¡Se pueden anidar!
```
if n = 2 then 2 else if n = 1 then 3 else 1
```
