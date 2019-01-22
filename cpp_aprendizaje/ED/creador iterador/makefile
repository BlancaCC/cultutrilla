iterador.out: iterador.cpp
	g++ $^ -o $@

test:
	echo "Los números a meter son "
	cat numeros.txt 
	./iterador.out < numeros.txt
