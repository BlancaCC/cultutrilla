{- DEVUELVE DE UNA LISTA LAS POSICIONES PARES 
Granada 30 / III / 18
-}

-- mi solución 
f :: [Int]-> [Int]
f [] = []
f [_]=[]
f ( x : xm : xs) = [xm] ++ f xs


-- Solución de Boerworz
f1 xs = map fst $ filter (\t -> (odd . snd) t) $ (flip zip) [0..] xs

-- Solución de idiot1347
f lst = [x | (x,y) <- zip lst [1..length lst], even y]
