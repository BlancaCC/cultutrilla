{- Devuelve una lista de tamaño n | 1<= n <= 100
Granada 30-3-18
-}

-- Mi solución
fn n = [ x | x <- [1..100] , x<= n]

-- la editoriao lo resuelve así
fn1 n = take n [0..]

-- take coge los n primeros de una lista 
