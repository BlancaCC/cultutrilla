#!/bin/bash

lim=10

for (( c=1; c<lim; c++ ))
do
    for (( d=1; d<lim; d++ ))
    do
	a=$(($lim+$d))
    done
done

echo fin $0 con pid $$, a vale $a


