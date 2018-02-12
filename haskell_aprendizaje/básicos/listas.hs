-- HAY QUE SER MUY TONTO PARA NO UTILIZAR LISTAS
-- Dado un natural n  y una lista, repetir cada elemento de la lista n veces



-- La solución más cutre, la mía 
f :: Int -> [Int] -> [Int]

f n arr = 
  return [ a+b*0 | a <- arr , b<-[1..n]] !! 0

main :: IO()

main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr ). map read. words 


-- Solución 1, Boerworz
f n = concat . map (replicate n)

-- This part handles the Input and Output and can be used as it is. Do not modify this part.
main = do
   n <- readLn :: IO Int
   inputdata <- getContents
   mapM_ putStrLn $ map show $ f n $ map (read :: String -> Int) $ lines inputdata
   

-- Solución 2, Parajao

f _ [] = []
f n (x:xs) = take n(repeat x) ++ f n xs


-- Solución 3, Saeedn

-- basic version
 rep 0 x = []
 rep n x = x : rep (n-1) x

 f n [] = []
 f n (x:xs) = rep n x ++ f n xs

-- advance version
f n = concat . map (replicate n)


--Solución 4,syllogismos
f n [] = [] 
f n [a] = take n $ repeat a
f n (x:xs) = (take n $ repeat x) ++ f n xs
