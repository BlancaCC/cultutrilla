cat#!/bin/bash
inicio=100
fin=30000
incremento=500

ejecutable="n"
salida="n.dat"
 
i=$inicio
echo > $salidax
while [ $i -lt $fin ] 
do
  echo "Ejecución tam = " $i
  echo `./$ejecutable $i 10000` >> $salida
  i=$[$i+$incremento]
done
