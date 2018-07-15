# Guía rápida de python para principiantes

## Introdución
Querida Paula, ya sabes que me encanta darte la tabarra, así que antes de apresurarnos en el enfangoso mundo pythónico te daré la tabarra con lo que es un programa:
* secuencia de instrucciones que una computadora es capaz de interpretar o ejecutar *
En el caso de python interpretado, es decir que irá leyendo y realizando a pies juntillas las instrucciones una por una. Y esto a usted le interesa , ya que los errores de ptogramción no surgiran hasta que no llegue  a susodicha línea y como motivación para el cuidado de la sintáxis.

Además python es de tipado dinámico, lo que significa que el tipo de variable se define en asignación, lo cual le permite escribir:
```python
a = 2.43		# variable de tipo float
a = 'hola caracola'	# variable de tipo string o cadena de caracteres
```
(Tranquila a partir de aquí no voy a entrar en más terminología)

## Bases de la programación
Todo algoritmo básico es capaza de componerse a partir de variables, condiciones y repeticiones, en ellos dividiré este manual.

### Los tipos básicos son:
```python
a = 2.43		# variable de tipo float
a = 'hola caracola'	# variable de tipo string o cadena de caracteres
a = False 		# booleano (sólo admite verdadero o falso
a = 'a' 		# un caracter
```

Y si lo tuyo es almacenarlos lo puedes hacer en *listas*:  
```python
lista = [ 2.71828 , 'e' , 'Vivan las "mates" ' , ['P','a'] ] # declaración básica, 
lista.append( True ) 	  	     	       	 	     # añade el valor lógico True al final
lista.pop( 3 ) 	   					     # elimina y devuelve el valor en la posición 3: ['P','a'], (como es natural se empieza en 0
	     						     # 	       ['P','a'] además es equivalente a 'pa'
```							   
Escribiendo `help( list ) `tendrás todos los métodos (append y pop son dos métodos ) de las listas explicados
Y escribiendo `help( list.append )`tendrás el de uno en concreto,
también puedes conocer sólo los métodos con `dir( list )`


También existen los diccionarios y conjuntos, eso se lo dejo a su propia investigación, pero de momento con lo visto irá servida <3


## Repeticiones

Si ahora te diera el gusanillo de recorrer la lista lo podrías con bucle.

### for

```python
for i in lista:
    print( i )

# alernativamente

for i in range( len( lista) ): # len devuelve la longitud y range genera una lista de números, del 0 a la longitud de la lista
    print( lista[i] )          # lista [ i ] hace referencia al elemento i-ésimo de la lista

```

## Condiciones y while

Todos sabemos que es una condición, si ocurre cierta cosa pasa esto, si no lo otro

``` python3
if a == b:
   print ( f' a y b son iguales y valen: {a} ' )
elif a < b:
     print ( ' a es menor que b, qué barbarie' )
else:
	while a > b :
	      b += c # sumo a b c
	      print( ' Tarde o temprano b alcanzará a a si esta se queda igual ' )
```

Observemos que while es otra esctrutura de repetición

