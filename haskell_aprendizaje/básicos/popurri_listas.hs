-- DA UNA LISTA A LA INVERSA
rev :: [Int]-> [Int]
rev [] = []
rev (x :xs) = rev xs ++ [x]

-- SUMA LAS POSICIONES IMPARES DE UN ARRAY

impares :: [Int]-> [Int]
impares [] = []
impares[_] = []
impares ( x : xm : xs) = [x] ++ impares xs

suma :: [Int] -> Int
suma [x]=x 
suma (x : xs) = x + suma xs 

suma_impares:: [Int]-> Int
suma_impares l = suma (impares l) 

-- versión abreviada 
si :: [Int]->Int
si [] = 0
si[_] = 0
si (x:xm:xs) =
  x + si xs

----------------------------------------------------------------------------------------------------

--SUMA LOS NÚMEROS IMPARES

--mi solución  

sum_odd :: [Int] -> Int
sum_odd (x : xs)
  | [] = 0
  | odd x  = x + sum_odd xs
  | otherwise = sum_odd xs
  
  --Boerworz
f = sum . filter odd

----------------------------------------------------------------------------------------------------
-- DEVUELVE LA LONGITUD DE UNA LISTA

-- mi solución
len0 = [a]-> Int
len0[_]= 1
len0 (x: xs) = 1 + len0


-- otra
len =  foldl (\acc el -> acc + 1) 0 

