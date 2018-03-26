-- Eso de repetirse está muy bien, pero a veces es tedioso para el reiterador, he aquí distintas versiones en haskell para cansinos de alta arcunia

-- Granada 12-02-2018

-- Versión 0, recursiva

hello_worlds 0 = return ()
hello_worlds n = do
  putStrLn "Hello Worlds"
  hello_worlds (n-1)

-- Versión 1, con replicate, la cual no termino de entender

bye_worlds n = mapM putStrLn $ replicate n "Bye Word"

-- Versión 2 simple y bonita, recursiva
olvido 1 = "Se me ha olvidado"
olvido n = "Se me ha olvidado\n" ++ olvido( n-1 )
olvidos n = putStrLn ( olvido n )

-- Versión 3  por compresión
amor n = putStrLn s
  where (x:s) = concat [ "\nte quiero" | _<- [1..n]]
----------------------------------------
main = do
  n <- readLn :: IO Int
  hello_worlds n
  bye_worlds n
  olvidos n
  amor n



  
