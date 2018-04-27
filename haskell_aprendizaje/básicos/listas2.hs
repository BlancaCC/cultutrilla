{-
Ejemplos de funciones básicas con listas y compresión... 
-}
-- Devuelve TODOS los números primos 
prime = filterPrime [2..]
  where filterPrime (p:xs) =
          p : filterPrime[x | x <- xs, mod x p /=0 ]

-- Devuelve n primos
give_prime :: Int -> [Integer]
give_prime n = take n prime


-- Devuelve el primer elemento que cumple una condición concreta
give a n = head ( dropWhile (a n) prime)


-- DIVISORES DE UN NÚMERO

-- versión por comprensión de listas 
divisoresC :: Int -> [Int]
divisoresC n = [ x | x <- [1..(n-1)], mod n x == 0]


-- versión por filtro


divisoresF :: Int -> [Int]
divisoresF n = filter (divisible n ) [1..(n-1)]
  where divisible a b = mod a b == 0

