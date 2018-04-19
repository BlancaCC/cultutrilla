{- MIMIFIQUIDIR, el programa para meterse con la gente por excelencia
Granada 31 /III / 18
-}
iin :: Char -> [Char] -> Bool
iin _ [] = False
iin a (x:xs) 
  | a == x = True
  | otherwise = iin a xs

mimificar :: [Char] -> [Char]
mimificar [] = []
mimificar ( x : xs)
  | x `iin` "aeou" = ['i'] ++ mimificar xs
  | x `iin` "áéóú" =['í'] ++ mimificar xs
  | x `iin` "AEOU" = ['I'] ++ mimificar xs
  | x `iin` "ÁÉÓÚ" = ['Í'] ++ mimificar xs
  | otherwise = [x] ++  mimificar xs
