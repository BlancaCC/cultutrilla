INCLUDE = ./include
FLAGS = -g # flag de depuración
EXE = bin/uso_pilas_max.out
SRC = ./src/
OBJ = ./obj/

$(EXE) : $(OBJ)uso_pila_max.o
	g++  -o $(EXE) $(FLAGS) $(OBJ)uso_pila_max.o

$(OBJ)uso_pila_max.o:  $(SRC)uso_pila_max.cpp $(INCLUDE)/pila_max.tpp $(INCLUDE)/pila_max.h $(INCLUDE)/vector_dinamico.tpp 
	g++ -c $(FLAGS) $(SRC)uso_pila_max.cpp -o $(OBJ)uso_pila_max.o -I$(INCLUDE)

valgrind:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./$(EXE)

test:
	./$(EXE)
clear:
	rm $(EXE)
documentacion:
	doxygen doc/doxys/Doxyfile
