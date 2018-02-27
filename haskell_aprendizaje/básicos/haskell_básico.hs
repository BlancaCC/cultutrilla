{-
Ejercicios sobre el Haskell básico
Blanca 16/2/18
-}


{- 1_ Función `a_derecha_de`
  Añade un número (puede ser de varios dígitos) a la derecha de un número entero:
 ejmplos:
1.1 `a_derecha_de` 2 --> 2
1 `a_derecha_ de `2 --> 21
-}
a_derecha_de  :: Integer -> Integer -> Integer
a_derecha_de x@ _ 0 = x
a_derecha_de  x y = y*10 + signum(y)*x

{-
2. División por sustracción: divS
Función recursiva que devuelce el resto de la división entera utilizando sustracciones
-}
divS :: Integer -> Integer -> Integer
divS x y
  | x < y = x
  | otherwise = divS (x-y) y


{-
3. Cociente mediante sumas y restac
Devuelve el cociente de dividir dos núemeros enteros usuando sumas y rectas
-}
-- Muy parecido al ejercicio 5
  
{-
 4.- sum_desde_hasta: sumInter
Devuelve la sumatoria desde un valor entero hasta otro
  -}
sumInter :: Integer -> Integer -> Integer
sumInter x y
  | x > y = sumInter y x
  | x == y = x
  | otherwise = x + sumInter x  (x+1)

-- En este caso debe ser x <= y 
sumInter2 :: Integer -> Integer -> Integer
sumInter2 x y
  | x > y = 0
  | x == y = x
  | otherwise = x + y + sumInter (x+1) (y-1)
  

{- 5. trocear
Esciba una función trocear que tome un número de n dígitos y que usando sólo sumas y restas, devuelva un par donde el primer elemento corresponde a
los n-1 primeros dígitos de enteros, y el segundo sea el dígito n-ésimo 
-}

-- Calculo cociente y resto de dividir entre 10, esta función se ahorraría com maybe (creo)
div10 :: Integer -> Integer -> (Integer,Integer)
div10 x y  -- x = resto, y = cociente
  | x < 10 = ( y , x )
  | otherwise = div10 ( x-10) (y+1)
  
trocear :: Integer -> (Integer , Integer )
trocear x = div10 x 0
