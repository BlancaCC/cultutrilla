SRC=usodiccionario

$(SRC).out: $(SRC).cpp diccionario.h
	g++ -g -o $@ $(SRC).cpp

clear:
	rm *~ *.out

valgrind:
	valgrind --leak-check=yes ./$(SRC).out < data.txt
test:
	./$(SRC).out < data.txt


