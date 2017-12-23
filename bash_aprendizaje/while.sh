#!/bin/bash

cnt=1
nombre=`date +%d_%m_%y.cpp`

while test -e $nombre
do
    nombre=`date +%d_%m_%y_V$cnt.cpp`
    let cnt++
done
touch $nombre
