#!/bin/bash
inicio=100
fin=30000
incremento=500

ejecutable="burbujamejor"
salida="burbum.dat"
 
i=$inicio
echo > $salida
while [ $i -lt $fin ] 
do
  echo "Ejecución tam = " $i
  echo `./$ejecutable $i $i` >> $salida
  i=$[$i+$incremento]
done
